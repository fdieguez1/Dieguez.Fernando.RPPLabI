#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

#define MAX_CLIENT_LENGTH 51

typedef struct {
    int id;
    char descripcion[MAX_CLIENT_LENGTH];
} eCategoria;

/** \brief carga automatica de categorias
 *
 * \param categoriaArray[] eCategoria arreglo de categorias
 * \param sizeC int tamaño categorias
 * \param int* categoriasId puntero al autoincremental para categorias
 * \return int 0 si hubo error, 1 si logro hardcodear
 *
 */
int hardcodeCategorias(eCategoria categoriaArray[], int sizeC, int* categoriasId, int* conteoCategorias);


/** \brief muestra los categorias y le pide al usuario que ingrese un categoria
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param categorias[] eCategoria arreglo de categorias
 * \param sizeC int tamaño del arreglo
 * \return int devuelve 1 si encontro el categoria 0 si no lo encontro
 *
 */
int getCategoriaId(int *resultingId, eCategoria categorias[], int sizeC);

/** \brief busca un categoria en un arreglo de categorias pasando su id de legajo
 *
 * \param categorias[] eCategoria arreglo de categorias
 * \param sizeCLT int tamaño del arreglo
 * \param id int id buscado
 * \param resultingCategoria eCategoria* resultado de la busqueda
 * \return int -1 si hubo error, 0 si no lo encontro, 1 si logro encontrarlo
 *
 */
int findCategoriaById(eCategoria categorias[], int sizeC,int id, eCategoria *resultingCategoria);

/** \brief muestra un listado de categorias
 *
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado
 * \return void
 *
 */
void showCategorias(eCategoria categorias[], int sizeC);
/** \brief muestra un categoria
 *
 * \param categoria eCategoria categoria
 * \param showTitles int para mostrar o no los titulos
 * \return void
 *
 */
void showCategoria(eCategoria categoria, int showTitles);

#endif // CATEGORIA_H_INCLUDED
