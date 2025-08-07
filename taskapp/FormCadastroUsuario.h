//---------------------------------------------------------------------------

#ifndef FormCadastroUsuarioH
#define FormCadastroUsuarioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmCadastroUsuario : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EdtNomeUsuario;
	TLabel *Label3;
	TEdit *EdtEmail;
	TLabel *Label4;
	TEdit *EdtSenha;
	TBitBtn *BtnSalvarCadastro;
	TBitBtn *BtnCancelar;
	TLabel *Label5;
	TEdit *EdtConfirmarSenha;
	void __fastcall BtnSalvarCadastroClick(TObject *Sender);
    void __fastcall BtnCancelarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmCadastroUsuario(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCadastroUsuario *FrmCadastroUsuario;
//---------------------------------------------------------------------------
#endif
