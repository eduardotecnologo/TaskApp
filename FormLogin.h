//---------------------------------------------------------------------------

#ifndef FormLoginH
#define FormLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelUsuario;
	TEdit *EditUsuario;
	TLabel *LabelSenha;
	TEdit *EditSenha;
	TButton *Button1;
	TLabel *LblMensagem;
	TLabel *Label1;
	TButton *BtnCadastrarUsuario;
	void __fastcall BtnLoginClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnCadastrarUsuarioClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLogin *FrmLogin;
//---------------------------------------------------------------------------
#endif
