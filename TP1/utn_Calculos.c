#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Validar numero y cargar numero*/

int get_Numero(float numeroIngresado)
{
	float retorno;

	printf("Por favor ingrese un numero:");
	scanf("%f", &retorno);
	while(retorno == 0)
	{
		printf("El valor ingresado no es valido \n");
		printf("Ingrese un numero nuevamente \n");
		scanf("%f", &numeroIngresado);
		retorno=numeroIngresado;
	}
	return retorno;
}

/*suma*/

float suma(float numero1, float numero2)
{
	float total;

	total=numero1+numero2;
	return total;
}

/*resta*/

float resta(float numero1, float numero2)

{
	float total;
	total=numero1-numero2;
	return total;
}

/*division*/

float division(float numero1, float numero2)

{
	float total;

	total = (float)numero1/numero2;
	return total;
}

/*multiplicacion*/

float multiplicacion(float numero1, float numero2)

{
	float total;

	total = (float)numero1*numero2;
	return total;
}


/*Factorial de num1*/

float factorial(float numero1)

{
	float fact = 1;
	int i;
	int total;

	for (i = numero1; i > 1; i--)
	{
		fact = fact * i;
	}
	total=fact;
	return total;
}

void MuestraResultados(float resultadoSuma, float resultadoResta, float resultadoMultiplicacion,float resultadoDivision,float resultadoFactorialA,float resultadoFactorialB)
{
	printf("El resultado de la suma es: %.2f\n\nEl resultado de la resta es: %.2f\n\nEl resultado de la multiplicacion es: %.2f\n\nEl resutlado de la division es: %.2f\n\nEl factorial del numero A es: %.2f\n\nEl factorial del numero B es: %.2f\n\n",
			resultadoSuma,
			resultadoResta,
			resultadoMultiplicacion,
			resultadoDivision,
			resultadoFactorialA,
			resultadoFactorialB);
}

