//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormRecuperarSenha.h"
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRecuperarSenha *FrmRecuperarSenha;
//---------------------------------------------------------------------------
__fastcall TFrmRecuperarSenha::TFrmRecuperarSenha(TComponent* Owner)
	: TForm(Owner)
{
    Position = poScreenCenter;
    BorderStyle = bsDialog;
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecuperarSenha::FormShow(TObject *Sender)
{
    // Configurar o formulário com os dados
    LblUsuario->Caption = "Usuário: " + Usuario;
    EditNovaSenha->Text = NovaSenha;
    
    // Selecionar todo o texto da senha para facilitar a cópia
    EditNovaSenha->SelectAll();
    EditNovaSenha->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecuperarSenha::BtnCopiarSenhaClick(TObject *Sender)
{
    // Copiar a senha para a área de transferência
    Clipboard()->AsText = EditNovaSenha->Text;
    
    // Mostrar confirmação
    ShowMessage("Senha copiada para a área de transferência!");
    
    // Selecionar novamente o texto
    EditNovaSenha->SelectAll();
    EditNovaSenha->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecuperarSenha::BtnFecharClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
