//---------------------------------------------------------------------------

#ifndef clientH
#define clientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "login.h"
//---------------------------------------------------------------------------
class TclientForm : public TForm
{
__published:    // IDE-managed Components
    TDBGrid *orders;
    TLabel *title;
    TDBGrid *details;
    TDataSource *DataSourceOrders;
    TEdit *sum;
    TLabel *LabelSum;
    TButton *ButtonOrder;
    TEdit *provider;
    TLabel *LabelProvider;
    TDataSource *DataSourceOrder;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ordersCellClick(TColumn *Column);
    void __fastcall ButtonOrderClick(TObject *Sender);
private:    // User declarations
    int id;
    TFDQuery *queryDataOrders;
    TFDQuery *queryDataOrder;
public:        // User declarations
    __fastcall TclientForm(TComponent* Owner);
    void setIdClient(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TclientForm *clientForm;
//---------------------------------------------------------------------------
#endif
