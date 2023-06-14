//---------------------------------------------------------------------------

#ifndef registrationH
#define registrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "login.h"
//---------------------------------------------------------------------------
class Treg : public TForm
{
__published:    // IDE-managed Components
    TLabel *LabelRole;
    TComboBox *role;
    TLabel *LabelLogin;
    TEdit *login;
    TLabel *LabelPassword;
    TEdit *password;
    TLabel *LabelFullname;
    TEdit *fullname;
    TLabel *LabelAddress;
    TEdit *address;
    TLabel *LabelPhone;
    TEdit *phone;
    TLabel *LabelCompany;
    TEdit *company;
    TImage *Image1;
    TButton *ButtonRegister;
    TButton *ButtonCancel;
    void __fastcall ButtonCancelClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall roleChange(TObject *Sender);
    void __fastcall ButtonRegisterClick(TObject *Sender);
private:    // User declarations
    int id = 0;
    void setMode();
    bool insertNewUser();
public:        // User declarations
    __fastcall Treg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Treg *reg;
//---------------------------------------------------------------------------
#endif
