#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFunciones.h"

int main()
{
    int opcion; // Variable donde se guardará la opción indicada (1 al 9)
    char seguir = 's';
    float operandoA = 0.0, operandoB = 0.0;
    float resultado; // Variable donde se guardará la operación indicada

    while (seguir == 's')
    {

        opcion = menu("\n1.Ingresar primer operando\n2.Ingresar segundo operando\n3.Sumar\n4.Restar\n5.Multiplicar\n6.Dividir\n7.Factorial\n8.Calcular todas las operaciones\n9.Salir\n\n");
        while(opcion > 9 || opcion < 1)
        {
        system("cls");
        opcion = menu("\n~OPCION INVALIDA~\n1.Ingresar primer operando\n2.Ingresar segundo operando\n3.Sumar\n4.Restar\n5.Multiplicar\n6.Dividir\n7.Factorial\n8.Calcular todas las operaciones\n9.Salir\n\n");
        }


        switch(opcion)
        {

        case 1: /**< Primer ingreso */
            printf("Primer operando:");
            scanf("%f", &operandoA);
            break;

        case 2: /**< Segundo ingreso */
            printf("Segundo operando:");
            scanf("%f", &operandoB);
            break;

        case 3: /**< Suma */
            resultado = sumar(operandoA, operandoB);
            printf("\n~ El resultado de la suma es %.2f ~\n\n", resultado);
            break;

        case 4: /**< Resta */
            resultado = restar(operandoA, operandoB);
            printf("\n~ El resultado de la resta es %.2f ~\n\n", resultado);
            break;

        case 5: /**< Multiplicación */
            resultado = multiplicar(operandoA, operandoB);
            printf("\n~ El resultado de la multiplicacion es %.2f ~\n\n", resultado);
            break;

        case 6: /**< División */
            if(operandoA == 0 || operandoB == 0)
            {
                printf("\nError! No se puede dividir por 0");
                break;
            }
            else
            {
                resultado = dividir(operandoA, operandoB);
                printf("\n~ El resultado de la division es %.2f ~", resultado);
                break;
            }

        case 7: /**< Factorización */
            resultado = factorial(operandoA);
            printf("~ El resultado de la factorizacion es %.2f ~", resultado);
            break;

        case 8: /**< Todas las operaciones */
            resultado = sumar(operandoA, operandoB);
            printf("\n~ El resultado de la suma es %.2f ~\n\n", resultado);
            resultado = restar(operandoA, operandoB);
            printf("\n~ El resultado de la resta es %.2f ~\n\n", resultado);
            resultado = multiplicar(operandoA, operandoB);
            printf("\n~ El resultado de la multiplicacion es %.2f ~\n\n", resultado);
            if(operandoA == 0 || operandoB == 0)
            {
                printf("\nError! No se puede dividir por 0");
                break;
            }
            else
            {
                resultado = dividir(operandoA, operandoB);
                printf("\n~ El resultado de la division es %.2f~ ", resultado);
                break;
            }
            resultado = factorial(operandoA);
            printf("\n~ El resultado de la factorizacion es %.2f ~", resultado);
            break;

        case 9: /**< Terminar programa */
            seguir= 'n';
            break;
        }

    seguir = tolower(seguir);

    }

    return 0;
}
