package repository

import (
	"taskapp-api/internal/models"
	"gorm.io/gorm"
)

type UserRepository struct {
	db *gorm.DB
}

func NewUserRepository(db *gorm.DB) *UserRepository {
	return &UserRepository{db: db}
}

// FindByUsuario busca usuário pelo nome de usuário
func (r *UserRepository) FindByUsuario(usuario string) (*models.User, error) {
	var user models.User
	err := r.db.Where("usuario = ?", usuario).First(&user).Error
	if err != nil {
		return nil, err
	}
	return &user, nil
}

// FindByEmail busca usuário pelo email
func (r *UserRepository) FindByEmail(email string) (*models.User, error) {
	var user models.User
	err := r.db.Where("email = ?", email).First(&user).Error
	if err != nil {
		return nil, err
	}
	return &user, nil
}

// Create cria um novo usuário
func (r *UserRepository) Create(user *models.User) error {
	return r.db.Create(user).Error
}

// Update atualiza um usuário
func (r *UserRepository) Update(user *models.User) error {
	return r.db.Save(user).Error
}

// UpdatePassword atualiza apenas a senha do usuário
func (r *UserRepository) UpdatePassword(usuario string, novaSenha string, temporaria bool) error {
	return r.db.Model(&models.User{}).
		Where("usuario = ?", usuario).
		Updates(map[string]interface{}{
			"senha":                 novaSenha,
			"senha_temporaria":      temporaria,
			"data_alteracao_senha":  gorm.Expr("NOW()"),
		}).Error
}