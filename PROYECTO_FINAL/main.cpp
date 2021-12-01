#include "Funcion.h"
#include "Usuario.h"
#include "Admin.h"
#include "Cliente.h"
#include "Suministros.h"

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
                    Usuario usu;
                    Administrador admin;
                    Cliente cli;
                    op2 = usu.menu_usu();
                    switch(op2){
                        case 1:
							admin.loguearse_admin();
                            break;
                        case 2:
                            cli.loguearse_cli();
                            break;
                    }
                }while(op2 != 3);
                break;
            case 2:
                system("cls");
                int cliente_o_admin;
                do{
                    system("cls");
                    Administrador admin;
                    Cliente cli;
                    cout << "<<-------Tipo de Usuario------->>" << endl;
                    cout << "1. Administrador" << endl;
                    cout << "2. Cliente" << endl;
                    cout << "3. Retornar al Menu"<< endl;
                    cout<<"Opcion: ";
                    cin>> cliente_o_admin;
                    switch(cliente_o_admin){
						case 1:
							if(admin.registrarse_admin() == true){
                                error();
							}
							break;
						case 2:
							if (cli.registrarse_cli() == true){
                                error();
							}
							break;
					}
                }while(cliente_o_admin != 3);
                break;
        }
    }while(op != 3);
    return 0;
}
