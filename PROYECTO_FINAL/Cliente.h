#include "Funcion.h"
#include "Login.h"
#include "Register.h"
#pragma once

class Cliente{
    public:
        Registrar reg;
        Loguear log;

        Cliente();

        void Login();
        void Eliminar_registro();
};
