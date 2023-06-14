//---------------------------------------------------------------------------

#ifndef vendorH
#define vendorH
#include <Data.DB.hpp>
#include <System.Classes.hpp>
#include "share.hpp"
#include <Vcl.Controls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>
#include "login.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TvendorForm : public TForm
{
__published:    // IDE-managed Components
    TDBGrid *DBGrid;
    TDataSource *DataSource;
    TButton *ButtonAdd;
    TButton *ButtonEdit;
    TButton *ButtonDel;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall DBGridDblClick(TObject *Sender);
    void __fastcall ButtonEditClick(TObject *Sender);
    void __fastcall ButtonAddClick(TObject *Sender);
    void __fastcall ButtonDelClick(TObject *Sender);
private:    // User declarations
    int id;
    TFDQuery *queryDataProducts;
    Product getDataProduct(int id);
public:        // User declarations
    __fastcall TvendorForm(TComponent* Owner);
    void setIdVendor(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TvendorForm *vendorForm;
//---------------------------------------------------------------------------
#endif
