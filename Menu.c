#include <stdio.h>
#include <stdlib.h>
#include "aritmetica.h"

int main(void) {

      setbuf(stdout, NULL);

      float a, b, x, resultado, resultado_b;
	  int l, respuesta, respuesta2;

	  /*ingresa los numeros a tomar*/
	  printf("ingrese numero uno:");
	  scanf("%f", &a);
	  printf("ingrese numero dos:");
	  scanf("%f", &b);

	  printf("ingrese opcion a realizar 1-suma  2-resta  3-division  4-multiplicacion 5-factorial: ");
	  scanf("%d", &l);

	  switch(l)
	  {
	   case 1:
	       { respuesta=suma(a,b,&resultado);
	       	   if(respuesta == 0);
	       	   {
	       printf("\nEl resultado de la suma es: %f", resultado);
	            break;}}

	   case 2:
	          { respuesta=resta(a,b,&resultado);
	       	   if(respuesta == 0);
	       	   {
	       printf("\nEl resultado de la resta es: %f", resultado);
	            break;}}

	   case 3:
	        { respuesta=division(a,b,&resultado);
	       	   if(respuesta == 0);
	       	   {
	       printf("El resultado de la division es: %f", resultado);
	            break;}}

	   case 4:
	         { respuesta=multiplicacion(a,b,&resultado);
	       	   if(respuesta == 0);
	       	   {
	       printf("El resultado de la multiplicacion es: %f", resultado);
	            break;}}
	   case 5:
	          { respuesta=factorial_a(a,&resultado);
                respuesta2=factorial_b(b,&resultado_b);
	       	   if(respuesta == 0 && respuesta2 == 0);
	       	   {
	       printf("El factorial de A es %f y el factorial de B es %f", resultado, resultado_b);
	            break;}}
	  }
	  system("pause");
	return EXIT_SUCCESS;
}
