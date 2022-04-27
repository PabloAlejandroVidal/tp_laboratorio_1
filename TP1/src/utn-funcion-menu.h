///
/// utn-funcion-menu.h
///
/// Created on: Apr 11, 2022
///
/// Author: Pablo Vidal
///

#ifndef UTN_FUNCION_MENU_H_
#define UTN_FUNCION_MENU_H_

/** @brief ingresarKilometro pide y valida el ingreso de los km e imprime un mensaje confirmando los km ingresados.
 *         Informa en caso de que ya se hayan ingresado anteriormente para no pisar los datos
 *         Los kilometros se guardaran en la direccion de memoria que se le pasa por parametro.
 */
int ingresarKilometro(int *km, int min, int max);


/** @brief ingresarPrecios pide y valida los precios para ambas aerolineas e imprime un mensaje para confirmar.
 *         Informa en caso de que ya se hayan ingresado anteriormente para no pisar los datos.
 *         El precios se guardaran en las direcciones de memoria que se pasa por parametro.
 */
int ingresarPrecios(int* precioAerolineas, int* precioLatam, int min, int max);


/** @brief calcularCostos Realiza todos los calculos necesaria para poder mostrar los resultados.
 *         en caso de que se pidan posteriormente.
 *         Esta funcion no realizara ningun calculo mientras no esten todos los datos necesarios para realizar el mismo
 *         en caso de llamarla mostrara un mensaje de error indicando que falta ingresar datos.
 */
int calcularCostos(int* costosCalculados, int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb,
		float* precioLatamCred, float* precioLatamBTC, float *precioLatamPorKm, float* precioAerolineasDeb,
		float* precioAerolineasCred, float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio);


/** @brief informarResultado Imprime en pantalla un informe de los resultados esperados.
 *         Esta funcion solo mostrara dichos resultados si previamente se realizaron los calculos con la funcion calcularCostos.
 *         Si los costos no fueron calculados y se intenta mostrar el informe dara un mensaje de error informando el motivo.
 */
int informarResultado(int* costosCalculados, int* km, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, int* precioAerolineas, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio);


/** @brief cargarDatosForzados calcula los costos e imprime en pantalla un informe de los mismos, con los datos ingresados
 *         por defecto en el mismo programa
 *         No es necesario indicar nada para mostrar este informe.
 *         Si se ingresaron kilometros o precios para las aerolineas por el usuario esos datos se pisaran por los que trae el programa.
 */
int cargarDatosForzados(int* km, int* precioAerolineas, int* precioLatam, float* precioLatamDeb, float* precioLatamCred,
		float* precioLatamBTC, float* precioLatamPorKm, float* precioAerolineasDeb, float* precioAerolineasCred,
		float* precioAerolineasBTC, float* precioAerolineasPorKm, int* diferenciaPrecio, int* costosCalculados);


/** @brief finalizarPrograma Finaliza el programa mostrando el mensaje que se indique en la llamada a la funcion.
 */
int finalizarPrograma(char* mensaje);

#endif /* UTN_FUNCION_MENU_H_ */
