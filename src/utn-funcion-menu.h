/*
 * utn-funcion-menu.h
 *
 *  Created on: Apr 11, 2022
 *      Author: rolga
 */

#ifndef UTN_FUNCION_MENU_H_
#define UTN_FUNCION_MENU_H_

int ingresarKilometro(int *km, int min, int max);

int ingresarPrecios(int* precioAerolineas, int* precioLatam, int min, int max);

int calcularCostos(int* costosCalculados, int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb,
		float* precioLatamCred, float* precioLatamBTC, float *precioLatamPorKm, float* precioAerolineasDeb,
		float* precioAerolineasCred, float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio);

int informarResultado(int* costosCalculados, int* km, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, int* precioAerolineas, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio);

int cargarDatosForzados(int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio, int* costosCalculados);

int finalizarPrograma(char* mensaje);

#endif /* UTN_FUNCION_MENU_H_ */
