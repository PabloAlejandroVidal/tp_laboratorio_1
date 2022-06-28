#include <stdio.h>
#include <stdlib.h>
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
	Passenger *new;
	int added;
	added = 0;
	if(pFile != NULL){
		do{
			new = Passenger_new();
			fread(new, sizeof(Passenger), 1, pFile);
			if(!feof(pFile)){
				ll_add(pArrayListPassenger, new);
				added ++;
			}else{
				printf("Se ha completado la carga con %d registros correctamente\n", added);
				free(new);
			}
		}while(!feof(pFile));
	}else{
		printf("Error al abrir el archivo\n");
	}
	fclose(pFile);
    return 1;
}
