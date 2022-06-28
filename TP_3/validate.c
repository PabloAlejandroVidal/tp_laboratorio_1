/**
 * validate.c
 *
 *  Created on: Jun 8, 2022
 *      Author: Vidal Pablo
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
#include "validate.h"

int isAlphaString(char* str){
	int ret;
	int i;
	ret = 0;
	i = 0;
	while(str[i] != '\0'){
		if(isalpha(str[i])){
			ret = 1;
		}else{
			ret = 0;
			break;
		}
		i++;
	}
	return ret;
}

int isAlphaNumString(char* str){
	int ret;
	int i;
	ret = 0;
	i = 0;
	while(str[i] != '\0'){
		if(isalpha(str[i]) || isdigit(str[i])){
			ret = 1;
		}else{
			ret = 0;
			break;
		}
		i++;
	}
	return ret;
}

int isNumeric(char* str){
	int i = 0;
	int ret = 0;
	int decim = 0;
	int sign = 1;

	while(str[i] != '\0'){
		if(isdigit(str[i])){
			if(decim == 1){
				ret = 2;
			}else{
				ret = 1;
			}
		}else{
			if(str[i] == '.'){
				 if(strlen(str)>i+1 || i > 0){
					if(decim == 0){
						decim = 1;
					}else{
						ret = 0;
						break;
					}
				 }else{
					ret = 0;
					break;
				 }
			}else{
				if(i == 0){
					if(str[i] == '-' && i == 0 && strlen(str)>i+1){
						sign = -1;
					}else{
						ret = 0;
						break;
					}
				}
			}
		}
		i++;
	}
	ret = ret * sign;

	//retorna 0 no es numero
	//retorna -1 es negativo
	//retorna -2 es negativo decimal
	//retorna 1 es positivo 0 o mas
	//retorna 2 es positivo decimal
	return ret;
}

int getString(char* str, int maxLen){
	int len;
	void* p;
	p = fgets(str, maxLen+1, stdin);
	fflush(stdin);
	if(p!=NULL){
		len = strlen(str);
		if(str[len-1] == '\n'){
			str[len-1] = '\0';
		}
		len = strlen(str);
	}else{
		len = -1;
	}
	return len;
}

int ingresar(char* msg, char* str, int max){
	printf(msg);
	getString(str, max);

	return 0;
}

int menu(char* msg){
	char respuesta[2];
	int ret = -1;
	printf(msg);
	getString(respuesta, 2);
	if(isNumeric(respuesta)){
		ret = atoi(respuesta);
	}
	return ret;
}

int numcmp(float num1, float num2){
	int ret;
	ret = 0;
	if(num1 > num2){
			ret = 1;
		}else{
			if(num1 < num2){
				ret = -1;
			}
		}
	return ret;
}
