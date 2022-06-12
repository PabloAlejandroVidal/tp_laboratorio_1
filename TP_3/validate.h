/**
 * validate.h
 *
 *  Created on: Jun 8, 2022
 *      Author: Vidal Pablo
 **/

#ifndef VALIDATE_H_
#define VALIDATE_H_

int isAlphaString(char* str);

int isAlphaNumString(char* str);

int isNumeric(char* str);

int getString(char* str, int maxLen);

int ingresar(char* msg, char* str, int max);

int menu(char* msg);

#endif /* VALIDATE_H_ */
