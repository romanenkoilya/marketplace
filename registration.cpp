//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "registration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Treg *reg;
//---------------------------------------------------------------------------
__fastcall Treg::Treg(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Treg::ButtonCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall Treg::FormCreate(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT name FROM roles";
    try
    {
        query->Open();
        if (!query->IsEmpty())
        {
            query->First();
            while (!query->Eof)
            {
                role->Items->Add(query->FieldByName("name")->AsString);
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
void __fastcall Treg::roleChange(TObject *Sender)
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "SELECT id FROM roles WHERE name = :role";
    query->ParamByName("role")->AsString = role->Text;
    try
    {
        query->Open();
        if (!query->Eof)
        {
            this->id = query->FieldByName("id")->AsInteger;
        }
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
    delete query;

    setMode();
}

void Treg::setMode()
{
    fullname->Clear();
    address->Clear();
    company->Clear();
    phone->Clear();

    switch(id)
    {
        case 1:
            fullname->Enabled = true;
            address->Enabled = true;
            company->Enabled = false;
            phone->Enabled = true;
            break;
        case 2:
            fullname->Enabled = false;
            address->Enabled = true;
            company->Enabled = true;
            phone->Enabled = true;
            break;
        case 3:
            fullname->Enabled = false;
            address->Enabled = true;
            company->Enabled = true;
            phone->Enabled = true;
            break;
        default:
            return;
    }
}

//---------------------------------------------------------------------------
void __fastcall Treg::ButtonRegisterClick(TObject *Sender)
{
    if (login->Text == "" || password->Text == "") {
        ShowMessage("Логин и пароль не могут быть пустыми");
        return;
    }

    switch(id)
    {
        case 1:
            if (fullname->Text == "" || address->Text == "" || phone->Text == "") {
                ShowMessage("Не все поля заполнены");
                return;
            }
            break;
        case 2:
        case 3:
            if (address->Text == "" || phone->Text == "" || company->Text == "") {
                ShowMessage("Не все поля заполнены");
                return;
            }
            break;
        default:
            ShowMessage("Не выбрана роль");
            return;
    }

    if (!insertNewUser())
    {
        ShowMessage("Не удалось зарегистрировать учетную запись");
        return;
    } else {
        ShowMessage("Учетная запись была успешно зарегистрирована");
    }

    this->Close();
}

bool Treg::insertNewUser()
{
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = auth->getDBConnect();
    query->SQL->Text = "insert into users (login, password, fullname, address, phone, company, role) values (:login, :password, :fullname, :address, :phone, :company, :role);";
    query->ParamByName("login")->AsString = login->Text;
    query->ParamByName("password")->AsString = password->Text;
    query->ParamByName("fullname")->AsString = fullname->Text;
    query->ParamByName("address")->AsString = address->Text;
    query->ParamByName("phone")->AsString = phone->Text;
    query->ParamByName("company")->AsString = company->Text;
    query->ParamByName("role")->AsInteger = this->id;

    try
    {
        query->ExecSQL();
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
        return false;
    }

    delete query;
    return true;
}

//---------------------------------------------------------------------------
