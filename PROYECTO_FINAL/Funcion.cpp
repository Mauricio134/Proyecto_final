#include "Funcion.h"

int menu(){
    int x;
    system("cls");
    cout << "<<-------Bienvenido------->>" << endl;
    cout << "1. Ingresar" << endl;
    cout << "2. Registrarse" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> x;
    return x;
}

int menu_admin(){
    int x;
    system("cls");
    cout << "<<-------Bienvenido------->>" << endl;
    cout << "1. Mostrar Usuarios" << endl;
    cout << "2. Eliminar Usuarios" << endl;
    cout << "3. Registrar Suministros" << endl;
    cout << "4. Modificar Suministros" << endl;
    cout << "5. Mostrar Suministros" << endl;
    cout << "6. Lista de Pedidos" << endl;
    cout << "7. Eliminar Pedidos" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
    cin >> x;
    return x;
}

int menu_cli(){
    int x;
    system("cls");
    cout << "<<-------Bienvenido------->>" << endl;
    cout << "1. Realizar Pedido" << endl;
    cout << "2. Salir" << endl;
    cout << "Opcion: ";
    cin >> x;
    return x;
}

void error(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}
