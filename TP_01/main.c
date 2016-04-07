#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFunciones.h"

int main()
{
    int opcion;
    char seguir = 's';
    float operandoA = 0.0, operandoB = 0.0;
    float resultado;

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
        case 1:
            printf("Primer operando:");
            scanf("%f", &operandoA);
            break;
        case 2:
            printf("Segundo operando:");
            scanf("%f", &operandoB);
            break;
        case 3:
            resultado = sumar(operandoA, operandoB);
            printf("\n~ El resultado de la suma es %.2f ~\n\n", resultado);
            break;
        case 4:
            resultado = restar(operandoA, operandoB);
            printf("\n~ El resultado de la resta es %.2f ~\n\n", resultado);
            break;
        case 5:
            resultado = multiplicar(operandoA, operandoB);
            printf("\n~ El resultado de la multiplicacion es %.2f ~\n\n", resultado);
            break;
        case 6:
            if(operandoA == 0 || operandoB == 0)
            {
                printf("Error! No se puede dividir por 0");
                break;
            }
            else
            {
            resultado = dividir(operandoA, operandoB);
            printf("El resultado es %.2f", resultado);
            break;
            }

        case 7:
            resultado = factorial(operandoA);
            break;
        case 8: // CALCULAR TODAS
            break;
        case 9:
            seguir= 'n';
            break;
        }

    seguir = tolower(seguir);

    }
 // AAASDADADa


    return 0;
}
