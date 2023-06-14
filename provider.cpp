//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "provider.h"
#include <System.DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TproviderForm *providerForm;
//---------------------------------------------------------------------------
__fastcall TproviderForm::TproviderForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TproviderForm::setIdClient(int id)
{
    this->id = id;
}

void __fastcall TproviderForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    TForm *ParentForm = static_cast<TForm*>(this->Owner);
    ParentForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TproviderForm::FormShow(TObject *Sender)
{
    queryDataOrders = new TFDQuery(NULL);
    queryDataOrders->Connection = auth->getDBConnect();
    queryDataOrders->SQL->Text = "select o.id, u.fullname as client, s.name as status, strftime('%Y.%m.%d %H:%M', o.create_date) as create_date, strftime('%Y.%m.%d %H:%M', o.delivery_date) as delivery_date, u.address, u.phone from orders as o left join statuses as s on s.id = o.status left join users as u on u.id = o.client where o.provider = :id order by s.id asc";
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

void __fastcall TproviderForm::ordersCellClick(TColumn *Column)
{
    auto co = orders->DataSource->DataSet->Fields;

    int order = co->FieldByName("id")->AsInteger;

    queryDataOrder = new TFDQuery(NULL);
    queryDataOrder->Connection = auth->getDBConnect();
    queryDataOrder->SQL->Text = "select    p.name as product, u.company as vendor, p.sum from basket as b left join products as p on p.id = b.product left join users as u on u.id = p.vendor where b.\"order\" = :id";
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

    client->Text = co->FieldByName("client")->AsString;
    createDate->Text = co->FieldByName("create_date")->AsString;
    phone->Text = co->FieldByName("phone")->AsString;
    address->Text = co->FieldByName("address")->AsString;
    status->ItemIndex = status->Items->IndexOf(co->FieldByName("status")->AsString);

    // Установка времени
    if (!co->FieldByName("delivery_date")->IsNull) {

        TFormatSettings formatSettings = TFormatSettings::Create();
        formatSettings.ShortDateFormat = "yyyy.mm.dd";
        formatSettings.LongTimeFormat = "hh:nn";
        formatSettings.DateSeparator = '.';
        formatSettings.TimeSeparator = ':';

        TDateTime deliveryDate = StrToDateTime(co->FieldByName("delivery_date")->AsString, formatSettings);

        date->Date = DateOf(deliveryDate);
        time->Time = TimeOf(deliveryDate);
    } else {
        date->Date = DateOf(Now());
        time->Time = TimeOf(Now());
    }
}
//---------------------------------------------------------------------------

void __fastcall TproviderForm::FormCreate(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT name FROM statuses";
    try
    {
        query->Open();
        if (!query->IsEmpty())
        {
            query->First();
            while (!query->Eof)
            {
                status->Items->Add(query->FieldByName("name")->AsString);
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

void __fastcall TproviderForm::ButtonUpdateClick(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "update orders set status = (select id from statuses where name = :status), delivery_date = :date where id = :id";
    query->ParamByName("status")->AsString = status->Items->Strings[status->ItemIndex];
    query->ParamByName("date")->AsDateTime = TDateTime(YearOf(date->Date), MonthOf(date->Date), DayOf(date->Date), HourOf(time->Time), MinuteOf(time->Time), 0, 0);
    query->ParamByName("id")->AsInteger = orders->DataSource->DataSet->Fields->FieldByName("id")->AsInteger;
    try
    {
        query->ExecSQL();
        ShowMessage("Статус был обновлен");
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
    delete query;

    orders->DataSource->DataSet->Refresh();
}
//---------------------------------------------------------------------------

