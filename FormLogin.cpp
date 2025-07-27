//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLogin.h"
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

