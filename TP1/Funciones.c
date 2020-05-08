#include <stdio.h>

/*suma*/

int suma(float num1, float num2, float* presultado)
{
	float total;
	int retorno=1;

	if(presultado	!=	NULL	&&	num2	!=	0)
	{
        total = (float)num1+num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*resta*/

int resta(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0)
	{
        total = (float)num1-num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*division*/

int division(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0)
	{
        total = (float)num1/num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*multiplicacion*/

int multiplicacion(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0)
	{
        total = (float)num1*num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}


/*Factorial de num1*/

int factorial(float num1, float* presultado)

{
	float fact = 1;
	int i;
	int retorno=1;

	if(presultado != NULL && num1 != 0)
	{
       for (i = num1; i > 1; i--){
    fact = fact * i;
}
    *presultado=fact;
	 retorno=0;
	}
	return retorno;
}


