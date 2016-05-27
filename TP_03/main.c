#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../lib/misFunciones.h"

int main()
{
    EMovie pMovie[CANTIDAD];
    char seguir='s';
    char nombreArchivo[31] = "index.html";
    int opcion=0;

    inicializarEstados(pMovie);

    while(seguir=='s')
    {

        opcion = menu("~Menu:\n1- Agregar pelicula\n2- Modificar pelicula\n3- Borrar pelicula\n4- Generar pagina web\n5- Salir\n\n", "Opcion invalida !\n", 5);

        switch(opcion)
        {
            case 1:
                agregarPelicula(pMovie);
                break;
            case 2:
                modificarPelicula(pMovie);
                break;
            case 3:
                borrarPelicula(pMovie);
                break;
            case 4:
                generarPagina(pMovie, nombreArchivo);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
