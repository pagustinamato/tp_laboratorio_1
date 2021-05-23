#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define T 1000


int main()
{
    setbuf(stdout,NULL);

    Employee empleado[T];
    int opcion;
    int menu;
    int resultado;
    int flagCarga=0;
    int id;
    int indice;


    indice=initEmployee(empleado,T);
    respuestaMenu(indice);

    do
    {
        menu=utn_getNumero(&opcion,"\n1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n\n", "Error, reingrese nuevamente una opcion\n",1,5,2);
        if(menu==0)
        {
            switch(opcion)
            {
            case 1:
                resultado=addEmployee(empleado,T,&id);
                respuestas(resultado);
                flagCarga=1;
                break;
            case 2:
                if(flagCarga==1)
                {
                    resultado=modificarEmpleado(empleado,T);
                    respuestas(resultado);
                }
                else
                {
                    printf("Debere realizar la carga de un empleado primero");
                }
                break;
            case 3:
                if(flagCarga==1)
                {
                    resultado=removeEmployee(empleado,T);
                    respuestas(resultado);
                }
                else
                {
                    printf("Debere realizar la carga de un empleado primero");
                }
                break;
            case 4:
                if(flagCarga==1)
                {
                    menu=utn_getNumero(&opcion,"1-Lista los empleados ordenados alfabeticamente por Apellido y Sector\n2-Total de promedio de salarios y cantidad de empleados que superan el mismo\n\n",
                                       "Error reingrese nuevamente una opcion\n\n",1,2,2);
                    if(menu==0)
                    {
                        if(opcion==1)
                        {
                            resultado=sortEmployee(empleado,T,1);
                            resultado=printEmployee(empleado,T);
                            respuestas(resultado);
                        }
                        else
                        {
                            salarioPromedio(empleado,T);
                        }
                    }
                }
                else
                {
                    printf("Debere realizar la carga de un empleado primero");
                }
                break;
            }
        }
    }
    while(opcion!=5);

    return 0;
}
