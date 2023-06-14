//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "product.h"
#include "login.h"
#include "vendor.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TproductF *productF;
//---------------------------------------------------------------------------
__fastcall TproductF::TproductF(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TproductF::setIDProduct(int id)
{
    this->id = id;
}

void TproductF::setIDVendor(int id)
{
    this->vendor = id;
}

void __fastcall TproductF::FormCreate(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT name FROM types";

    try
    {
        query->Open();

        if (!query->IsEmpty())
        {
            query->First();
            while (!query->Eof)
            {
                productType->Items->Add(query->FieldByName("name")->AsString);
                query->Next();
            }
        }
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TproductF::ButtonCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void TproductF::updateData()
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "update products set name = :name, type = (select id from types where name = :type), sum = :sum where id = :id";
    query->ParamByName("name")->AsString = productName->Text;
    query->ParamByName("type")->AsString = productType->Items->Strings[productType->ItemIndex];
    query->ParamByName("sum")->AsFloat = StrToFloat(productSum->Text);
    query->ParamByName("id")->AsInteger = this->id;

    try
    {
        query->ExecSQL();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    delete query;
}

void TproductF::insertData()
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "insert into products (name, type, sum, vendor) select :name, id, :sum, :vendor from types where types.name = :type";
    query->ParamByName("name")->AsString = productName->Text;
    query->ParamByName("type")->AsString = productType->Items->Strings[productType->ItemIndex];
    query->ParamByName("sum")->AsFloat = StrToFloat(productSum->Text);
    query->ParamByName("vendor")->AsInteger = this->vendor;

    try
    {
        query->ExecSQL();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    delete query;
}

void __fastcall TproductF::ButtonSaveClick(TObject *Sender)
{
    edit ? updateData() : insertData();
    this->Close();
}
//---------------------------------------------------------------------------

