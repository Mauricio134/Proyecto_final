#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

ifstream Cli_lec;
ifstream Admin_lec;

void pausa();
void error();

class Register{
    public:
        string usuario; //cliente y admin
        string contrasena; //cliente y admin
        string dni; //cliente
        string id; //admin
        string telefono; //cliente
        string direccion; //cliente // Usar getline

        Register(){
            usuario = "";
            contrasena = "";
            dni = "";
            id = "";
            telefono = "";
            direccion = "";
        }

		void registrarse_cli();
		void registrarse_admin();
};

class Login{
    public:
        string usuario;
        string contrasena;
        string dni;
        string id;
        string telefono;
        string direccion;
        string usuaux;
        string contraux;
        bool encontrado;

        Login(){
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

        void loguearse_cli(){
            cout << "<----- LogIn ----->" << endl;
            cout << "Usuario: ";
            cin >> usuaux;
            cout << "Contrasena: ";
            cin >> contraux;
            Cli_lec.open("clientes.txt", ios::in);
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

		void loguearse_admin(){
            Admin_lec.open("Admin.txt", ios::in);
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
};

class Cliente{
    public:
        Register reg;
        Login log;

        Cliente(){

        }

        void Login(){
            system("cls");
            log.loguearse_cli();
        }
};

class Administrador{
    public:
        Register reg;
        Login log;

        Administrador(){

        }

		void Login(){
			system("cls");
			log.loguearse_admin();
		}
};

class Usuario{
    public:
        Administrador admin;
        Cliente cli;

        Usuario(){

        }

        int menu_usu(){
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
};

void Register::registrarse_cli(){
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

void Register::registrarse_admin(){
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

int main(){
	system ("color f0");
	system ("cls");
	int op;
    do{
        system("cls");
        op = menu();
        switch(op){
            case 1:
                int op2;
                do{
                    Usuario user1;
                    op2 = user1.menu_usu();
                    switch(op2){
                        case 1:
							user1.admin.Login();
                            break;
                        case 2:
                            user1.cli.Login();
                            break;
                    }
                }while(op2 != 3);
                break;
            case 2:
                system("cls");
                int cliente_o_admin;
                do{
                    cout << "<<-------Tipo de Usuario------->>" << endl;
                    cout << "1. Administrador" << endl;
                    cout << "2. Cliente" << endl;
                    cout << "3. Retornar al Menu"<< endl;
                    cout<<"Opcion: ";
                    cin>> cliente_o_admin;
					Register inicio;
                    switch(cliente_o_admin){
						case 1:
							inicio.registrarse_admin();
							break;
						case 2:
							inicio.registrarse_cli();
							break;
					}
                }while(cliente_o_admin != 3);
                break;
        }
    }while(op != 3);
    return 0;
}

void error(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void pausa(){
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}
