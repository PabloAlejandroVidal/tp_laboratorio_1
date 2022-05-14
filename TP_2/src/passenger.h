/**
 * passenger.h
 *
 *  Created on: May 8, 2022
 *      Author: Vidal Pablo
 **/

#ifndef PASSENGER_H_
#define PASSENGER_H_

struct{
int id;
char name[51];
char lastName[51];
float price;
int flycode;
int typePassenger;
int isEmpty;
}typedef Passenger;

struct{
int id;
char code[51];
int status;
}typedef FlightCode;

struct{
int id;
char status[51];
}typedef StatusFlight;

struct{
int id;
char type[51];
}typedef PassengerType;

#define CANT 2000
#define CODE_CANT 50
#define CARGA_STATUS 3
#define CARGA_TYPE 4
#define CARGA_CODE 5
#define STRLEN 51
#define VERIFY_MSG printf("Verifique el dato ingresado\n");
#define EXIT_MSG printf("Programa finalizado\n");

/** @brief Busca en el array de pasajeros el id indicado
 * @param id identificador a buscar
 * @param list lista de pasajeros del que se busca su id
 * @return devuelve la posicion en el array del id encontrado o -1 si no se encontro
 */
int searchById(int id, Passenger list[]);

/** @brief Busca en el array de pasajeros la posicion del primer elemento con el estado indicado
 * @param estado indica el estado a buscar en el array de la estructura
 * @param list lista de pasajeros en la que se buscara el estado
 * @return devuelve la posicion en el array del primer elemento que se encuentra con el estado indicado,
 * 			en caso de no encontrarlo a lo largo del array, devuelve -1
 */
int searchByIsEmpty(int estado, Passenger list[]);

/** @brief carga los datos de codigo de vuelo en la direccion de memoria que se le pasa por puntero
 *
 * @param codeList direccion de memoria del array FlightCode
 * @return devuelve 0 si se ejecuta la funcion
 */
int cargarFlightCode(FlightCode* codeList);

/** @brief carga los datos de estado de vuelo en la direccion de memoria que se le pasa por puntero
 *
 * @param statusList direccion de memoria del array StatusFlight
 * @return devuelve 0 si se ejecuta la funcion
 */
int cargarStatusFlight(StatusFlight* statusList);

/** @brief carga los datos de tipo de pasajero en la direccion de memoria que se le pasa por puntero
 *
 * @param classList direccion de memoria del array PassengerType
 * @return devuelve 0 si finaliza la funcion
 */
int cargarPassengerType(PassengerType* classList);

/** @brief ordena el array por apellido y tipo de pasajero
 *
 * @param list lista de pasajeros
 * @param order se ingresa 1 para indicar que se realice el orden ascendente
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int sortPassenger(Passenger list[], int order);

/** @brief ordena el array por estado de vuelo
 *
 * @param list lista de pasajeros
 * @param order se ingresa 1 para indicar que se realice el orden ascendente
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int sortPassengerByStatusFlight(Passenger list[], int order);

/** @brief muestra la suma de los precios y promedio
 *
 * @param list lista de pasajeros
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int mostrarPrecios(Passenger list[]);

/** @brief muestra la lista de pasajeros con su codigo de vuelo y demas informacion
 *
 * @param list lista de pasajeros
 * @param filtro 0 indica sin filtro, 1 solo se veran pasajeros activos
 * @param codeList lista con los codigos de vuelo
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int printPassengers(Passenger list[], int filtro, FlightCode codeList[]);

/** @brief muentra las opciones para imprimir en pantalla el listado de pasajeo
 *
 * @param list lista de pasajeros
 * @param codeList lista con los codigos de vuelo
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int informar(Passenger list[], FlightCode codeList[]);

/** @brief realiza la baja logica de un pasajero
 *
 * @param list lista de pasajeros
 * @param indica la posicion del pasajero a dar de baja en el array
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int removePassenger(Passenger list[], int index);

/** @brief permite la baja del pasajero pidiendo al usuario y validando por id
 *
 * @param list lista de pasajeros
 */
void darDeBaja(Passenger list[]);

/** @brief permite modificar los datos del pasajero a traves de un menu
 *
 * @param list lista de pasajeros
 */
void modificar(Passenger list[]);

/** @brief permite y valida el ingreso de un codigo de vuelo con el formato AA-000
 *
 * @param codeList lista de codigos de vuelo
 * @return
 */
int getFlightCode(FlightCode codeList[]);

/** @brief
 *
 * @param list lista de pasajeros
 * @param len largo del string
 * @param index posicion donde se guarda el nuevo pasajero
 * @param id codigo unico del pasajero
 * @param name nombre del pasajero
 * @param lastName apellido del pasajero
 * @param price precio del vuelo
 * @param typePassenger tipo numerico de pasajero
 * @param flycode numero que corresponde a un codigo de vuelo
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int addPassenger(Passenger* list, int len, int index, int id, char name[],char
lastName[],float price,int typePassenger, int flycode);

/** @brief Permite el alta del pasajero
 *
 * @param list lista de pasajeros
 * @param codeList lista con codigos de vuelos permitidos
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int darDeAlta(Passenger list[], FlightCode codeList[]);

/** @brief inicializa el estado del string de codigos de vuelo en 0
 *
 * @param list lista de codigos de vuelo
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int initFlightCode(FlightCode list[]);

/** @brief inicializa el campo isEmpty de los pasajeros en 1
 *
 * @param list lista de pasajeros
 * @return devuelve 0 si finaliza la funcion correctamente
 */
int initPassenger(Passenger list[]);

#endif /* PASSENGER_H_ */
