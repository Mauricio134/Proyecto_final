#pragma once
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include "Usuario.h"

using namespace std;
#include "Login.h"
#include "Register.h"

class Administrador{
    public:
        Registrar reg;
        Loguear log;

        Administrador();

		void Login();
};
