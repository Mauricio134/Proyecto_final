#include "Login.h"
#include "Cliente.h"
#include "Suministros.h"

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
            int op;
            do{
                op = menu_cli();
                switch(op){
                    case 1:
                        break;
                }
            }while(op != 2);
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
            int op;
            do{
                Cliente cliente;
                Suministros suministros;
				Registrar registro;
                op = menu_admin();
                switch(op){
                    case 1:registro.mostrar_registro();
                        break;
                    case 2:
                        cliente.Eliminar_registro();
                        break;
                    case 3:
                        suministros.agregar_produ();
                        break;
                    case 4:
                        break;
                    case 5:
                        suministros.ver_sumi();
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }
            }while(op != 8);
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

void Loguear::eliminar(){
    ifstream Lectura("clientes.txt", ios::in);
    ofstream aux("Auxiliar.txt", ios::out);
    if (Lectura.is_open()){
        cout << "Colocar DNI: ";
        cin >> dniaux;
        Lectura >> contrasena;
        Lectura >> usuario;
        while(!Lectura.eof()){
            Lectura.ignore(10000, '\n');
            getline(Lectura,direccion);
            Lectura >> telefono;
            Lectura >> dni;
            if (dni == dniaux){
                cout << "Contrasena: " << contrasena <<"\n"<< "Usuario: " << usuario <<"\n"<< "Direccion: " << direccion <<"\n"<< "Telefono: " << telefono <<"\n"<< "DNI: " << dni << endl;
                cout << "\t!!!! Registro Eliminado !!!!" << endl;
            } else {
                aux << contrasena <<"\n"<< usuario <<"\n"<< direccion <<"\n"<< telefono <<"\n"<< dni << endl;
            }
            Lectura >> contrasena;
            Lectura >> usuario;
        }
        Lectura.close();
        aux.close();
        system("pause");
    }else{
        cout << "Error" << endl;
    }

    remove("clientes.txt");
    rename("Auxiliar.txt", "clientes.txt");
}
