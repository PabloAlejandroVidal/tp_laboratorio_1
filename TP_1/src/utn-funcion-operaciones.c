/*
 * utn-functions.c
 *
 *  Created on: Apr 4, 2022
 *      Author: Pablo Vidal
 */

#include <stdio.h>
#include <stdlib.h>

int aplicarPorcentaje(float* num, int num2, float num3){
	*num = num2 * num3;

	return 0;
}

int dividir(float* cociente, int num2, float num3){
	*cociente = num2 / num3;

	return 0;
}

int restar(int* resta, int num2, int num3){
	*resta = num2 - num3;

	return 0;
}

int obtenerValorAbsoluto(int *valor, int num2){

	if(num2 < 0)
		*valor = num2 * -1;

	return 0;
}
