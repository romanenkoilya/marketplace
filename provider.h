//---------------------------------------------------------------------------

#ifndef providerH
#define providerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "login.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TproviderForm : public TForm
{
__published:    // IDE-managed Components
    TDBGrid *orders;
    TDataSource *DataSourceOrders;
    TLabel *LabelTitle;
    TEdit *client;
    TLabel *LabelClient;
    TEdit *address;
    TLabel *LabelAddress;
    TLabel *LabelPhone;
    TEdit *phone;
    TLabel *LabelCreateDate;
    TEdit *createDate;
    TLabel *LabelDeliveryDate;
    TComboBox *status;
    TLabel *LabelStatus;
    TDBGrid *details;
    TLabel *LabelSum;
    TEdit *sum;
    TDataSource *DataSourceOrder;
    TDatePicker *date;
    TTimePicker *time;
    TButton *ButtonUpdate;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ordersCellClick(TColumn *Column);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButtonUpdateClick(TObject *Sender);
private:    // User declarations
    int id;
    TFDQuery *queryDataOrders;
    TFDQuery *queryDataOrder;
public:        // User declarations
    __fastcall TproviderForm(TComponent* Owner);
    void setIdClient(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TproviderForm *providerForm;
//---------------------------------------------------------------------------
#endif
