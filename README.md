# TaskApp

Aplicativo de Tarefas em **C++ Builder**

---

## 🧱 Camadas da Arquitetura

### 1. Apresentação (View)
- Formulários (`TForm`) com os componentes visuais.
- Interage com o usuário (exibe quadros, listas, cartões).
- **Não deve conter regras de negócio.**
- **Exemplos:** `TfrmMain`, `TfrmBoard`, `TfrmCardEditor`

### 2. Presenter
- Controla a lógica da interface.
- Recebe eventos da View e coordena chamadas para o Model.
- Atualiza a View com dados do Model.
- **Exemplos:** `BoardPresenter`, `CardPresenter`

### 3. Modelo (Model)
- Contém as regras de negócio e estrutura dos dados.
- Gerencia entidades como `Board`, `List`, `Card`, `User`.
- **Não conhece a interface.**

### 4. Persistência / Repositórios
- Responsável por salvar e carregar dados (arquivo, banco de dados, API REST).
- Pode usar FireDAC (para SQLite, MySQL, etc.).
- **Exemplos:** `CardRepository`, `BoardRepository`

---

## 📌 Exemplo de Fluxo (Adicionar Cartão)

1. Usuário clica em **"Adicionar Cartão"**.
2. View dispara evento → chama `CardPresenter::AddCard()`.
3. Presenter valida os dados, cria um `Card` e chama o `CardRepository` para salvar.
4. Presenter atualiza a View para exibir o novo cartão.

---

## 🧰 Ferramentas no C++ Builder

- **FMX (FireMonkey):** Para multiplataforma (Windows, macOS, Android).
- **VCL:** Para apps desktop Windows nativos.
- **FireDAC:** Para acesso a banco de dados.
- **REST Client Library:** Caso integre com servidores ou APIs externas.
- **LiveBindings:** Para conectar