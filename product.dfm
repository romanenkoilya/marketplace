object productF: TproductF
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1099#1081' '#1087#1088#1086#1076#1091#1082#1090
  ClientHeight = 168
  ClientWidth = 452
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object LabelName: TLabel
    Left = 12
    Top = 19
    Width = 86
    Height = 15
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object LabelType: TLabel
    Left = 75
    Top = 48
    Width = 23
    Height = 15
    Caption = #1058#1080#1087':'
  end
  object LabelSum: TLabel
    Left = 35
    Top = 77
    Width = 63
    Height = 15
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100':'
  end
  object ButtonSave: TButton
    Left = 256
    Top = 120
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 0
    OnClick = ButtonSaveClick
  end
  object ButtonCancel: TButton
    Left = 350
    Top = 120
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = ButtonCancelClick
  end
  object productName: TEdit
    Left = 104
    Top = 16
    Width = 321
    Height = 23
    TabOrder = 2
    TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1076#1091#1082#1090#1072
  end
  object productType: TComboBox
    Left = 104
    Top = 45
    Width = 321
    Height = 23
    Style = csDropDownList
    TabOrder = 3
    TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1080#1087' '#1087#1088#1086#1076#1091#1082#1090#1072
  end
  object productSum: TEdit
    Left = 104
    Top = 74
    Width = 121
    Height = 23
    TabOrder = 4
    TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1089#1090#1086#1080#1084#1086#1089#1090#1100
  end
end
