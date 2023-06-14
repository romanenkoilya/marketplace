//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "about.h"
#include <ShellAPI.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TaboutForm *aboutForm;
//---------------------------------------------------------------------------
__fastcall TaboutForm::TaboutForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TaboutForm::LinkOnGitGubClick(TObject *Sender)
{
    ShellExecuteW(Handle, L"open", L"https://github.com/romanenkoilya/marketplace", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TaboutForm::LinkOnGitGubMouseEnter(TObject *Sender)
{
    LinkOnGitGub->Font->Style = LinkOnGitGub->Font->Style << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TaboutForm::LinkOnGitGubMouseLeave(TObject *Sender)
{
    LinkOnGitGub->Font->Style = LinkOnGitGub->Font->Style >> fsUnderline;
}
//---------------------------------------------------------------------------
