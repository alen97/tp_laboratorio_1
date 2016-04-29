#define CANTIDAD 20

typedef struct
{

    char nombre[50];
    short int edad;
    short int estado; /**< 0: Vac�o - 1: Ocupado */
    long int dni;

}EPersona;


/** \brief Inicializa los flag de estado en 0 (Vac�o)
 *
 * \param Variable de la estructura
 */
void inicializarEstado(EPersona personas[]);

/** \brief
 *
 * \param Variable de la estructura
 */
void agregarPersona(EPersona persona[]);
void borrarPersona(EPersona persona[]);
void ordenarPersonas(EPersona persona[]);
void imprimirLista(EPersona persona[]);
void imprimirGrafico(EPersona persona[]);
