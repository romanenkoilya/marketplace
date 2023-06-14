object orderForm: TorderForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1099#1081' '#1079#1072#1082#1072#1079
  ClientHeight = 557
  ClientWidth = 1443
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object LabelTypes: TLabel
    Left = 8
    Top = 5
    Width = 65
    Height = 37
    Caption = #1058#1080#1087#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelProducts: TLabel
    Left = 327
    Top = 5
    Width = 122
    Height = 37
    Caption = #1055#1088#1086#1076#1091#1082#1090#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelBasket: TLabel
    Left = 880
    Top = 5
    Width = 106
    Height = 37
    Caption = #1050#1086#1088#1079#1080#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelSum: TLabel
    Left = 1200
    Top = 384
    Width = 81
    Height = 15
    Caption = #1054#1073#1097#1072#1103' '#1089#1091#1084#1084#1072':'
  end
  object LabelProvider: TLabel
    Left = 902
    Top = 384
    Width = 66
    Height = 15
    Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
  end
  object types: TDBGrid
    Left = 8
    Top = 48
    Width = 305
    Height = 497
    DataSource = DataSourceTypes
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = typesCellClick
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'name'
        Title.Caption = #1058#1080#1087' '#1087#1088#1086#1076#1091#1082#1090#1072
        Width = 262
        Visible = True
      end>
  end
  object products: TDBGrid
    Left = 327
    Top = 48
    Width = 538
    Height = 497
    DataSource = DataSourceProducts
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnDblClick = productsDblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'name'
        Title.Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1086#1076#1091#1082#1090#1072
        Width = 270
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'vendor'
        Title.Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
        Width = 144
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sum'
        Title.Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
        Width = 81
        Visible = True
      end>
  end
  object provider: TComboBox
    Left = 974
    Top = 381
    Width = 220
    Height = 23
    Style = csDropDownList
    TabOrder = 2
    TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
  end
  object sum: TEdit
    Left = 1287
    Top = 381
    Width = 130
    Height = 23
    ReadOnly = True
    TabOrder = 3
  end
  object ButtonCreate: TButton
    Left = 1185
    Top = 512
    Width = 108
    Height = 33
    Caption = #1054#1092#1086#1088#1084#1080#1090#1100' '#1079#1072#1082#1072#1079
    TabOrder = 4
    OnClick = ButtonCreateClick
  end
  object ButtonCancel: TButton
    Left = 1309
    Top = 512
    Width = 108
    Height = 33
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 5
    OnClick = ButtonCancelClick
  end
  object ButtonDelete: TButton
    Left = 1261
    Top = 335
    Width = 156
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1080#1079' '#1082#1086#1088#1079#1080#1085#1099
    TabOrder = 6
    OnClick = ButtonDeleteClick
  end
  object ButtonAdd: TButton
    Left = 880
    Top = 335
    Width = 156
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1082#1086#1088#1079#1080#1085#1091
    TabOrder = 7
    OnClick = ButtonAddClick
  end
  object search: TEdit
    Left = 464
    Top = 14
    Width = 401
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    TextHint = #1055#1086#1080#1089#1082' '#1087#1088#1086#1076#1091#1082#1090#1072' '#1087#1086' '#1085#1072#1079#1074#1072#1085#1080#1102
    OnChange = searchChange
  end
  object StringGrid: TStringGrid
    Left = 880
    Top = 48
    Width = 537
    Height = 281
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect, goFixedRowDefAlign]
    TabOrder = 9
    OnDblClick = StringGridDblClick
  end
  object DataSourceTypes: TDataSource
    Left = 912
    Top = 488
  end
  object DataSourceProducts: TDataSource
    Left = 1024
    Top = 488
  end
end
