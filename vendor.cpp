//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "vendor.h"
#include "product.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TvendorForm *vendorForm;
//---------------------------------------------------------------------------
__fastcall TvendorForm::TvendorForm(TComponent* Owner)
    : TForm(Owner)
{
}
// Установка вендора, который вошёл в систему
void TvendorForm::setIdVendor(int id)
{
    this->id = id;
}
//---------------------------------------------------------------------------
void __fastcall TvendorForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    TForm *ParentForm = static_cast<TForm*>(this->Owner);
    ParentForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TvendorForm::FormShow(TObject *Sender)
{
    queryDataProducts = new TFDQuery(NULL);
    queryDataProducts->Connection = auth->getDBConnect();
    queryDataProducts->SQL->Text = "SELECT p.id, p.name, t.name as type, p.sum FROM products as p LEFT JOIN types as t on t.id = p.type WHERE p.vendor = :vendor";
    DataSource->DataSet = queryDataProducts;
    queryDataProducts->ParamByName("vendor")->AsInteger = this->id;
    try
    {
        this->queryDataProducts->Open();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
}
//---------------------------------------------------------------------------
Product TvendorForm::getDataProduct(int id)
{
    Product data;
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT p.id, p.name, t.name as type, p.sum, p.vendor FROM products as p LEFT JOIN types as t on t.id = p.type WHERE p.id = :id";
    query->ParamByName("id")->AsInteger = id;
    try
    {
        query->Open();
        data.id = query->FieldByName("id")->AsInteger;
        data.name = query->FieldByName("name")->AsString;
        data.typeName = query->FieldByName("type")->AsString;
        data.sum = query->FieldByName("sum")->AsFloat;
        data.vendor = query->FieldByName("vendor")->AsInteger;
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
    return data;
}
void __fastcall TvendorForm::DBGridDblClick(TObject *Sender)
{
    int idProduct = DBGrid->DataSource->DataSet->Fields->FieldByName("id")->AsInteger;
    Product p = getDataProduct(idProduct);
    if (p.id) {
        TproductF *form = new TproductF(this);
        form->setIDProduct(idProduct);
        form->productName->Text = p.name;
        form->productType->ItemIndex = form->productType->Items->IndexOf(p.typeName);
        form->productSum->Text = p.sum;
        form->Caption = p.name;
        form->edit = true;
        form->ShowModal();
        DBGrid->DataSource->DataSet->Refresh();
        delete form;
    }
}
//---------------------------------------------------------------------------

void __fastcall TvendorForm::ButtonEditClick(TObject *Sender)
{
    DBGridDblClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TvendorForm::ButtonAddClick(TObject *Sender)
{
    TproductF *form = new TproductF(this);
    form->setIDVendor(id);
    form->ShowModal();
    DBGrid->DataSource->DataSet->Refresh();
    delete form;
}
//---------------------------------------------------------------------------

void __fastcall TvendorForm::ButtonDelClick(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "delete from products where id = :id";
    query->ParamByName("id")->AsInteger = DBGrid->DataSource->DataSet->Fields->FieldByName("id")->AsInteger;
    try
    {
        query->ExecSQL();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
    delete query;

    DBGrid->DataSource->DataSet->Refresh();
}
//---------------------------------------------------------------------------

