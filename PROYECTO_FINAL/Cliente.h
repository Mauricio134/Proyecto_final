#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Pedidos.h"

using namespace std;

class Cliente : public Usuario{
    public:
        Pedidos pedido;
        string dni;
		string **regc;
		int tamano;

        Cliente();
        ~Cliente();

        bool registrarse_cli();
        void loguearse_cli();
        void Eliminar_registro();
        void Mostrar_registro();
        int menu_cli();
		int cont_cli();
};
