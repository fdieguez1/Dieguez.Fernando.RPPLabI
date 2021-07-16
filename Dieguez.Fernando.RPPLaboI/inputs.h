#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

#include "date.h"

//Biblioteca de inputs basada en Apunte_Inputs_V1.3 UTN FRA
/** \brief Verifica si la cadena ingresada es numerica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \return int Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
 int esNumerica(char* cadena);


/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 *
 * \param cadena char* Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud int Define el tamaño de cadena
 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
 int myGets(char* cadena, int longitud);



/** \brief Verifica si la cadena ingresada es un entero
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return int Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
 int getInt(int* pResultado);

/** \brief  Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char[] mensaje Es el mensaje a ser mostrado
 * \param char[] mensajeError Es el mensaje de Error a ser mostrado
 * \param int minimo Es el numero minimo a ser aceptado
 * \param int maximo Es el numero maximo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
                  maximo, int reintentos);

/** \brief obtiene un string y lo guarda en un puntero
 *
 * \param pResultado char*  arreglo de chars para guardar el string
 * \return int -1 si hubo error, 0 si funciono
 *
 */
int getString(char* pResultado);

/** \brief pide un string al usuario y verifica que este dentro del maximo del tamaño del arreglo que lo va a almacenar
 *
 * \param resultingString[] char puntero a memoria del arreglo de chars donde se guardara el resultado
 * \param title[] char titulo a mostrar para el ingreso
 * \param maxLength int largo maximo para el arreglo de caracteres
 * \return int devuelve -1 si hubo error, 1 si todo resulto ok
 *
 */
int askForString(char resultingString[], char title[], int maxLength);

/** \brief pide el ingreso de sexo para la carga pasandole un puntero y un arreglo de opciones posibles
 *
 * \param pSex char puntero de char para guardar la opcion elegida
 * \param posibleValues[] char valores posibles a ser evaluados
 * \param title[] char titulo para mostrar
 * \return int 0 si hubo error, 1 si lo logro
 *
 */
int askSex(char *pSex, char title[]);

/** \brief Verifica si la cadena ingresada es numerica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \return int Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int isFloat(char* str);


/** \brief Verifica si la cadena ingresada es un float
 *
 * \param resultingFloat float* puntero para el resultado
 * \return int devuelve 1 si obtuvo el numero -1 si hubo error
 *
 */
int getFloat(float* resultingFloat);

/** \brief  Solicita un flotante al usuario, luego de verificarlo devuelve el resultado
 *
 * \param resultingFloat Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param char[] message Es el mensaje a ser mostrado
 * \param char[] errorMessage Es el mensaje de Error a ser mostrado
 * \param float minF Es el flotante minimo a ser aceptado
 * \param float maxF Es el flotante maximo a ser aceptado
 * \return Retorna 1 si se obtuvo el flotante y -1 si no
 *
 */
float myGetFloat(float* resultingFloat, char* message, char* errorMessage, float minF, float
                  maxF, int reintentos);


int stringToLower(char str[]);
int stringToUpper(char str[]);

/** \brief compara dos fechas y dice si son iguales o mayores una que la otra
 *
 * \param dateA eDate* fecha a
 * \param dateB eDate* fecha b
 * \return int 0 si son iguales, -1 si a es menor, 1 si a es mayor
 *
 */
int compareDates(eDate dateA, eDate dateB);

#endif // INPUTS_H_INCLUDED
