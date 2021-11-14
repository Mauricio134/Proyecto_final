#include "Funcion.h"
#pragma once

class Suministros{
    public:
        string id;
        string tipo;
        string marca;
        string precio;
        string cantidad;
        Suministros(){
			id = "";
			tipo = "";
			marca = "";
			precio = "";
			cantidad = "";
		}
        void agregar_produ();
		void ver_sumi();
};
void Suministros::agregar_produ(){
	ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("suministros.txt",ios::in);
    escritura.open("suministros.txt",ios::out | ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"<----- Agregar un suministro ----->";
        fflush(stdin);
        system("cls");
        cout<<"Ingrese una id para el suministro: ";
        cin >> auxCodigo;
        if(auxCodigo == "")
            do
            {
                cout<<"Id no v\240lido!, intentalo nuevamente: ";
                cin >> auxCodigo;
            }
            while(auxCodigo == "");
        do
        {
            verificador.seekg(0);
            getline(verificador,id);
            while(!verificador.eof())
            {
                getline(verificador,tipo);
				getline(verificador,marca);
				getline(verificador,precio);
                getline(verificador,cantidad);

                if(id == auxCodigo)
                {
                    coincidencia=true;
                    cout<<"Ya existe un suministro con esa id!" << endl;
                    cout<<"El suministro con esa id es: "<< tipo << endl;
                    cout<<"Ingresa una id diferente!: ";
                    cin >> auxCodigo;
                    if(auxCodigo == "")
                        do
                        {
                            cout << "\nId de suministro no v\240lido!, intentalo nuevamente: ";
                            cin >> auxCodigo;
                        }
                        while(auxCodigo == "");
                    break;
                }

                getline(verificador,id);
            }

            if(verificador.eof()&& auxCodigo != id)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("cls");
        id = auxCodigo;
        cout<<"\t\t\t\t***Registrar un suministro***\t\t\t\t\n\n";
        cout<<"Ingresa el id del Suministro: ";
        cout<<id;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del Suministro: ";
        getline(cin,tipo);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la marca del suministro: ";
        getline(cin,marca);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el precio del Suministro: ";
        getline(cin,precio);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la cantidad del Suministro: ";
        getline(cin,cantidad);
        cout<<"\n\n";

        escritura <<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidad<<"\n";

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

void Suministros::ver_sumi(){
	system("cls");
	int i=0;
    ifstream lectura;
    lectura.open("suministros.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los suministros***\t\t\t\t\n\n";
        getline(lectura,id);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,tipo);;
            getline(lectura,marca);
			getline(lectura,precio);;
            getline(lectura,cantidad);
            cout<<"Id: "<<id<<endl;
            cout<<"Nombre: "<<tipo<<endl;
			cout<<"Marca: "<<marca<<endl;
			cout<<"Precio: S/"<<precio<<endl;
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"\n\n";
            getline(lectura,id);
        }

        if(i==1)
            cout<<"Hay un solo suministro registrado en este almacen\n\n";

        else

            cout<<"Hay un total de "<<i<<" clientes registrados en este almacen\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}
//En el main, lo configuras como mejor prefieras
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
							int sistema;
							cout<<"\nSi deseas ver el menu administrativo, ingresa el codigo de la pasteleria: ";
							cin>>sistema;
							//Esto lo agregue por que cualquiera puede crearse unperfil de administrador,pero
							//si quiere modificar un dato, debe saber la clave que solo el personal conoce
							if (sistema==2021001){
								system("cls");
								int eleccion;
								do{
									cout << "<<-------Menu Administrativo------->>" << endl;
									cout << "1. Agregar suministro" << endl;
									cout << "2. Ver suministros"<< endl;
									cout << "3. Ver clientes registrados en el sistema"<<endl;
									cout << "4. Retornar al Menu"<< endl;
									cout<<"Opcion: ";
									cin>> eleccion;
									Suministros inicio;
									Register inicio_1;
									switch(eleccion){
										case 1:
											inicio.agregar_produ();
											break;
										case 2:
											inicio.ver_sumi();
											break;
										case 3:
											inicio_1.ver_cli();
											break;	
									}
								}while(eleccion != 4);
							}
							else{
								cout<<"No es miembro oficial"<<endl;
								break;
							}
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
