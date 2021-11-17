#pragma once
#include "Login.h"
#include "Register.h"

class Administrador{
    public:
        Registrar reg;
        Loguear log;

        Administrador();

		void Login();
};
