#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include "ArrayEmployees.h"

#define NAME 50
#define DESCRIPCION 50

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

/** \brief Muestra solo los datos cargados, sin descripcion
 * \param Employee Estructura empleados
 * \return
 */
void mostrar(Employee);

/** \brief Muestra solo las columnas
 * \param
 * \return
 *
 */
void mostrarSoloColumnas();

/** \brief Calcula el salario promedio de los empleados
 *
 * \param Employee* Estructura empleados
 * \param int Tam tamano del array
 * \return
 */
void salarioPromedio(Employee*, int);

/** \brief Calcula la cantidad de empelados que superaron el salario promedio
 *
 * \param Employee* Estructura empleados
 * \param int Tam tamano del array
 * \param float salario promedio
 * \return int cantidad de empleados que superan el salario promedio
 *
 */
int empMayorSalarioPromedio(Employee*,int, float);

/** \brief Muestra si el resultado que retorna las funciones fuero OK o no.
 * \param int resultado de funciones
 * \return
 */
void respuestas(int);

/** \brief Muestra si la opcion ingresada en el menu es valida
 * \param int  resultado de funcion
 * \return
 */
void respuestaMenu(int);

#endif // UTN_H_INCLUDED
