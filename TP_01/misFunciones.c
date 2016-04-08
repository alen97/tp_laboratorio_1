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
float sumar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 + operando2;
    return resultado;
}


/** \brief Solicita dos n�meros a restar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la resta
 *
 */
float restar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 - operando2;
    return resultado;
}


/** \brief Solicita dos n�meros a multiplicar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la multiplicaci�n
 *
 */
float multiplicar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}


/** \brief Solicita dos n�meros a dividir
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la divisi�n, en caso de dividir por 0 devuelve error
 *
 */
float dividir(float operando1, float operando2)
{
    float resultado;
    if(operando2 != 0)
    {
        resultado = operando1 / operando2;
        return resultado;
    }
    else
    {
        return 0;
    }

}


/** \brief Solicita un numero para factorizar y devuelve el resultado
 *
 * \param Numero a factorizar
 * \return Resultado de la factorizaci�n
 *
 */
long int factorial(int numero)
{
    int x;

    if(numero != 1)
    {
        x = factorial(numero - 1);
        return (numero * x);
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
