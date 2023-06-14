//---------------------------------------------------------------------------

#ifndef orderH
#define orderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "login.h"
#include <Datasnap.DBClient.hpp>
//---------------------------------------------------------------------------
class TorderForm : public TForm
{
__published:    // IDE-managed Components
    TDBGrid *types;
    TDBGrid *products;
    TComboBox *provider;
    TEdit *sum;
    TLabel *LabelTypes;
    TLabel *LabelProducts;
    TLabel *LabelBasket;
    TLabel *LabelSum;
    TLabel *LabelProvider;
    TButton *ButtonCreate;
    TButton *ButtonCancel;
    TButton *ButtonDelete;
    TButton *ButtonAdd;
    TDataSource *DataSourceTypes;
    TDataSource *DataSourceProducts;
    TEdit *search;
    TStringGrid *StringGrid;
    void __fastcall ButtonCancelClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall typesCellClick(TColumn *Column);
    void __fastcall searchChange(TObject *Sender);
    void __fastcall ButtonAddClick(TObject *Sender);
    void __fastcall ButtonDeleteClick(TObject *Sender);
    void __fastcall StringGridDblClick(TObject *Sender);
    void __fastcall productsDblClick(TObject *Sender);
    void __fastcall ButtonCreateClick(TObject *Sender);
private:    // User declarations
    int id;
    TFDQuery *queryDataTypes;
    TFDQuery *queryDataProducts;
    void calcWindthCellsBasket();
    void createBasket();
    void addToBasket(BasketRow row);
    void delFromBasket();
    void deleteRowFromStringGrid(int id);
    String getSum();

    int addNewOrder();
    bool addNewBasket(int idOrder);

//    String getSum = [&]() {
//        float sum = 0.0;
//        for (int i = 1; i < StringGrid->RowCount; i++) {
//            sum += StrToFloat(StringGrid->Cells[4][i]);
//        }
//        return FloatToStr(sum);
//    };
public:        // User declarations
    __fastcall TorderForm(TComponent* Owner);
    void getProducts(String name = "");
    void setIdClient(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TorderForm *orderForm;
//---------------------------------------------------------------------------
#endif
