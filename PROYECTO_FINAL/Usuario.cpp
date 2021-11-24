#include "Usuario.h"

Usuario::Usuario(){

}

void Usuario::registrarse_cli(){
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::out | ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"<----- Registrarse ----->";
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
            getline(verificador,contrasena);
            while(!verificador.eof())
            {
                getline(verificador,usuario);
                getline(verificador,direccion);
                getline(verificador,telefono);
                getline(verificador,dni);

                if(contrasena == auxCodigo)
                {
                    coincidencia=true;
                    cout<<"Ya existe un cliente con esa clave!" << endl;
                    //cout<<"El cliente con esa clave es: "<< usuario << endl;  //se elimina esta dado que revela contrase�a de otro usuario
                    cout<<"Ingresa una clave diferente!: ";
                    cin >> auxCodigo;
                    if(auxCodigo == "")
                        do
                        {
                            cout << "\nCodigo de cliente no v\240lido!, intentalo nuevamente: ";
                            cin >> auxCodigo;
                        }
                        while(auxCodigo == "");
                    break;
                }

                getline(verificador,contrasena);
            }

            if(verificador.eof()&& auxCodigo != contrasena)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("cls");
        contrasena = auxCodigo;
        cout<<"<----- Registrarse como Cliente ----->" << endl;
        cout<<"Contrasena: ";
        cout<< contrasena << endl;
        fflush(stdin);
        cout<<"Ingresa tu Nombre de Usuario: ";
        cin >> usuario;
        fflush(stdin);
        cout<<"Ingresa tu Direccion: ";
        getline(cin,direccion);
        fflush(stdin);
        cout<<"Ingresa tu N\243mero de Telefono: ";
        cin >> telefono;
        fflush(stdin);
		cout<<"Ingresa tu DNI: ";
        cin >> dni;

        escritura << contrasena <<"\n"<< usuario <<"\n"<< direccion <<"\n"<< telefono <<"\n"<< dni << endl;

        cout<<"El registro se ha completado correctamente." << endl;

        //return false;
    }

    /*else
    {
        return true;
    }*/

    escritura.close();
    verificador.close();
	system("pause");
}

void Usuario::registrarse_admin(){
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
        //return false;
    }

    /*else
    {
        return true;
    }*/

    escritura.close();
    verificador.close();
	system("pause");
}

void Usuario::mostrar_registro(){
	system("cls");
	int i=0;
    ifstream lectura;
    lectura.open("clientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Usuarios (Clientes)***\t\t\t\t\n\n";
        getline(lectura,contrasena);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,usuario);;
            getline(lectura,direccion);
			getline(lectura,telefono);;
            getline(lectura,dni);
            cout<<"Contrasena: "<<contrasena<<"\t";
            cout<<"Nombre: "<<usuario<<"\t";
			cout<<"Direccion: "<<direccion<<"\t";
			cout<<"Telefono"<<telefono<<"\t";
            cout<<"DNI: "<<dni<<endl;
            cout<<"\n\n";
            getline(lectura,contrasena);
        }

        if(i==1){
            cout<<"Hay un solo usuario(cliente) registrado \n\n";
        }
        else{
            cout<<"Hay un total de "<< i <<" Usuarios(clientes) registrados \n\n";
        }
    }
    else
    {
        cout << "No hay registros!!!" << endl;
    }
    lectura.close();
    system("pause");
}

void Usuario::loguearse_cli(){
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
						pedido.registrar_pedido(dni);
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

void Usuario::loguearse_admin(){
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
				Usuario registro;
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
                        /*if(suministros.agregar_produ() == true){
                            error();
                        }*/
						suministros.agregar_produ();
                        break;
                    case 4:
                        suministros.mod_sumi();
                        break;
                    case 5:
                        /*if (suministros.ver_sumi() == true){
                            error();
                        }*/
						suministros.ver_sumi();
                        break;
                    case 6:
						pedidos.mostrar();
                        break;
                    case 7:
						pedidos.eliminar();
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

void Usuario::eliminar(){
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

void Usuario::mostrar(){
    system("cls");
	int i=0;
    ifstream lectura;
    lectura.open("clientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Usuarios (Clientes)***\t\t\t\t\n\n";
        getline(lectura,contrasena);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,usuario);
            getline(lectura,direccion);
			getline(lectura,telefono);
            getline(lectura,dni);
            cout<<"Nombre: "<<usuario<<endl;
			cout<<"Direccion: "<<direccion<<endl;
			cout<<"Telefono: "<<telefono<<endl;
            cout << "--------------------------" << endl;
            getline(lectura,contrasena);
        }

        if(i==1){
            cout<<"Hay un solo usuario(cliente) registrado \n\n";
        }
        else{
            cout<<"Hay un total de "<< i <<" Usuarios(clientes) registrados \n\n";
        }
    }
    else
    {
        cout << "No hay registros!!!" << endl;
    }
    lectura.close();
    system("pause");
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
