//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLogin.h"
#include "DmConexao.h"
#include "FormTaskMain.h"
#include "FormBoasVindas.h"
extern TFrmBoasVindas *FrmBoasVindas;
extern TDataModule1 *DataModule1;
extern TFrmTaskMain *FrmTaskMain;

#include "FormCadastroUsuario.h"
#include "FormRecuperarSenha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmLogin *FrmLogin;
//---------------------------------------------------------------------------
__fastcall TFrmLogin::TFrmLogin(TComponent* Owner)
	: TForm(Owner)
{
	Position = poScreenCenter;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::BtnCadastrarUsuarioClick(TObject *Sender)
{
    // Abrir o formulário de cadastro de usuário (a ser criado)
    // Exemplo:
	// FrmCadastroUsuario->ShowModal();
	if(!FrmCadastroUsuario)
	   FrmCadastroUsuario = new TFrmCadastroUsuario(this);
	   FrmCadastroUsuario->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::FormShow(TObject *Sender)
{
	Position = poScreenCenter;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLogin::BtnRecuperarSenhaClick(TObject *Sender)
{
	// Verificar se o usuário foi informado
	if (EditUsuario->Text.Trim() == "")
	{
		LblMensagem->Caption = "Informe o usuário para recuperar!";
		EditUsuario->SetFocus();
		return;
	}

	// Criar a query principal para verificar se o usuário existe
	TFDQuery *query = new TFDQuery(NULL);
	try
	{
		query->Connection = DataModule1->FDConnection;
		query->SQL->Text = "SELECT id, usuario, email FROM usuarios WHERE usuario = :usuario";
		query->ParamByName("usuario")->AsString = EditUsuario->Text.Trim();
		query->Open();

		if (!query->Eof)
		{
			// Usuário encontrado
			String usuario = query->FieldByName("usuario")->AsString;
			String email = query->FieldByName("email")->AsString;

			// Gerar senha temporária
			String novaSenha = GerarSenhaTemporaria();

			// Atualizar a senha no banco de dados
			TFDQuery *updateQuery = new TFDQuery(NULL);
			try
			{
				updateQuery->Connection = DataModule1->FDConnection;
				updateQuery->SQL->Text =
					"UPDATE usuarios SET senha = :senha, senha_temporaria = 1, data_alteracao_senha = NOW() "
					"WHERE usuario = :usuario";
				updateQuery->ParamByName("senha")->AsString = novaSenha;
				updateQuery->ParamByName("usuario")->AsString = usuario;
				updateQuery->ExecSQL();

				// Mostrar formulário com senha copiável
				if (!FrmRecuperarSenha)
					FrmRecuperarSenha = new TFrmRecuperarSenha(this);

				FrmRecuperarSenha->Usuario = usuario;
				FrmRecuperarSenha->NovaSenha = novaSenha;

				// Mostrar informações adicionais se houver email
				if (email != "")
				{
					FrmRecuperarSenha->LblInstrucoes->Caption += "\n\nUma cópia foi enviada para: " + email;
				}

				FrmRecuperarSenha->ShowModal();

				LblMensagem->Caption = "Senha temporária gerada com sucesso!";
				EditSenha->Text = "";
				EditUsuario->SetFocus();
			}
			__finally
			{
				updateQuery->Free();
			}
		}
		else
		{
			LblMensagem->Caption = "Usuário não encontrado no sistema!";
			ShowMessage("O usuário informado não foi encontrado em nossa base de dados.\n\nVerifique se o nome de usuário está correto.");
		}
	}
	__finally
	{
		query->Free();
	}
}

//---------------------------------------------------------------------------

// Função para auxiliar na recuperação de senha
String TFrmLogin::GerarSenhaTemporaria()
{
	String senha = "";
    String caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int tamanho = 8; // Senha de 8 caracteres

    // Usar semente baseada no tempo atual
    Randomize();

    for(int i = 0; i < tamanho; i++)
    {
        int indice = Random(caracteres.Length());
        senha += caracteres[indice + 1]; // +1 porque String em C++ é 1-indexed
    }

    return senha;
}


//---------------------------------------------------------------------------

void __fastcall TFrmLogin::btnEntrarClick(TObject *Sender)
{
	String usuario = EditUsuario->Text.Trim();
	String senha = EditSenha->Text.Trim();

	if (usuario.IsEmpty() || senha.IsEmpty()) {
		LblMensagem->Caption = "Preencha todos os campos!";
		return;
	}

	TFDQuery *query = new TFDQuery(NULL);
	try {
		query->Connection = DataModule1->FDConnection;
		query->SQL->Text = "SELECT * FROM usuarios WHERE usuario = :usuario AND senha = :senha";
		query->ParamByName("usuario")->AsString = usuario;
		query->ParamByName("senha")->AsString = senha;
		query->Open();

		if (!query->Eof) {
			String nomeUsuario = query->FieldByName("usuario")->AsString;

			if(!FrmBoasVindas)
			   FrmBoasVindas = new TFrmBoasVindas(this);

			// Login válido
            FrmBoasVindas->NomeUsuario = nomeUsuario;
			FrmBoasVindas->Show();
//			FrmTaskMain = new TFrmTaskMain(this);
//			FrmTaskMain->Show();
			this->Hide(); // Oculta o login, mas mantém a aplicação rodando
		}
		else
		{
			LblMensagem->Caption = "Usuário ou senha inválidos!";
		}
	}
	__finally {
		query->Free();
	}
}
//---------------------------------------------------------------------------

