#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Suministros{
    public:
        string id;
        string tipo;
        string marca;
        string precio;
        string cantidad;
		string **reg;
		int tamano;


        Suministros();
        ~Suministros();

        bool agregar_produ();
        bool ver_sumi();
        void mod_sumi();
		int cont_sumi();
};
