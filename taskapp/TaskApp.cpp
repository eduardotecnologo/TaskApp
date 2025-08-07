//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FormTaskApp.cpp", Form1);
USEFORM("DmConexao.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("FormCadastroUsuario.cpp", FrmCadastroUsuario);
USEFORM("FormLogin.cpp", FrmLogin);
USEFORM("FormRecuperarSenha.cpp", FrmRecuperarSenha);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFrmLogin), &FrmLogin);
		Application->CreateForm(__classid(TFrmCadastroUsuario), &FrmCadastroUsuario);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TFrmRecuperarSenha), &FrmRecuperarSenha);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
