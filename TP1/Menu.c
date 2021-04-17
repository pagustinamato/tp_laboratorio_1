#include <stdio.h>
#include <stdlib.h>
#include "aritmetica.h"

int main(void) {

	float a, b, resultado, resultado_b;
	int respuesta, respuesta_b;
	char c;
	do{
		setbuf(stdout, NULL);
		system("cls");
		/*ingresa los numeros a tomar*/

		printf("1 : ingrese operando A:");
		scanf("%f", &a);
		printf("2 : ingrese operando B:");
		scanf("%f", &b);

		/*Muestra los numero cargados*/
		printf("El operando A es: %f y el operando B es: %f",a,b);

		/*Ejecuta las funciones de calculo*/
		respuesta=suma(a,b,&resultado);
		if(respuesta==0)
		{
			printf("\nEl resultado de la suma de A+B es: %f", resultado);
		};
		respuesta=resta(a,b,&resultado);
		if(respuesta == 0)
		{
			printf("\nEl resultado de la resta de A-B es: %f", resultado);
		};
		respuesta=multiplicacion(a,b,&resultado);
		if(respuesta == 0)
		{
			printf("\nEl resultado de la multiplicacion de A*B es: %f", resultado);
		};
		respuesta=division(a,b,&resultado);
		if(respuesta == 0)
		{
			printf("\nEl resultado de la division de A/B es: %f", resultado);
		}
		else
		{
			printf("\nERROR: No se puede dividir por 0\n");
			break;
		}
		respuesta=factorial(a,&resultado);
		respuesta_b=factorial(b,&resultado_b);
		if(respuesta == 0 && respuesta_b == 0)
		{
			printf("\nEl factorial del operando A es %f y el factorial de B es: %f",resultado, resultado_b);
		}
		printf("\n\nDesea continuar?");
		scanf("%s",&c);
	}while (c != 'n');
	system("pause");
	return EXIT_SUCCESS;
}
