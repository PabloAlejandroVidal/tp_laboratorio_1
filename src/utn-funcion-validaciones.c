/*
 * utn-functions.c
 *
 *  Created on: Apr 4, 2022
 *      Author: Pablo Vidal
 */

#include <stdio.h>
#include <stdlib.h>

int validarChar(char* mensaje, char* respuesta, int cc, char* c){

	char ingreso;
	int i, ret;
	ret = -1;
	i = 0;
	while(ret == -1){
		if(mensaje != NULL && respuesta != NULL && c != NULL){
			if(cc > 0 && cc < 10){
				while(c[i] != '\0'){
					i ++;
				}
				if(i == cc){
					printf("%s", mensaje);
					scanf("%c", &ingreso);
					fflush(stdin);
					for(i=0;i<cc;i++){
						if(ingreso == c[i]){
							ret = 0;
							*respuesta = ingreso;
						}
					}
				}
				else{
					printf("[Error] en los parametros al llamar a la funcion (validarChar): la cantidad de caracteres no coincide con el numero indicado.\n");
					exit (-1);
				}
			}
			else{
				printf("[Error] en los parametros al llamar a la funcion (validarChar): la cantidad de caracteres a validar debe ser entre 1 y 9.\n");
				exit (-1);
			}
		}
		if(ret==-1){
			printf("Se produjo un error. Vuelva a intentarlo.\n");
		}
	}
	return ret;
}

int validarInt(char* mensaje, int* numIngresado, int min, int max){

	int ret, num;
	ret = -1;
	while(ret == -1){
		if(numIngresado != NULL){
			if(min <= max){
				printf("%s", mensaje);
				scanf("%d",&num);
				fflush(stdin);

				if(num > min && num < max){
					*numIngresado = num;
					ret = 0;
				}
			}
			else{
				printf("[Error] en los parametros al llamar a la funcion (validarInt): el valor minimo no puede ser mayor al maximo.\n");
				exit (-1);
			}
		}
		if(ret==-1){
			printf("Se produjo un error. Vuelva a intentarlo.\n");
		}
	}
	return ret;
}
