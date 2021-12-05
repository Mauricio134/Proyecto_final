#include "Funcion.h"

int menu(){
    int x;
    system("cls");
    cout << "====================================" << endl;
    cout << "||           BIENVENIDO           ||" << endl;
    cout << "====================================" << endl;
    cout << "====================================" << endl;
    cout << "|| [1] Ingresar                   ||" << endl;
    cout << "|| [2] Registrarse                ||" << endl;
    cout << "|| [3] Salir                      ||" << endl;
    cout << "====================================" << endl;
    cout << "Opcion: ";
    cin >> x;
    return x;
}

void error(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}
