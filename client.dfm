object clientForm: TclientForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 631
  ClientWidth = 1043
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object title: TLabel
    Left = 472
    Top = 8
    Width = 295
    Height = 40
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1079#1072#1082#1072#1079#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 40
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelSum: TLabel
    Left = 810
    Top = 349
    Width = 81
    Height = 15
    Caption = #1054#1073#1097#1072#1103' '#1089#1091#1084#1084#1072':'
  end
  object LabelProvider: TLabel
    Left = 698
    Top = 320
    Width = 66
    Height = 15
    Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
  end
  object orders: TDBGrid
    Left = 8
    Top = 8
    Width = 441
    Height = 616
    DataSource = DataSourceOrders
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = ordersCellClick
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Title.Caption = #1053#1086#1084#1077#1088' '#1079#1072#1082#1072#1079#1072
        Width = 89
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'provider'
        Title.Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'status'
        Title.Caption = #1057#1090#1072#1090#1091#1089
        Width = 114
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'create_date'
        Title.Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072
        Width = 102
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'delivery_date'
        Title.Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080
        Width = 91
        Visible = True
      end>
  end
  object details: TDBGrid
    Left = 472
    Top = 54
    Width = 546
    Height = 257
    DataSource = DataSourceOrder
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'product'
        Title.Caption = #1055#1088#1086#1076#1091#1082#1090
        Width = 245
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'type'
        Title.Caption = #1058#1080#1087
        Width = 172
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sum'
        Title.Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
        Width = 82
        Visible = True
      end>
  end
  object sum: TEdit
    Left = 897
    Top = 346
    Width = 121
    Height = 23
    ReadOnly = True
    TabOrder = 2
  end
  object ButtonOrder: TButton
    Left = 472
    Top = 342
    Width = 112
    Height = 32
    Caption = #1053#1086#1074#1099#1081' '#1079#1072#1082#1072#1079
    TabOrder = 3
    OnClick = ButtonOrderClick
  end
  object provider: TEdit
    Left = 770
    Top = 317
    Width = 248
    Height = 23
    ReadOnly = True
    TabOrder = 4
  end
  object DataSourceOrders: TDataSource
    Left = 536
    Top = 432
  end
  object DataSourceOrder: TDataSource
    Left = 536
    Top = 504
  end
end
