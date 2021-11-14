#include "Funcion.h"
#pragma once

class Registrar{
    public:
        string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente

        Registrar();

		void registrarse_cli();
		void registrarse_admin();
};
