/**
 * passenger.c
 *
 *  Created on: May 8, 2022
 *      Author: Vidal Pablo
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "passenger.h"

int searchById(int id, Passenger list[]){
	int indice;
	indice = buscarIntVector(&list[0].id, &list[1].id, CANT, id);
	return indice;
}

int searchByIsEmpty(int estado, Passenger list[]){
	int indice;
	indice = buscarIntVector(&list[0].isEmpty, &list[1].isEmpty, CANT, estado);
	return indice;
}

int cargarFlightCode(FlightCode* codeList){

	int i;
	FlightCode new[5] = {
			{1, "AB-123", 1}, {2, "ZX-899", 2}, {3, "RX-500", 3}, {4, "PP-101", 1}, {5, "FD-022", 2}
	};
	for(i = 0; i < 5; i ++){
		codeList[i].id = new[i].id;
		strcpy(codeList[i].code, new[i].code);
		codeList[i].status = new[i].status;

	}
	return 0;
}

int cargarStatusFlight(StatusFlight* statusList){
	int i;
	StatusFlight new[CARGA_STATUS] = {
			{1, "ACTIVO"}, {2, "DEMORADO"}, {3, "CANCELADO"}
	};

	for(i = 0; i < 3; i ++){
		statusList[i].id = new[i].id;
		strcpy(statusList[i].status, new[i].status);
	}

	return 0;
}

int cargarPassengerType(PassengerType* classList){
	int i;
	PassengerType new[CARGA_TYPE] = {
			{1, "PRIMERA"}, {2, "EJECUTIVA"}, {3, "PREMIUM"}, {4, "TURISTA"}
	};
	for(i = 0; i < 3; i ++){
		classList[i].id = new[i].id;
		strcpy(classList[i].type, new[i].type);
	}
	return 0;
}

int sortPassenger(Passenger list[], int order){
	int i, j;
	Passenger aux;
	if(order == 1){
		for(i = 1; i < CANT; i++){
			for(j = 0; j < i; j++){
				if(strcmp(list[i].lastName, list[j].lastName) < 0){
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}else{
					if(strcmp(list[i].lastName, list[j].lastName) == 0){
						if(list[i].typePassenger > list[j].typePassenger){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}else{
		for(i = 1; i < CANT; i++){
			for(j = 0; j < i; j++){
				if(strcmp(list[i].lastName, list[j].lastName) > 0){
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}else{
					if(strcmp(list[i].lastName, list[j].lastName) == 0){
						if(list[i].typePassenger < list[j].typePassenger){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}
	return 0;
}

int sortPassengerByStatusFlight(Passenger list[], int order){
		int i, j;
		Passenger aux;
		if(order == 1){
			for(i = 1; i < CANT; i++){
				for(j = 0; j < i; j++){
					if(list[i].flycode < list[j].flycode){
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}else{
			for(i = 1; i < CANT; i++){
				for(j = 0; j < i; j++){
					if(list[i].flycode > list[j].flycode){
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}

	return 0;
}
int mostrarPrecios(Passenger list[]){
	float precioTotal = 0;
	int cant = 0;
	float promedio;
	int cantMayorPromedio = 0;
	int i;

	for(i = 0; i < CANT; i++){
		if(list[i].isEmpty == 0){
			precioTotal += list[i].price;
			cant ++;
		}
	}
	if(cant > 0){
		promedio = promediar(precioTotal, cant);
		for(i = 0; i < CANT; i++){
				if(list[i].isEmpty == 0){
					if(list[i].price > promedio){
						cantMayorPromedio ++;
					}
				}
			}
		printf("La suma de los precios de vuelo de los %d pasajes es %.2f\n",cant, precioTotal);
		printf("El promedio del precio de los vuelos es %.2f\n", promedio);
		printf("La cantidad de pasajes que superan el promedio es %d\n", cantMayorPromedio);

	}

	return 0;
}

int printPassengers(Passenger list[], int filtro, FlightCode code[]){
	StatusFlight status[CARGA_STATUS];
	PassengerType type[CARGA_TYPE];
	cargarStatusFlight(status);
	cargarPassengerType(type);
	int i;
	int auxCode;
	int auxType;
	int auxStatus;
	if(filtro == 0){
		printf("%42s\n","Lista de pasajeros");
	}else{
		printf("%42s\n","Lista de pasajeros con estado de vuelo activo");
	}
	printf(" _____________________________________________________________________________________________________\n");
	printf("| %-15s| %-15s| %-15s| %-15s| %-15s| %-15s|\n","NOMBRE", "APELLIDO","CLASE", "ESTADO", "PRECIO", "VUELO");
	printf("+----------------+----------------+----------------+----------------+----------------+----------------+\n");
	for(i=0; i< CANT; i++){
		if(list[i].isEmpty == 0){
			auxCode = (list[i].flycode -1);
			auxType = (list[i].typePassenger -1);
			auxStatus = (code[auxCode].status -1);
			if(code[auxCode].status == 1 || filtro == 0){
			printf("+----------------+----------------+----------------+----------------+----------------+----------------+\n");
			printf("| %-15s| %-15s| %-15s| %-15s| %-15.2f| %-15s|\n", list[i].name, list[i].lastName,
					type[auxType].type, status[auxStatus].status, list[i].price, code[auxCode].code);
			}
		}
	}
	printf("+________________+________________+________________+________________+________________+________________+\n");

	return 0;
}

int informar(Passenger list[], FlightCode codeList[]){
	int index;
	int opcion, orden;
	index = searchByIsEmpty(0, list);

	if(index > -1){
		opcion = menuInt("\n1. Listar por nombre\n2. Mostrar precios\n3. Listar por estado de vuelo\n", 1, 3);
		switch(opcion){
		case 1:
			orden = menuInt("\n1. Orden ascendente\n2. Orden descendente\n", 1, 2);
			sortPassenger(list, orden);
			printPassengers(list, 1, codeList);
			break;
		case 2:
			mostrarPrecios(list);
			break;
		case 3:
			orden = menuInt("\n1. Orden ascendente\n2. Orden descendente\n", 1, 2);
			sortPassengerByStatusFlight(list, orden);
			printPassengers(list, 0, codeList);
			break;
		}
	}
		else{
		printf("No hay pasajeros para mostrar\n");
	}
	return 0;
}

int removePassenger(Passenger list[], int index){
	int opcion;
	int ret = -1;
	if(list[index].isEmpty == 0 && index > -1){
		printf("Confirma la baja del pasajero %s con ID %d?\n", list[index].name, list[index].id);
		opcion = menuInt("1. Aceptar\n2. Cancelar\n", 1, 2);
		if(opcion == 1){
			list[index].isEmpty = -1;
			ret = 0;
		}
	}
	return ret;
}

void darDeBaja(Passenger list[]){
	int estado;
	int id;
	int indice;
	int isRemoved = -1;
	estado = searchByIsEmpty(0, list);
	if(estado == -1){
		printf("No hay pasajeros para dar de baja\n");
	}else{
		getInt(&id, "Ingrese el id del pasajero que quiera dar de baja\n", 1, CANT);
		indice = searchById(id, list);
		isRemoved = removePassenger(list, indice);
		if(isRemoved != -1){
			printf("Se dio de baja pasajero con id %d\n", id);
		}
		else{
			printf("No se encontro ningun pasajero con id %d\n", id);
		}
	}
}

void modificar(Passenger list[]){
	int estado;
	int id;
	int indice;
	int opcion;
	Passenger aux;
	estado = searchByIsEmpty(0, list);
	if(estado == -1){
		printf("No hay pasajeros para modificar\n");
	}
	else{
		getInt(&id, "Ingrese el id del pasajero que quiere modificar\n", 1, CANT);
		indice = searchById(id, list);
		if(list[indice].isEmpty == 0 && indice > -1){
			do{
			opcion = menuInt("Seleccione el campo que desea modificar\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Salir\n", 1, 5);
				switch(opcion){
					case 1:
						getStr(aux.name, "Ingresar Nombre\n", 1, STRLEN, 0);
						strcpy(list[id].name, aux.name);
					break;
					case 2:
						getStr(aux.lastName, "Ingresar Apellido\n", 1, STRLEN, 0);
						strcpy(list[id].lastName, aux.lastName);
					break;
					case 3:
						getFloat(&aux.price, "Ingresar Precio\n", 1, 200000);
						list[id].price = aux.price;
					break;
					case 4:
						getInt(&aux.typePassenger, "Ingresar Tipo de Pasajero\n", 1, 10);
						list[id].typePassenger = aux.typePassenger;
					break;
				}
			}while(opcion != 6);
		}
		else{
			printf("No se encontro ningun pasajero con id %d\n", id);
		}
	}
}

int addPassenger(Passenger* list, int len, int index, int id, char name[],char
lastName[],float price,int typePassenger, int flycode){
	int retorno = -1;

	if(index > -1){
		list[index].id = index+1;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		list[index].flycode = flycode;
		list[index].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}


int getFlightCode(FlightCode codeList[]){
	StatusFlight statusList[CARGA_STATUS];
	cargarStatusFlight(statusList);
	char str[51];
	int len;
	int estado;
	int i;
	int code;
	int opcion;
	int indice;
	int ret;
	int lenValido = 6;
	ret = 0;
	estado = 1;

	while(estado == 1){
		printf("Ingrese un codigo de vuelo\n");
		for(i = 0; i< CODE_CANT; i++){
			if(codeList[i].status > 0){
				printf("%s\n", codeList[i].code);
			}
		}
		len = getString(str, 10);
		if(len != lenValido){
			printf("Verifique que el codigo contenga 6 caracteres\n");
		}else{
			for(i = 0; i < len; i++){
				if(i<2){
					if(str[i] >= 'A' && str[i] <= 'Z'){
					}
				}else{
					if(i>2){
						if( str[i] >= 48 && str[i] <= 57){
						}
					}
					else{
						if(str[i] == '-'){
						}else{
							printf("El codigo ingresado no es valido\n");
						estado = 1;
						break;
						}
					}
				}
			}
			if(i == len){
				estado = 0;
			}
			if(estado == 0){
				for(i = 0; i < CODE_CANT; i++){
					if(strcmp(str, codeList[i].code) == 0){
						code = i;
						break;
					}
				}
				if(i == CODE_CANT){
					printf("El codigo de vuelo %s ingresado no se encuentra registrado\n"
							"¿Desea cargarlo en el sistema?\n", str);
					opcion = menuInt("1. Registrar\n2. Cancelar\n", 1, 2);
					if(opcion == 1){
						indice = buscarIntVector(&codeList[0].id, &codeList[1].id, CODE_CANT, 0);
						if(indice > -1){
							strcpy(codeList[indice].code, str);
							codeList[indice].id = indice +1;
							printf("Se ingreso el codigo de vuelo %s\n", codeList[indice].code);
							printf("Ingrese el estado para el codigo de vuelo\n");
							for(i = 0; i < CARGA_STATUS; i++){
								printf("%d. %s\n", statusList[i].id, statusList[i].status);
							}
							opcion = menuInt("", 1, CARGA_STATUS);
							codeList[indice].status = opcion;
							ret = codeList[indice].id;

						}else{
							printf("No hay mas espacio para ingresar un codigo de vuelo nuevo");
						}
					}else{
						estado = 1;
					}
				}else{
					ret = code+1;
				}
			}
		}
	}
	return ret;
}

int darDeAlta(Passenger list[], FlightCode codeList[]){
	Passenger new;
	int addPassengerError;
	int index;
	addPassengerError = 0;
	index = searchByIsEmpty(1, list);
	if(index == -1){
		printf("No hay espacio para mas pasajeros\n");
	}
	else{
		new.id = index+1;
		getStr(new.name, "Ingresar Nombre\n", 1, STRLEN, 0);
		getStr(new.lastName, "Ingresar Apellido\n", 1, STRLEN, 0);
		getFloat(&new.price, "Ingresar precio\n", 1, 200000);
		new.flycode = getFlightCode(codeList);
		getInt(&new.typePassenger, "Ingresar tipo de pasajero\n", 1, 10);
		addPassengerError = addPassenger(list, CANT, index, new.id, new.name, new.lastName,
				new.price, new.typePassenger, new.flycode);
		if(addPassengerError == 0){
			printf("Se ingreso el pasajero %s con ID %d correctamente\n",
					list[index].name, list[index].id);
		}
	}
	return 0;
}

int initFlightCode(FlightCode list[]){
	int init;
	init = 0;
	cargarIntVector(&list[0].status, &list[1].status, CODE_CANT, init);
	return 0;
}

int initPassenger(Passenger list[]){
	int init;
	init = 1;
	cargarIntVector(&list[0].isEmpty, &list[1].isEmpty, CANT, init);
	return 0;
}
