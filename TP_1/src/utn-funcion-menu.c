/*
 * utn-funciones-menu.c
 *
 *  Created on: Apr 4, 2022
 *      Author: Pablo Vidal
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn-funcion-operaciones.h"
#include "utn-funcion-validaciones.h"
#include "utn-funcion-menu.h"

#define BTC 4606954
#define CFKM 7090
#define CFPAL 162965
#define CFPLT 159339
#define DESC10 0.9
#define REC25 1.25

int ingresarKilometro(int *km, int min, int max){
	if(*km){
		printf("Ya se ingresaron los kilometros\n\n");
	}
	else{
		validarInt("Ingresar kilómetros:\n", km, min, max);
		printf("[Kilómetros asignados: %dkm]\n\n",*km);
	}
	return 0;
}

int ingresarPrecios(int* precioAerolineas, int* precioLatam, int min, int max){
	if(*precioAerolineas && *precioLatam){
		printf("Los precios ya fueron ingresados\n\n");
	}
	else{
		char opcionChar = ' ';
			while(opcionChar!='a' && (*precioAerolineas == 0 || *precioLatam == 0)){
				validarChar("[y] Ingresar precio para Aerolíneas\n[z] Ingresar precio para Latam\n[a] Atras\n", &opcionChar, 3, "yza");
			switch(opcionChar){
				case 'y':
					if(*precioAerolineas){
						printf("El precio para Aerolíneas ya fue ingresado\n\n");
					}
					else{
						validarInt("Ingresar precio de vuelos para Aerolíneas: ", precioAerolineas, min, max);
						printf("[Precio ingresado para Aerolíneas: %d]\n\n",*precioAerolineas);
					}
				break;
				case 'z':
					if(*precioLatam){
						printf("El precio para Latam ya fue ingresado\n\n");
					}
					else{
						validarInt("Ingresar precio de vuelos para Latam: ", precioLatam, min, max);
						printf("[Precio ingresado para Latam: %d]\n\n",*precioLatam);
					}
				break;
			}
		}
	}
	return 0;
}

int calcularCostos(int* costosCalculados, int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb,
		float* precioLatamCred, float* precioLatamBTC, float *precioLatamPorKm, float* precioAerolineasDeb,
		float* precioAerolineasCred, float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio){
	if(*costosCalculados){
		printf("Los costos ya han sido calculados\n\n");
	}
	else{
		if(*km && *precioAerolineas && *precioLatam){
			aplicarPorcentaje(precioLatamDeb, *precioLatam, DESC10);
			aplicarPorcentaje(precioLatamCred, *precioLatam, REC25);
			dividir(precioLatamBTC, *precioLatam, BTC);
			dividir(precioLatamPorKm, *precioLatam, *km);
			aplicarPorcentaje(precioAerolineasDeb, *precioAerolineas, DESC10);
			aplicarPorcentaje(precioAerolineasCred, *precioAerolineas, REC25);
			dividir(precioAerolineasBTC, *precioAerolineas, BTC);
			dividir(precioAerolineasPorKm, *precioAerolineas, *km);
			restar(diferenciaPrecio, *precioLatam, *precioAerolineas);
			obtenerValorAbsoluto(diferenciaPrecio, *diferenciaPrecio);
			*costosCalculados = 1;
			printf("¡Costos calculados exitosamente!\n\n");
		}
		else{
		printf("No se ingresaron datos suficientes para calcular los costos.\n\n");
		}
	}
return 0;
}

int informarResultado(int* costosCalculados, int* km, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, int* precioAerolineas, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio){

	char opcionChar = ' ';

	if(*costosCalculados){
		printf("Kilómetros de vuelo: %dkm\n\n", *km);
		printf("Latam:\n");
		printf("precio Latam: %d\n", *precioLatam);
		printf("a) Precio con tarjeta de débito: %.2f\n", *precioLatamDeb);
		printf("b) Precio con tarjeta de crédito: %.2f\n", *precioLatamCred);
		printf("c) Precio pagando con bitcoin: %.6f\n", *precioLatamBTC);
		printf("d) Precio unitario (por km): %.2f\n\n", *precioLatamPorKm);
		printf("Aerolíneas:\n");
		printf("precio Aerolíneas: %d\n", *precioAerolineas);
		printf("a) Precio con tarjeta de débito: %.2f\n", *precioAerolineasDeb);
		printf("b) Precio con tarjeta de crédito: %.2f\n", *precioAerolineasCred);
		printf("c) Precio pagando con bitcoin: %.6f\n", *precioAerolineasBTC);
		printf("d) Precio unitario (por km): %.2f\n\n", *precioAerolineasPorKm);
		printf("La diferencia de precio es: %d\n\n", *diferenciaPrecio);

		validarChar("[c] Calcular otro vuelo\n[s] Salir\n", &opcionChar, 2, "cs");
		if(opcionChar == 'c'){
			km = 0;
			precioAerolineas = 0;
			precioLatam = 0;
			costosCalculados = 0;
			printf("Ingresar nuevos datos\n\n");
		}
		else{
			if(opcionChar == 's'){
				printf("El programa ha finalizado.\n\n");
				exit (-1);
			}
		}
	}
	else{
		printf("Debes calcular los costos antes para informar los resultados.\n\n");
	}
	return 0;
}

int cargarDatosForzados(int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio, int* costosCalculados){

	char opcionChar = ' ';

	*km = CFKM;
	*precioAerolineas = CFPAL;
	*precioLatam = CFPLT;

	aplicarPorcentaje(precioLatamDeb, *precioLatam, DESC10);
	aplicarPorcentaje(precioLatamCred, *precioLatam, REC25);
	dividir(precioLatamBTC, *precioLatam, BTC);
	dividir(precioLatamPorKm, *precioLatam, *km);
	aplicarPorcentaje(precioAerolineasDeb, *precioAerolineas, DESC10);
	aplicarPorcentaje(precioAerolineasCred, *precioAerolineas, REC25);
	dividir(precioAerolineasBTC, *precioAerolineas, BTC);
	dividir(precioAerolineasPorKm, *precioAerolineas, *km);
	restar(diferenciaPrecio, *precioLatam, *precioAerolineas);
	obtenerValorAbsoluto(diferenciaPrecio, *diferenciaPrecio);

	printf("Carga forzada de datos:\n");
	printf("Kilómetros de vuelo: %dkm\n\n", *km);
	printf("Precio Latam: %d\n", *precioLatam);
	printf("a) Precio con tarjeta de débito: %.2f\n", *precioLatamDeb);
	printf("b) Precio con tarjeta de crédito: %.2f\n", *precioLatamCred);
	printf("c) Precio pagando con bitcoin: %.6f\n", *precioLatamBTC);
	printf("d) Precio unitario (por km): %.2f\n\n", *precioLatamPorKm);
	printf("Precio Aerolíneas: %d\n", *precioAerolineas);
	printf("a) Precio con tarjeta de débito: %.2f\n", *precioAerolineasDeb);
	printf("b) Precio con tarjeta de crédito: %.2f\n", *precioAerolineasCred);
	printf("c) Precio pagando con bitcoin: %.6f\n", *precioAerolineasBTC);
	printf("d) Precio unitario (por km): %.2f\n\n", *precioAerolineasPorKm);
	printf("La diferencia de precio es: %d\n\n", *diferenciaPrecio);

	validarChar("[c] Calcular otro vuelo\n[s] Salir\n", &opcionChar, 2, "cs");

	if(opcionChar == 'c'){
		*km = 0;
		*precioAerolineas = 0;
		*precioLatam = 0;
		*costosCalculados = 0;
		printf("Ingresar nuevos datos\n\n");
	}
	else{
		if(opcionChar == 's'){
			finalizarPrograma("El programa ha finalizado.\n\n");
		}
	}
	return 0;
}

int finalizarPrograma(char* mensaje){
	printf("%s", mensaje);
	exit (-1);

	return 0;
}
