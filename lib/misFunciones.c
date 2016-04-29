#include <stdio.h>
#include <string.h>
#include "misFunciones.h"

int menu(char* items)
{
    int numero;
    printf(items);
    scanf("%d", &numero);
    return numero;
}

/**< getInt(&edad, "Ingrese edad", "Edad invalida", 1, 99); */
int getInt(int* ret, char* msg, char* error_msg, int min, int max)
{
    int numero;
    printf(msg);
    scanf("%d", &numero);

    if(numero <= min || numero >= max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        *ret = numero;
    }

    return 0;
}

int getShortInt(short int* ret, char* msg, char* error_msg, int min, int max)
{
    int numero;
    printf(msg);
    scanf("%d", &numero);

    if(numero <= min || numero >= max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        *ret = numero;
    }

    return 0;
}

int getLongInt(long int* ret, char* msg, char* error_msg, int min, int max)
{
    int numero;
    printf(msg);
    scanf("%d", &numero);

    if(numero <= min || numero >= max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        *ret = numero;
    }

    return 0;
}


/**< getString(&nombre, "Ingrese nombre", "nombre invalido", 2, 49); */
int getString(char* ret, char* msg, char* error_msg, int min, int max)
{
    char cadena[50];
    printf(msg);
    fflush(stdin);
    gets(cadena);

    if(strlen(cadena) <= min || strlen(cadena) >= max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        *ret = *cadena;
    }


    return 0;
}

/**< getFloat(&salario, "Ingrese salario", "salario invalido", 800, 50000); */
int getFloat(float* ret, char* msg, char* error_msg, int min, int max)
{
    float numero;
    printf(msg);
    scanf("%f", &numero);

    if(numero <= min || numero >= max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        *ret = numero;
    }
    return 0;
}
