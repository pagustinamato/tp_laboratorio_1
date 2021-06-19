#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include "Employee.h"


/** \brief Busca el indice del array donde encuete el valor VACIO=0
 *
 * \param Employee[] Estructura empleados
 * \param Tam tamano del array
 * \return retorna el indice donde esta libre para cargar
 */
int BuscarLibreEmpleado(Employee[], int);

/** \brief Obtiene un cadena de caracteres
 *
 * \param int* puntero de numero ingresado
 * \param char* mensaje que se quiere mostar por pantalla
 * \param char* mensaje de error que se quiere mostar por pantalla
 * \param int cantidad de reintentos si se equivoca
 * \return -1 si la funcion arrojo error, 0 si esta OK
 *
 */
int utn_getNombre(char*,int, char*, char*, int);

/** \brief Obtiene un numero entero
 *
 * \param int* puntero de numero ingresado
 * \param char* mensaje que se quiere mostar por pantalla
 * \param char* mensaje de error que se quiere mostar por pantalla
 * \param int cantidad de reintentos si se equivoca
 * \return -1 si la funcion arrojo error, 0 si esta OK
 */
int utn_getNumero(int*, char*, char*, int, int, int);

/** \brief Obtiene un numero flotante
 *
 * \param int* puntero de numero ingresado
 * \param char* mensaje que se quiere mostar por pantalla
 * \param char* mensaje de error que se quiere mostar por pantalla
 * \param int cantidad de reintentos si se equivoca
 * \return -1 si la funcion arrojo error, 0 si esta OK
 */
int utn_getFloat(float*, char*, char*, int, int, int);

/** \brief Obtiene un numero entero
 *
 * \param int* puntero de numero ingresado
 * \return -1 si la funcion arrojo error, 0 si esta OK
 */
int getInt(int*);

/** \brief Obtiene un caracter
 *
 * \param char* puntero de caracter ingresado
 * \param char* mensaje que se quiere mostar por pantalla
 * \param char* mensaje de error que se quiere mostar por pantalla
 * \param int cantidad de reintentos si se equivoca
 * \return -1 si la funcion arrojo error, 0 si esta OK
 */
int utn_getCaracter(char*, char*, char*, int);

#endif // UTN_H_INCLUDED
