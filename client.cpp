//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "client.h"
#include "order.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TclientForm *clientForm;
//---------------------------------------------------------------------------
__fastcall TclientForm::TclientForm(TComponent* Owner)
    : TForm(Owner)
{
}

void TclientForm::setIdClient(int id)
{
    this->id = id;
}
//---------------------------------------------------------------------------
void __fastcall TclientForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    TForm *ParentForm = static_cast<TForm*>(this->Owner);
    ParentForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TclientForm::FormShow(TObject *Sender)
{
    queryDataOrders = new TFDQuery(NULL);
    queryDataOrders->Connection = auth->getDBConnect();
    queryDataOrders->SQL->Text = "select o.id, u.company as provider, s.name as status, o.create_date, o.delivery_date from orders as o left join statuses as s on s.id = o.status left join users as u on u.id = o.provider where o.client = :id";
    DataSourceOrders->DataSet = queryDataOrders;
    queryDataOrders->ParamByName("id")->AsInteger = this->id;
    try
    {
        this->queryDataOrders->Open();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    if (orders->SelectedField)
    {
        ordersCellClick(NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TclientForm::ordersCellClick(TColumn *Column)
{
    int order = orders->DataSource->DataSet->Fields->FieldByName("id")->AsInteger;

    provider->Text = orders->DataSource->DataSet->Fields->FieldByName("provider")->AsString;

    queryDataOrder = new TFDQuery(NULL);
    queryDataOrder->Connection = auth->getDBConnect();
    queryDataOrder->SQL->Text = "select p.name as product, t.name as type, p.sum from basket as b left join products as p on p.id = b.product left join types as t on t.id = p.type where b.\"order\" = :id";
    DataSourceOrder->DataSet = queryDataOrder;
    queryDataOrder->ParamByName("id")->AsInteger = order;

    try
    {
        queryDataOrder->Open();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    float sum = 0;

    try
    {
        queryDataOrder->DisableControls();
        while (!queryDataOrder->Eof)
        {
            sum += queryDataOrder->FieldByName("sum")->AsFloat;
            queryDataOrder->Next();
        }
        this->sum->Text = FloatToStr(sum);
    }
    __finally
    {
        queryDataOrder->EnableControls();
    }
}
//---------------------------------------------------------------------------

void __fastcall TclientForm::ButtonOrderClick(TObject *Sender)
{
    TorderForm *form = new TorderForm(this);
    form->setIdClient(this->id);
    form->ShowModal();
    orders->DataSource->DataSet->Refresh();
    delete form;
}
//---------------------------------------------------------------------------

