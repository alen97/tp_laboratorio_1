#include <stdio.h>
#include <string.h>
#include "misFunciones.h"

int menu(char* items, char* errorMsg, int cantidad)
{
    int numero;
    printf(items);
    scanf("%d", &numero);
    if(numero > 0 && numero <= cantidad)
    {
        return numero;
    }
    else
    {
        printf("%s\n",errorMsg);
        return -1;
    }

}

/**< getInt(&edad, "Ingrese edad", "Edad invalida", 1, 99); */
int getInt(int* ret, char* msg, char* error_msg, int min, int max)
{
    int numero;
    printf(msg);
    scanf("%d", &numero);

    if(numero < min || numero > max)
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
    short int numero;
    printf(msg);
    scanf("%hi", &numero);

    if(numero < min || numero > max)
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
    long int numero;
    printf(msg);
    scanf("%ld", &numero);

    if(numero < min || numero > max)
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

int getChar(char* ret, char* msg, char* error_msg)
{
    char caracter;
    printf(msg);
    fflush(stdin);
    scanf("%c", &caracter);

    if(sizeof(caracter) > 1 || sizeof(caracter) < 0) /**< REVISAR SIZEOF */
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        ret = &caracter;
    }


    return 0;
}

/**< getString(&nombre, "Ingrese nombre", "nombre invalido", 2, 49); */
int getString(char* ret, char* msg, char* error_msg, int min, int max)
{
    char cadena[max+1], buffer[5060];
    printf(msg);
    fflush(stdin);
    gets(buffer);

    if(strlen(buffer) < min || strlen(buffer) > max)
    {
        printf (error_msg); /**< FUERA RANGO */
        return -1;
    }
    else
    {
        strcpy(cadena,buffer);
        strcpy(ret, cadena);
    }


    return 0;
}

/**< getFloat(&salario, "Ingrese salario", "salario invalido", 800, 50000); */
int getFloat(float* ret, char* msg, char* error_msg, int min, int max)
{
    float numero;
    printf(msg);
    scanf("%f", &numero);

    if(numero < min || numero > max)
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
