#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Usuario{
    public:
        //Variables
		string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string telefono; //cliente
        string direccion; //cliente
		string usuaux;
        string contraux;
        string dniaux;
        bool encontrado;

        Usuario();
        //Métodos
        int menu_usu();
};
