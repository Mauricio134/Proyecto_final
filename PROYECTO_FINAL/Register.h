#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Registrar{
    public:
        string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente

        Registrar();

		bool registrarse_cli();
		bool registrarse_admin();
};
