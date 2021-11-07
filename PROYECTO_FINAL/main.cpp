#include <iostream>
#include <fstream>

using namespace std;

class Register{
    public:
        string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente // Usar getline
};

class Login{
    public:
        string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente
        string usuaux;
        string contraux;
};

class Cliente{
    public:
        Register reg;
        Login log;
};

class Administrador{
    public:
        Register reg;
        Login log;
};

class Usuario{
    public:
        Administrador admin;
        Cliente cli;
};

int main()
{

    return 0;
}
