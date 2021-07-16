#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

#define MAX_CLIENT_LENGTH 51

typedef struct {
    int id;
    char descripcion[MAX_CLIENT_LENGTH];
} eLocalidad;

/** \brief carga automatica de localidades
 *
 * \param localidadArray[] eLocalidad arreglo de localidades
 * \param sizeL int tamaño localidades
 * \param int* localidadesId puntero al autoincremental para localidades
 * \return int 0 si hubo error, 1 si logro hardcodear
 *
 */
int hardcodeLocalidades(eLocalidad localidadArray[], int sizeL, int* localidadesId, int* conteoLocalidades);


/** \brief muestra los localidades y le pide al usuario que ingrese un localidad
 *
 * \param resultingId int* puntero para guardar el resultado
 * \param localidads[] eLocalidad arreglo de localidades
 * \param sizeL int tamaño del arreglo
 * \return int devuelve 1 si encontro el localidad 0 si no lo encontro
 *
 */
int getLocalidadId(int *resultingId, eLocalidad localidads[], int sizeL);

/** \brief busca un localidad en un arreglo de localidades pasando su id de legajo
 *
 * \param localidades[] eLocalidad arreglo de localidades
 * \param sizeLLT int tamaño del arreglo
 * \param id int id buscado
 * \param resultingLocalidad eLocalidad* resultado de la busqueda
 * \return int -1 si hubo error, 0 si no lo encontro, 1 si logro encontrarlo
 *
 */
int findLocalidadById(eLocalidad localidades[], int sizeL,int id, eLocalidad *resultingLocalidad);

/** \brief muestra un listado de localidades
 *
 * \param localidads[] eLocalidad listado de localidades
 * \param sizeL int tamaño del listado
 * \return void
 *
 */
void showLocalidades(eLocalidad localidads[], int sizeL);
/** \brief muestra un localidad
 *
 * \param localidad eLocalidad localidad
 * \param showTitles int para mostrar o no los titulos
 * \return void
 *
 */
void showLocalidad(eLocalidad localidad, int showTitles);

#endif // LOCALIDAD_H_INCLUDED
