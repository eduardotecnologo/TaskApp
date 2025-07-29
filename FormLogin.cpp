//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLogin.h"
#include "DmConexao.h"
extern TDataModule1 *DataModule1;

#include "FormCadastroUsuario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmLogin *FrmLogin;
//---------------------------------------------------------------------------
__fastcall TFrmLogin::TFrmLogin(TComponent* Owner)
	: TForm(Owner)
{
    Position = poScreenCenter;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::BtnLoginClick(TObject *Sender)
{
    if(EditUsuario->Text == "" || EditSenha->Text == "")
    {
        LblMensagem->Caption = "Preencha formulrio e senha";
    }
    else
    {
        LblMensagem->Caption = "Tentativa de Login...";
	}

	// Criar a query para verificar login
	TFDQuery *query = new TFDQuery(NULL);
	try
	{
		query->Connection = DataModule1->FDConnection;
		query->SQL->Text = "SELECT id, usuario FROM usuarios WHERE usuario = :usuario AND senha = :senha";
		query->ParamByName("usuario")->AsString = EditUsuario->Text.Trim();
		query->ParamByName("senha")->AsString = EditSenha->Text.Trim();
		query->Open();

		if(!query->Eof)
		{
          LblMensagem->Caption = "Login realizado com Sucesso!";
          ModalResult = mrOk; // Fecha o modal com sucesso
		}
		else
		{
		  LblMensagem->Caption = "Login inválido!";
		  EditSenha->Text = "";
          EditSenha->SetFocus();
		}
	}
	__finally
	{
        query->Free();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::BtnCadastrarUsuarioClick(TObject *Sender)
{
    // Abrir o formulário de cadastro de usuário (a ser criado)
    // Exemplo:
	// FrmCadastroUsuario->ShowModal();
	if(!FrmCadastroUsuario)
	   FrmCadastroUsuario = new TFrmCadastroUsuario(this);
       FrmCadastroUsuario->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::FormShow(TObject *Sender)
{
  	Position = poScreenCenter;
}
//---------------------------------------------------------------------------

