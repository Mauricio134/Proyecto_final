#pragma once
#include <iostream>
<<<<<<< HEAD
#include "Admin.h"
#include "Cliente.h"
=======
#include <fstream>
>>>>>>> 2a3bc346442c75b57baac00506d4960b90b35eca

using namespace std;

class Usuario{
    public:
<<<<<<< HEAD
        Administrador admin;
        Cliente cli;
        //Constructor
        Usuario();
        //Metodos
=======
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
>>>>>>> 2a3bc346442c75b57baac00506d4960b90b35eca
        int menu_usu();
};
