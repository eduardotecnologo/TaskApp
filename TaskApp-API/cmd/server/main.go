package main

import (
	"log"
	"fmt"
	"taskapp-api/internal/handlers"
	"taskapp-api/internal/middleware"
	"taskapp-api/internal/repository"
	"taskapp-api/internal/services"
	"github.com/gin-gonic/gin"
	"github.com/spf13/viper"
)

func main() {
	// Carregar configurações ....
	if err := loadConfig(); err != nil {
		log.Fatal("Erro ao carregar configurações:::", err)
	}

	// Conectar ao banco de dados
	dbConfig := repository.DatabaseConfig{
		Host:     viper.GetString("database.host"),
		Port:     viper.GetInt("database.port"),
		User:     viper.GetString("database.user"),
		Password: viper.GetString("database.password"),
		Name:     viper.GetString("database.name"),
		Charset:  viper.GetString("database.charset"),
	}

	db, err := repository.NewDatabase(dbConfig)
	if err != nil {
		log.Fatal("Erro ao conectar com o banco:", err)
	}

	// Inicializar repositórios
	userRepo := repository.NewUserRepository(db)

	// Inicializar serviços
	authService := services.NewAuthService(userRepo, viper.GetString("jwt.secret"))

	// Inicializar handlers
	authHandler := handlers.NewAuthHandler(authService)

	// Configurar Gin
	if viper.GetString("server.mode") == "production" {
		gin.SetMode(gin.ReleaseMode)
	}

	router := gin.Default()

	// Middlewares globais
	router.Use(middleware.CORSMiddleware())

	// Rotas públicas (sem autenticação)
	api := router.Group("/api")
	{
		auth := api.Group("/auth")
		{
			auth.POST("/login", authHandler.Login)
			auth.POST("/register", authHandler.Register)
			auth.POST("/forgot-password", authHandler.ForgotPassword)
		}
	}

	// Rotas protegidas (com autenticação)
	protected := api.Group("/")
	protected.Use(middleware.AuthMiddleware(viper.GetString("jwt.secret")))
	{
		// Aqui virão as rotas protegidas (boards, lists, cards)
		protected.GET("/profile", func(c *gin.Context) {
			usuario := c.GetString("usuario")
			c.JSON(200, gin.H{
				"usuario": usuario,
				"message": "Perfil do usuário autenticado",
			})
		})
	}

	// Rota de health check
	router.GET("/health", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"status": "OK",
			"message": "TaskApp API está funcionando",
		})
	})

	// Iniciar servidor
	port := viper.GetString("server.port")
	host := viper.GetString("server.host")
	
	log.Printf("🚀 Servidor iniciando em http://%s:%s", host, port)
	log.Printf("📋 Health check: http://%s:%s/health", host, port)
	log.Printf("🔐 Login endpoint: http://%s:%s/api/auth/login", host, port)
	
	if err := router.Run(fmt.Sprintf("%s:%s", host, port)); err != nil {
		log.Fatal("Erro ao iniciar servidor:", err)
	}
}

func loadConfig() error {
	viper.SetConfigName("config")
	viper.SetConfigType("yaml")
	viper.AddConfigPath("./configs")
	viper.AddConfigPath("../../configs") // Para quando executar de cmd/server

	// Valores padrão
	viper.SetDefault("server.port", "8080")
	viper.SetDefault("server.host", "localhost")
	viper.SetDefault("server.mode", "debug")
	viper.SetDefault("database.charset", "utf8mb4")
	viper.SetDefault("jwt.secret", "taskapp-secret-key")

	if err := viper.ReadInConfig(); err != nil {
		log.Printf("Aviso: Não foi possível ler o arquivo de configuração: %v", err)
		log.Println("Usando configurações padrão...")
	}

	return nil
}