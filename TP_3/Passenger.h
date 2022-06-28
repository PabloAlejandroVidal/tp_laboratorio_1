/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	int codigoVuelo;
	int statusFlight;
}Passenger;

typedef struct
{
	int id;
	char codigoVuelo[20];
	int statusFlight;
}Flycode;

typedef struct
{
	int id;
	char tipoPasajero[20];
}Typepassenger;

typedef struct
{
	int id;
	char estadoVuelo[20];
}StatusFlight;



int Passenger_compararId(void* a,void* b);
int Passenger_compararPrecio(void* a,void* b);
int Passenger_compararNombre(void* a,void* b);
int Passenger_compararApellido(void* a,void* b);
int Passenger_compararTipoPasajero(void* a,void* b);
int Passenger_compararCodigoVuelo(void* a,void* b);
int Passenger_compararEstadoVuelo(void* a,void* b);

Passenger* Passenger_new();
Passenger* Passenger_newParam(LinkedList* pArrayListPassenger, char* id, char* nombre, char* apellido, char* precio,
			char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);
//Passenger* Passenger_newNombre(LinkedList* pArrayListPassenger, char* nombre);

void Passenger_delete();

int Passenger_setId(Passenger* this,char* id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

//agregados

Passenger* Passenger_search(LinkedList* pListPassenger, int id);

int Passenger_readId();
int Passenger_writeId(int newid);

int Passenger_validateNombre(char* nombre);
int Passenger_validateId(LinkedList* pListPassenger,char* id);
int Passenger_validatePrecio(char* precio);
int Passenger_validateCodigoVuelo(char* flightCode);
int Passenger_validateTipoPasajero(char* tipoPasajero);
int Passenger_validateEstadoVuelo(char* estadoVuelo);

int codigoVueloToEstadoVuelo(char* codigo);

int tipoPasajeroToString(char* tipoPasajero, int tipoPasajeroInt);
int codigoVueloToString(char* codigoVuelo, int codigoVueloInt);
int estadoVueloToString(char* estadoVuelo, int estadoVueloInt);

void listarFlightCode();
void listarTypePass();

#endif /* PASSENGER_H_ */
