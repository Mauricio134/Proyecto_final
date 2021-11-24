#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"

using namespace std;

class Administrador : public Usuario{
    public:
        string id; //admin

        Administrador();

        void registrarse_admin();
        void loguearse_admin();
};
