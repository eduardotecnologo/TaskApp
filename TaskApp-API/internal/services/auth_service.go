package services

import (
	"errors"
	"math/rand"
	"strings"
	"time"
	"taskapp-api/internal/models"
	"taskapp-api/internal/repository"
	"golang.org/x/crypto/bcrypt"
	"github.com/golang-jwt/jwt/v5"
)

type AuthService struct {
	userRepo  *repository.UserRepository
	jwtSecret string
}

func NewAuthService(userRepo *repository.UserRepository, jwtSecret string) *AuthService {
	return &AuthService{
		userRepo:  userRepo,
		jwtSecret: jwtSecret,
	}
}

// Login autentica o usuário
func (s *AuthService) Login(req *models.LoginRequest) (*models.LoginResponse, error) {
	// Buscar usuário
	user, err := s.userRepo.FindByUsuario(strings.TrimSpace(req.Usuario))
	if err != nil {
		return nil, errors.New("usuário ou senha inválidos")
	}

	// Verificar senha
	err = bcrypt.CompareHashAndPassword([]byte(user.Senha), []byte(req.Senha))
	if err != nil {
		return nil, errors.New("usuário ou senha inválidos")
	}

	// Gerar token JWT
	token, err := s.generateJWT(user.Usuario)
	if err != nil {
		return nil, errors.New("erro ao gerar token de autenticação")
	}

	return &models.LoginResponse{
		Token:   token,
		Usuario: user.Usuario,
		Message: "Login realizado com sucesso",
	}, nil
}

// Register cadastra um novo usuário
func (s *AuthService) Register(req *models.RegisterRequest) error {
	// Validar se as senhas coincidem
	if req.Senha != req.ConfirmarSenha {
		return errors.New("as senhas não coincidem")
	}

	// Verificar se usuário já existe
	_, err := s.userRepo.FindByUsuario(strings.TrimSpace(req.Usuario))
	if err == nil {
		return errors.New("este nome de usuário já existe")
	}

	// Verificar email se fornecido
	if req.Email != "" {
		if !strings.Contains(req.Email, "@") {
			return errors.New("e-mail inválido")
		}
		// Verificar se email já existe
		_, err := s.userRepo.FindByEmail(strings.TrimSpace(req.Email))
		if err == nil {
			return errors.New("este e-mail já está cadastrado")
		}
	}

	// Hash da senha
	hashedPassword, err := bcrypt.GenerateFromPassword([]byte(req.Senha), bcrypt.DefaultCost)
	if err != nil {
		return errors.New("erro ao processar senha")
	}

	// Criar usuário
	user := &models.User{
		Usuario: strings.TrimSpace(req.Usuario),
		Email:   strings.TrimSpace(req.Email),
		Senha:   string(hashedPassword),
	}

	return s.userRepo.Create(user)
}

// ForgotPassword gera nova senha temporária
func (s *AuthService) ForgotPassword(req *models.ForgotPasswordRequest) (*models.ForgotPasswordResponse, error) {
	// Buscar usuário
	user, err := s.userRepo.FindByUsuario(strings.TrimSpace(req.Usuario))
	if err != nil {
		return nil, errors.New("usuário não encontrado no sistema")
	}

	// Gerar senha temporária
	novaSenha := s.gerarSenhaTemporaria()

	// Hash da nova senha
	hashedPassword, err := bcrypt.GenerateFromPassword([]byte(novaSenha), bcrypt.DefaultCost)
	if err != nil {
		return nil, errors.New("erro ao gerar nova senha")
	}

	// Atualizar senha no banco
	err = s.userRepo.UpdatePassword(user.Usuario, string(hashedPassword), true)
	if err != nil {
		return nil, errors.New("erro ao atualizar senha")
	}

	return &models.ForgotPasswordResponse{
		Usuario:   user.Usuario,
		NovaSenha: novaSenha,
		Email:     user.Email,
		Message:   "Senha temporária gerada com sucesso",
	}, nil
}

// generateJWT gera um token JWT
func (s *AuthService) generateJWT(usuario string) (string, error) {
	claims := jwt.MapClaims{
		"usuario": usuario,
		"exp":     time.Now().Add(24 * time.Hour).Unix(),
		"iat":     time.Now().Unix(),
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	return token.SignedString([]byte(s.jwtSecret))
}

// gerarSenhaTemporaria gera uma senha aleatória de 8 caracteres
func (s *AuthService) gerarSenhaTemporaria() string {
	caracteres := "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	tamanho := 8
	
	rand.Seed(time.Now().UnixNano())
	senha := make([]byte, tamanho)
	
	for i := 0; i < tamanho; i++ {
		senha[i] = caracteres[rand.Intn(len(caracteres))]
	}
	
	return string(senha)
}