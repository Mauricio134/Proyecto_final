#include "Admin.h"

Administrador::Administrador(){
    id = " ";
}

bool Administrador::registrarse_admin()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("Admin.txt",ios::in);
    escritura.open("Admin.txt",ios::out | ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"<----- Registrar Contrasena ----->";
        fflush(stdin);
        system("cls");
        cout<<"Ingrese su contrasena: ";
        cin >> auxCodigo;
        if(auxCodigo == "")
            do
            {
                cout<<"Contrasena no v\240lido!, intentalo nuevamente: ";
                cin >> auxCodigo;
            }
            while(auxCodigo == "");
        do
        {
            verificador.seekg(0);
            verificador>>contrasena;
            while(!verificador.eof())
            {
                verificador>>usuario;
                verificador>>id;

                if(contrasena == auxCodigo)
                {
                    coincidencia=true;
                    cout<<"Ya existe un administrador con esa clave!" << endl;
                    //cout<<"El cliente con esa clave es: "<< usuario << endl;  //se elimina esta dado que revela contrase�a de otro usuario
                    cout<<"Ingresa una clave diferente!: ";
                    cin >> auxCodigo;
                    if(auxCodigo == "")
                        do
                        {
                            cout << "\nCodigo de administrador no v\240lido!, intentalo nuevamente: ";
                            cin >> auxCodigo;
                        }
                        while(auxCodigo == "");
                    break;
                }

                verificador>>contrasena;
            }

            if(verificador.eof()&& auxCodigo != contrasena)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("cls");
        contrasena = auxCodigo;
        cout<<"<----- Registrarse como Administrador ----->" << endl;
        cout<<"Contrasena: ";
        cout<< contrasena << endl;
        fflush(stdin);
        cout<<"Ingresa tu Nombre de Usuario: ";
        cin >> usuario;
        cout<<"Ingresa tu ID: ";
        cin >> id;
        fflush(stdin);

        escritura << contrasena <<"\n"<< usuario <<"\n"<< id << endl;

        cout<<"El registro se ha completado correctamente." << endl;
        return false;
    }

    else
    {
        return true;
    }

    escritura.close();
    verificador.close();
	system("pause");
}

void Administrador::loguearse_admin(){
    system("cls");
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
				Pedidos pedidos;
                op = menu_admin();
                switch(op){
                    case 1:
                        cliente.Mostrar_registro();
                        break;
                    case 2:
                        cliente.Eliminar_registro();
                        break;
                    case 3:
                        if(suministros.agregar_produ() == true){
                            error();
                        }
                        break;
                    case 4:
                        suministros.mod_sumi();
                        break;
                    case 5:
                        if (suministros.ver_sumi() == true){
                            error();
                        }
                        break;
                    case 6:
						pedidos.mostrar_pedidos();
                        break;
                    case 7:
						pedidos.eliminar_pedido();
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

int Administrador::menu_admin(){
    int num;
    system("cls");
    cout << "<<-------Bienvenido "<< usuario << "------->>" << endl;
    cout << "1. Mostrar Usuarios" << endl;
    cout << "2. Eliminar Usuarios" << endl;
    cout << "3. Registrar Suministros" << endl;
    cout << "4. Modificar Suministros" << endl;
    cout << "5. Mostrar Suministros" << endl;
    cout << "6. Lista de Pedidos" << endl;
    cout << "7. Eliminar Pedidos" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
    cin >> num;
    return num;
}
