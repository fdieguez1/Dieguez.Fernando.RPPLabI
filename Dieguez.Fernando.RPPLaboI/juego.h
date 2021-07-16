#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "categoria.h"

#define LARGO_MAX_NOMBRE 20

typedef struct {
    int codigo;
    char descripcion[LARGO_MAX_NOMBRE];
    float importe;
    int idCategoria;
} eJuego;

/** \brief carga automatica de juegos
 *
 * \param juegoArray[] eJuego arreglo de juegos
 * \param sizeJ int tamaño juegos
 * \param int* juegoId puntero del autoincremental de id de juego
 * \param int primera categoria cargada
 * \return int 0 si hubo error, 1 si logro hardcodear
 *
 */
int hardcodeJuegos(eJuego juegoArray[], int sizeJ, int* juegoId, int categoriaId, int* conteoJuegos);

/** \brief muestra los juegos y le pide al usuario que ingrese un juego
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param juegos[] eJuego arreglo de juegos
 * \param sizeJ int tamaño del arreglo
 * \return int devuelve 1 si encontro el juego 0 si no lo encontro
 *
 */
int getJuegoId(int *resultingId, eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);

/** \brief busca por id un juego y lo almacena en una variable dada
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado
 * \param id int id a buscar
 * \param resultingJuego eJuego* juego devuelto por la funcion
 * \return int devuelve 1 si encontro, 0 si no lo encontro, -1 si hubo error
 *
 */
int getJuegoById(eJuego juegos[], int sizeJ, int id,eJuego* resultingJuego);

/** \brief muestra un listado de juegos
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado
 * \return void
 *
 */
void showJuegos(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);
/** \brief muestra un juego
 *
 * \param juego eJuego juego
 * \param showTitles int para mostrar o no los titulos
 * \return void
 *
 */
void showJuego(eJuego juego, int showTitles, eCategoria categorias[], int sizeC);

/** \brief devuelve el indice de un juego en un listadoo
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado
 * \param id int id de juego a buscar
 * \return int devuelve el indice del juego encontrado
 *
 */
int findJuegoById(eJuego juegos[], int sizeJ,int id);
#endif // JUEGO_H_INCLUDED
