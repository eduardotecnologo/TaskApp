package repository

import (
	"fmt"
	"taskapp-api/internal/models"
	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
)

type DatabaseConfig struct {
	Host     string
	Port     int
	User     string
	Password string
	Name     string
	Charset  string
}

func NewDatabase(config DatabaseConfig) (*gorm.DB, error) {
	dsn := fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&parseTime=True&loc=Local",
		config.User,
		config.Password,
		config.Host,
		config.Port,
		config.Name,
		config.Charset,
	)

	db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{
		Logger: logger.Default.LogMode(logger.Info),
	})
	
	if err != nil {
		return nil, fmt.Errorf("erro ao conectar com o banco de dados: %v", err)
	}

	// Auto migrate das tabelas
	err = db.AutoMigrate(&models.User{})
	if err != nil {
		return nil, fmt.Errorf("erro ao executar migrations: %v", err)
	}

	return db, nil
}