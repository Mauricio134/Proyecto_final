#include "Pedidos.h"

Pedidos::Pedidos(){
    usuario = " ";
    contrasena = " ";
    dni = " ";
    telefono = " ";
    direccion = " ";
    cantidad = 0;
    dia = " ";
    mes = " ";
    ano = " ";
    cajas = 0;
    pasteles = 0;
    fresa = 0;
    coco = 0;
    circulo = 0;
    precio = 0.0;
    sum = 0;
}

void Pedidos::mostrar(){
    system("cls");
	int i=0;
    ifstream lectura;
    lectura.open("Pedidos.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Pedidos***\t\t\t\t\n\n";
        getline(lectura,dni);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,usuario);
            getline(lectura,direccion);
			getline(lectura,telefono);
			getline(lectura,dia);
			getline(lectura,mes);
			getline(lectura,ano);
			getline(lectura,tipo);
            getline(lectura,dni);
            cout<<"DNI: "<<usuario<<endl;
			cout<<"Direccion: "<<direccion<<endl;
			cout<<"Telefono: "<<telefono<<endl;
			cout<<"Dia: "<<dia<<endl;
			cout<<"Mes: "<<mes<<endl;
			cout<<"Ano: "<<ano<<endl;
			cout<<"Tipo de pedido: "<<tipo<<endl;
			cout<<"Tipo de pedido: "<<fresa<<endl;
			cout<<"Tipo de pedido: "<<coco<<endl;
			cout<<"Tipo de pedido: "<<circulo<<endl;
            cout << "--------------------------" << endl;
            getline(lectura,dni);
        }

        if(i==1){
            cout<<"Hay un solo pedido registrado \n\n";
        }
        else{
            cout<<"Hay un total de "<< i <<" pedidos registrados \n\n";
        }
    }
    else
    {
        cout << "No hay pedidos!!!" << endl;
    }
    lectura.close();
    system("pause");
}

void Pedidos::pasteles_opciones(){
    system("cls");
    cout << "Digitar cantidad de Pasteles de Fresa (por caja): " << endl;
    cin >> fresa;
    cout << "Digitar cantidad de Pasteles de Coco (por caja): " << endl;
    cin >> coco;
    cout << "Digitar cantidad de Pasteles Circulares (por caja): " << endl;
    cin >> circulo;
    return;
}

int Pedidos::Caja_o_personal(){
    int x;
    cout << "1) Elegir Por Cajas (20 pasteles por caja)" << endl;
    cout << "2) Elegir Cantidad en especifica" << endl;
    cout << "3) Cancelar Pedido" << endl;
    cin >> x;
    return x;
}

void Pedidos::registrar_pedido(string dniaux){
    system("cls");
    ifstream Cli_lec("clientes.txt", ios::in);
    ofstream Pedido_in("Pedidos.txt", ios::out|ios::app);

    Cli_lec>>contrasena;
    while(!Cli_lec.eof()){
        Cli_lec>>usuario;
        Cli_lec.ignore(10000, '\n');
        getline(Cli_lec,direccion);
        Cli_lec>>telefono;
        Cli_lec>>dni;
        if (dni == dniaux){
            cout << "<------Pedido------>" << endl;
            int op;
            op = Caja_o_personal();
            do{
                switch(op){
                    case 1:
                        system("cls");
                        cout << "Colocar cantidad de cajas: " << endl;
                        cin >> cantidad;
                        pasteles_opciones();
                        sum = fresa + coco + circulo;
                        cajas = 1;
                        if(sum > 20 || sum < 10){
                            system("cls");
                            cout << "La cantidad por caja es de 10 a 20 pasteles" << endl;
                            system("pause");
                        }
                        else{
                            op = 3;
                        }
                        break;
                    case 2:
                        system("cls");
                        cout << "Colocar cantidad de pasteles: " << endl;
                        cin >> cantidad;
                        pasteles_opciones();
                        pasteles = 1;
                        op = 3;
                        break;
                }
            }while(op != 3);
            cout << "Colocar el Dia de Realizacion del Pedido: ";
            cin >> dia;
            cout << "Colocar el Mes de Realizacion del Pedido (Enero = 01): ";
            cin >> mes;
            cout << "Colocar el Año de Realizacion del Pedido: ";
            cin >> ano;

            Pedido_in << usuario << endl;
            Pedido_in << direccion << endl;
            Pedido_in << telefono << endl;
            Pedido_in << dia << endl;
            Pedido_in << mes << endl;
            Pedido_in << ano << endl;
            Pedido_in << cantidad << endl;
            Pedido_in << fresa << endl;
            Pedido_in << coco << endl;
            Pedido_in << circulo << endl;
            if (cajas == 1){
                precio = sum*1.50;
                tipo = "Caja";
            }
            else if(pasteles == 1){
                precio = cantidad*1.5;
                tipo = "Pasteles";
            }
            Pedido_in << precio << endl;
            Pedido_in << tipo << endl;
            system("cls");
            cout << "<------Pedido------>" << endl;
            cout << "Usuario: " << usuario << endl;
            cout << "Direccion: " << direccion << endl;
            cout << "Telefono: " << telefono << endl;
            cout << "Fecha de Realizacion del Pedido: " << dia << "/" << mes << "/" << ano << endl;
            cout << "Pedido: ";
            if (cajas == 1){
                cout << cantidad << " cajas." << endl;
                cout << "<------Contenido de la caja------>" << endl;
                cout << "Pasteles de Fresa: " << fresa << " pasteles" << endl;
                cout << "Pasteles de Coco: " << coco << " pasteles" << endl;
                cout << "Pasteles Circulares: " << circulo << " pasteles" << endl;
            }
            else if(pasteles == 1){
                cout << cantidad << " pasteles." << endl;
            }
            cout << "Costo: " << "s/." << precio << endl;
        }
        Cli_lec>>contrasena;
    }
    Cli_lec.close();
    system("pause");
}
