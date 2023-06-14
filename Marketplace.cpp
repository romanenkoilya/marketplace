//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("registration.cpp", reg);
USEFORM("vendor.cpp", vendorForm);
USEFORM("provider.cpp", providerForm);
USEFORM("client.cpp", clientForm);
USEFORM("login.cpp", auth);
USEFORM("order.cpp", orderForm);
USEFORM("product.cpp", productF);
USEFORM("about.cpp", aboutForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try
    {
        Application->Initialize();
        Application->MainFormOnTaskBar = true;
        Application->CreateForm(__classid(Tauth), &auth);
        Application->CreateForm(__classid(TvendorForm), &vendorForm);
        Application->CreateForm(__classid(TproductF), &productF);
        Application->CreateForm(__classid(TclientForm), &clientForm);
        Application->CreateForm(__classid(TorderForm), &orderForm);
        Application->CreateForm(__classid(TproviderForm), &providerForm);
        Application->CreateForm(__classid(Treg), &reg);
        Application->CreateForm(__classid(TaboutForm), &aboutForm);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    catch (...)
    {
        try
        {
            throw Exception("");
        }
        catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
