#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFunciones.h"

int main()
{
    int opcion; /**< Variable donde se guardará la opción indicada (1 al 9) */
    char seguir = 's';
    float operandoA = 0.0, operandoB = 0.0;

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
            sumar(operandoA, operandoB);
            break;

        case 4: /**< Resta */
            restar(operandoA, operandoB);
            break;

        case 5: /**< Multiplicación */
            multiplicar(operandoA, operandoB);
            break;

        case 6: /**< División */
            dividir(operandoA, operandoB);
            break;

        case 7: /**< Factorización */
            printf("~ El resultado de la factorizacion es %li ~", factorial((long)operandoA));
            break;

        case 8: /**< Todas las operaciones */
            sumar(operandoA, operandoB);
            restar(operandoA, operandoB);
            multiplicar(operandoA, operandoB);
            dividir(operandoA, operandoB);
            factorial(operandoA);
            printf("~ El resultado de la factorizacion es %li ~", factorial((long)operandoA));

        case 9: /**< Terminar programa */
            seguir= 'n';
            break;
        }

    seguir = tolower(seguir);

    }

    return 0;
}
