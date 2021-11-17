#include "Register.h"

Registrar::Registrar(){
    usuario = "";
    contrasena = "";
    dni = "";
    id = "";
    telefono = "";
    direccion = "";
}

void Registrar::registrarse_cli(){
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
                    //cout<<"El cliente con esa clave es: "<< usuario << endl;  //se elimina esta dado que revela contraseña de otro usuario
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
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
	pausa();
}

void Registrar::registrarse_admin(){
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
                    //cout<<"El cliente con esa clave es: "<< usuario << endl;  //se elimina esta dado que revela contraseña de otro usuario
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
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
	pausa();
}

void Registrar::mostrar_registro(){
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
            getline(lectura,tipo);;
            getline(lectura,marca);
			getline(lectura,precio);;
            getline(lectura,cantidad);
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
        error();
    }
    lectura.close();
    pausa();
}
