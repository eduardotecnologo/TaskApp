# API Backend para TaskApp

## 🎯 **Go (Golang)**

Após análise das opções disponíveis, **Go** é a escolha recomendada para o backend do TaskApp pelos seguintes motivos:

### ✅ **Vantagens do Go para este projeto**

1. **Performance Excepcional**
   - Ideal para APIs com muitos usuários simultâneos
   - Concorrência nativa com goroutines
   - Compilação rápida e eficiente

2. **Simplicidade e Produtividade**
   - Sintaxe limpa e fácil de aprender
   - Menos boilerplate que Java
   - Foco no código de negócio

3. **Deploy e Manutenção**
   - Binário único, fácil de containerizar
   - Menor consumo de memória
   - Startup rápido

4. **Ecossistema Moderno**
   - Frameworks web maduros (Gin, Echo)
   - ORMs eficientes (GORM)
   - Ferramentas de desenvolvimento excelentes

### ⚖️ **Comparação com Java Spring**

| Aspecto | Go | Java Spring |
|---------|----|-------------|
| **Performance** | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| **Simplicidade** | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ |
| **Ecossistema** | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| **Curva de Aprendizado** | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ |
| **Deploy** | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| **Memória** | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ |

## 🏗️ **Arquitetura Proposta**

```
TaskApp-API/
├── cmd/
│   └── server/
│       └── main.go                 # Ponto de entrada da aplicação
├── internal/
│   ├── handlers/                   # Controladores HTTP
│   │   ├── auth.go                 # Autenticação
│   │   ├── users.go                # Gestão de usuários
│   │   ├── boards.go               # Gestão de quadros
│   │   ├── lists.go                # Gestão de listas
│   │   └── cards.go                # Gestão de cartões
│   ├── models/                     # Estruturas de dados
│   │   ├── user.go
│   │   ├── board.go
│   │   ├── list.go
│   │   └── card.go
│   ├── repository/                 # Camada de persistência
│   │   ├── user_repository.go
│   │   ├── board_repository.go
│   │   └── database.go
│   ├── services/                   # Lógica de negócio
│   │   ├── auth_service.go
│   │   ├── user_service.go
│   │   └── board_service.go
│   └── middleware/                 # Middlewares HTTP
│       ├── auth.go                 # Autenticação JWT
│       ├── cors.go                 # CORS
│       └── logging.go              # Logging
├── pkg/                           # Pacotes públicos
│   ├── utils/                     # Utilitários
│   └── validators/                # Validações
├── configs/                       # Configurações
├── migrations/                    # Migrações do banco
├── go.mod                         # Dependências
├── go.sum                         # Checksums
└── README.md                      # Documentação
```

## 📋 **Endpoints da API**

### 🔐 **Autenticação**
```
POST   /api/auth/login              # Login de usuário
POST   /api/auth/register           # Registro de usuário
POST   /api/auth/refresh            # Renovar token
POST   /api/auth/forgot-password    # Esqueci minha senha
POST   /api/auth/reset-password     # Resetar senha
```

### 👤 **Usuários**
```
GET    /api/users/profile           # Obter perfil
PUT    /api/users/profile           # Atualizar perfil
DELETE /api/users/profile           # Deletar conta
```

### 📋 **Boards (Quadros)**
```
GET    /api/boards                  # Listar quadros
POST   /api/boards                  # Criar quadro
GET    /api/boards/{id}             # Obter quadro
PUT    /api/boards/{id}             # Atualizar quadro
DELETE /api/boards/{id}             # Deletar quadro
```

### 📝 **Lists (Listas)**
```
GET    /api/boards/{boardId}/lists  # Listar listas do quadro
POST   /api/boards/{boardId}/lists  # Criar lista
PUT    /api/lists/{id}              # Atualizar lista
DELETE /api/lists/{id}              # Deletar lista
```

### 🃏 **Cards (Cartões)**
```
GET    /api/lists/{listId}/cards    # Listar cartões da lista
POST   /api/lists/{listId}/cards    # Criar cartão
PUT    /api/cards/{id}              # Atualizar cartão
DELETE /api/cards/{id}              # Deletar cartão
POST   /api/cards/{id}/move         # Mover cartão
```

## 🛠️ **Stack Tecnológica**

### **Core**
- **Go 1.21+** - Linguagem principal
- **Gin** - Framework web rápido e leve
- **GORM** - ORM para Go
- **MySQL** - Banco de dados

### **Autenticação & Segurança**
- **JWT-Go** - Tokens JWT
- **bcrypt** - Criptografia de senhas
- **CORS** - Cross-Origin Resource Sharing

### **Desenvolvimento**
- **Viper** - Gerenciamento de configuração
- **Zap** - Logging estruturado
- **Swagger** - Documentação da API
- **Air** - Hot reload para desenvolvimento

### **Ferramentas**
- **Docker** - Containerização
- **Postman/Insomnia** - Testes da API
- **Git** - Controle de versão

## 🗄️ **Modelo de Dados**

### **Tabela: users**
```sql
CREATE TABLE users (
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    is_active BOOLEAN DEFAULT TRUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
```

### **Tabela: boards**
```sql
CREATE TABLE boards (
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100) NOT NULL,
    description TEXT,
    user_id BIGINT NOT NULL,
    is_public BOOLEAN DEFAULT FALSE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
```

### **Tabela: lists**
```sql
CREATE TABLE lists (
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100) NOT NULL,
    position INT NOT NULL,
    board_id BIGINT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (board_id) REFERENCES boards(id) ON DELETE CASCADE
);
```

### **Tabela: cards**
```sql
CREATE TABLE cards (
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(200) NOT NULL,
    description TEXT,
    position INT NOT NULL,
    list_id BIGINT NOT NULL,
    due_date DATE,
    priority ENUM('low', 'medium', 'high') DEFAULT 'medium',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (list_id) REFERENCES lists(id) ON DELETE CASCADE
);
```

## 🔄 **Migração do Frontend**

### **Adaptações Necessárias no C++ Builder**

1. **Substituir FireDAC por HTTP Client**
   - Usar `TIdHTTP` ou `TRESTClient`
   - Implementar chamadas REST para a API

2. **Gerenciamento de Tokens**
   - Armazenar JWT token localmente
   - Implementar refresh automático

3. **Tratamento de Respostas**
   - Parsear JSON responses
   - Implementar tratamento de erros HTTP

### **Exemplo de Adaptação**
```cpp
// Antes (FireDAC)
TFDQuery *query = new TFDQuery(NULL);
query->Connection = DataModule1->FDConnection;
query->SQL->Text = "SELECT * FROM usuarios WHERE usuario = :usuario";

// Depois (HTTP Client)
TRESTClient *client = new TRESTClient(NULL);
TRESTRequest *request = new TRESTRequest(NULL);
request->Client = client;
request->Resource = "api/auth/login";
request->Method = rmPOST;
```

## 🚀 **Plano de Implementação**

### **Fase 1: Base da API**
- [ ] Estrutura do projeto Go
- [ ] Configuração do banco de dados
- [ ] Sistema de autenticação JWT
- [ ] CRUD básico de usuários

### **Fase 2: Funcionalidades Core**
- [ ] Gestão de quadros (boards)
- [ ] Gestão de listas
- [ ] Gestão de cartões
- [ ] Validações e middleware

### **Fase 3: Integração**
- [ ] Documentação Swagger
- [ ] Testes da API
- [ ] Adaptação do frontend C++
- [ ] Deploy e configuração

### **Fase 4: Melhorias**
- [ ] Cache Redis
- [ ] Logs estruturados
- [ ] Monitoramento
- [ ] CI/CD

## 📊 **Benefícios da Migração**

1. **Escalabilidade**: API pode servir múltiplos clientes
2. **Manutenibilidade**: Separação clara de responsabilidades
3. **Flexibilidade**: Possibilidade de web/mobile apps
4. **Performance**: Backend otimizado em Go
5. **Segurança**: Autenticação JWT robusta
6. **Padrões**: REST API seguindo melhores práticas

---

**Próximo passo**: Implementar a estrutura base da API em Go seguindo esta arquitetura. 