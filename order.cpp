//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "order.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TorderForm *orderForm;
//---------------------------------------------------------------------------
__fastcall TorderForm::TorderForm(TComponent* Owner)
    : TForm(Owner)
{
}

void TorderForm::setIdClient(int id)
{
    this->id = id;
}
//---------------------------------------------------------------------------
void __fastcall TorderForm::ButtonCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TorderForm::FormShow(TObject *Sender)
{
    createBasket();

    queryDataTypes = new TFDQuery(NULL);
    queryDataTypes->Connection = auth->getDBConnect();
    queryDataTypes->SQL->Text = "SELECT id, name FROM types";
    DataSourceTypes->DataSet = queryDataTypes;
    try
    {
        this->queryDataTypes->Open();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    if (types->SelectedField)
    {
        getProducts();
    }

    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT company FROM users as u LEFT JOIN roles as r on r.id = u.role WHERE r.name = :name";
    query->ParamByName("name")->AsString = "Поставщик";

    try
    {
        query->Open();

        if (!query->IsEmpty())
        {
            query->First();
            while (!query->Eof)
            {
                provider->Items->Add(query->FieldByName("company")->AsString);
                query->Next();
            }
        }
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
}

void TorderForm::getProducts(String name)
{
    if (queryDataProducts) {
        delete queryDataProducts;
    }

    int type = types->DataSource->DataSet->Fields->FieldByName("id")->AsInteger;

    queryDataProducts = new TFDQuery(NULL);
    queryDataProducts->Connection = auth->getDBConnect();
    queryDataProducts->SQL->Text = "select p.id, p.name, u.company as vendor, p.sum from products as p left join users as u on p.vendor = u.id where p.type = :id";
    if (name != "") {
        queryDataProducts->SQL->Text += " and p.name LIKE :name";
        queryDataProducts->ParamByName("name")->AsString = "%" + name + "%";
    }
    queryDataProducts->ParamByName("id")->AsInteger = type;
    DataSourceProducts->DataSet = queryDataProducts;
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
void __fastcall TorderForm::typesCellClick(TColumn *Column)
{
    getProducts();
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::searchChange(TObject *Sender)
{
    getProducts(search->Text);
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::ButtonAddClick(TObject *Sender)
{
    TFields *fields = products->DataSource->DataSet->Fields;

    if (fields->FieldByName("id")->IsNull)
        return;

    addToBasket({
        fields->FieldByName("id")->AsInteger,
        fields->FieldByName("name")->AsString,
        types->DataSource->DataSet->Fields->FieldByName("name")->AsString,
        fields->FieldByName("vendor")->AsString,
        fields->FieldByName("sum")->AsFloat
    });
}

void TorderForm::addToBasket(BasketRow row)
{
    StringGrid->RowCount++;
    StringGrid->Cells[0][StringGrid->RowCount-1] = row.id;
    StringGrid->Cells[1][StringGrid->RowCount-1] = row.name;
    StringGrid->Cells[2][StringGrid->RowCount-1] = row.type;
    StringGrid->Cells[3][StringGrid->RowCount-1] = row.vendor;
    StringGrid->Cells[4][StringGrid->RowCount-1] = row.sum;
    calcWindthCellsBasket();

    sum->Text = getSum();
}

String TorderForm::getSum()
{
    float sum = 0.0;
    for (int i = 1; i < StringGrid->RowCount; i++) {
        sum += StrToFloat(StringGrid->Cells[4][i]);
    }
    return FloatToStr(sum);
}

void TorderForm::delFromBasket()
{
    if (StringGrid->Selection.Top > 0)
    {
        deleteRowFromStringGrid(StringGrid->Selection.Top);
        calcWindthCellsBasket();
        sum->Text = getSum();
    }
}

void TorderForm::deleteRowFromStringGrid(int id)
{
    int count = StringGrid->RowCount;
    int row = StringGrid->Row;

    if ( count - StringGrid->FixedRows <= 1 ) return;

    for (; id < count; id++)
    {
        StringGrid->Rows[id] = StringGrid->Rows[id+1];
    }

    StringGrid->RowCount--;
}

void TorderForm::createBasket()
{
    StringGrid->Cells[0][0] = "id";
    StringGrid->Cells[1][0] = "Наименование продукта";
    StringGrid->Cells[2][0] = "Тип";
    StringGrid->Cells[3][0] = "Производитель";
    StringGrid->Cells[4][0] = "Стоимость";

    StringGrid->ColWidths[0] = 0;

    calcWindthCellsBasket();
}

void TorderForm::calcWindthCellsBasket()
{
    for (int col = 1; col < StringGrid->ColCount; col++)
    {
        int maxWidth = 0;
        for (int row = 0; row < StringGrid->RowCount; row++)
        {
            int cellWidth = StringGrid->Canvas->TextWidth(StringGrid->Cells[col][row]);
            if (cellWidth > maxWidth)
            {
                maxWidth = cellWidth;
            }
        }

        StringGrid->ColWidths[col] = maxWidth + 10;
    }
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::ButtonDeleteClick(TObject *Sender)
{
    delFromBasket();
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::StringGridDblClick(TObject *Sender)
{
    delFromBasket();
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::productsDblClick(TObject *Sender)
{
    ButtonAddClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TorderForm::ButtonCreateClick(TObject *Sender)
{
    if (StringGrid->RowCount <= 1) {
        ShowMessage("Вы не выбрали ни один товар");
        return;
    }

    if (provider->Text == "") {
        ShowMessage("Не был указан поставщик");
        return;
    }
    // Создать заказ
    int idOrder = addNewOrder();
    // Добавить корзину в БД
    if (idOrder && addNewBasket(idOrder))
        ShowMessage("Заказ был успешно оформлен");
    else
        ShowMessage("Заказ не был оформлен");
    
    // Закрыть форму
    this->Close();
}

int TorderForm::addNewOrder()
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "insert into orders (client, provider, status, create_date) select :client as client, id as provider, 1 as status, datetime() as create_date from users where company = :provider RETURNING id;";
    query->ParamByName("client")->AsInteger = this->id;
    query->ParamByName("provider")->AsString = provider->Text;

    int idOrder = 0;

    try
    {
        query->Open();
        idOrder = query->FieldByName("id")->AsInteger;
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }

    delete query;

    return idOrder;
}

bool TorderForm::addNewBasket(int idOrder)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "insert into basket (\"order\", product) values (:order, :product);";

    for (int row = 1; row < StringGrid->RowCount; row++)
    {
        query->ParamByName("order")->AsInteger = idOrder;
        query->ParamByName("product")->AsInteger = StrToInt(StringGrid->Cells[0][row]);

        try
        {
            query->ExecSQL();
        }
        catch (EDatabaseError& E)
        {
            ShowMessage("Ошибка при выполнении запроса: " + E.Message);
            return false;
        }
    }

    delete query;

    return true;
}
//---------------------------------------------------------------------------


