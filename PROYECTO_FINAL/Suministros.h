#include "Funcion.h"
#pragma once

class Suministros{
    public:
        string id;
        string tipo;
        string marca;
        string precio;
        string cantidad;

        Suministros();

        void agregar_produ();
		void ver_sumi();
};
