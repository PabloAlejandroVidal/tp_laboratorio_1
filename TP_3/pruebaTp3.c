#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "validate.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main(){
	setbuf(stdout, 0);
    int option;
    int optionb;
    LinkedList* listaPasajeros;
    int openMode;
    int idaux;
    int edited;
    option = 0;
    optionb = 0;
    openMode = 0;
    idaux = 0;
    edited = 0;
    listaPasajeros = ll_newLinkedList();

    do{
    	option = menu(
    			"    ________________________________________________ \n"
    			"   |______________________MENU______________________|\n"
    			" 1 | Cargar archivo (modo texto)                    |\n"
    			" 2 | Cargar archivo (modo binario)                  |\n"
    			" 3 | Alta de pasajero                               |\n"
    			" 4 | Modificar datos de pasajero                    |\n"
    			" 5 | Baja de pasajero                               |\n"
    			" 6 | Listar pasajeros                               |\n"
    			" 7 | Ordenar pasajeros                              |\n"
    			" 8 | Guardar registros en archivo (modo texto)      |\n"
    			" 9 | Guardar registros en archivo (modo binario)    |\n"
    			"10 |_Salir__________________________________________|\n");

        switch(option)
        {
			case 0:
				break;
			case 1:
            	if(openMode == 0){
					controller_loadFromText("data.csv", listaPasajeros);
					openMode = 1;
            	}else{
            		printf("Ya se ha cargado un archivo anteriormente\n");
            	}
                break;
            case 2:
            	if(openMode == 0){
					controller_loadFromBinary("data.bin", listaPasajeros);
					openMode = 2;
            	}else{
            		printf("Ya se ha cargado un archivo anteriormente\n");
            	}
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros, &idaux);
            	edited = 1;
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	edited = 1;
            	break;
            case 5:
            	controller_removePassenger(listaPasajeros);
            	edited = 1;
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
            	if(openMode == 1){
            		controller_saveAsText("data.csv", listaPasajeros);
            	}else{
            		printf("Para guardar como texto, debe ser abierto en modo texto\n");
            	}
            	break;
            case 9:
            	if(edited == 0){
            		controller_saveAsBinary("data.bin", listaPasajeros);
            	}else{
            		printf("No puedes guardar los datos abiertos como binario una vez modificados\n");
            	}
            	break;
            case 10:
				while(optionb != 2){

					if(edited == 1){
						printf("Estas a punto de salir sin haber guardado los cambios\n");
						optionb = menu(
								"    ________________________________________________ \n"
								"   |_______________Finalizar Programa_______________|\n"
								" 1 | Guardar y salir                                |\n"
								" 2 | volver al menu anterior                        |\n"
								"10 |_Salir sin guardar______________________________|\n");

						switch(optionb){
						case 1:
							if(openMode == 1){
								controller_saveAsText("data.csv", listaPasajeros);
							}else{
								if(openMode == 2){
									controller_saveAsBinary("data.bin", listaPasajeros);
								}
								edited = 0;
								optionb = 2;
								option = 10;
							}
							break;
						case 2:
							option = 0;
							break;
						case 10:
							edited = 0;
							optionb = 2;
							break;
						}
					}
				optionb = 2;
				}
				break;
            default:
            	printf("El numero ingresado no es una opcion valida\n");
            	break;
        }
    }while(option != 10);
    printf("Programa finalizado\n");
    return 0;
}

