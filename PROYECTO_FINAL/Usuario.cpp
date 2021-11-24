#include "Usuario.h"

Usuario::Usuario(){
    usuario = " "; //cliente y admin
    contrasena = " "; //cliente y admin
    telefono = " "; //cliente
    direccion = " "; //cliente
	usuaux = " ";
    contraux = " ";
    dniaux = " ";
    encontrado = false;
}

int Usuario::menu_usu(){
    int num;
    system("cls");
    cout << "<<-------Tipo de Usuario------->>" << endl;
    cout << "1. Administrador" << endl;
    cout << "2. Cliente" << endl;
    cout << "3. Retornar al Menu"<< endl;
    cout << "Opcion: ";
    cin >> num;
    return num;
}
