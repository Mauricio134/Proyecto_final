#include "Pedidos.h"

Pedidos::Pedidos(){
    id = " ";
    usuario = " ";
    contrasena = " ";
    dni = " ";
    telefono = " ";
    direccion = " ";
    tipo = " ";
    cantidad = 0;
    dia = " ";
    mes = " ";
    ano = " ";
	idaux = " ";
	cajas = 0;
	pasteles = 0;
    fresa = 0;
    coco = 0;
    circulo = 0;
    precio = 0.0;
    sum = 0;
    reg = nullptr;
	tamano = 0;
	auxano = "";
	auxmes = "";
}

Pedidos::~Pedidos(){
    if (reg != nullptr && tamano > 0){
        for (int o = 0; o < tamano; o++) {
            delete [] reg[o];
        }
        delete [] reg;
    }
}

int Pedidos::cont_ped(){
	system("cls");
    int i = 0;
    ifstream lectura;
    lectura.open("Pedidos.txt", ios::in);
    if (lectura.is_open())
    {
        getline(lectura, usuario);
        while (!lectura.eof())
        {
			i++;
			for (int k = 0; k < 12; k++){
                getline(lectura,direccion);
			}
			getline(lectura, usuario);
		}
	}
	lectura.close();
	return i;
}

void Pedidos::mostrar_pedidos(){
    system("cls");
	int i=0;
	int n = 0;
	tamano = cont_ped();
	reg=new string*[tamano];
    for(int i=0;i<tamano;i++){
        reg[i]=new string[13];
    }
    ifstream lectura("Pedidos.txt",ios::in);
    if(lectura.is_open())
    {
        cout << "================================================" << endl;
        cout << "||             LISTADO DE PEDIDOS             ||" << endl;
        cout << "================================================" << endl;
        lectura >> usuario;
        while(!lectura.eof())
        {
            i++;
            lectura.ignore(10000, '\n');
            getline(lectura,direccion);
            lectura >> telefono;
			lectura >> dia;
			lectura >> mes;
			lectura >> ano;
			lectura >> cantidad;
			lectura >> fresa;
            lectura >> coco;
            lectura >> circulo;
            lectura >> precio;
            lectura >> tipo;
            lectura >> id;
            reg [n][0] = usuario;
			reg [n][1] = direccion;
			reg [n][2] = telefono;
			reg [n][3] = dia;
			reg [n][4] = mes;
			reg [n][5] = ano;
			reg [n][6] = to_string(cantidad);
			reg [n][7] = to_string(fresa);
			reg [n][8] = to_string(coco);
			reg [n][9] = to_string(circulo);
			reg [n][10] = to_string(precio);
			reg [n][11] = tipo;
			reg [n][12] = id;
            n++;
            lectura >> usuario;
        }
        for (int n = 0; n<tamano ; n++){
            cout << "Id: " << reg [n][12] << endl;
            cout << "Usuario: " << reg [n][0] << endl;
            cout << "Direccion: " << reg [n][1] << endl;
            cout << "Telefono: " << reg [n][2] << endl;
            cout << "Fecha de Realizacion del Pedido: " << reg [n][3] << "/" << reg [n][4] << "/" << reg [n][5] << endl;
            cout << "Pedido: ";
            if (reg [n][11] == "Caja"){
                cout << reg [n][6] << " cajas." << endl;
                cout << "<===== Contenido de la caja =====>" << endl;
                cout << "Pasteles de Fresa: " << reg [n][7] << " pasteles" << endl;
                cout << "Pasteles de Coco: " << reg [n][8] << " pasteles" << endl;
                cout << "Pasteles Circulares: " << reg [n][9] << " pasteles" << endl;
            }
            else if(reg [n][11] == "Pasteles"){
                cout << cantidad << " pasteles." << endl;
                cout << "<===== Tipos de pasteles =====>" << endl;
                cout << "Pasteles de Fresa: " << reg [n][7] << " pasteles" << endl;
                cout << "Pasteles de Coco: " << reg [n][8] << " pasteles" << endl;
                cout << "Pasteles Circulares: " << reg [n][9] << " pasteles" << endl;
            }
            cout << "Costo: " << "s/." << reg [n][10] << endl;
            cout << "--------------------------" << endl;
        }
        if(i==1){
            cout << "================================================" << endl;
            cout << "||        HAY SOLO 1 PEDIDO REGISTRADO        ||" << endl;
            cout << "================================================" << endl;
        }
        else{
            cout << "================================================" << endl;
            cout << "||         HAY " << tamano << " PEDIDOS REGISTRADOS          ||" << endl;
            cout << "================================================" << endl;
        }
        lectura.close();
        system("pause");
    }
    else
    {
        cout << "================================================" << endl;
        cout << "||              NO HAY PEDIDOS                ||" << endl;
        cout << "================================================" << endl;
        lectura.close();
        system("pause");
    }
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
    ofstream Pedido_in("Pedidos.txt", ios::out | ios::app);

    Cli_lec>>contrasena;
    while(!Cli_lec.eof()){
        Cli_lec>>usuario;
        Cli_lec.ignore(10000, '\n');
        getline(Cli_lec,direccion);
        Cli_lec>>telefono;
        Cli_lec>>dni;
        if (dni == dniaux){
            cout << "================================================" << endl;
            cout << "||                   PEDIDO                   ||" << endl;
            cout << "================================================" << endl;
            int op;
            op = Caja_o_personal();
            do{
                switch(op){
                    case 1:
                        system("cls");
                        cout << "Colocar el id: ";
                        cin >> id;
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
                        cout << "Colocar el id: ";
                        cin >> id;
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
            Pedido_in << id << endl;
            system("cls");
            cout << "================================================" << endl;
            cout << "||                   PEDIDO                   ||" << endl;
            cout << "================================================" << endl;
            cout << "Id: " << id << endl;
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
                cout << "<------Tipos de pasteles------>" << endl;
                cout << "Pasteles de Fresa: " << fresa << " pasteles" << endl;
                cout << "Pasteles de Coco: " << coco << " pasteles" << endl;
                cout << "Pasteles Circulares: " << circulo << " pasteles" << endl;
            }
            cout << "Costo: " << "s/." << precio << endl;
        }
        Cli_lec>>contrasena;
    }
    Cli_lec.close();
    system("pause");
}
void Pedidos::eliminar_pedido(){
	system("cls");
    ifstream Lect("Pedidos.txt", ios::in);
    ofstream aux("Auxiliar.txt", ios::out);
    if (Lect.is_open()) {
        cout << "Colocar ID: "<<endl;;
        cin >> idaux;
        Lect >> usuario;
        while (!Lect.eof()) {
            Lect.ignore(10000, '\n');
            getline(Lect,direccion);
            Lect >> telefono;
			Lect >> dia;
			Lect >> mes;
			Lect >> ano;
			Lect >> cantidad;
			Lect >> fresa;
            Lect >> coco;
            Lect >> circulo;
            Lect >> precio;
            Lect >> tipo;
            Lect >> id;
            if (id == idaux)  {
                cout << "================================================" << endl;
                cout << "||                   PEDIDO                   ||" << endl;
                cout << "================================================" << endl;
                cout << "ID: " << id << endl;
				cout << "Usuario: " << usuario << endl;
				cout << "Direccion: " << direccion << endl;
				cout << "Telefono: " << telefono << endl;
				cout << "Fecha de Realizacion del Pedido: " << dia << "/" << mes << "/" << ano << endl;
                cout << "======================================================" << endl;
                cout << "||                REGISTRO ELIMINADO                ||" << endl;
                cout << "======================================================" << endl;
            }
            else {
                aux << usuario << endl;
                aux << direccion << endl;
                aux << telefono << endl;
                aux << dia << endl;
                aux << mes << endl;
                aux << ano << endl;
                aux << cantidad << endl;
                aux << fresa << endl;
                aux << coco << endl;
                aux << circulo << endl;
                aux << precio << endl;
                aux << tipo << endl;
                aux << id << endl;
            }
            Lect >> usuario;
        }
        Lect.close();
        aux.close();
    }
    else {
        cout << "Error" << endl;
    }

    remove("Pedidos.txt");
    rename("Auxiliar.txt", "Pedidos.txt");
    system("pause");
}

void Pedidos::reporte_mens() {
    system("cls");
    int i = 0;
    ifstream lectura;
    lectura.open("Pedidos.txt", ios::in);
    if (lectura.is_open())
    {
        cout << "Ingrese la anualidad de cual desea el reporte: " << endl;
        cin >> auxano;
        cout << "Ingrese el mes del cual desea el reporte: " << endl;
        cin >> auxmes;
        system("cls");
        cout << "======================================================" << endl;
        cout << "||                  REPORTE MENSUAL                 ||" << endl;
        cout << "======================================================" << endl;
        lectura >> usuario;
        while (!lectura.eof())
        {
            lectura.ignore(10000, '\n');
            getline(lectura,direccion);
            lectura >> telefono;
			lectura >> dia;
			lectura >> mes;
			lectura >> ano;
			lectura >> cantidad;
			lectura >> fresa;
            lectura >> coco;
            lectura >> circulo;
            lectura >> precio;
            lectura >> tipo;
            lectura >> id;

            if (auxmes == mes && auxano == ano) {
                cout << "Usuario: " << usuario << " Dia: " << dia << " Mes: " << mes << " Precio: " << "s/." << precio << endl;
                i += precio;
            }
            lectura >> usuario;
        }
        cout << "\n";
        cout << "--------------------------" << endl;
        cout << "Ventas del mes: " << "s/." << i << endl;
        cout << "--------------------------" << endl;

    }
    else
    {
        cout << "================================================" << endl;
        cout << "||              NO HAY PEDIDOS                ||" << endl;
        cout << "================================================" << endl;
    }
    lectura.close();
    system("pause");
}
