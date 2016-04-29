#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "../lib/misFunciones.h"

void inicializarEstado(EPersona personas[])
{
    int i;
    for(i=0; i<CANTIDAD; i++)
    {
        personas[i].estado = 0;
    }
}

void agregarPersona(EPersona persona[])
{
    int i;
    for(i=0; i<CANTIDAD; i++)
    {
        if(persona[i].estado == 0)
        {
            fflush(stdin);
            if(getString(persona[i].nombre, "Ingrese nombre: ", "El nombre es invalido.\n", 2, 30) == -1)
            {
                break;
            }

            if(getShortInt(&persona[i].edad, "Ingrese edad: ", "La edad es invalida.\n", 1, 99) == -1)
            {
                break;
            }

            if(getLongInt(&persona[i].dni, "Ingrese DNI: ", "El DNI es invalido.\n", 5000000, 100000000) == -1)
            {
                break;
            }


            persona[i].estado = 1;

            break;
        }

        if(i == CANTIDAD-1)
        {
            printf("\n~ ~ No queda espacio en el sistema ~ ~\n\n");
        }
    }

}

void borrarPersona(EPersona persona[])
{

    int i;
    long int dni;
    printf("Ingrese el DNI de la persona que desea borrar: ");
    scanf("%ld", &dni);

    for(i=0; i<CANTIDAD; i++)
    {
        if(dni == persona[i].dni)
        {
            persona[i].estado = 0;
        }
    }

}

void ordenarPersonas(EPersona persona[])
{
    EPersona personaAux;
    int i, j;
    for(i=0; i<CANTIDAD-1; i++)
    {
        for(j=i+1; j<CANTIDAD; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] = personaAux;
            }

        }
    }
}


void imprimirLista(EPersona persona[])
{
    int i;
    for(i=0; i<CANTIDAD; i++)
    {
        if(persona[i].estado == 1)
        {
            ordenarPersonas(persona);

            printf("\n%s\n", persona[i].nombre);
            printf("%hi\n", persona[i].edad);
            printf("%ld\n", persona[i].dni);
            printf( "\n ~  ~  ~  ~  ~ \n" );

        }

    }


}

void imprimirGrafico(EPersona persona[])
{
    int i,x, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

    for(x=0; x<CANTIDAD; x++)
    {
        if(persona[x].estado == 1)
        {
            if(persona[x].edad <= 18)
            {
                hasta18++;
            }

            if(persona[x].edad >= 19 && persona[x].edad <= 35)
            {
                de19a35++;
            }

            if(persona[x].edad > 35)
            {
                mayorDe35++;
            }
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", hasta18, de19a35, mayorDe35);
}

