//---------------------------------------------------------------------------

#ifndef aboutH
#define aboutH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TaboutForm : public TForm
{
__published:    // IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *LinkOnGitGub;
    TLabel *Label3;
    TLabel *Label4;
    void __fastcall LinkOnGitGubClick(TObject *Sender);
    void __fastcall LinkOnGitGubMouseEnter(TObject *Sender);
    void __fastcall LinkOnGitGubMouseLeave(TObject *Sender);
private:    // User declarations
public:        // User declarations
    __fastcall TaboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TaboutForm *aboutForm;
//---------------------------------------------------------------------------
#endif
