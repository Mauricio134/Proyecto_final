#pragma once
#include "Login.h"
#include "Register.h"

class Cliente : public Usuario{
    public:
        Usuario log;

        Cliente();

        void Login();
        void Eliminar_registro();
        void Mostrar_registro();
};
