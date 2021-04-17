#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	float numeroA;
	float numeroB;
	float resultadoSuma;
	float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactorialA;
    float resultadoFactorialB;
	int opcion;

	opcion=0;
	do{
		setbuf(stdout, NULL);

		printf("1. Ingresar el 1er operando:\n");
		printf("2. Ingresar el 2do operando:\n");
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n\n");
		printf("5. Salir\n");
		printf("Elija una opcion:");
		scanf("%d", &opcion);

		switch(opcion)
		{
		/*ingresa los numeros a tomar*/
		case 1:
			numeroA=get_Numero(numeroA);
			printf("El numero es %f:\n\n", numeroA);
			break;
		case 2:
            numeroB=get_Numero(numeroA);
			printf("El numero es %f:\n\n", numeroB);
			break;
        case 3:
            resultadoSuma=suma(numeroA,numeroB);
            resultadoResta=resta(numeroA,numeroB);
            resultadoMultiplicacion=multiplicacion(numeroA,numeroB);
            resultadoDivision=division(numeroA,numeroB);
            resultadoFactorialA=factorial(numeroA);
            resultadoFactorialB=factorial(numeroB);
            break;
        case 4:
             MuestraResultados(resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision,resultadoFactorialA,resultadoFactorialB);
             break;
		}
	}while (opcion != 5);
	system("pause");
	return EXIT_SUCCESS;
}
