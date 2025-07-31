//---------------------------------------------------------------------------
#ifndef FormRecuperarSenhaH
#define FormRecuperarSenhaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmRecuperarSenha : public TForm
{
__published:	// IDE-managed Components
	TLabel *LblTitulo;
	TLabel *LblUsuario;
	TLabel *LblNovaSenha;
	TEdit *EditNovaSenha;
	TButton *BtnCopiarSenha;
	TButton *BtnFechar;
	TLabel *LblInstrucoes;
	TBevel *Bevel1;
	void __fastcall BtnCopiarSenhaClick(TObject *Sender);
	void __fastcall BtnFecharClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	String Usuario;
	String NovaSenha;
	__fastcall TFrmRecuperarSenha(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRecuperarSenha *FrmRecuperarSenha;
//---------------------------------------------------------------------------
#endif
