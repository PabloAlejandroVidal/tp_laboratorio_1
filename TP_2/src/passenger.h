/**
 * passenger.h
 *
 *  Created on: May 8, 2022
 *      Author: Vidal Pablo
 **/

#ifndef PASSENGER_H_
#define PASSENGER_H_

struct{
int id;
char name[51];
char lastName[51];
float price;
int flycode;
int typePassenger;
int isEmpty;
}typedef Passenger;

struct{
int id;
char code[51];
int status;
}typedef FlightCode;

struct{
int id;
char status[51];
}typedef StatusFlight;

struct{
int id;
char type[51];
}typedef PassengerType;

#define CANT 2000
#define STRLEN 51
#define VERIFY_MSG printf("Verifique el dato ingresado\n");
#define EXIT_MSG printf("Programa finalizado\n");

int searchById(int id, Passenger list[]);

int searchByIsEmpty(int estado, Passenger list[]);

FlightCode cargarFlightCode(int id);

StatusFlight cargarStatusFlight(int id);

PassengerType cargarPassengerType(int id);

int sortPassenger(Passenger list[], int order);

int sortPassengerByStatusFlight(Passenger list[], int order);

int mostrarPrecios(Passenger list[]);

int printPassengers(Passenger list[], int filtro);

int informar(Passenger list[]);

int removePassenger(Passenger list[], int index);

void darDeBaja(Passenger list[]);

void modificar(Passenger list[]);

int addPassenger(Passenger* list, int len, int index, int id, char name[],char
lastName[],float price,int typePassenger, int flycode);

int darDeAlta(Passenger list[]);

int initPassenger(Passenger list[]);

#endif /* PASSENGER_H_ */
