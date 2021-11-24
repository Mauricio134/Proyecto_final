#pragma once
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include "Usuario.h"

using namespace std;
#include "Login.h"
#include "Register.h"
=======
#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Suministros.h"
#include "Pedidos.h"
#include "Funcion.h"

using namespace std;
>>>>>>> 2a3bc346442c75b57baac00506d4960b90b35eca

class Administrador{
    public:
<<<<<<< HEAD
        Registrar reg;
        Loguear log;
=======
        string id; //admin
>>>>>>> 2a3bc346442c75b57baac00506d4960b90b35eca

        Administrador();

        bool registrarse_admin();
        void loguearse_admin();
        int menu_admin();
};
