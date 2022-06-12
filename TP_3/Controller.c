#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "validate.h"
#include "ingresos.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	FILE* pFile = fopen(path, "r");
	parser_PassengerFromText(pFile , pArrayListPassenger);

	return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	FILE* pFile = fopen(path, "r");
	parser_PassengerFromBinary(pFile, pArrayListPassenger);

    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* idaux){
	char id[10], nombre[50], apellido[50], precio[12], flyCode[20], typePassenger[20], statusFlight[20];
	Passenger *new;
	int validate;
	int ret;
	int lastid;
	ret = -1;

	new = Passenger_new();
	validate = 1;

	if(new != NULL){
		while(validate != 0){
			ingresar_nombre(&validate, nombre);
		}
		validate = 1;

		while(validate != 0){
			ingresar_apellido(&validate, apellido);
		}
		validate = 1;

		while(validate != 0){
			ingresar_precio(&validate, precio);
		}
		validate = 1;

		while(validate){
			ingresar_codigoVuelo(&validate, flyCode);
		}
		validate = 1;

		while(validate){
			ingresar_tipoPasajero(&validate, typePassenger);
		}

		int vuelo = codigoVueloToEstadoVuelo(flyCode);
		estadoVueloToString(statusFlight, vuelo);

		if(*idaux == 0){
			Passenger_readId(&lastid, "id.csv");
			*idaux = lastid+1;
			sprintf(id, "%d  .",*idaux);
		}else{
			sprintf(id, "%d",*idaux);
		}
		(*idaux)++;
		new = Passenger_newParam(pArrayListPassenger, id, nombre, apellido, precio, flyCode, typePassenger, statusFlight);
		if(new != NULL){
			ll_add(pArrayListPassenger, new);
			printf("El registro se ha cargado con exito en LinkedList\n");
			ret = 0;
		}

//		if(new == NULL){
//			printf("Error al cargar un nuevo registro en LinkedList\n");
//		}
	}else{
		ret = -2;
	}
    return ret;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	Passenger* new;
	int option, id, len, validate;
	char str[10], nombre[50], apellido[50], precio[10];
	validate = 1;
	len = ll_len(pArrayListPassenger);
	if(len > 0){
		if(pArrayListPassenger != NULL){
			printf("Ingrese el ID del pasajero que desea modificar\n");
			getString(str, 10);
			id = atoi(str);

			new = Passenger_search(pArrayListPassenger, id);
			if(new != NULL){
				option = menu(
					"    ________________________________________________ \n"
					"   |__________Modificar Datos Del Pasajero__________|\n"
					" 1 | Nombre                                         |\n"
					" 2 | Apellido                                       |\n"
					" 3 | Precio de vuelo                                |\n"
					" 4 | Codigo de vuelo                                |\n"
					" 5 | Tipo de pasajero                               |\n"
					"10 |_Salir__________________________________________|\n");
				switch(option){
				case 1:
					while(validate != 0){
						ingresar_nombre(&validate, nombre);
					}
					break;
				case 2:
					while(validate != 0){
						ingresar_apellido(&validate, apellido);
					}
					break;
				case 3:
					while(validate != 0){
						ingresar_precio(&validate, precio);
					}
					validate = 1;
					break;
				case 4:
					break;
				case 5:
					break;
				case 10:
					break;
				default:
					break;
				}

			}else{
				printf("El ID ingresado no esta registrado\n");
			}
		}else{
			printf("Un error ha ocurrido\n");
		}
	}
	printf("No hay registros cargados para modificar\n");
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
	int len, id;
	char str[10];
	Passenger* new;
	len = ll_len(pArrayListPassenger);
	if(len > 0){
		if(pArrayListPassenger != NULL){
			printf("Ingrese el ID del pasajero que dar de baja\n");
			getString(str, 10);
			id = atoi(str);
			new = Passenger_search(pArrayListPassenger, id);
			if(new != NULL){
				ll_remove(pArrayListPassenger, id);
				printf("El pasajero se ha dado de baja correctamente\n");
			}else{
				printf("El id ingresado no se encuentra en los registros\n");
			}
			ll_remove(pArrayListPassenger, 0);
		}else{
			printf("Un error ha ocurrido\n");
		}
	}else{
		printf("No hay registros cargados para dar de baja\n");
	}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){
	int len, i;
	len = ll_len(pArrayListPassenger);
	Passenger* pass;
	char nombre[50], apellido[50], flyCode[20],	typePassenger[20], statusFlight[20];
	int id;
	float precio;
	if(len > 0){
		printf(
				" ________________________________________________________________________________________ \n"
				"|___________________________________LISTA DE PASAJEROS___________________________________|\n");
		for(i = 0; i < len; i++){
			pass = ll_get(pArrayListPassenger, i);
			Passenger_getId(pass, &id);
			Passenger_getNombre(pass, nombre);
			Passenger_getApellido(pass, apellido);
			Passenger_getPrecio(pass, &precio);
			Passenger_getCodigoVuelo(pass, flyCode);
			Passenger_getTipoPasajero(pass, typePassenger);
			Passenger_getEstadoVuelo(pass, statusFlight);

			printf(
					"|%5d    %-12s %10s %11.2f %10s %17s %13s |\n",
					id, nombre, apellido, precio, flyCode, typePassenger, statusFlight);
		}
		printf("|________________________________________________________________________________________|\n");
	}else{
		printf("No hay registros cargados para listar\n");
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int len;
	len = ll_len(pArrayListPassenger);
	if(len > 0){
		int (*pFuncion)(void*, void*);
		pFuncion = Passenger_criterioNombre;
		//pFuncion = Passenger_criterioPrecio;
		ll_sort(pArrayListPassenger, pFuncion, 1);
	}else{
		printf("No hay registros para ordenar\n");
	}
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
	char id[10], nombre[50], apellido[50], precio[12], flyCode[20],	typePassenger[20], statusFlight[20];
	Passenger* new;
	FILE* pFile;
	float precioF;

	pFile = fopen("data.csv", "w");
	if(pFile != NULL){
		int len, i, obtId;
		precioF = atof(precio);
		len = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i=0; i<len; i++){
			new = ll_get(pArrayListPassenger, i);
			Passenger_getId(new, &obtId);
			sprintf(id,"%d",obtId);
			Passenger_getNombre(new, nombre);
			Passenger_getApellido(new, apellido);
			Passenger_getPrecio(new, &precioF);
			Passenger_getCodigoVuelo(new, flyCode);
			Passenger_getTipoPasajero(new, typePassenger);
			Passenger_getEstadoVuelo(new, statusFlight);

			fprintf(pFile, "%s,%s,%s,%.2f,%s,%s,%s\n", id, nombre, apellido, precioF, flyCode, typePassenger, statusFlight);
		}
	}else{
		printf("no se pudo guardar el archivo\n");
	}
	fclose(pFile);

	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}


