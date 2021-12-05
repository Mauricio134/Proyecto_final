#include "Cliente.h"

Cliente::Cliente(){
    dni = " ";
	regc = nullptr;
	tamano = 0;
}

Cliente::~Cliente(){
    if (regc != nullptr && tamano > 0){
        for (int o = 0; o < tamano; o++) {
            delete [] regc[o];
        }
        delete [] regc;
    }
}

bool Cliente::registrarse_cli(){
    system("cls");
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::out | ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        system("cls");
        cout << "==============================================" << endl;
        cout << "||           REGISTRAR CONTRASENA           ||" << endl;
        cout << "==============================================" << endl;
        fflush(stdin);
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
        cout << "======================================================" << endl;
        cout << "||              REGISTRAR COMO CLIENTE              ||" << endl;
        cout << "======================================================" << endl;
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

        cout << "======================================================" << endl;
        cout << "||                 REGISTRO EXITOSO                 ||" << endl;
        cout << "======================================================" << endl;
        escritura.close();
        verificador.close();
        system("pause");

        return false;
    }
    else
    {
        escritura.close();
        verificador.close();
        system("pause");
        return true;
    }
}

void Cliente::loguearse_cli(){
    system("cls");
    cout << "===========================================" << endl;
    cout << "||                 LOGIN                 ||" << endl;
    cout << "===========================================" << endl;
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
        cout << "======================================================" << endl;
        cout << "||       EL USUARIO Y/O CONTRSENA INCORRECTOS       ||" << endl;
        cout << "======================================================" << endl;
    }
    Cli_lec.close();
	system("pause");
}

void Cliente::Eliminar_registro(){
    system("cls");
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
                cout << "======================================================" << endl;
                cout << "||                REGISTRO ELIMINADO                ||" << endl;
                cout << "======================================================" << endl;
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
        cout << "=====================" << endl;
        cout << "||      ERROR      ||" << endl;
        cout << "=====================" << endl;
    }

    remove("clientes.txt");
    rename("Auxiliar.txt", "clientes.txt");
    system("pause");
}

int Cliente::cont_cli(){
	system("cls");
    int i = 0;
    ifstream lectura;
    lectura.open("clientes.txt", ios::in);
    if (lectura.is_open())
    {
        getline(lectura, contrasena);
        while (!lectura.eof())
        {
			i++;
			for (int k = 0; k < 5; k++){
				getline(lectura, usuario);
			}
			getline(lectura, contrasena);
		}
	}
	lectura.close();
	return i;
}


void Cliente::Mostrar_registro(){
    system("cls");
    int n = 0;
	tamano = cont_cli();

	regc=new string*[tamano];
    for(int i=0;i<tamano;i++){
        regc[i]=new string[5];
    }

	ifstream lectura;
    lectura.open("clientes.txt", ios::in);
    if (lectura.is_open())
    {
		lectura.seekg(0);
        cout << "================================================" << endl;
        cout << "||             LISTADO DE CLIENTES            ||" << endl;
        cout << "================================================" << endl;
        getline(lectura, contrasena);
        while (!lectura.eof())
        {

            getline(lectura, usuario);
            getline(lectura, direccion);
            getline(lectura, telefono);
            getline(lectura, dni);
			regc [n][0] = contrasena;
			regc [n][1] = usuario;
			regc [n][2] = direccion;
			regc [n][3] = telefono;
			regc [n][4] = dni;
            getline(lectura, contrasena);
			n++;
        }

		for (int x = 0; x < tamano; x++){
			for (int k = 0; k < 5; k++){
				if (k==1)
                {
					cout << "Nombre: " <<regc [x][k] << endl;
				}
				if (k==2)
                {
					cout << "Direccion: " <<regc [x][k] << endl;
				}
				if (k==3)
                {
					cout << "Telefono: " <<regc [x][k] << endl;
				}
				if (k==4)
                {
					cout << "DNI: " <<regc [x][k] << endl;
				}

			}
			cout << "--------------------------" << endl;
		}
        if (tamano == 1) {
            cout << "================================================" << endl;
            cout << "||       HAY SOLO 1 CLIENTE REGISTRADO        ||" << endl;
            cout << "================================================" << endl;
        }
        else {
            cout << "================================================" << endl;
            cout << "||         HAY " << tamano << " CLIENTE REGISTRADOS          ||" << endl;
            cout << "================================================" << endl;
        }
        lectura.close();
        system("pause");

    }
    else
    {
        cout << "================================================" << endl;
        cout << "||             NO HAY REGISTROS               ||" << endl;
        cout << "================================================" << endl;
        lectura.close();
        system("pause");
    }
}

int Cliente::menu_cli(){
    int num;
    system("cls");
    cout << "===============================================" << endl;
    cout << "||           BIENVENIDO " << usuario << "          ||" << endl;
    cout << "===============================================" << endl;
    cout << "===============================================" << endl;
    cout << "|| [1] Realizar Pedido                       ||" << endl;
    cout << "|| [2] Salir                                 ||" << endl;
    cout << "===============================================" << endl;
    cout << "Opcion: ";
    cin >> num;
    return num;
}
