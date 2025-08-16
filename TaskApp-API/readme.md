# TaskApp API

API REST em Go para o sistema TaskApp, substituindo a conexão direta com MySQL do frontend C++ Builder.

## 🚀 Funcionalidades Implementadas

### Autenticação
- ✅ Login de usuários
- ✅ Cadastro de usuários
- ✅ Recuperação de senha (geração de senha temporária)
- ✅ Autenticação JWT
- ✅ Hash de senhas com bcrypt

## 🛠️ Tecnologias

- **Go 1.21+**
- **Gin** - Framework web
- **GORM** - ORM para MySQL
- **JWT** - Autenticação
- **bcrypt** - Hash de senhas
- **Viper** - Configuração

## 📋 Endpoints

### Autenticação
```
POST /api/auth/login          # Login
POST /api/auth/register       # Cadastro
POST /api/auth/forgot-password # Recuperar senha
GET  /health                  # Health check
```

## ⚙️ Configuração

### 1. Instalar dependências
```bash
go mod tidy
```

### 2. Configurar banco (configs/config.yaml)
```yaml
database:
  host: 172.26.37.69
  port: 3306
  user: taskuser
  password: taskpass
  name: taskapp
```

### 3. Executar
```bash
go run cmd/server/main.go
```

## 🔧 Uso com C++ Builder

### Exemplo de Login
```cpp
// Substituir a query FireDAC por chamada HTTP
TRESTClient *client = new TRESTClient(NULL);
TRESTRequest *request = new TRESTRequest(NULL);
TRESTResponse *response = new TRESTResponse(NULL);

client->BaseURL = "http://localhost:8080";
request->Client = client;
request->Response = response;
request->Resource = "api/auth/login";
request->Method = rmPOST;

// JSON do login
TJSONObject *json = new TJSONObject();
json->AddPair("usuario", EditUsuario->Text);
json->AddPair("senha", EditSenha->Text);
request->AddBody(json->ToString(), ctAPPLICATION_JSON);

request->Execute();

if (response->StatusCode == 200) {
    // Login bem-sucedido
    TJSONObject *responseJson = (TJSONObject*)TJSONObject::ParseJSONValue(response->Content);
    String token = responseJson->GetValue("token")->Value();
    // Armazenar token para próximas requisições
}
```

## 🗄️ Migração do Banco

A API automaticamente cria/atualiza as tabelas usando GORM AutoMigrate. A tabela `usuarios` existente será mantida e adaptada conforme necessário.

## 🔒 Segurança

- Senhas são hasheadas com bcrypt
- Autenticação JWT com expiração de 24h
- CORS configurado para desenvolvimento
- Validação de entrada em todos os endpoints

## 📊 Próximos Passos

1. ✅ Sistema de autenticação completo
2. 🚧 Endpoints para boards/listas/cards
3. 🚧 Middleware de logging
4. 🚧 Testes unitários
5. 🚧 Documentação Swagger