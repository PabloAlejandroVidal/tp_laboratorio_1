///
/// utn-functions-operaciones.h
///
/// Created on: Apr 4, 2022
///
/// Author: Pablo Vidal
///

#ifndef UTN_FUNCION_OPERACIONES_H_
#define UTN_FUNCION_OPERACIONES_H_


/** @brief int aplicarPorcentaje multiplica un numero entero por un flotante y guarda el resultado en la
 *         direccion de memoria que se le envia como argumento.
 *
 * @param float* num apunta a la direccion de memoria de la variable que se le pase como argumento.
 *         en esa direccion guardara el resultado de la multiplicacion.
 *
 * @param int num2 entero al que se le aplicara un aumento o decremento porcentual.
 *
 * @param float num3 numero flotante por el que se multiplicara al entero para aplicar un recargo o descuento.
 *
 *@return Devuelve 0 si la funcion se ejecuto correctamente.
 */
int aplicarPorcentaje(float* num, int num2, float num3);


/** @brief int dividir divide un numero entero por un flotante y guarda el resultado en la
 *         direccion de memoria que se le envia como argumento.
 *
 * @param float* num apunta a la direccion de memoria de la variable que se le pase como argumento.
 *         en esa direccion guardara el resultado de la division.
 *
 * @param int num2 entero a dividir.
 *
 * @param float num3 numero flotante por el que se va a dividir.
 *
 *@return Devuelve 0 si la funcion se ejecuto correctamente.
 */
int dividir(float* num, int num2, float num3);


/** @brief int restar resta dos enteros y guarda el resultado en la
 *         direccion de memoria que se le envia como argumento.
 *
 * @param int* num apunta a la direccion de memoria de la variable que se le pase como argumento.
 *         en esa direccion guardara el resultado de la resta.
 *
 * @param int num2 entero a restar.
 *
 * @param int num3 numero enter que se va a restar al anterior.
 *
 *@return Devuelve 0 si la funcion se ejecuto correctamente.
 */
int restar(int* num, int num2, int num3);


/** @brief int obtenerValorAbsoluto pide como argumento un numero entero y devuelve el mismo valor positivo.
 *
 * @param int* valor apunta a la direccion de memoria de la variable que se le pase como argumento.
 *         en esa direccion guardara el numero positivo.
 *
 * @param int num2 entero positivo o negativo.
 *
 *@return Devuelve 0 si la funcion se ejecuto correctamente.
 */
int obtenerValorAbsoluto(int *valor, int num2);

#endif /* UTN_FUNCION_OPERACION_H_ */
