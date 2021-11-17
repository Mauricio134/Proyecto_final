#include "Suministros.h"

Suministros::Suministros(){
    id = "";
    tipo = "";
    marca = "";
    precio = "";
    cantidad = "";
}

bool Suministros::agregar_produ(){
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
        cout<<"Ingresa el precio unitario del Suministro: ";
        getline(cin,precio);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la cantidad del Suministro: ";
        getline(cin,cantidad);
        cout<<"\n\n";

        escritura <<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidad<<"\n";

        cout<<"El registro se ha completado correctamente." << endl;
        escritura.close();
        verificador.close();
        system("pause");
        return false;
    }

    else
    {
        escritura.close();
        verificador.close();
        return true;
    }
}

bool Suministros::ver_sumi(){
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
            cout<<"Id: "<<id<<"\t";
            cout<<"Nombre: "<<tipo<<"\t";
			cout<<"Marca: "<<marca<<"\t";
			cout<<"Precio: S/"<<precio<<"\t";
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"\n\n";
            getline(lectura,id);
        }

        if(i==1){
            cout<<"Hay un solo suministro registrado en este almacen\n\n";
        }
        else{
            cout<<"Hay un total de "<< i <<" suministros registrados en este almacen\n\n";
        }
        lectura.close();
        system("pause");
        return false;
    }
    else
    {
        lectura.close();
        return true;
    }
}

void Suministros::mod_sumi(){
	system ("cls");
	string idaux;
	string cantidadaux;
	ifstream lec("suministros.txt",ios::in);
	ofstream aux("auxiliar.txt", ios::out|ios::app);
	if (lec.is_open()){
		cout << "Ingrese el id del suministro que desea modificar" << endl;
		cin >> idaux;
		lec >> id;
		lec.seekg(0);
		getline(lec,id);
		while (!lec.eof()){
			getline(lec,tipo);
			getline(lec,marca);
			getline(lec,precio);
            getline(lec,cantidad);

			if (id == idaux){
				cout << "digite la nueva cantidad" <<endl;
				cin >> cantidadaux;
				aux<<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidadaux<<"\n";
			}
			else{
				aux<<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidad<<"\n";
			}
			getline(lec,id);
		}
		lec.close();
		aux.close();
	}
	else{
		cout << "Error" << endl;
	}
	remove("suministros.txt");
	rename("auxiliar.txt", "suministros.txt");
	system("pause");
}

void Suministros::mod_sumi(){
	system ("cls");
	string idaux;
	string cantidadaux
	ifstream lec;
	lec.open("suministros.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if (lec.is_open()){
		cout << "Ingrese el id del suministro que desea modificar" << endl;
		cin >> idaux;
		lec >> id;
		lec.seekg(0);
		getline(lec,id);
		while (!lec.eof()){
			getline(lec,tipo);
			getline(lec,marca);
			getline(lec,precio);
            getline(lec,cantidad);
			
			if (id== idaux){
				cout << "digite la nueva cantidad" <<endl;
				cin >> cantidadaux;
				aux<<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidadaux<<"\n";
			}
			else{
				aux<<id<<"\n"<<tipo<<"\n"<<marca<<"\n"<<precio<<"\n"<<cantidad<<"\n";
			}
			getline(lec,id);	
		}
		lec.close;
		aux.close;
	}
	else{
		error();
	}
	remove ("suministros.txt");
	rename ("auxiliar.txt", "suministros.txt")
}