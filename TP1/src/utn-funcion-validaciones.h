///
/// utn-function-validaciones.h
///
/// Created on: Apr 4, 2022
///
/// Author: Pablo Vidal
///

#ifndef UTN_FUNCION_VALIDACIONES_H_
#define UTN_FUNCION_VALIDACIONES_H_


/** @brief int validarChar Pide al usuario que ingrese un caracter mostrando un mensaje,
 *         lo valida y lo guarda en la direccion de memoria a la que apunta respuesta.
 *         la cantidad de caracteres que toma *c debe coindir con el numero entero que indique cc.
 *
 * @param char* mensaje Muestra el mensaje que se pasa como argumento en la llamada a la funcion.
 *
 * @param char* respuesta apunta a la direccion de memoria donde guarda el caracter ingresado por el usuario.
 *
 * @param int cc numero entero que debe coincidir con la cantidad de caracteres permitidos*
 *
 * @param char* c se pasa una cadena con los caracteres que validaran al ingresado por el usuario.
 *
 *@return Devuelve 0 si la funcion se ejecuto correctamente.
 */
int validarChar(char* mensaje, char* respuesta, int cc, char* c);


/** @brief int validarInt Pide al usuario que ingrese un numero mostrando un mensaje,
 *         lo valida y lo guarda en la direccion de memoria a la que apunta numIngresado.
 *
 * @param char* mensaje Muestra el mensaje que se pasa como argumento en la llamada a la funcion.
 *
 * @param char* numIngresado apunta a la direccion de memoria donde guarda el numero ingresado por el usuario.
 *
 * @param int min valor de entero minimo que se le permita ingresar al usuario.
 *
 * @param int max valor de entero maximo que se le permita ingresar al usuario.
 *
 *@return Devuelve 0 si la funcion se ejecuta correctamente.
 */
int validarInt(char* mensaje, int* numIngresado, int min, int max);

#endif /* UTN_FUNCION_VALIDACIONES_H_ */

