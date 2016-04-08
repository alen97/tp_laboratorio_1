#include <stdio.h>
#include <string.h>
#include <ctype.h>


/** \brief Solicita dos n�meros a sumar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la suma
 *
 */
void sumar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 + operando2;
    printf("\n~ El resultado de la suma es %.2f ~\n\n", resultado);
}


/** \brief Solicita dos n�meros a restar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la resta
 *
 */
void restar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 - operando2;
    printf("\n~ El resultado de la resta es %.2f ~\n\n", resultado);
}


/** \brief Solicita dos n�meros a multiplicar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la multiplicaci�n
 *
 */
void multiplicar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    printf("\n~ El resultado de la multiplicacion es %.2f ~\n\n", resultado);
}


/** \brief Solicita dos n�meros a dividir
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la divisi�n, en caso de dividir por 0 devuelve error
 *
 */
void dividir(float operando1, float operando2)
{
    float resultado;
    if(operando1 != 0 && operando1 != 0)
    {
        resultado = operando1 / operando2;
        printf("\n~ El resultado de la division es %.2f ~", resultado);
    }
    else
    {
        printf("\nError! No se puede dividir por 0");
    }

}


/** \brief Solicita un numero para factorizar y devuelve el resultado
 *
 * \param Numero a factorizar
 * \return Resultado de la factorizaci�n
 *
 */
long int factorial(long int numero)
{
    int x;
    long int resultado;

    if(numero != 1)
    {
        x = factorial(numero - 1);
        resultado = numero * x;
        return resultado;
    }
    else
    {
        return 1;
    }
}


/** \brief Muestra una lista al usuario y devuelve la opci�n elegida
 *
 * \param Texto del men� (con sus opciones)
 * \return Opci�n elegida
 *
 */
int menu(char* items)
{
    int numero;
    printf(items);
    scanf("%d", &numero);
    return numero;
}
