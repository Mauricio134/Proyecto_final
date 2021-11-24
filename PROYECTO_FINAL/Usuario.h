#pragma once
#include <iostream>
#include "Admin.h"
#include "Cliente.h"

using namespace std;

class Usuario{
    public:
        Administrador admin;
        Cliente cli;
        //Constructor
        Usuario();
        //Metodos
        int menu_usu();
};
