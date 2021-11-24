#pragma once
#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Suministros.h"
#include "Pedidos.h"
#include "Funcion.h"

using namespace std;

class Administrador : public Usuario{
    public:
        string id; //admin

        Administrador();

        bool registrarse_admin();
        void loguearse_admin();
        int menu_admin();
};
