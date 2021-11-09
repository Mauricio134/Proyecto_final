#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

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

        void registroPrincipal();
		void registrarse();
};

class Login{
    public:
        void loguearse_cli(){
            string usuario; //cliente y admin
            string contrasena; //cliente y admin
            string dni; //cliente
            //string id; //admin
            string telefono; //cliente
            string direccion; //cliente
            string usuaux;
            string contraux;
            bool encontrado = false;
            ifstream Cli_lec("clientes.txt", ios::in);
            cout << "<----- LogIn ----->" << endl;
            cout << "Usuario: ";
            cin >> usuaux;
            cout << "Contrasena: ";
            cin >> contraux;
            while(!Cli_lec.eof() && !encontrado){
                getline(Cli_lec,contrasena);
                getline(Cli_lec,usuario);
                getline(Cli_lec,direccion);
                getline(Cli_lec,telefono);
                getline(Cli_lec,dni);
                if (usuario == usuaux && contrasena == contraux){
                    cout << "Bienvenidos" << endl;
                    encontrado = true;
                }
            }
            if (usuario != usuaux && contrasena == contraux){
                cout << "El usuario no es correcto..." << endl;
            }else if ( usuario == usuaux && contrasena != contraux){
                cout << "La contrasena no es correcta..." << endl;
            }else if (usuario != usuaux && contrasena != contraux){
                cout << "El usuario y contrasena no son correctos..." << endl;
            }
            Cli_lec.close();
            system("pause");
        }

    /*void loguearse_admin(){
        string usu;
        string contra;
        string id;
        string usuaux;
        string contraaux;
        bool encontrado = false;
        Admin_lec.open("Admin.txt", ios::in);
        cout << "<----- LogIn ----->" << endl;
        cout << "Usuario: ";
        cin >> usuaux;
        cout << "Contrasena: ";
        cin >> contraaux;
        Admin_lec>>usu;
        while(!Admin_lec.eof() && !encontrado){
            Admin_lec>>contra;
            Admin_lec>>id;
            if (usu == usuaux && contra == contraaux){
                cout << "Bienvenidos" << endl;
                encontrado = true;
            }
            Admin_lec>>usu;
        }
        if (usu != usuaux && contra == contraaux){
            cout << "El usuario no es correcto..." << endl;
        }else if ( usu == usuaux && contra != contraaux){
            cout << "La contrasena no es correcta..." << endl;
        }else if (usu != usuaux && contra != contraaux){
            cout << "El usuario y contrasena no son correctos..." << endl;
        }
        Admin_lec.close();
        system("pause");
    }*/
};

class Cliente{
    public:
        Register reg;
        Login log;

        void Login(){
            system("cls");
            log.loguearse_cli();
        }
};

class Administrador{
    public:
        Register reg;
        Login log;
};

class Usuario{
    public:
        Administrador admin;
        Cliente cli;

        int menu(){
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

void Register::registrarse()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"<----- Registrarse ----->";
        fflush(stdin);
        system("cls");
        cout<<"Ingrese su contrasena: ";
        getline(cin,auxCodigo);
        if(auxCodigo == "")
            do
            {
                cout<<"Contrasena no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
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
                    cout<<"El cliente con esa clave es: "<< usuario << endl;
                    cout<<"Ingresa una clave v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo == "")
                        do
                        {
                            cout << "\nCodigo de cliente no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
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
        contrasena=auxCodigo;
        cout<<"<----- Registrarse como Cliente ----->" << endl;
        cout<<"Contrasena: ";
        cout<<contrasena << endl;
        fflush(stdin);
        cout<<"Ingresa tu Nombre de Usuario: ";
        getline(cin,usuario);
        fflush(stdin);
        cout<<"Ingresa tu Direccion: ";
        getline(cin,direccion);
        fflush(stdin);
        cout<<"Ingresa tu N\243mero de Telefono: ";
        getline(cin,telefono);
        fflush(stdin);
		cout<<"Ingresa tu DNI: ";
        getline(cin,dni);

        escritura<<contrasena<<"\n"<<usuario<<"\n"<<direccion<<"\n"<<telefono<<"\n"<<dni<<"\n";

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

int main()
{
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
                    op2 = user1.menu();
                    switch(op2){
                        case 1:
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
                    switch(cliente_o_admin){
                    case 1:
                        cout<<"\nEres el admin\n";
                        break;
                    case 2:
                        Register inicio;
                        inicio.registrarse();
                        break;
                    }
                }while(cliente_o_admin != 3);
                break;
        }
    }while(op != 3);
    return 0;
}
void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}
