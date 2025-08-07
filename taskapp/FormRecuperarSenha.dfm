object FrmRecuperarSenha: TFrmRecuperarSenha
  Left = 0
  Top = 0
  Caption = 'Recuperação de Senha'
  ClientHeight = 300
  ClientWidth = 450
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LblTitulo: TLabel
    Left = 24
    Top = 24
    Width = 402
    Height = 25
    Caption = 'Senha Temporária Gerada com Sucesso!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 24
    Top = 55
    Width = 402
    Height = 2
  end
  object LblUsuario: TLabel
    Left = 24
    Top = 80
    Width = 402
    Height = 17
    Caption = 'Usuário: admin'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LblNovaSenha: TLabel
    Left = 24
    Top = 120
    Width = 402
    Height = 17
    Caption = 'Nova Senha Temporária:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LblInstrucoes: TLabel
    Left = 24
    Top = 240
    Width = 402
    Height = 45
    Caption = 
      'IMPORTANTE:'#13#10'• Esta é uma senha temporária'#13#10'• Altere sua senha ' +
      'após fazer login'#13#10'• A senha temporária expira em 24 horas'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditNovaSenha: TEdit
    Left = 24
    Top = 143
    Width = 402
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    Text = 'Temp1234'
  end
  object BtnCopiarSenha: TButton
    Left = 24
    Top = 190
    Width = 195
    Height = 35
    Caption = 'Copiar Senha'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = BtnCopiarSenhaClick
  end
  object BtnFechar: TButton
    Left = 231
    Top = 190
    Width = 195
    Height = 35
    Caption = 'Fechar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BtnFecharClick
  end
end
