object DataModule1: TDataModule1
  Height = 480
  Width = 640
  object FDConnection: TFDConnection
    Params.Strings = (
      'Server=172.26.37.69'
      'Database=taskapp'
      'User_Name=taskuser'
      'Password=taskpass'
      'UseSSL=0'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 48
    Top = 40
  end
  object FDQuery: TFDQuery
    Connection = FDConnection
    Left = 48
    Top = 120
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\EduDevWin\Downloads\libmysql.dll\LIBMYSQL.DLL'
    Left = 48
    Top = 192
  end
end
