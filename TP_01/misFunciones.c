#include <stdio.h>
#include <string.h>
#include <ctype.h>


/** \brief Solicita dos números a sumar
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


/** \brief Solicita dos números a restar
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


/** \brief Solicita dos números a multiplicar
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la multiplicación
 *
 */
float multiplicar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}


/** \brief Solicita dos números a dividir
 *
 * \param Primer operando
 * \param Segundo operando
 * \return Resultado de la división, en caso de dividir por 0 devuelve error
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
 * \return Resultado de la factorización
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


/** \brief Muestra una lista al usuario y devuelve la opción elegida
 *
 * \param Texto del menú (con sus opciones)
 * \return Opción elegida
 *
 */
int menu(char* items)
{
    int numero;
    printf(items);
    scanf("%d", &numero);
    return numero;
}
