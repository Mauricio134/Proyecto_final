#include "Login.h"
#include "Register.h"
#pragma once

class Administrador{
    public:
        Registrar reg;
        Loguear log;

        Administrador();

		void Login();
};
