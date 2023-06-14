object providerForm: TproviderForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 484
  ClientWidth = 1227
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object LabelTitle: TLabel
    Left = 672
    Top = 8
    Width = 187
    Height = 40
    Caption = #1044#1077#1090#1072#1083#1080' '#1079#1072#1082#1072#1079#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 40
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelClient: TLabel
    Left = 672
    Top = 64
    Width = 42
    Height = 15
    Caption = #1050#1083#1080#1077#1085#1090':'
  end
  object LabelAddress: TLabel
    Left = 672
    Top = 93
    Width = 88
    Height = 15
    Caption = #1040#1076#1088#1077#1089' '#1076#1086#1089#1090#1072#1074#1082#1080':'
  end
  object LabelPhone: TLabel
    Left = 985
    Top = 64
    Width = 97
    Height = 15
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072':'
  end
  object LabelCreateDate: TLabel
    Left = 695
    Top = 122
    Width = 65
    Height = 15
    Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072':'
  end
  object LabelDeliveryDate: TLabel
    Left = 688
    Top = 167
    Width = 116
    Height = 23
    Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelStatus: TLabel
    Left = 750
    Top = 196
    Width = 54
    Height = 23
    Caption = #1057#1090#1072#1090#1091#1089':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelSum: TLabel
    Left = 893
    Top = 122
    Width = 93
    Height = 15
    Caption = #1062#1077#1085#1085#1086#1089#1090#1100' '#1079#1072#1082#1072#1079#1072':'
  end
  object orders: TDBGrid
    Left = 8
    Top = 8
    Width = 649
    Height = 466
    DataSource = DataSourceOrders
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
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
        Width = 86
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'client'
        Title.Caption = #1050#1083#1080#1077#1085#1090
        Width = 208
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'status'
        Title.Caption = #1057#1090#1072#1090#1091#1089
        Width = 75
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'create_date'
        Title.Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072
        Width = 113
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'delivery_date'
        Title.Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'address'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'phone'
        Visible = False
      end>
  end
  object client: TEdit
    Left = 720
    Top = 61
    Width = 251
    Height = 23
    ReadOnly = True
    TabOrder = 1
  end
  object address: TEdit
    Left = 766
    Top = 90
    Width = 443
    Height = 23
    ReadOnly = True
    TabOrder = 2
  end
  object phone: TEdit
    Left = 1088
    Top = 61
    Width = 121
    Height = 23
    ReadOnly = True
    TabOrder = 3
  end
  object createDate: TEdit
    Left = 766
    Top = 119
    Width = 121
    Height = 23
    ReadOnly = True
    TabOrder = 4
  end
  object status: TComboBox
    Left = 810
    Top = 198
    Width = 169
    Height = 23
    Style = csDropDownList
    TabOrder = 5
  end
  object details: TDBGrid
    Left = 672
    Top = 240
    Width = 537
    Height = 234
    DataSource = DataSourceOrder
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 6
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'product'
        Title.Caption = #1058#1086#1074#1072#1088
        Width = 245
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'vendor'
        Title.Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
        Width = 162
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sum'
        Title.Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
        Width = 78
        Visible = True
      end>
  end
  object sum: TEdit
    Left = 992
    Top = 119
    Width = 121
    Height = 23
    ReadOnly = True
    TabOrder = 7
  end
  object date: TDatePicker
    Left = 810
    Top = 167
    Width = 102
    Height = 25
    Date = 45090.000000000000000000
    DateFormat = 'dd/mm/yyyy'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    TabOrder = 8
  end
  object time: TTimePicker
    Left = 918
    Top = 167
    Width = 61
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    TabOrder = 9
    Time = 45090.955175798610000000
    TimeFormat = 'h:nn'
  end
  object ButtonUpdate: TButton
    Left = 1038
    Top = 176
    Width = 131
    Height = 33
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1079#1072#1082#1072#1079
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonUpdateClick
  end
  object DataSourceOrders: TDataSource
    Left = 920
    Top = 8
  end
  object DataSourceOrder: TDataSource
    Left = 1032
    Top = 8
  end
end
