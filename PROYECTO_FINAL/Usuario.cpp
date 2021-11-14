#include "Usuario.h"

Usuario::Usuario(){

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
