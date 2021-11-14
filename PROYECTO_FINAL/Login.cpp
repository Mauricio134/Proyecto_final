#include "Login.h"

Loguear::Login(){
    usuario = "";
    contrasena = "";
    dni = "";
    id = "";
    telefono = "";
    direccion = "";
    usuaux = "";
    contraux = "";
    encontrado = false;
}

void Loguear::loguearse_cli(){
    cout << "<----- LogIn ----->" << endl;
    cout << "Usuario: ";
    cin >> usuaux;
    cout << "Contrasena: ";
    cin >> contraux;
    ifstream Cli_lec("clientes.txt", ios::in);
    Cli_lec >> contrasena;
    Cli_lec >> usuario;
    while(!Cli_lec.eof() && !encontrado){
        Cli_lec.ignore(10000, '\n');
        getline(Cli_lec,direccion);
        Cli_lec >> telefono;
        Cli_lec >> dni;
        if (usuario == usuaux && contrasena == contraux){
            cout << "Bienvenidos" << endl;
            encontrado = true;
        }
        Cli_lec >> contrasena;
        Cli_lec >> usuario;
    }
    if (!encontrado){
        cout << "El usuario y/o contrasena no es correcto..." << endl;
    }
    Cli_lec.close();
    system("pause");
}

void Loguear::loguearse_admin(){
    ifstream Admin_lec("Admin.txt", ios::in);
    cout << "<----- LogIn ----->" << endl;
    cout << "Usuario: ";
    cin >> usuaux;
    cout << "Contrasena: ";
    cin >> contraux;
    Admin_lec >> contrasena;
    while(!Admin_lec.eof() && !encontrado){
        Admin_lec >> usuario;
        Admin_lec >> id;
        if (usuario == usuaux && contrasena == contraux){
            cout << "Bienvenidos" << endl;
            encontrado = true;
        }

        Admin_lec >> contrasena;
    }
    if (!encontrado){
        cout << "El usuario y/o contrasena no es correcto..." << endl;
    }
    Admin_lec.close();
    system("pause");
}
