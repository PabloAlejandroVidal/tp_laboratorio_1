#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "validate.h"
#include "ingresos.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	char  id[10], nombre[50], apellido[50], precio[12], flyCode[20], typePassenger[20], statusFlight[20], linea[100];
	Passenger* new;
	int i;
	int iDatos;
	int newid;
	int lastid;
	int added;
	int error;
	added = 0;
	error = 0;
	i = 1;
	iDatos = 0;

	fscanf(pFile, "%[^\n]\n", linea);
		while(!feof(pFile)){
			i++;
			iDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, flyCode, typePassenger, statusFlight);

			if(iDatos == 7){
				new = Passenger_newParam(pArrayListPassenger, id, nombre, apellido, precio, flyCode, typePassenger, statusFlight);
				if(new != NULL){
					ll_add(pArrayListPassenger, new);
					newid = atoi(id);
						Passenger_writeId(&newid, "id.csv");
						added ++;
				}else{
					error ++;
					printf("ERROR! No se pudo cargar el registro. Linea %d\n", i);
				}
			}else{
				error ++;
				printf("ERROR! al leer el registro. Linea %d\n", i);
			}
		}
		printf("Se ha completado la carga con %d registros ingresados correctamente, %d errores\n", added, error);
		fclose(pFile);
    return 1;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	Passenger *new, *pFind;
	int id;
	int error;
	int added;
	int lastid;
	int newid;
	error = 0;
	added = 0;
	if(pFile != NULL){
		while(!feof(pFile)){
			new = Passenger_new();
			fread(&new, sizeof(new), 1, pFile);
			Passenger_getId(new, &id);
			pFind = Passenger_search(pArrayListPassenger, id);
			if(pFind == NULL ){
				ll_add(pArrayListPassenger, new);
				Passenger_getId(new, &newid);
				Passenger_readId(&lastid, "id.csv");
				if(newid > lastid){
					Passenger_writeId(&newid, "id.csv");
				}
				added++;
			}else{
				error++;
			}
		}
		printf("Se ha completado la carga con %d registros ingresados correctamente, %d errores\n", added, error);
	}else{
		printf("Error al abrir el archivo\n");
	}
	fclose(pFile);
    return 1;
}



