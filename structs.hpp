#ifndef structsH
#define structsH

#include <System.Classes.hpp>

struct User
{
    int id = 0;
    String login;
    String password;
    String fullname;
    String address;
    String phone;
    String company;
    int role;
};

struct TypeProduct
{
    int id = 0;
    String name;
};

struct Product
{
    int id = 0;
    String name;
    int type;
    String typeName;
    float sum;
    int vendor;
};

struct BasketRow
{
    int id;
    String name;
    String type;
    String vendor;
    double sum;
};

#endif
