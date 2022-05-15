/**
 * validaciones.h
 *
 *  Created on: May 13, 2022
 *      Author: Vidal Pablo
 **/

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/** @brief calcula el promedio calculado con un total y cantidad ingresada
 *
 * @param suma recibe la suma
 * @param cant recibe la cantidad de numeros sumados
 * @return devuelve el promedio de tipo float
 */
float promediar(float suma, int cant);

/** @brief permite cargar un vector  de tipo int con un valor especifico
 *
 * @param dir1 direccion del primer elemento del vector
 * @param dir2 direccion del segundo elemento del vector
 * @param cant cantidad de elementos que se va a recorrer
 * @param valor valor a setear en cada espacio del vector
 * @return devuelve 0 si se finaliza la funcion
 */
int cargarIntVector(int* dir1, int* dir2, int cant, int valor);

/** @brief permite buscar un valor entero en un vector
 *
 * @param elmnt1 direccion del primer elemento del vector
 * @param elmnt2 direccion del segundo elemento del vector
 * @param cant cantidad de elementos que se va a recorrer
 * @param toFind elemento tipo int a buscar
 * @return devuelve la primer posicion del elemento encontrado, si no se encuentra devuelve -1
 */
int buscarIntVector(int* elmnt1, int* elmnt2, int cant, int toFind);

/** @brief permite verificar si un elemento tiene un caracter que no sea una letra
 *
 * @param str string a examinar
 * @param len largo del string a recorrer
 * @return devuelve 1 si encuentra algo diferente a una letra, 0 si si no se encontro
 */
int findNotLetter(char str[], int len);

/** @brief permite verificar el tipo de entero ingresado
 *
 * @param str string a recorrer
 * @param len largo del string
 * @return devuelve -1 si el umero es negativo, 1 si es positivo y 0 si su valor es nulo (0)
 */
int findKindInt(char str[], int len);

/** @brief permite validar si una cadena es un numero de tipo flotante
 *
 * @param str string del numero a validar
 * @param len largo del string
 * @return devuelve 0 si no es un numero flotante
 */
int findKindFloat(char str[], int len);

/** @brief Guarda un string ingresado por fgets stdin y devuelve su length sin incluir '\0'
 *
 * @param str direccion donde se guarda el string
 * @param maxLen largo maximo permitido para el string, en caso de ser mayor lo trunca
 * @return devuelve su length sin incluir '\0'
 */
int getString(char str[], int maxLen);

/** @brief Valida una cadena de caracteres que este dentro de un minimo y maximo de caracteres
 *
 * @param str donde se guarda el string ingresado
 * @param msg mensaje que se le muestra al usuario para pedir el ingreso
 * @param minLen minimo permitido
 * @param maxLen maximo de caracteres permitidos
 * @param soloLetras si se quiere que solo acepte letras
 * @return devuelve 0 si finalizo la funcion
 */
int getStr(char str[], char msg[], int minLen, int maxLen, int soloLetras);

/** @brief Valida una cadena de caracteres que sea de tipo int entre un minimo y maximo permitido
 *
 * @param integ direccion de memoria donde se guarda el int validado
 * @param msg mensaje que se le muestra al usuario para pedir el ingreso del numero
 * @param min minimo valor aceptado
 * @param max maximo valor aceptado
 * @return devuelve 0 si finalizo la funcion
 */
int getInt(int* integ, char msg[], int min, int max);

/** @brief
 *
 * @param flotante Valida una cadena de caracteres que sea de tipo numerica entre un minimo y maximo permitido
 * @param msg mensaje que se le muestra al usuario para pedir el ingreso del numero
 * @param min minimo valor aceptado
 * @param max maximo valor aceptado
 * @return devuelve 0 si finalizo la funcion
 */
int getFloat(float* flotante, char msg[], int min, int max);

/** @brief imprime un mensaje ofreciendo  opciones al usuario
 *
 * @param opcion direccion donde guarda la opcion ingresada por el usuario
 * @param min valor minimo permitido para las opciones
 * @param max valor maximo permitido para las opciones
 * @return devuelve 0 si finalizo la funcion
 */
int menuInt(char* opcion, int min, int max);

#endif /* VALIDACIONES_H_ */
