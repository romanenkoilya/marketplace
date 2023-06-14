//---------------------------------------------------------------------------

#ifndef productH
#define productH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "share.hpp"
//---------------------------------------------------------------------------
class TproductF : public TForm
{
__published:    // IDE-managed Components
    TButton *ButtonSave;
    TButton *ButtonCancel;
    TEdit *productName;
    TComboBox *productType;
    TEdit *productSum;
    TLabel *LabelName;
    TLabel *LabelType;
    TLabel *LabelSum;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButtonCancelClick(TObject *Sender);
    void __fastcall ButtonSaveClick(TObject *Sender);
private:    // User declarations
    int id;
    int vendor;
    void updateData();
    void insertData();
public:        // User declarations
    bool edit = false;
    __fastcall TproductF(TComponent* Owner);
    void setIDProduct(int id);
    void setIDVendor(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TproductF *productF;
//---------------------------------------------------------------------------
#endif
