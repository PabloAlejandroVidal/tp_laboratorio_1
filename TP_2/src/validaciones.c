/**
 * validaciones.c
 *
 *  Created on: May 13, 2022
 *      Author: Vidal Pablo
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "passenger.h"
#include "validaciones.h"

float promediar(float suma, int cant){
	float promedio;
	promedio = suma / cant;
	return promedio;
}

int cargarIntVector(int* dir1, int* dir2, int cant, int valor){
	int i;
	int dif;
	dif = dir2 - dir1;
			for(i=0; i<cant; i++){
				int* intDir = dir1 + dif * i;
				*intDir = valor;
			}
	return 0;
}

int buscarIntVector(int* elmnt1, int* elmnt2, int cant, int toFind){
	int i;
	int dif;
	int ret;
	ret = -1;
	dif = elmnt2 - elmnt1;
	for(i=0; i < cant; i++){
		if(*(elmnt1 + (dif * i)) == toFind){
			ret = i;
			break;
		}
	}
	return ret;
}

int findNotLetter(char str[], int len){
	int i;
	int ret;

	for(i=0; i<len; i++){
		if( !((str[i] >= 'A' && str[i] <='z') && !(str[i] > 'Z' && str[i] < 'a'))){
			ret = 1;
			break;
		}else{
			ret = 0;
		}
	}
	return ret;
}

int findKindInt(char str[], int len){
	int i;
	int ret = 0;

	for(i=0; i<len; i++){
		if(isdigit(str[i]) == 0){
			if(i == 0 && str[i] == '-'){
				ret = -1;
			}else{
				ret = 0;
				break;
			}
		}else{
			ret = 1;
		}
	}
	return ret;
}

int findKindFloat(char str[], int len){
	int i;
	int ret = 1;
	int isFloat = 0;

	for(i=0; i<len; i++){
		if(isdigit(str[i]) == 0){
			if(i == 0 && str[i] == '-'){
				ret = -1;
			}else{
				if(str[i] == '.' && isFloat == 0){
					isFloat = 1;
				}else{
				ret = 0;
				break;
				}
			}
		}
	}
	return ret;
}

int getString(char str[], int maxLen){
		maxLen +=2;
		int len;
		fgets(str, maxLen, stdin);
		fflush(stdin);
		len = strlen(str)-1;
		str[len] = '\0';
	return len;
}

int getStr(char str[], char msg[], int minLen, int maxLen, int soloLetras){
	int len;
	int estado;
	estado = 1;

	while(estado == 1){
		printf(msg);
		len = getString(str, maxLen);
		if(len > maxLen || len < minLen){
			printf("El numero de caracteres ingresados debe ser entre %d y %d caracteres\n", minLen, maxLen);
		}else{
			estado = 0;
			if(soloLetras){
				if(findNotLetter(str, len) == 1){
					printf("El dato ingresado solo debe contener letras\n");
					estado = 1;
				}
			}
		}
	}
	return 0;
}

int getInt(int* integ, char msg[], int min, int max){
	char str[STRLEN];
	int maxLen;
	int len;
	int estado;
	int aux;
	estado = 1;
	maxLen = 11;

	while(estado){
		printf(msg);
		len = getString(str, maxLen);
		if(len >= maxLen){
			printf("El numero ingresado es demasiado largo\n");
		}else{
			estado = 0;
			if(findKindInt(str, len) == 0){
				printf("El dato ingresado debe ser un numero\n");
				estado = 1;
			}else{
				aux = atoi(str);
				if(aux >= min && aux <= max){
					*integ = aux;
				}
				else{
					printf("Debes ingresar un dato valido\n");
					estado = 1;
				}
			}
		}
	}
	return 0;
}


int getFloat(float* flotante, char msg[], int min, int max){
	char str[STRLEN];
	int maxLen;
	int len;
	int estado;
	float aux;
	estado = 1;
	maxLen = 11;

	while(estado){
		printf(msg);
		len = getString(str, maxLen);
		if(len >= maxLen){
			printf("El numero ingresado es demasiado largo\n");
		}else{
			estado = 0;
			if(findKindFloat(str, len) == 0){
				printf("El dato ingresado debe ser un numero\n");
				estado = 1;
			}else{
				aux = atof(str);
				if(aux >= min && aux <= max){
					*flotante = aux;
				}
				else{
					printf("Debes ingresar un dato valido\n");
					estado = 1;
				}
			}
		}
	}
	return 0;
}

int menuInt(char* opcion, int min, int max){
	int respuesta;
	printf(opcion);
	scanf("%d", &respuesta);
	fflush(stdin);
	while(!(respuesta >= min && respuesta <= max)){
		VERIFY_MSG
		printf(opcion);
		scanf("%d", &respuesta);
		fflush(stdin);
	}
	return respuesta;
}

