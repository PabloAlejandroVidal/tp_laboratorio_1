/**
 * validaciones.h
 *
 *  Created on: May 13, 2022
 *      Author: Vidal Pablo
 **/

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

float promediar(float suma, int cant);

int cargarIntVector(int* dir1, int* dir2, int cant, int valor);

int buscarIntVector(int* elmnt1, int* elmnt2, int cant, int toFind);

int findNotLetter(char str[], int len);

int findKindInt(char str[], int len);

int findKindFloat(char str[], int len);

//Guarda un string ingresado por fgets stdin y devuelve su length sin incluir '\0'
int getString(char str[], int maxLen);

int getStr(char str[], char msg[], int minLen, int maxLen, int soloLetras);

int getInt(int* integ, char msg[], int min, int max);

int getFloat(float* flotante, char msg[], int min, int max);

int menuInt(char* opcion, int min, int max);

#endif /* VALIDACIONES_H_ */
