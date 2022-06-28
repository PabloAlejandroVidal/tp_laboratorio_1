/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
#include "validate.h"
#include "math.h"


int Passenger_compararId(void* a,void* b){
	int ret;
	int id1;
	int id2;

	Passenger_getId((Passenger*)a, &id1);
	Passenger_getId((Passenger*)b, &id2);

	ret = numcmp(id1, id2);
	return ret;
}
int Passenger_compararPrecio(void* a,void* b){
	int ret;
	float precio1;
	float precio2;

	Passenger_getPrecio((Passenger*)a, &precio1);
	Passenger_getPrecio((Passenger*)b, &precio2);

	ret = numcmp(precio1, precio2);
	return ret;
}


int Passenger_compararNombre(void* a,void* b){
	int ret;
	char nombre1[20];
	char nombre2[20];

	Passenger_getNombre((Passenger*)a, nombre1);
	Passenger_getNombre((Passenger*)b, nombre2);
	ret = strcmp(nombre1, nombre2);

	return ret;
}

int Passenger_compararApellido(void* a,void* b){
	int ret;
	char apellido1[20];
	char apellido2[20];

	Passenger_getApellido((Passenger*)a, apellido1);
	Passenger_getApellido((Passenger*)b, apellido2);
	ret = stricmp(apellido1, apellido2);

	return ret;
}

int Passenger_compararTipoPasajero(void* a,void* b){
	int ret;
	char tipoPasajero1[21];
	char tipoPasajero2[21];

	Passenger_getTipoPasajero((Passenger*)a, tipoPasajero1);
	Passenger_getTipoPasajero((Passenger*)b, tipoPasajero2);

	ret = strcmp(tipoPasajero1, tipoPasajero2);
	return ret;
}

int Passenger_compararCodigoVuelo(void* a,void* b){
	int ret;
	char codigoVuelo1[21];
	char codigoVuelo2[21];

	Passenger_getCodigoVuelo((Passenger*)a, codigoVuelo1);
	Passenger_getCodigoVuelo((Passenger*)b, codigoVuelo2);

	ret = strcmp(codigoVuelo1, codigoVuelo2);
	return ret;
}

int Passenger_compararEstadoVuelo(void* a,void* b){
	int ret;
	char estadoVuelo1[21];
	char estadoVuelo2[21];

	Passenger_getEstadoVuelo((Passenger*)a, estadoVuelo1);
	Passenger_getEstadoVuelo((Passenger*)b, estadoVuelo2);

	ret = strcmp(estadoVuelo1, estadoVuelo2);
	return ret;
}



Passenger* Passenger_new(){
	Passenger* new;
	new = malloc(sizeof(Passenger));
	return new;
}

int Passenger_readId(){
	FILE* pFile;
	int id;
	pFile = fopen("id.bin", "r");
	fread(&id, sizeof(int), 1, pFile);
	id++;
	fclose(pFile);
	return id;
}

int Passenger_writeId(int newid){
	FILE* pFile;
	pFile = fopen("id.bin", "w");
	fwrite(&newid, sizeof(int), 1, pFile);
	fclose(pFile);
	return 0;
}

Passenger* Passenger_newParam(LinkedList* pArrayListPassenger, char* id, char* nombre, char* apellido, char* precio,
							char* codigoVuelo, char* tipoPasajero, char* estadoVuelo){
	Passenger* new;
	int ret;
	int i = 0;
	new = Passenger_new();
	ret = 0;

	for(i=0; i<7; i++){
		switch(i){
			case 0:
				ret = Passenger_setId(new, id);
			break;
			case 1:
				ret = Passenger_setNombre(new, nombre);
			break;
			case 2:
				ret = Passenger_setApellido(new, apellido);
			break;
			case 3:
				ret = Passenger_setPrecio(new, precio);
			break;
			case 4:
				ret = Passenger_setCodigoVuelo(new, codigoVuelo);
			break;
			case 5:
				ret = Passenger_setTipoPasajero(new, tipoPasajero);
			break;
			case 6:
				ret = Passenger_setEstadoVuelo(new, estadoVuelo);
			break;
		}
		if(ret != 0){
			free(new);
			new = NULL;
			break;
		}
	}
	return new;
}

int Passenger_setId(Passenger* this,char* id){
	int ret;
	ret = -1;
	if(this != NULL){
		this->id = atoi(id);
		ret = 0;
	}
	//return = 0 bien
	//return = -1 error
	return ret;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int ret;
	ret = -1;
	if(this != NULL){
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int ret;
	ret = -1;
	if(this != NULL){
		strcpy(this->apellido, apellido);
		ret = 0;
	}
	return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int ret;
	ret = -1;
	if(this != NULL){
		this->codigoVuelo = Passenger_validateCodigoVuelo(codigoVuelo);
		ret = 0;
	}
	return ret;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int ret;
	ret = -1;
	if(this != NULL){
		this->tipoPasajero = Passenger_validateTipoPasajero(tipoPasajero);
		ret = 0;
	}
	return ret;
}

int Passenger_setPrecio(Passenger* this,char* precio){
	int ret;
	ret = -1;
	if(this != NULL){
		this->precio = atof(precio);
		ret = 0;
	}
	return ret;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo){
	int ret;
	ret = -1;
	if(this != NULL){
		//obtengo el id del estado de vuelo
		this->statusFlight = Passenger_validateEstadoVuelo(estadoVuelo);
		ret = 0;
	}
	return ret;
}




int Passenger_validateId(LinkedList* pListPassenger,char* id){
	int ret, sign;
	Passenger* pFound;
	ret = -1;
	sign = 0;

	if(pListPassenger != NULL && id != NULL){
		sign = isNumeric(id);
		if(sign == 1){
			pFound = Passenger_search(pListPassenger, atoi(id));
			if(pFound == NULL){
					ret = 0;
				}else{
					ret = -3;
				}
		}else{
			ret = -2;
		}
	}
	//return = 0 bien
	//return = -1 error
	//return = -2 id no valido
	//return = -3 id en uso
	return ret;
}

int Passenger_validateNombre(char* nombre){
	int ret, len;
	ret = -1;
	len = 0;

	if(nombre != NULL){
		if(isAlphaString(nombre)){
			len = strlen(nombre);
			if(len > 0 && len < 20){
				ret = 0;
			}else{
				ret = -3;
			}
		}else{
			ret = -2;
		}
	}
	//return = 0 bien
	//return = -1 error
	//return = -2 caracteres invalidos
	//return = -3 tamanio incorrecto
	return ret;
}



int Passenger_validateCodigoVuelo(char* flightCode){
	Flycode pass[8] = {{1,"BA2491A", 1}, {2,"IB0800A", 1}, {3,"MM0987B", 2}, {4, "TU6789B", 1}, {5,"GU2345F", 3}, {6,"HY4567D", 4}, {7,"FR5678G", 2}, {8,"BR3456J", 4}};
	int ret = -1;
	if(flightCode != NULL){
		for(int i = 0; i< 8; i++){
			if(strcmp(pass[i].codigoVuelo, flightCode) == 0){
				ret = pass[i].id;
				break;
			}
		}
	}
	//return = 0 id no encontrado
	//return = -1 error
	// return > 0 es el id
	return ret;
}

int Passenger_validateTipoPasajero(char* tipoPasajero){
	Typepassenger type[4] = {{1, "FirstClass"}, {2, "ExecutiveClass"}, {3, "EconomyClass"}};
	int ret;
	ret = -1;

	if(tipoPasajero != NULL){
		ret = -2;
		for(int i=0; i<3; i++){
			if(strcmp(tipoPasajero, type[i].tipoPasajero) == 0){
				ret = type[i].id;
				break;
			}
		}
	}
	//return -1 error
	//return > 0 id tipo pasajero
	return ret;
}

int Passenger_validateEstadoVuelo(char* estadoVuelo){

	StatusFlight estados[4] = {{1, "Aterrizado"}, {2, "En Horario"}, {3, "En Vuelo"}, {4, "Demorado"}};

	int ret;
	ret = -1;

	if(estadoVuelo != NULL){
		for(int i=0; i<4; i++){
			if(strcmp(estadoVuelo, estados[i].estadoVuelo) == 0){
				ret = estados[i].id;
				break;
			}
		}
	}
	//return -1 error
	//return > 0 id status flight
	return ret;
}

int Passenger_validatePrecio(char* precio){
	int ret, num;
	ret = -1;
	num = 0;
	if(precio != NULL){
		num = isNumeric(precio);
	}
	if(num > 0){
		ret = 0;
	}else{
		ret = -2;
	}
	return ret;
}

///
///
///

int Passenger_getId(Passenger* this, int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		ret = 0;
	}
	return ret;
}


int Passenger_getNombre(Passenger* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int ret = -1;
	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		ret = 0;
	}
	return ret;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int ret = -1;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
	}
	return ret;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int ret = -1;
	if(this != NULL && codigoVuelo != NULL){
		codigoVueloToString(codigoVuelo, this->codigoVuelo);
	}
	return ret;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int ret = -1;
	if(this != NULL && tipoPasajero != NULL){
		tipoPasajeroToString(tipoPasajero, this->tipoPasajero);
		ret = 0;
	}
	return ret;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){
	int ret = -1;
	if(this != NULL && estadoVuelo != NULL){
		estadoVueloToString(estadoVuelo, this->statusFlight);
		ret = 0;
	}
	return ret;
}

///
///
///

int codigoVueloToString(char* codigoVuelo, int codigoVueloInt){
	Flycode pass[8] = {{1,"BA2491A", 1}, {2,"IB0800A", 1}, {3,"MM0987B", 2}, {4, "TU6789B", 1}, {5,"GU2345F", 3}, {6,"HY4567D", 4}, {7,"FR5678G", 2}, {8,"BR3456J", 4}};
	int ret = -1;
	if(codigoVuelo != NULL){
		ret = 0;
		for(int i = 0; i< 8; i++){
			if(codigoVueloInt == pass[i].id){
				strcpy(codigoVuelo, pass[i].codigoVuelo);
				ret = codigoVueloInt;
				break;
			}
		}
	}

	return ret;
}

int tipoPasajeroToString(char* tipoPasajero, int tipoPasajeroInt){
	Typepassenger type[3] = {{1, "FirstClass"}, {2, "ExecutiveClass"}, {3, "EconomyClass"}};
	int ret;
	ret = -1;
	if(tipoPasajero != NULL){
		ret = 0;
		for(int i=0; i<3; i++){
			if(tipoPasajeroInt == type[i].id){
				strcpy(tipoPasajero, type[i].tipoPasajero);
				ret = tipoPasajeroInt;
				break;
			}
		}
	}
	//return -1 error
	//return > 0 id tipo pasajero
	return ret;
}

int estadoVueloToString(char* estadoVuelo, int estadoVueloInt){
	StatusFlight status[4] = {{1, "Aterrizado"}, {2, "En Horario"}, {3, "En Vuelo"}, {4, "Demorado"}};
	int ret;
	ret = -1;
	if(estadoVuelo != NULL){
		ret = 0;
		for(int i=0; i<4; i++){
			if(estadoVueloInt == status[i].id){
				strcpy(estadoVuelo, status[i].estadoVuelo);
				ret = estadoVueloInt;
				break;
			}
		}
	}
	//return -1 error
	//return > 0 id tipo pasajero
	return ret;
}

int codigoVueloToEstadoVuelo(char* codigo){
	Flycode pass[8] = {{1,"BA2491A", 1}, {2,"IB0800A", 1}, {3,"MM0987B", 2}, {4, "TU6789B", 1}, {5,"GU2345F", 3}, {6,"HY4567D", 4}, {7,"FR5678G", 2}, {8,"BR3456J", 4}};
	int ret = -1;
	if(codigo != NULL){
		ret = 0;
		for(int i=0; i<8; i++){
			if(strcmp(pass[i].codigoVuelo, codigo) == 0){
				ret = pass[i].statusFlight;
				break;
			}
		}
	}
	return ret;
}


Passenger* Passenger_search(LinkedList* pListPassenger, int id){
	Passenger *pPass, *pRet;
	int len, i;

	pRet = NULL;
	len = ll_len(pListPassenger);

	for(i=0; i<len; i++){
		pPass = ll_get(pListPassenger, i);
		if(pPass->id == id){
			pRet = pPass;
			break;
		}
	}
	return pRet;
}

void listarFlightCode(){
	char string[20];
	printf(
			" ______________________\n"
			"|___Codigos De Vuelo___|\n");
	for(int i = 0; i<8; i++){
		codigoVueloToString(string, i+1);
		printf("|%14s        |\n", string);
	}
	printf("|______________________|\n");
}

void listarTypePass(){
	char string[20];
	printf(
			" ______________________\n"
			"|___Tipo de Pasajero___|\n");
	for(int i = 0; i<3; i++){
		tipoPasajeroToString(string, i+1);
		printf("|    %-18s|\n", string);
	}
	printf("|______________________|\n");
}
