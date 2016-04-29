#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../lib/MisFunciones.h"

int main()
{
    EPersona personas[CANTIDAD];
    inicializarEstado(personas);

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {

        opcion = menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n\n");

        switch(opcion)
        {
            case 1:
                agregarPersona(personas);
                break;
            case 2:
                borrarPersona(personas);
                break;
            case 3:
                imprimirLista(personas);
                break;
            case 4:
                imprimirGrafico(personas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

