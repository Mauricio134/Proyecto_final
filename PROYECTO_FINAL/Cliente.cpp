#include "Cliente.h"

Cliente::Cliente(){

}

void Cliente::Login(){
    system("cls");
    log.loguearse_cli();
}

void Cliente::Eliminar_registro(){
    system("cls");
    log.eliminar();
}
