/*
 ============================================================================
 Name        : UTN-TP-01.c
 Author      : Pablo Vidal
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn-funcion-operaciones.h"
#include "utn-funcion-validaciones.h"
#include "utn-funcion-menu.h"

int main(void) {
	int opcionNum, km, precioAerolineas, precioLatam, costosCalculados, diferenciaPrecio;
	float precioLatamDeb, precioLatamCred, precioLatamBTC, precioLatamPorKm, precioAerolineasDeb, precioAerolineasCred, precioAerolineasBTC, precioAerolineasPorKm;

	opcionNum = 0;
	km = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	costosCalculados = 0;

	setbuf(stdout, NULL);

	while(opcionNum != 10){
		validarInt(" 1. Ingresar Kilómetros\n 2. Ingresar Precio de Vuelos\n 3. Calcular todos los costos\n 4. Informar Resultados\n 5. Carga forzada de datos\n10. Salir\n", &opcionNum, 0, 11);
		switch(opcionNum){
			case 1:
				ingresarKilometro(&km, 0, 20000);
				break;

			case 2:
				ingresarPrecios(&precioAerolineas, &precioLatam, 0, 500000);
				break;

			case 3:
				calcularCostos(&costosCalculados, &km, &precioAerolineas, &precioLatam, &precioLatamDeb, &precioLatamCred, &precioLatamBTC, &precioLatamPorKm, &precioAerolineasDeb, &precioAerolineasCred, &precioAerolineasBTC, &precioAerolineasPorKm, &diferenciaPrecio);
				break;

			case 4:
				informarResultado(&costosCalculados, &km, &precioLatam, & precioLatamDeb, & precioLatamCred, & precioLatamBTC, &precioLatamPorKm, &precioAerolineas, & precioAerolineasDeb, & precioAerolineasCred, & precioAerolineasBTC, & precioAerolineasPorKm, &diferenciaPrecio);
				break;

			case 5:
				cargarDatosForzados(&km, &precioAerolineas, &precioLatam, &precioLatamDeb, &precioLatamCred, &precioLatamBTC, &precioLatamPorKm, &precioAerolineasDeb, &precioAerolineasCred, &precioAerolineasBTC, &precioAerolineasPorKm, &diferenciaPrecio, &costosCalculados);
				break;
		}
	}
	finalizarPrograma("El programa ha finalizado.\n\n");
	return 0;
}
