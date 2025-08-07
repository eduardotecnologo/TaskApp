object FrmCadastroUsuario: TFrmCadastroUsuario
  Left = 0
  Top = 0
  Caption = 'Cadastro de Usu'#225'rio'
  ClientHeight = 441
  ClientWidth = 529
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 128
    Top = 24
    Width = 240
    Height = 25
    Caption = 'Novo por aqui? Cadastre-se!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 128
    Top = 80
    Width = 42
    Height = 15
    Caption = 'Usu'#225'rio'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 128
    Top = 136
    Width = 34
    Height = 15
    Caption = 'E-mail'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 128
    Top = 192
    Width = 36
    Height = 15
    Caption = 'Senha'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Senha'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 128
    Top = 248
    Width = 96
    Height = 15
    Caption = 'Confirmar Senha'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Senha'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object EdtNomeUsuario: TEdit
    Left = 128
    Top = 96
    Width = 240
    Height = 23
    TabOrder = 0
  end
  object EdtEmail: TEdit
    Left = 128
    Top = 152
    Width = 240
    Height = 23
    TabOrder = 1
  end
  object EdtSenha: TEdit
    Left = 128
    Top = 208
    Width = 240
    Height = 23
    TabOrder = 2
  end
  object BtnSalvarCadastro: TBitBtn
    Left = 128
    Top = 320
    Width = 240
    Height = 25
    Caption = 'Salvar Cadastro'
    TabOrder = 3
    OnClick = BtnSalvarCadastroClick
  end
  object BtnCancelar: TBitBtn
    Left = 128
    Top = 360
    Width = 240
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 4
  end
  object EdtConfirmarSenha: TEdit
    Left = 128
    Top = 264
    Width = 240
    Height = 23
    TabOrder = 5
  end
end
