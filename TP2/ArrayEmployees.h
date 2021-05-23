#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/** \brief Indica que posiciones del array estan vacias para la carga de datos
 *
 * \param Employee* Estructura empleados
 * \param Tam tamano del array
 * \return -1 si la funcion arrojo error, 0 si esta OK
 *
 */

int initEmployee(Employee*,int);

/** \brief Carga los empleados en los lugares vacios desde la primera posicion
 *
 * \param Employee[]
 * \param int tam
 * \param *id
 * \return -1 si la funcion arrojo error, 0 si esta OK
 *
 */
/**int addEmployee(Employee[], int, int*, char , char , float , int);**/
int addEmployee(Employee*, int, int*);

/** \brief busca el empleado por id
 *
 * \param Employee[]
 * \param int tam
 * \param int id
 * \return -1 si la funcion arrojo error, 0 si esta OK
 *
 */
int findEmployeeById(Employee*, int, int);

 /** \brief modifica el empleado buscado por id
  *
  * \param list Employee*
  * \param int tam
  * \return -1 si la funcion arrojo error, 0 si esta OK
  *
  */
int modificarEmpleado(Employee*, int);

 /** \brief elimina al empleado buscado por id
  *
  * \param list Employee*
  * \param int tam
  * \return -1 si la funcion arrojo error, 0 si esta OK
  *
  */
int removeEmployee(Employee*, int);

  /** \brief Ordena de forma alfabetica los empleados y por sector
   *
   * \param list Employee*
   * \param int tam
   * \param int order 1 UP or 0 DOWN
   * \return -1 si la funcion arrojo error, 0 si esta OK
   *
   */
int sortEmployee(Employee*, int, int);

/** \brief imprime todos los empleados cargados
 *
 * \param list Employee*
 * \param int tam
 * \return -1 si la funcion arrojo error, 0 si esta OK
 *
 */
int printEmployee(Employee*, int);



#endif // ARRAYEMPLOYEES_H_INCLUDED
