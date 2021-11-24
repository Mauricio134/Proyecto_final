#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Pedidos{
    public:
        string usuario;
        string contrasena;
        string dni;
        string telefono;
        string direccion;
        string dia;
        string mes;
        string ano;
        string tipo;
		string auxusu;
		string auxdia;
		string auxmes;
		string auxano;
        double precio;
        int sum;
        int cantidad;
        int cajas;
        int pasteles;
        int fresa, coco, circulo;

        Pedidos();

        void mostrar_pedidos();
        void registrar_pedido(string );
        void pasteles_opciones();
		void eliminar_pedido();
        int Caja_o_personal();
};
