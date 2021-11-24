#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Pedidos.h"

using namespace std;

class Cliente{
    public:
<<<<<<< HEAD
        Registrar reg;
        Loguear log;
=======
        Pedidos pedido;
        string dni;
		string **regc;
>>>>>>> 2a3bc346442c75b57baac00506d4960b90b35eca

        Cliente();

        bool registrarse_cli();
        void loguearse_cli();
        void Eliminar_registro();
        void Mostrar_registro();
        int menu_cli();
		int cont_cli();
};
