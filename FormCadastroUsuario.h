//---------------------------------------------------------------------------

#ifndef FormCadastroUsuarioH
#define FormCadastroUsuarioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmCadastroUsuario : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
private:	// User declarations
public:		// User declarations
	__fastcall TFrmCadastroUsuario(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCadastroUsuario *FrmCadastroUsuario;
//---------------------------------------------------------------------------
#endif
