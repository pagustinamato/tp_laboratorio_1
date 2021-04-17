#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/**
 * @fn int get_Numero(float)
 * @brief Pide el numero ingresado, valida que no se igual a 0, y carga el mismo en memoria.
 *
 * @param Numero ingresado por pantalla
 * @return Devuelve el numero que se ingreso por pantalla, tras su validacion
 */
int get_Numero(float numeroIngresado);

/**
 * @fn float suma(float, float)
 * @brief Realiza la operacion aritmetica de sumar los numeros que se ingreson
 *
 * @param numero1  El  primer numero que se ingreso por pantalla
 * @param numero2  El  segundo numero que se ingreso por pantalla
 * @return Devuelve el resultado de la suma de los numeros ingresados
 */
float suma(float numero1, float numero2);

/**
 * @fn float resta(float, float)
 * @brief Realiza la operacion aritmetica de sumar los numeros que se ingreson
 *
 * @param numero1 El  primer numero que se ingreso por pantalla
 * @param numero2 El  segundo numero que se ingreso por pantalla
 * @return Devuelve el resultado de la resta de los numeros ingresados
 */
float resta(float numero1, float numero2);

/**
 * @fn float multiplicacion(float, float)
 * @brief Realiza la operacion aritmetica de multiplicar los numeros que se ingreson
 *
 * @param numero1 El  primer numero que se ingreso por pantalla
 * @param numero2 El  segundo numero que se ingreso por pantalla
 * @return Devuelve el resultado de la multiplicacion de los numeros ingresados
 */
float multiplicacion(float numero1, float numero2);

/**
 * @fn float division(float, float)
 * @brief Realiza la operacion aritmetica de division los numeros que se ingreson
 *
 * @param numero1 El  primer numero que se ingreso por pantalla
 * @param numero2 El  segundo numero que se ingreso por pantalla
 * @return Devuelve el resultado de la division de los numeros ingresados
 */
float division(float numero1, float numero2);

/**
 * @fn float factorial(float)
 * @brief Realiza la operacion aritmetica de calcular el factorial los numeros que se ingreson
 *
 * @param numero1 Numero que se ingresa
 * @return Devuelve el factorial del numero ingresado
 */
float factorial(float numero1);

/**
 * @fn void MuestraResultados(float, float, float, float, float, float)
 * @brief Muestra por pantalla el resultado de todas las operaciones aritmeticas que se realizaron en la opcion 3
 *
 * @param resultadoSuma -- Resultado de la suma
 * @param resultadoResta -- Resultado de la resta
 * @param resultadoMultiplicacion -- Resultado de la multiplicacion
 * @param resultadoDivision -- Resultado de la Division
 * @param resultadoFactorialA -- Resultado del factorial del NumeroA
 * @param resultadoFactorialB -- Resultado del factorial del NumeroB
 */
void MuestraResultados(float resultadoSuma, float resultadoResta, float resultadoMultiplicacion,float resultadoDivision,float resultadoFactorialA,float resultadoFactorialB);

#endif // UTN_H_INCLUDED
