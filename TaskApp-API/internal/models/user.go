package models

import (
	"time"
	"gorm.io/gorm"
)

type User struct {
	ID                   uint      `json:"id" gorm:"primaryKey"`
	Usuario           string       `gorm:"type:varchar(255);uniqueIndex"`
    Email             string       `gorm:"type:varchar(255);uniqueIndex"`
    Senha             string       `gorm:"type:varchar(255);not null"`
    SenhaTemporaria   bool         `gorm:"default:false"`
	DataAlteracaoSenha   *time.Time `json:"data_alteracao_senha"`
	CreatedAt            time.Time `json:"created_at"`
	UpdatedAt            time.Time `json:"updated_at"`
	DeletedAt            gorm.DeletedAt `json:"-" gorm:"index"`
}

// LoginRequest representa os dados de login
type LoginRequest struct {
	Usuario string `json:"usuario" binding:"required"`
	Senha   string `json:"senha" binding:"required"`
}

// LoginResponse representa a resposta do login
type LoginResponse struct {
	Token   string `json:"token"`
	Usuario string `json:"usuario"`
	Message string `json:"message"`
}

// RegisterRequest representa os dados de cadastro
type RegisterRequest struct {
	Usuario        string `json:"usuario" binding:"required"`
	Email          string `json:"email"`
	Senha          string `json:"senha" binding:"required,min=6"`
	ConfirmarSenha string `json:"confirmar_senha" binding:"required"`
}

// ForgotPasswordRequest representa a solicitação de recuperação de senha
type ForgotPasswordRequest struct {
	Usuario string `json:"usuario" binding:"required"`
}

// ForgotPasswordResponse representa a resposta da recuperação de senha
type ForgotPasswordResponse struct {
	Usuario   string `json:"usuario"`
	NovaSenha string `json:"nova_senha"`
	Email     string `json:"email,omitempty"`
	Message   string `json:"message"`
}