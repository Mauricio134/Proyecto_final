#pragma once
#include "Login.h"
#include "Register.h"

class Administrador : public Usuario{
    public:
        Loguear log;

        Administrador();

		void Login();
};
