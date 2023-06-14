//---------------------------------------------------------------------------

#ifndef loginH
#define loginH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.StdCtrls.hpp>
/*
    Основные заголовки для подключения к БД
*/
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.sqlite.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
/*
    ХЗ
*/
//#include <Data.DB.hpp>
//#include <FireDAC.Phys.hpp>
//#include <FireDAC.Phys.Intf.hpp>
//#include <FireDAC.Stan.Error.hpp>
//#include <FireDAC.Stan.Intf.hpp>
//#include <FireDAC.Stan.Option.hpp>
//#include <FireDAC.Stan.Pool.hpp>
//#include <FireDAC.UI.Intf.hpp>

//---------------------------------------------------------------------------
#include <map>
#include "share.hpp"
//---------------------------------------------------------------------------
class Tauth : public TForm
{
__published:    // IDE-managed Components
    TEdit *login;
    TEdit *password;
    TLabel *loginLabel;
    TLabel *passwordLabel;
    TButton *ButtonAuth;
    TImage *logo;
    TLabel *title;
    TLabel *registration;
    TButton *about;
    void __fastcall registrationMouseEnter(TObject *Sender);
    void __fastcall registrationMouseLeave(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButtonAuthClick(TObject *Sender);
    void __fastcall registrationClick(TObject *Sender);
    void __fastcall aboutClick(TObject *Sender);
private:    // User declarations
    TFDConnection *dbConnect;

    void showVendorForm(User &user);
    void showClientForm(User &user);
    void showProviderForm(User &user);

    void __fastcall connetToDatabase();
    User __fastcall getUserRole(String ulogin, String upassword);
public:        // User declarations
    TFDConnection *getDBConnect();
    __fastcall Tauth(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tauth *auth;
//---------------------------------------------------------------------------
#endif
