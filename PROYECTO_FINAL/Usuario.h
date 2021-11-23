#include "Admin.h"
#include "Cliente.h"

using namespace std;

class Usuario{
    public:
        //Variables
		string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente
		string usuaux;
        string contraux;
        string dniaux;
        bool encontrado;
		Pedidos pedido;
        //Metodos
        int menu_usu();
		void registrarse_cli();
        void registrarse_admin();
        void mostrar_registro();
		void loguearse_cli();
		void loguearse_admin();
		void eliminar();
		void mostrar();
};
