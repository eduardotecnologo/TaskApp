//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FormTaskApp.cpp", TFrmTaskApp);
USEFORM("DmConexao.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("FormCadastroUsuario.cpp", FrmCadastroUsuario);
USEFORM("FormLogin.cpp", FrmLogin);
USEFORM("FormRecuperarSenha.cpp", FrmRecuperarSenha);
USEFORM("FormTaskMain.cpp", FrmTaskMain);
USEFORM("FormBoasVindas.cpp", FrmBoasVindas);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFrmLogin), &FrmLogin);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TFrmBoasVindas), &FrmBoasVindas);
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
