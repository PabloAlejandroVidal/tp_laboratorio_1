/**
 * ingresos.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Vidal Pablo
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "validate.h"
#include "ingresos.h"

void ingresar_nombre(int* validate, char* nombre){
	printf("Ingresar nombre\n");
	getString(nombre, 50);
	*validate = Passenger_validateNombre(nombre);
	switch(*validate){
	case -1:
		printf("Error inesperado\n");
		break;
	case -2:
		printf("Debes ingresar caracteres validos para el nombre\n");
		break;
	case -3:
		printf("Verifica el largo del nombre\n");
		break;
	}
}

void ingresar_apellido(int* validate, char* apellido){
	printf("Ingresar apellido\n");
	getString(apellido, 50);
	*validate = Passenger_validateNombre(apellido);
	switch(*validate){
	case -1:
		printf("Error inesperado\n");
		break;
	case -2:
		printf("Debes ingresar caracteres validos para el apellido\n");
		break;
	case -3:
		printf("Verifica el largo del apellido\n");
		break;
	}
}

void ingresar_precio(int* validate, char* precio){
	printf("Ingresar precio\n");
	getString(precio, 12);
	*validate = Passenger_validatePrecio(precio);
	switch(*validate){
	case -1:
		printf("Error inesperado\n");
		break;
	case -2:
		printf("El precio ingresado no es valido\n");
		break;
	}
}

void ingresar_codigoVuelo(int* validate, char* flyCode){
printf("Ingresar codigo de vuelo\n");
	listarFlightCode();
	getString(flyCode, 7);
	*validate = Passenger_validateCodigoVuelo(flyCode);
	switch(*validate){
	case 0:
		printf("El codigo ingresado no esta disponible\n");
		break;
	case -1:
		printf("Error\n");
		break;
	default:
		*validate = 0;
		break;
	}
}

void ingresar_tipoPasajero(int* validate, char* typePassenger){
	printf("Ingresar tipo de pasajero\n");
	listarTypePass();
	getString(typePassenger, 20);
	*validate = Passenger_validateTipoPasajero(typePassenger);
	switch(*validate){
	case -1:
		printf("Error inesperado\n");
		break;
	case -2:
		printf("El Codigo ingresado no es valido\n");
		break;
	default:
		*validate = 0;
		break;
	}
}
