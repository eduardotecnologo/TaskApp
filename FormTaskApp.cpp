//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTaskApp.h"
#include "FormLogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	if (FrmLogin->ShowModal() != mrOk) {
		Application->Terminate(); // Fecha o app se o login for cancelado
    } else {
        // Login foi bem-sucedido, pode continuar
        // Verifica se o EditUsuario tem conteúdo (login normal) ou se veio do cadastro
        if (FrmLogin->EditUsuario->Text.Trim() != "") {
            Caption = "TaskApp - Logado como: " + FrmLogin->EditUsuario->Text;
        }
        // Se não tem conteúdo, o título já foi definido no cadastro
    }
}
//---------------------------------------------------------------------------
