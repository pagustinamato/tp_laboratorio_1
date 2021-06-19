#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "defines.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf(stdout,NULL);

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	switch (MainMenu()) {
    			case 1:
    				controller_loadFromText(SOURCE_DATA, listaEmpleados);
    				break;
    			case 2:
    				controller_loadFromBinary(SOURCE_DATA_BIN, listaEmpleados);
    				break;
    			case 3:
    				controller_addEmployee( listaEmpleados);
    				break;
    			case 4:
    				controller_editEmployee( listaEmpleados);
    				break;
    			case 5:
    				controller_removeEmployee( listaEmpleados);
    				break;
    			case 6:
    				controller_ListEmployee( listaEmpleados);
    				break;
    			case 7:
    				controller_sortEmployee( listaEmpleados);
    				break;
    			case 8:
    				controller_saveAsText(SOURCE_DATA, listaEmpleados);
    				break;
    			case 9:
    				controller_saveAsBinary(SOURCE_DATA_BIN, listaEmpleados);
    				break;
    			case 10:
    				ll_clear(listaEmpleados);
    				ll_deleteLinkedList(listaEmpleados);
    				exit(0);
    				break;
    			}
    }while(1);
    return 0;
}

