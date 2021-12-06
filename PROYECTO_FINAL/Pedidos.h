#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Pedidos{
    public:
        string id;
        string usuario;
        string contrasena;
        string dni;
        string telefono;
        string direccion;
        string dia;
        string mes;
        string ano;
        string tipo;
		string idaux;
		string auxano, auxmes;

		int cajas, pasteles;
        float precio;
        int sum;
        int cantidad;
        int fresa, coco, circulo;
        string **reg;
		int tamano;

        Pedidos();
        ~Pedidos();

        void eliminar_pedido();
        void mostrar_pedidos();
        void registrar_pedido(string );
        void pasteles_opciones();
        int Caja_o_personal();
        int cont_ped();
        void reporte_mens();
};
