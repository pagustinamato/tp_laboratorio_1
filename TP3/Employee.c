#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
#include "defines.h"



Employee* employee_new()
{
	Employee* empleado;

	empleado=(Employee*)malloc(sizeof(Employee));

	return empleado;
}


Employee* employee_newParametros(char *idStr, char *nombreStr,char *horasTrabajadasStr, char *sueldo)
{

	Employee *newEmployee = employee_new();

	if (newEmployee != NULL && idStr != NULL && nombreStr != NULL
			&& horasTrabajadasStr != NULL && sueldo != NULL) {
		if (employee_setId(newEmployee, atoi(idStr)) == 0
				&& employee_setHorasTrabajadas(newEmployee,
						atoi(horasTrabajadasStr)) == 0
						&& employee_setSueldo(newEmployee, atof(sueldo)) == 0) {
			return newEmployee;
		}
	}
	employee_delete(newEmployee);
	return NULL;
}


////////////////////////   SETTERS  /////////////////////////////////

int employee_setId(Employee *this, int id) {
	int retorno;
	int maxId = 0;
	retorno = -1;

	if (this != NULL) {
		retorno = 0;
		if (id < 0) {
			maxId++;
			this->id = id;
		} else {
			if (id > maxId) {
				maxId = id;
			}
			this->id = id;
		}
	}
	return retorno;
}


int employee_setNombre(Employee* this, char *nombre)
{
	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}

	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno = -1;

	if (this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno = -1;

	if (this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}


///////////////    GETTERS    /////////////////////////////////

int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno=-1;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre)
{
	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno = -1;

	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno = -1;

	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}


void employee_show(Employee *this) {
	if (this != NULL) {
		int id;
		int sueldo;
		int horasTrabajadas;
		char nombre[SIZE_CHAR];
		if (employee_getId(this, &id) == 0
				&& employee_getNombre(this, nombre) == 0
				&& employee_getHorasTrabajadas(this, &horasTrabajadas) == 0
				&& employee_getSueldo(this, &sueldo) == 0) {
			printf("ID: %d - NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d\n",
					id, nombre, sueldo, horasTrabajadas);
		}
	}
}

int employee_GetDataForNewEmployee(char *pNombre, char *phorasTrabajadas,
		char *pSueldo) {
	int retorno = -1;
	float *auxfloat = 0;
	int *auxint = 0;

	if (pNombre != NULL && phorasTrabajadas != NULL && pSueldo != NULL) {
		*auxfloat=atof(pSueldo);
		*auxint=atoi(phorasTrabajadas);
		if (utn_getNombre(pNombre, NAME,
				"Ingrese el nombre para el nuevo empleado: ",
				"ERROR!!!!  ingrese nuevamente el nombre\n", REINTENTOS) == 0
				&& utn_getNumero(auxint,
						"Ingrese las horas trabajadas para el nuevo empleado: ",
						"ERROR!!!! ingrese nuevamente el nombre\n",
						MIN_WORKED_HOURS, MAX_WORKED_HOURS, REINTENTOS) == 0
						&& utn_getFloat(auxfloat,
								"Ingrese el sueldo para el nuevo empleado: ",
								"ERROR!!!! ingrese nuevamente el nombre\n",
								MIN_SALARY, MAX_SALARY, REINTENTOS) == 0) {
			printf(" DATOS NUEVO EMPLEADO \n");
			retorno = 0;
		}

	}
	return retorno;
}

int employee_OrderListEmployeesByName(void *pOne, void *pTwo) {
	int retorno = -1;
	Employee *auxEmployeeOne;
	Employee *auxEmployeeTwo;
	char nameOne[SIZE_CHAR];
	char nameTwo[SIZE_CHAR];

	if (pOne != NULL && pTwo != NULL) {

		auxEmployeeOne = (Employee*) pOne;
		auxEmployeeTwo = (Employee*) pTwo;
		if (employee_getNombre(auxEmployeeOne, nameOne) == 0
				&& employee_getNombre(auxEmployeeTwo, nameTwo) == 0) {
			if (strcmp(nameOne, nameTwo) > 0) {
				printf("El ordenamiento se realizo de forma exitosa");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int employee_OrderListEmployeesByWordedHours(void *pOne, void *pTwo) {
	int retorno = -1;
	Employee *auxEmployeeOne;
	Employee *auxEmployeeTwo;
	int hoursOne;
	int hoursTwo;

	if (pOne != NULL && pTwo != NULL) {
		auxEmployeeOne = (Employee*) pOne;
		auxEmployeeTwo = (Employee*) pTwo;
		if (employee_getHorasTrabajadas(auxEmployeeOne, &hoursOne) == 0
				&& employee_getHorasTrabajadas(auxEmployeeTwo, &hoursTwo)
		== 0) {
			if (hoursOne > hoursTwo) {
				printf("El ordenamiento se realizo de forma exitosa");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int employee_OrderListEmployeesBySalary(void *pOne, void *pTwo) {
	int retorno = -1;
	Employee *auxEmployeeOne;
	Employee *auxEmployeeTwo;
	int salaryOne;
	int salaryTwo;

	if (pOne != NULL && pTwo != NULL) {
		auxEmployeeOne = (Employee*) pOne;
		auxEmployeeTwo = (Employee*) pTwo;
		if (employee_getSueldo(auxEmployeeOne, &salaryOne) == 0
				&& employee_getSueldo(auxEmployeeTwo, &salaryTwo) == 0) {
			if (salaryOne > salaryTwo) {
				printf("El ordenamiento se realizo de forma exitosa");
				retorno = 0;
			}
		}
	}
	return retorno;
}
