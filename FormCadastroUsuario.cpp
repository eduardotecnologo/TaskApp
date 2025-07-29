//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCadastroUsuario.h"
#include "DmConexao.h"
extern TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCadastroUsuario *FrmCadastroUsuario = nullptr;
//---------------------------------------------------------------------------
__fastcall TFrmCadastroUsuario::TFrmCadastroUsuario(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmCadastroUsuario::BtnSalvarCadastroClick(TObject *Sender)
{
	 if(EdtNomeUsuario->Text.Trim() == "")
	 {
		ShowMessage("O Campo Usuário é Obrigatório!");
		EdtNomeUsuario->SetFocus();
		return;
	 }
	 if(EdtSenha->Text.Trim() == "")
	 {
		ShowMessage("O Campo Senha é Obrigatório!");
		EdtSenha->SetFocus();
		return;
	 }
	 if(EdtSenha->Text.Length() < 6)
	 {
        ShowMessage("A Senha deve conter no mínimo 6 caracteres!");
		EdtSenha->SetFocus();
		return;
	 }
	 
	 // Verificar se as senhas coincidem
	 if(EdtConfirmarSenha->Text != EdtSenha->Text)
	 {
		ShowMessage("As senhas não coincidem!");
		EdtConfirmarSenha->SetFocus();
		return;
	 }
	 
	 // O E-mail é Opcional
	 if(EdtEmail->Text.Trim() != "" && !EdtEmail->Text.Pos("@"))
	 {
		ShowMessage("E-mail inválido!");
		EdtEmail->SetFocus();
        return;
	 }
	 
	 // Verificar se usuário já existe
	 TFDQuery *queryCheck = new TFDQuery(NULL);
	 try {
		 queryCheck->Connection = DataModule1->FDConnection;
		 queryCheck->SQL->Text = "SELECT id FROM usuarios WHERE usuario = :usuario";
		 queryCheck->ParamByName("usuario")->AsString = EdtNomeUsuario->Text.Trim();
		 queryCheck->Open();
		 
		 if (!queryCheck->Eof) {
			 ShowMessage("Este nome de usuário já existe. Escolha outro.");
			 EdtNomeUsuario->SetFocus();
			 return;
		 }
	 }
	 __finally {
		 queryCheck->Free();
	 }
	 
	 // Inserir novo usuário
	 TFDQuery *queryInsert = new TFDQuery(NULL);
	 try {
		 queryInsert->Connection = DataModule1->FDConnection;
		 queryInsert->SQL->Text = "INSERT INTO usuarios (usuario, senha, email) VALUES (:usuario, :senha, :email)";
		 queryInsert->ParamByName("usuario")->AsString = EdtNomeUsuario->Text.Trim();
		 queryInsert->ParamByName("senha")->AsString = EdtSenha->Text.Trim();
		 queryInsert->ParamByName("email")->AsString = EdtEmail->Text.Trim();
		 queryInsert->ExecSQL();
		 
		 ShowMessage("Usuário cadastrado com sucesso!");
		 ModalResult = mrOk; // Fecha o formulário
	 }
	 catch (Exception &e) {
		ShowMessage("Erro ao cadastrar usuário: " + e.Message);
	 }
	 queryInsert->Free(); // Fora do try/catch
}
//---------------------------------------------------------------------------
void __fastcall TFrmCadastroUsuario::BtnCancelarClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
