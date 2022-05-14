/*
 ============================================================================
 Name        : TP2.c
 Author      : Pablo Vidal
 Version     :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"
#include "validaciones.h"

int main(void){
	setbuf(stdout, 0);
	int opcion;
	Passenger passList[CANT];
	initPassenger(passList);

	do{
		opcion = menuInt("1. Altas\n2. Modificar\n3. Baja\n4. Informar\n", 1, 4);

		switch(opcion){
			case 1:
				darDeAlta(passList);
			break;
			case 2:
				modificar(passList);
			break;
			case 3:
				darDeBaja(passList);
			break;
			case 4:
				informar(passList);
			break;
			default:{
				VERIFY_MSG
			}
		}
	}while(opcion != 5);

	return 0;
}
