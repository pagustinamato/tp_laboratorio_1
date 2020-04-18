#include <stdio.h>

/*suma*/

float suma(float num1, float num2, float* presultado)
{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0);
	{
        total = (float)num1+num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*resta*/

float resta(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0);
	{
        total = (float)num1-num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*division*/

float division(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0);
	{
        total = (float)num1/num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*multiplicacion*/

float multiplicacion(float num1, float num2, float* presultado)

{
	float total;
	int retorno=1;

	if(presultado != NULL && num2 != 0);
	{
        total = (float)num1*num2;
		*presultado=total;
	 retorno=0;
	}
	return retorno;
}


/*Factorial de num1*/

float factorial_a(float num1, float* presultado)

{
	float total;
	int i, fact;
	int retorno=1;

	if(presultado != NULL && num1 != 0);
	{
        for(i=1; i<=num1;i++)
        {
            total = total * i;
        }
    *presultado=total;
	 retorno=0;
	}
	return retorno;
}

/*Factorial de num2*/
float factorial_b(float num2, float* presultado)

{
	float total;
	int i, fact;
	int retorno=1;

	if(presultado != NULL && num2 != 0);
	{
        for(i=1; i<=num2;i++)
        {
            total = total * i;
        }
    *presultado=total;
	 retorno=0;
	}
	return retorno;
}

