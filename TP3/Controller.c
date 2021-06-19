#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Menu.h"


static int loadFromText = 0;
static int loadFromBinary = 0;
static void ListEmployees(LinkedList *pArrayListEmployee);
static int OrderListEmployees(LinkedList *pArrayListEmployee, int dataToOrder,int order);


int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) //abrir el archivo y pasarselo al loadfrom text
{
	FILE *pArchivo;
	int retorno = -1;

	printf("INICIO DE LEER DE ARCHIVO DE TEXTO \n");
	if (path != NULL && pArrayListEmployee != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			printf("Se abrio el archivo %s en modo lectura \n", path);
			if(parser_EmployeeFromText(pArchivo, pArrayListEmployee) == 0) {
				printf("Se leyeron los datos de forma exitosa \n");
				retorno = 0;
			} else {
				printf("Error no se pueden leer los datos \n");
			}
		} else {
			printf("Error no se puede abrir el archivo \n");
		}
	}
	printf("Finaliza la lectura del archivo \n");
	return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("INICIO DE LEER DE ARCHIVO DE BINARIO \n");
	int retorno = -1;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL) {
		//Primero leo el archivo en texto y lo guardo en binario y leo binario
		pFile = fopen(path, "rb");
		if(pFile != NULL){
			printf("Archivo: %s abierto en modo lectura. \n", path);
			parser_EmployeeFromBinary(pFile, pArrayListEmployee,1);
			loadFromBinary = 1;
		}else{
			printf("Archivo inexistente. Intentando leer archivo en modo escritura. Se tomaran datos desde el archivo de texto\n");
			pFile = fopen(path, "wb");
			if(pFile != NULL){
				printf(" Archivo: %s abierto en modo escritura. \n", path);
				parser_EmployeeFromBinary(pFile, pArrayListEmployee,0);
				printf("Se leyeron los datos correctamente. \n");
				retorno = 0;
				loadFromBinary = 1;
			}else{
				printf("Error al abrir el archivo binario. \n");
			}
		}
	} else {
		printf("ERROR!!! No se pueden leer los datos del archivo. \n");
	}
	printf("FIN DE LEER DE ARCHIVO DE BINARIO \n");
	return retorno;
}


int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno =-1;
	Employee *newEmployee;
	char nombre[SIZE_CHAR];
	char horasTrabajadas[SIZE_CHAR];
	char sueldo[SIZE_CHAR];


	printf("Se inicia la carga del empleado \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {

		if (employee_GetDataForNewEmployee(nombre, horasTrabajadas, sueldo)==0) {
			printf("Se ingreso correctamente los datos para cargar el nuevo empleado!!.\n");
			newEmployee = employee_newParametros(DEFAULT_ID, nombre,horasTrabajadas, sueldo);
			if(newEmployee != NULL){
				ll_add(pArrayListEmployee,newEmployee);
				retorno = 0;
			}else{
				printf("Error!! No se puede agregar el empleado, disculpe.\n");
			}

			printf("Se ingreso correctamente el nuevo empleado!!.\n");
		} else {
			printf("Error!! No se ingresaron correctamente los datos para el nuevo empleado.\n");
		}
	} else {
		printf(
				"Error!! La lista esta apuntando a NULL, no se puede agregar elementos.\n");
		printf(
				" Primero leer el archivo en texto o binario, para poder agregar elementos.\n");
	}
	printf("Finaliza la carga del empleado \n");
	return retorno;
}



int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	char nombre[SIZE_CHAR];
	int horasTrabajadas;
	int sueldo;
	char respuestaUsuario = 's';
	int index = -1;
	int resultGetIndex;
	int sizeArray;
	Employee *currentEmployee;

	printf("EDITAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {

		sizeArray = ll_len(pArrayListEmployee);
		ListEmployees(pArrayListEmployee);
		resultGetIndex = utn_getNumero(&index,"Ingrese el indice del empleado a modificar: ","ERROR!!!! ingrese un indice correcto\n", 1, sizeArray,REINTENTOS);
		if (!resultGetIndex && index != -1) {
			retorno = 0;
			currentEmployee = (Employee*) ll_get(pArrayListEmployee,index - 1);
			employee_show(currentEmployee);
			do {
				switch (ModifyMenu()) {
				case 1:
					utn_getNombre(nombre, NAME,
							"Ingrese el nombre para el empleado: ",
							"ERROR!!!!  ingrese nuevamente el nombre\n", REINTENTOS);
					employee_setNombre(currentEmployee, nombre);
					printf("Se modifico correctamente el nombre del empleado.\n");
					utn_getCaracter(&respuestaUsuario, "Quiere seguir modificando datos? (s - n): ",
							"ERROR!!!! ingrese s o n\n", REINTENTOS);
					break;
				case 2:
					utn_getNumero(&horasTrabajadas,
							"Ingrese las nuevas horas trabajadas (el minimo es 1): ",
							"ERROR!!!! ingrese correctamente las horas trabajadas\n",
							MIN_WORKED_HOURS, MAX_WORKED_HOURS, REINTENTOS);
					employee_setHorasTrabajadas(currentEmployee,
							horasTrabajadas);
					printf("Se modifico correctamente las horas trabajadas del empleado.\n");
					utn_getCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							"ERROR!!!! ingrese s o n\n", REINTENTOS);
					break;
				case 3:
					utn_getNumero(&sueldo, "Ingrese el nuevo salario MIN 1.000 MAX 1000000:\t",
							"ERROR!!!! ingrese correctamente el salario\n",
							MIN_SALARY, MAX_SALARY, REINTENTOS);
					employee_setSueldo(currentEmployee, sueldo);
					printf("Se modifico correctamente el sueldo del empleado.\n");
					utn_getCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							"ERROR!!!! ingrese s o n\n", REINTENTOS);
					break;
				case 4:
					respuestaUsuario = 'n';
					break;
				}
			} while (respuestaUsuario == 's');
		} else {
			printf(
					"ERROR!!!! En el ingreso de datos, no se puede modificar el empleado.\n");
		}
	} else {
		printf(
				"ERROR!!!! La lista esta apuntando a NULL o la lista esta vacia, no se puede editar elementos.\n");
	}
	printf("FIN DE EDITAR EMPLEADO \n");
	return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char respuestaUsuario = 's';
	int index = -1;
	int resultGetIndex;
	int sizeArray;
	Employee *currentEmployee;

	printf(" INICIO DE BORRAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		sizeArray = ll_len(pArrayListEmployee);
		ListEmployees(pArrayListEmployee);
		resultGetIndex = utn_getNumero(&index,"Ingrese el indice del empleado a borrar: ","ERROR!!!! ingrese un indice correcto\n", 1, sizeArray,REINTENTOS);
		if (!resultGetIndex && index != -1) {
			currentEmployee = (Employee*) ll_get(pArrayListEmployee,index - 1);
			employee_show(currentEmployee);
			utn_getCaracter(&respuestaUsuario,
					"Esta seguro que quiere borrar este empleado (s - n)?: ",
					"ERROR!!!! ingrese correctamente la opcion\n",REINTENTOS);
			if (respuestaUsuario == 's') {
				retorno = 0;
				employee_delete(currentEmployee);
				ll_remove(pArrayListEmployee, index - 1);
				printf("Se borro correctamente el empleado.\n");
			} else {
				printf(
						"Cancelando operacion eliminar empleado.\n");
			}
		} else {
			printf(
					"ERROR!!!! En el ingreso de datos, no se puede modificar el empleado.\n");
		}
	} else {
		printf(
				"ERROR!!!! La lista esta apuntando a NULL o la lista esta vacia, no se puede borrar elementos.\n");
	}
	printf(" FIN DE BORRAR EMPLEADO \n");
	return retorno;
}



int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	printf("INICIO DE LISTAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		retorno = 0;
		ListEmployees(pArrayListEmployee);
	} else {
		printf(
				"ERROR!!!! La lista esta apuntando a NULL o la lista esta vacia, no se puede mostrar elementos.\n");
	}
	printf("FIN DE LISTAR EMPLEADO \n");
	return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int order;
	int dataToOrder;
	printf("INICIO DE ORDENAR EMPLEADOS \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		retorno = 0;
		utn_getNumero(&order,"Ingrese el orden de ordenamiento de la lista(0 - DESC / 1 - ASC): ","ERROR!!!! ingrese 0 o 1\n", 0, 1,REINTENTOS);
		utn_getNumero(&dataToOrder,"1-Nombre\n2-Horas Trabajadas\n3-Salario\nIngrese el por que quiere ordenar la lista: ",	"ERROR!!!! ingrese 1 o 2 o 3\n", 1,	3, REINTENTOS);
		OrderListEmployees(pArrayListEmployee, dataToOrder, order);
		printf(" Se ordeno exitosamente \n");
		ListEmployees(pArrayListEmployee);
	} else {
		printf("ERROR!!!! La lista esta apuntando a NULL o la lista esta vacia, no se puede ordenar elementos.\n");
	}
	printf("FIN DE ORDENAR EMPLEADOS \n");
	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	printf("INICIO DE GUARDAR COMO TEXTO \n");
	int retorno = -1;
	FILE *pFile;
	int sizeArray;
	int i = 0;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[SIZE_CHAR];
	Employee *currentEmployee;
	Node *nodo;

	if(loadFromText){
		if (path != NULL && pArrayListEmployee != NULL) {
			pFile = fopen(path, "w");
			if (pFile != NULL) {
				fputs("id,nombre,horasTrabajadas,sueldo\n", pFile);
				printf("Insercion archivo.\n");
				sizeArray = ll_len(pArrayListEmployee);
				nodo= pArrayListEmployee->pFirstNode;
				while (i < sizeArray && nodo != NULL) {
					currentEmployee = (Employee*) nodo->pElement;
					employee_getId(currentEmployee, &id);
					employee_getNombre(currentEmployee,	nombre);
					employee_getHorasTrabajadas(currentEmployee,&horasTrabajadas);
					employee_getSueldo(currentEmployee,	&sueldo);
					fprintf(pFile, DATA_FORMAT_SAVE, id,nombre,horasTrabajadas,sueldo);
					i++;
					nodo = nodo->pNextNode;
				}
				printf("Proceso finalizado.\n");
				retorno = 0;
			} else {
				printf("ERROR!!!! En la apertura de archivo.\n");
			}
			fclose(pFile);
		} else {
			printf("ERROR!!! La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
		}
	}else{
		printf("ERROR!!! El archivo que se cargo en el inicio es binario , no se puede guardar en texto.\n");
	}
	printf("FIN DE GUARDAR COMO TEXTO \n");
	return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("INICIO DE GUARDAR COMO BINARIO \n");
	int retorno = -1;
	FILE *pFile;
	int sizeArray;
	int i = 0;
	Employee *currentEmployee;
	Employee currentEmployeeToSave;
	Node *nodo;

	if(loadFromBinary){
		if (path != NULL && pArrayListEmployee != NULL) {
			pFile = fopen(path, "wb");
			if (pFile != NULL) {
				sizeArray = ll_len(pArrayListEmployee);
				nodo = pArrayListEmployee->pFirstNode;
				while (i < sizeArray && nodo != NULL) {
					currentEmployee = (Employee*) nodo->pElement;
					employee_getId(currentEmployee, &currentEmployeeToSave.id);
					employee_getNombre(currentEmployee,	currentEmployeeToSave.nombre);
					employee_getHorasTrabajadas(currentEmployee,&currentEmployeeToSave.horasTrabajadas);
					employee_getSueldo(currentEmployee,	&currentEmployeeToSave.sueldo);
					fseek(pFile, 0L, SEEK_END);
					fwrite(&currentEmployeeToSave, sizeof(currentEmployeeToSave), 1,pFile);
					i++;
					nodo = nodo->pNextNode;
				}
				fclose(pFile);
			}
			printf("Proceso finalizado. Se guardo en forma binario, en el siguiente archivo: %s\n", path);
			retorno = 0;
		} else {
			printf("ERROR!!!! La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
		}
	}else{
		printf("ERROR!!!! El archivo que se cargo en el inicio es texto, no se puede guardar en binario.\n");
	}
	printf("FIN DE GUARDAR COMO BINARIO \n");
	return retorno;
}

static void ListEmployees(LinkedList *pArrayListEmployee) {
	printf("INICIO DE LISTA DE EMPLEADOS\n");
	int sizeArray = ll_len(pArrayListEmployee);
	int i = 0;
	Employee *currentEmployee;
	Node *nodo = pArrayListEmployee->pFirstNode;
	while (i < sizeArray && nodo != NULL) {
		currentEmployee = (Employee*) nodo->pElement;
		printf("INDICE:[%d] - ", (i + 1));
		employee_show(currentEmployee);
		i++;
		nodo = nodo->pNextNode;
	}
	printf("FIN DE LISTA DE EMPLEADOS\n");
}

static int OrderListEmployees(LinkedList *pArrayListEmployee, int dataToOrder,int order) {
	int retorno = -1;
	printf("INICIO DE ORDENAMIENTO LISTA DE EMPLEADOS\n");
	if (pArrayListEmployee != NULL && dataToOrder > 0 && order > -1) {
		retorno = 0;
		if (order) {
			printf("Ordenamiento ascendente\n");
		} else {
			printf("Ordenamiento descendente\n");
		}
		switch (dataToOrder) {
		case 1:
			printf(" Ordenamiento por nombre\n");
			ll_sort(pArrayListEmployee, employee_OrderListEmployeesByName,order);
			break;
		case 2:
			printf(" Ordenamiento por horas trabajadas\n");
			ll_sort(pArrayListEmployee,	employee_OrderListEmployeesByWordedHours, order);
			break;
		case 3:
			printf("Ordenamiento por salario\n");
			ll_sort(pArrayListEmployee, employee_OrderListEmployeesBySalary,order);
			break;
		}
		printf("Ordenamiento finalizado\n");
	} else {
		printf("ERROR!!! La lista esta apuntando a NULL .\n");
	}
	printf("FIN DE ORDENAMIENTO LISTA DE EMPLEADOS\n");
	return retorno;
}
