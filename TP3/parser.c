#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) //pasarle el archivo abierto
{
	char idStr[SIZE_CHAR];
	char nombreStr[SIZE_CHAR];
	char horasTrabajadasStr[SIZE_CHAR];
	char sueldoStr[SIZE_CHAR];
	int retorno;
	Employee *pEmpleado;

	pEmpleado = employee_new();

	retorno = -1;

	if (pFile != NULL && pEmpleado != NULL) {
		while (!feof(pFile)) {
			if(fscanf(pFile, READ_FORMAT, idStr, nombreStr,horasTrabajadasStr, sueldoStr)== 4) {
				pEmpleado = employee_newParametros(idStr, nombreStr,horasTrabajadasStr,sueldoStr);
				if (pEmpleado != NULL) {
					ll_add(pArrayListEmployee, pEmpleado);
					retorno = 0;
				}
			}
		}
		fclose(pFile);
	}
	return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int flg_header = -1;
	int retorno = -1;
	int result = 0;
	char auxId[SIZE_CHAR];
	char auxNombre[SIZE_CHAR];
	char auxHorasTrabajadas[SIZE_CHAR];
	char auxSueldo[SIZE_CHAR];
	Employee currentEmployee;
	Employee *newEmployee;
	FILE *pFileText;

	//Primero leo el archivo en texto y lo guardo en binario y leo binario

	pFileText = fopen(SOURCE_DATA, "r");
	if (pFile != NULL && pArrayListEmployee != NULL && pFileText != NULL) {
		retorno = 0;
		while (!feof(pFile) && !feof(pFileText)) {
			if (flg_header) {
				flg_header = 0;
				result = fscanf(pFileText, READ_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
			} else {
				result = fscanf(pFileText, READ_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
				currentEmployee.id = atoi(auxId);
				strcpy(currentEmployee.nombre, auxNombre);
				currentEmployee.horasTrabajadas = atoi(auxHorasTrabajadas);
				currentEmployee.sueldo = atoi(auxSueldo);
				if (result == 4) {
					fseek(pFile, 0L, SEEK_END);
					fwrite(&currentEmployee, sizeof(currentEmployee), 1, pFile);
				}
			}
		}
		fclose(pFileText);
		fclose(pFile);
		pFile = fopen(SOURCE_DATA_BIN, "rb");
	}

	while (!feof(pFile)) {
		result = fread(&currentEmployee, sizeof(currentEmployee), 1, pFile);
		if (result == 1) {
			newEmployee = employee_new();
			employee_setId(newEmployee,currentEmployee.id);
			employee_setNombre(newEmployee,currentEmployee.nombre);
			employee_setHorasTrabajadas(newEmployee,currentEmployee.horasTrabajadas);
			employee_setSueldo(newEmployee,currentEmployee.sueldo);
			if (newEmployee != NULL) {
				ll_add(pArrayListEmployee, newEmployee);
			}
		}
	}
	fclose(pFile);

	return retorno;
}
