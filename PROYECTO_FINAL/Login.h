#include "Funcion.h"
#pragma once

class Loguear{
    public:
        string usuario;
        string contrasena;
        string dni;
        string id;
        string telefono;
        string direccion;
        string usuaux;
        string contraux;
        string dniaux;
        bool encontrado;

        Login();

        void loguearse_cli();
		void loguearse_admin();
		void eliminar();
};
