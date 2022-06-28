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
    int lastid;
    int opened;
    int edited;
    option = 0;
    optionb = 0;
    lastid = 0;
    opened = 0;
    edited = 0;
    listaPasajeros = ll_newLinkedList();
    lastid = Passenger_readId();
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
            	if(opened == 0){
					controller_loadFromText("data.csv", listaPasajeros);
					opened = 1;
            	}else{
            		printf("Ya se ha cargado un archivo anteriormente\n");
            	}
                break;
            case 2:
            	if(opened == 0){
					controller_loadFromBinary("data.bin", listaPasajeros);
					opened = 1;
            	}else{
            		printf("Ya se ha cargado un archivo anteriormente\n");
            	}
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros, &lastid);
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
            case 9:
            	controller_saveAsText("data.csv", listaPasajeros);
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	edited = 0;
            	break;
            case 10:
				if(edited == 1){
					do{

						printf("Estas a punto de salir sin haber guardado los cambios\n");
						optionb = menu(
								"    ________________________________________________ \n"
								"   |_______________Finalizar Programa_______________|\n"
								" 1 | Guardar y salir                                |\n"
								" 2 | volver al menu anterior                        |\n"
								"10 |_Salir sin guardar______________________________|\n");

						switch(optionb){
						case 1:
								controller_saveAsText("data.csv", listaPasajeros);
								controller_saveAsBinary("data.bin", listaPasajeros);
								edited = 0;
								optionb = 2;
							break;
						case 2:
							option = 0;
							break;
						case 10:
							edited = 0;
							optionb = 2;
							break;
						}
					}while(optionb != 2);
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

