//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "login.h"
#include "vendor.h"
#include "client.h"
#include "provider.h"
#include "registration.h"
#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tauth *auth;
//---------------------------------------------------------------------------
__fastcall Tauth::Tauth(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tauth::registrationMouseEnter(TObject *Sender)
{
    registration->Font->Style = registration->Font->Style << fsUnderline;
}
void __fastcall Tauth::registrationMouseLeave(TObject *Sender)
{
    registration->Font->Style = registration->Font->Style >> fsUnderline;
}
//---------------------------------------------------------------------------
// Соединение с БД при создании формы
void __fastcall Tauth::connetToDatabase()
{
    this->dbConnect = new TFDConnection(NULL);
    this->dbConnect->DriverName = "SQLite";
    this->dbConnect->Params->Database = "marketplace.db";
    // Для чтения широких символов (Юникод)
    this->dbConnect->FormatOptions->MapRules->Add(dtWideMemo, dtWideString);
    this->dbConnect->LoginPrompt = false;
    try
    {
        this->dbConnect->Connected = true;
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Проблема с подключением к marketplace.db " + E.Message);
    }
}
TFDConnection *Tauth::getDBConnect()
{
    return this->dbConnect;
}
void __fastcall Tauth::FormCreate(TObject *Sender)
{
    // Подключение к БД при создании формы
    connetToDatabase();
    // Открыть форму по центру экрана
    auth->Left = (Screen->Width - auth->Width) / 2;
    auth->Top = (Screen->Height - auth->Height) / 2;
}
//---------------------------------------------------------------------------
void __fastcall Tauth::ButtonAuthClick(TObject *Sender)
{
    String ulogin = login->Text;
    String upassword = password->Text;
    User user = getUserRole(ulogin, upassword);
    if (!user.id) {
        ShowMessage("Логин или пароль не верны!");
    } else {
        switch (user.role)
        {
            case 1:
                showClientForm(user);
                break;
            case 2:
                showVendorForm(user);
                break;
            case 3:
                showProviderForm(user);
                break;
            default:
                ShowMessage("Что-то пошло не так");
                this->Close();
        }
        this->Hide();
    }
}
void Tauth::showVendorForm(User &user)
{
    TvendorForm *form = new TvendorForm(this);
    form->setIdVendor(user.id);
    form->Caption = user.company;
    form->Show();
}
void Tauth::showClientForm(User &user)
{
    TclientForm *form = new TclientForm(this);
    form->setIdClient(user.id);
    form->Caption = user.fullname;
    form->Show();
}
void Tauth::showProviderForm(User &user)
{
    TproviderForm *form = new TproviderForm(this);
    form->setIdClient(user.id);
    form->Caption = user.company;
    form->Show();
}
User __fastcall Tauth::getUserRole(String ulogin, String upassword)
{
    User data;
    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = this->dbConnect;
    query->SQL->Text = "SELECT id, fullname, company, role FROM users WHERE login = :login AND password = :password";
    query->ParamByName("login")->AsString = ulogin;
    query->ParamByName("password")->AsString = upassword;
    try
    {
        query->Open();
        if (!query->Eof)
        {
            data.id = query->FieldByName("id")->AsInteger;
            data.fullname = query->FieldByName("fullname")->AsString;
            data.company = query->FieldByName("company")->AsString;
            data.role = query->FieldByName("role")->AsInteger;
        }
    }
    catch (EDatabaseError& E)
    {
        ShowMessage("Ошибка при выполнении запроса: " + E.Message);
    }
    return data;
}
//---------------------------------------------------------------------------
void __fastcall Tauth::registrationClick(TObject *Sender)
{
    Treg *form = new Treg(this);
    form->ShowModal();
    delete form;
}
//---------------------------------------------------------------------------

void __fastcall Tauth::aboutClick(TObject *Sender)
{
    TaboutForm *form = new TaboutForm(this);
    form->ShowModal();
    delete form;
}
//---------------------------------------------------------------------------

