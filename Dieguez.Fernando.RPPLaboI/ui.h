#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define UI_WIDTH 93
#define LIST_THUMBNAIL 175

/** \brief muestra un menu de opciones
 *
 * \return void
 *
 */
void showMenu();

/** \brief muestra un titulo de error y luego el mensaje proporcionado
 *
 * \param errorMsg[] char mensaje a mostrar
 * \return void
 *
 */
void showError(char errorMsg[]);

/** \brief muestra una alerta con opcion de confirmar o cancelar y devuelve la opcion elegida
 *
 * \param alertMsg[] char el mensaje a mostrar
 * \return int devuelve 1 si eligio confirmar, 0 si eligio cualquier otra cosa
 *
 */
int showAlert(char alertMsg[]);

/** \brief muestra titulos para el listado de empleados
 *
 * \return void
 *
 */
void showTitlesForEmployees();

/** \brief muestra titulos para el listado de sectores
 *
 * \return void
 *
 */
void showTitlesForSectors();

/** \brief muestra titulos para el listado de comidas
 *
 * \return void
 *
 */
void showTitlesForFoods();

/** \brief muestra titulos para el listado de almuerzos
 *
 * \return void
 *
 */
void showTitlesForLunchs();

/** \brief muestra opciones para la edicion de un empleado
 *
 * \return void
 *
 */

void showEditOptions();

/** \brief muestra opciones para el ordenamiento de empleados
 *
 * \return void
 *
 */
void showOrderOptions();

/** \brief muestra titulos para el listado de juegos
 *
 * \return void
 *
 */
void showTitlesForJuegos();

/** \brief muestra titulos para el listado de categorias
 *
 * \return void
 *
 */
void showTitlesForCategorias();


/** \brief muestra titulos para el listado de localidades
 *
 * \return void
 *
 */
void showTitlesForLocalidades();

/** \brief muestra titulos para el listado de clientes
 *
 * \return void
 *
 */
void showTitlesForClientes();


/** \brief muestra titulos para el listado de alquileres
 *
 * \return void
 *
 */
void showTitlesForAlquileres();

/** \brief Imprime una linea a lo largo de la pantalla para actuar de divisor
 *
 *
 */
void printDivisor();

/** \brief Imprime una linea a lo largo de la pantalla para actuar de divisor (menos densidad que la linea comun)
 *
 * \return void
 *
 */
void printTableDivisor();
/** \brief imprime un texto calculando el ancho del texto y el ancho del contenedor y lo centra
 *
 * \return void
 * \param char* text texto a centrar e imprimir
 * \param int totalWidth ancho total del contenedor
 *
 */
void centerText(char* text, int totalWidth);

#endif // UI_H_INCLUDED
