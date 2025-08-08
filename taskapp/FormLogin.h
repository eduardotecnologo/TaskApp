//---------------------------------------------------------------------------

#ifndef FormLoginH
#define FormLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FormRecuperarSenha.h"
//---------------------------------------------------------------------------
class TFrmLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelUsuario;
	TEdit *EditUsuario;
	TLabel *LabelSenha;
	TEdit *EditSenha;
	TButton *btnEntrar;
	TLabel *LblMensagem;
	TLabel *Label1;
	TButton *BtnCadastrarUsuario;
	TButton *BtnRecuperarSenha;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnCadastrarUsuarioClick(TObject *Sender);
	void __fastcall BtnRecuperarSenhaClick(TObject *Sender);
	void __fastcall btnEntrarClick(TObject *Sender);
private:	// User declarations
	String GerarSenhaTemporaria();
public:		// User declarations
	__fastcall TFrmLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLogin *FrmLogin;
//---------------------------------------------------------------------------
#endif
