package middleware

import (
	"net/http"
	"strings"
	"github.com/gin-gonic/gin"
	"github.com/golang-jwt/jwt/v5"
)

func AuthMiddleware(jwtSecret string) gin.HandlerFunc {
	return func(c *gin.Context) {
		authHeader := c.GetHeader("Authorization")
		if authHeader == "" {
			c.JSON(http.StatusUnauthorized, gin.H{
				"error": "Token de autorização necessário",
			})
			c.Abort()
			return
		}

		// Verificar se o header tem o formato "Bearer <token>"
		tokenString := strings.TrimPrefix(authHeader, "Bearer ")
		if tokenString == authHeader {
			c.JSON(http.StatusUnauthorized, gin.H{
				"error": "Formato de token inválido",
			})
			c.Abort()
			return
		}

		// Validar o token
		token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
			return []byte(jwtSecret), nil
		})

		if err != nil || !token.Valid {
			c.JSON(http.StatusUnauthorized, gin.H{
				"error": "Token inválido",
			})
			c.Abort()
			return
		}

		// Extrair claims do token
		if claims, ok := token.Claims.(jwt.MapClaims); ok {
			c.Set("usuario", claims["usuario"])
		}

		c.Next()
	}
}