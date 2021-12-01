#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Cliente.h"
#include "Suministros.h"
#include "Pedidos.h"
#include "Funcion.h"

using namespace std;

class Administrador : public Usuario{
    public:
        string id;

        Administrador();

        bool registrarse_admin();
        void loguearse_admin();
        int menu_admin();
};
