//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FormTaskApp.cpp", Form1);
USEFORM("FormLogin.cpp", FrmLogin);
USEFORM("FormCadastroUsuario.cpp", FrmCadastroUsuario);
USEFORM("DmConexao.cpp", DataModule1); /* TDataModule: File Type */
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
