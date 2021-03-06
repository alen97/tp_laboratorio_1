#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "../lib/misFunciones.h"

void inicializarEstados(EMovie* movie)
{
    int i;
    for(i=0; i<CANTIDAD; i++)
    {
        movie[i].ocupado = 0;
    }
}

void agregarPelicula(EMovie* movie)
{
    int i;

    for(i=0; i<CANTIDAD; i++)
    {
        if(movie[i].ocupado != 1)
        {

            if(getString(movie[i].titulo, "\nIngrese el titulo de la pelicula: ", "\n~~Titulo invalido!\n\n", 2, 20) == -1)
            {
                break;
            }

            if(getString(movie[i].genero, "Genero: ", "\n~~Genero invalido!\n\n", 2, 20) == -1)
            {
                break;
            }

            if(getInt(&movie[i].duracion, "Duracion en minutos: ", "\n~~Duracion invalida!\n\n", 20, 200) == -1)
            {
                break;
            }

            if(getString(movie[i].descripcion, "Descripcion: ", "\n~~Descripcion invalida!\n\n", 10, 140) == -1)
            {
                break;
            }

            if(getInt(&movie[i].puntaje, "Puntaje: ", "\n~~Puntaje invalido!\n\n", 1, 10) == -1)
            {
                break;
            }

            if(getString(movie[i].linkImagen, "Link a la portada: ", "\n~~Link invalido!\n\n", 10, 50) == -1)
            {
                break;
            }

            movie[i].ocupado = 1;

            printf("\n~La pelicula '%s' fue registrada!\n\n", movie[i].titulo);

            break;
        }

        if(i == CANTIDAD-1) /**< �ltima iteraci�n */
        {
            printf("No hay mas memoria.\n");
        }
    }


}

void modificarPelicula(EMovie* movie)
{
    char auxPeli[31], auxTitulo[31], auxGenero[31], auxDesc[141], auxLink[60];
    int i, opcion, auxDuracion, auxPuntaje;
    short int flagSeguir = 1;

    if(getString(auxPeli, "\nIngrese el titulo de la pelicula a modificar: ", "\n~Titulo invalido!\n\n", 2, 20) != -1)
    {
        for(i=0; i<CANTIDAD; i++)
        {
            if(strcmp(auxPeli, movie[i].titulo) == 0)
            {

                do
                {
                    opcion = menu("\n~Menu de modificaciones:\n1- Titulo\n2-Genero\n3-Duracion\n4-Descripcion\n5-Puntaje\n6-Link a la imagen\n7-Volver al menu principal\n\n", "\n~Opcion invalida!\n\n", 7);

                    switch(opcion)
                    {
                        case 1:

                            if(getString(auxTitulo, "\nIngrese el nuevo titulo de la pelicula: ", "\n~~Titulo invalido!\n\n", 2, 20) != -1)
                            {
                                if(strcmp(movie[i].titulo, auxTitulo) == 0)
                                {
                                    printf("\n~El titulo ingresado es igual al anterior! !\n\n");
                                }
                                else
                                {
                                    strcpy(movie[i].titulo, auxTitulo);
                                    printf("\n~El titulo fue modificado exitosamente!\n\n");
                                }

                            }
                            break;

                        case 2:
                            if(getString(auxGenero, "\nIngrese el nuevo genero de la pelicula: ", "\n~~Genero invalido!\n\n", 2, 20) != -1)
                            {
                                if(strcmp(movie[i].genero, auxGenero) == 0)
                                {
                                    printf("\n~El genero ingresado es igual al anterior! !\n\n");
                                }
                                else
                                {
                                    strcpy(movie[i].genero, auxGenero);
                                    printf("\n~El genero fue modificado exitosamente!\n\n");
                                }
                            }
                            break;

                        case 3:
                            if(getInt(&auxDuracion, "\nIngrese la nueva duracion (minutos) : ", "\n~~Duracion invalida!\n\n", 20, 200) != -1)
                            {
                                if(movie[i].duracion == auxDuracion)
                                {
                                    printf("\n~La duracion ingresada es igual al anterior! !\n\n");
                                }
                                else
                                {
                                    movie[i].duracion = auxDuracion;
                                    printf("\n~La duracion fue modificada exitosamente!\n\n");
                                }
                            }
                            break;

                        case 4:
                            if(getString(auxDesc, "\nIngrese la nueva descripcion: ", "\n~~Descripcion invalida!\n\n", 10, 140) != -1)
                            {
                                if(strcmp(movie[i].descripcion, auxDesc) == 0)
                                {
                                    printf("\n~La descripcion ingresada es igual al anterior! !\n\n");
                                }
                                else
                                {
                                    strcpy(movie[i].descripcion, auxDesc);
                                    printf("\n~La descripcion fue modificada exitosamente!\n\n");
                                }
                            }
                            break;

                        case 5:
                            if(getInt(&auxPuntaje, "\nIngrese el nuevo puntaje: ", "\n~~Puntaje invalido!\n\n", 1, 10) != -1)
                            {
                                if(movie[i].puntaje == auxPuntaje)
                                {
                                    printf("\n~El puntaje ingresado es igual al anterior! !");
                                }
                                else
                                {
                                    movie[i].puntaje = auxPuntaje;
                                    printf("\n~El puntaje fue modificado exitosamente!\n");
                                }
                            }
                            break;

                        case 6:
                            if(getString(auxLink, "\nIngrese el nuevo link a la imagen: ", "\n~~Link invalido!\n\n", 10, 50) != -1)
                            {
                                if(strcmp(movie[i].linkImagen, auxLink) == 0)
                                {
                                    printf("\n~El link ingresado es igual al anterior! !");
                                }
                                else
                                {
                                    strcpy(movie[i].linkImagen, auxLink);
                                    printf("\n~El link fue modificado exitosamente!\n");
                                }
                            }
                            break;

                        case 7:
                            flagSeguir = 0;
                            break;
                    }

                }while(flagSeguir==1);

                if(flagSeguir == 0) /**< Rompe el for */
                {
                    break;
                }

            }
            else
            {
                if(i == CANTIDAD-1) /**< �ltima iteraci�n */
                {
                    printf("\n~Pelicula inexistente! Verifique el titulo e intente nuevamente.\n\n");
                    break;
                }
            }

        }
    }
}

void borrarPelicula(EMovie* movie)
{
    char aux[30];
    int i;

    if(getString(aux, "\nIngrese el titulo de la pelicula a eliminar: ", "\n~Titulo invalido!\n\n", 2, 20) != -1)
    {
        for(i=0; i<CANTIDAD; i++)
        {
            if(movie[i].ocupado == 1)
            {
                if(strcmp(movie[i].titulo, aux) == 0)
                {
                    movie[i].ocupado = 0;
                    printf("\n~Pelicula '%s' eliminada!\n\n", movie[i].titulo);
                    break;
                }
            }

            if(i == CANTIDAD-1)
            {
            printf("\n~No se encontraron datos!\n\n");
            }
        }
    }
}

void generarPagina(EMovie* movie, char* nombre)
{
     FILE *pArch;
     char fijoUno[] = "<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>";
     char fijoDos[] = "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";
     char dinamico[512], dinamicAux[512];
     int i;
     short int hayDatos = 0;

     pArch = fopen(nombre, "w");

     if(pArch == NULL)
     {
          printf("\n~No se pudo abrir el archivo!\n");
     }
     else
     {
         for(i=0; i<CANTIDAD; i++)
         {
              if(movie[i].ocupado == 1)
              {
                    sprintf(dinamicAux, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>", movie[i].linkImagen, movie[i].titulo, movie[i].genero, movie[i].puntaje, movie[i].duracion, movie[i].descripcion);

                    strcat(dinamico, dinamicAux);

                    if(hayDatos == 0)
                    {
                        hayDatos = 1;
                    }

              }

              if(i == CANTIDAD-1)
              {
                  if(hayDatos == 0)
                  {
                      printf("\n~No hay peliculas en la base de datos.\n\n");
                  }

              }
         }

         if(hayDatos == 1)
         {
             fwrite(fijoUno, sizeof(fijoUno), 1, pArch); //
             fwrite(dinamico, sizeof(dinamico), 1, pArch);
             fwrite(fijoDos, sizeof(fijoDos), 1, pArch);

             printf("\n\n~Pagina web generada exitosamente!\n\n");
         }

      }
      fclose(pArch);
}
