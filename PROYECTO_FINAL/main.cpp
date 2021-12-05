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
                    Cliente cli;
                    cout << "=========================================" << endl;
                    cout << "||           TIPO DE USUARIO           ||" << endl;
                    cout << "=========================================" << endl;
                    cout << "=========================================" << endl;
                    cout << "|| [1] Cliente                         ||" << endl;
                    cout << "|| [2] Retornar al Menu                ||"<< endl;
                    cout << "=========================================" << endl;
                    cout << "OPCION: ";
                    cin>> cliente_o_admin;

                    switch(cliente_o_admin){
						case 1:
							if (cli.registrarse_cli() == true){
                                error();
							}
							break;
					}
                }while(cliente_o_admin != 2);
                break;
        }
    }while(op != 3);
    return 0;
}
