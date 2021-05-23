#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"


int initEmployee(Employee* empleado, int tam)
{
    int i;
    int retorno=-1;

    if(tam >0)
    {
        retorno=0;
        for(i=0; i<tam; i++)
        {
            empleado[i].isEmpty=VACIO;
        }
    }
    return retorno;
}

int BuscarLibreEmpleado(Employee empleado[], int tam)
{
    int i;
    int index;
    index = -1;

    for(i=0; i<tam; i++)
    {
        if(empleado[i].isEmpty == VACIO)//Criterio de busqueda
        {
            index = i;
            break;
        }
    }

    return index;
}

/**int addEmployee(Employee empleado[], int tam, int* id, char name, char lastname, float salary, int sector)
{
    int index;
    int retorno=-1;
    Employee auxEmpleado;

    index=BuscarLibreEmpleado(empleado, tam);

    if(tam > 0 && id != NULL && index ==0)
    {

        if(utn_getNombre(&name,NAME,"\nIngrese Nombre: ","\nNombre no valido\n",2)==0 &&
           utn_getNombre(&lastname,NAME,"\nIngrese Apellido: ","\nApellido no valido\n",2)==0 &&
           utn_getNumero(&sector,"\nIngrese Sector:","\nElija una opcion valida\n",1,4,2)==0)
        {
            strcpy(auxEmpleado.name,&name);
            strcpy(auxEmpleado.lastname,&lastname);
            auxEmpleado.sector=sector;
            empleado[index]=auxEmpleado;
            empleado[index].isEmpty=OCUPADO;
            empleado[index].id=*id;
            *id = *id + 1;
            retorno=0;
        }
    }
    else
    {
        printf("No hay mas lugar en memoria para guardar otro producto.");
    }
    return retorno;
}**/
int addEmployee(Employee* empleado, int tam, int* id)
{
    int index;
    int retorno=-1;
    Employee auxEmpleado;

    index=BuscarLibreEmpleado(empleado, tam);

    if(tam > 0 && id != NULL && index != -1)
    {
        if(utn_getNombre(auxEmpleado.name,NAME,"\nIngrese Nombre: ","\nNombre no valido\n",2)==0 &&
                utn_getNombre(auxEmpleado.lastname,NAME,"\nIngrese Apellido: ","\nApellido no valido\n",2)==0 &&
                utn_getNumero(&auxEmpleado.sector,"\nIngrese Sector:","\nElija una opcion valida\n",1,4,2)==0 &&
                utn_getFloat(&auxEmpleado.salary,"\nIngrese Salario:","\nElija una opcion valida\n",1000,1000000,2)==0)
        {
            empleado[index]=auxEmpleado;
            empleado[index].isEmpty=OCUPADO;
            empleado[index].id=*id;
            *id = *id + 1;
            retorno=0;
        }
    }
    else
    {

        printf("No hay mas espacio en memoria para cargar empleados");
    }
    return retorno;
}

int findEmployeeById(Employee* empleado, int tam, int id)
{
    int i;
    int retorno;

    for(i=0; i<tam; i++)
    {
        if(id == empleado[i].id && empleado[i].isEmpty==OCUPADO)
        {
            retorno=i;
            break;
        }
    }
    return retorno;

}

int modificarEmpleado(Employee* empleado, int tam)
{
    int retorno=-1;
    int opcion;
    int id;
    int indice;
    int resultado;
    Employee auxEmpleado;

    printEmployee(empleado,tam);
    printf("\nIngrese el ID: \n");
    resultado=getInt(&id);
    indice=findEmployeeById(empleado,tam,id);
    fflush(stdin);

    if(resultado==0 && indice >=0 && utn_getNumero(&opcion,"\nDesea modificar:\n1-Nombre\n2-Apellido\n3-Sector\n4-Salario\nEliga opcion: ",
            "Elija una opcion valida\n",1,4,2)==0)
    {
        //printf("funcion getnumero funciono");
        switch(opcion)
        {
        case 1:
            if(utn_getNombre(auxEmpleado.name,NAME,"Ingrese Nombre\n","Nombre no valido\n",2)==0)
            {
                strcpy(empleado[indice].name,auxEmpleado.name);
                retorno=0;
            }
            break;
        case 2:
            if(utn_getNombre(auxEmpleado.lastname,NAME,"Ingrese Apellido\n","Apellido no valido\n",2)==0)
            {
                strcpy(empleado[indice].lastname,auxEmpleado.lastname);
                retorno=0;
            }
            break;
        case 3:
            if(utn_getNumero(&auxEmpleado.sector,"\nIngrese Sector:","\nElija una opcion valida\n",1,4,2)==0)
            {
                empleado[indice].sector=auxEmpleado.sector;
                retorno=0;
            }
            break;
        case 4:
            if(utn_getFloat(&auxEmpleado.salary,"\nIngrese Salario:","\nElija una opcion valida\n",1000,1000000,2)==0)
            {
                empleado[indice].salary=auxEmpleado.salary;
                retorno=0;
            }
            break;
        }
    }
    return retorno;

}

int removeEmployee(Employee* empleado, int tam)
{
    int retorno=-1;
    int id;
    int indice;
    int resultado;

    printEmployee(empleado,tam);
    printf("\nIngrese el ID: \n");
    resultado=getInt(&id);
    indice=findEmployeeById(empleado,tam,id);
    fflush(stdin);

    if(resultado==0 && indice >=0)
    {
        empleado[indice].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;

}

int sortEmployee(Employee* empleado, int tam, int order)
{
    int i;
    int j;
    int retorno=-1;
    Employee aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            printf("%d",order);
            if(order==0)
            {
                if(empleado[i].sector<empleado[j].sector && strcmp(empleado[i].lastname, empleado[j].lastname)<0)
                {
                    aux=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=aux;
                    retorno=0;
                }
            }
            else if(empleado[i].sector>empleado[j].sector && strcmp(empleado[i].lastname, empleado[i].lastname)>0)
            {
                aux=empleado[i];
                empleado[i]=empleado[j];
                empleado[j]=aux;
                retorno=0;
            }
        }
    }
    return retorno;
}

int printEmployee(Employee* empleado, int tam)
{
    int i;
    int retorno=-1;

    mostrarSoloColumnas();
    for(i=0; i<tam; i++)
    {
        if(empleado[i].isEmpty==OCUPADO)
        {
            mostrar(empleado[i]);
            retorno=0;
        }
    }
    return retorno;
}

void mostrarSoloColumnas()
{
    printf("\nID\t\tNombre\t\tApellido\t\tSector\n");
}

void mostrar(Employee empleado)
{
    printf("%d\t\t%s\t\t%-2s\t\t\t%2d\n",empleado.id, empleado.name,empleado.lastname,empleado.sector);
}

void salarioPromedio(Employee* empleado, int tam)
{
    int i;
    int empContador;
    float acum;
    float total;

    empContador=0;

    if(empleado != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(empleado[i].isEmpty==OCUPADO)
            {
                acum=acum+empleado[i].salary;
                empContador++;
            }
        }
    }
    total=acum/empContador;
    empContador=0;
    empContador=empMayorSalarioPromedio(empleado,tam,total);

    printf("Total Salarios\t\tPromedio de Salario\t\tCant. de empleados con salario mayor al promedio\n%.2f\t\t%5.2f\t\t%14d", acum,total,empContador);

}

int empMayorSalarioPromedio(Employee* empleado, int tam, float promedioSalario)
{
    int i;
    int contadorEmpleado;

    contadorEmpleado=0;

    if(empleado != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(empleado[i].salary>promedioSalario && empleado[i].isEmpty==OCUPADO)
            {
                contadorEmpleado++;
            }
        }
    }
    return contadorEmpleado;
}

void respuestas(int respuesta)
{
    if(respuesta==0)
    {
        printf("La operacion se realizo con exito!! ");
    }
    else
    {
        printf("Error al realizar la operacion.");
    }
}

void respuestaMenu(int respuesta)
{
    if(respuesta==0)
    {
        printf("Se inicializo con exito!! ");
    }
    else
    {
        printf("Error al inicializar.");
    }
}
