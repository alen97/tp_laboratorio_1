#define CANTIDAD 5

typedef struct{
    char titulo[21];
    char genero[21];
    int duracion;
    char descripcion[51];
    int puntaje;
    char linkImagen[51];
    short int ocupado;
}EMovie;

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief Inicializa los flags de estado en 0
 *
 * \param Puntero a estructura EMovie
 *
 */
void inicializarEstados(EMovie* movie);


/** \brief Agrega una pelicula al registro
 *
 *  \param movie la estructura a ser agregada al archivo
 */
void agregarPelicula(EMovie* movie);


/** \brief Modifica una pelicula registrada
 *
 * \param movie la estructura a modificar
 * \return
 *
 */

void modificarPelicula(EMovie* movie);


/** \brief Elimina una pelicula registrada
 *
 * \param dato del tipo estructura EMovie
 * \return
 *
 */
void borrarPelicula(EMovie* movie);


/** \brief Genera un archivo HTML con los datos de las peliculas
 *
 * \param dato del tipo estructura EMovie
 *
 */
void generarPagina(EMovie* movie, char* nombre);

#endif // FUNCIONES_H_INCLUDED
