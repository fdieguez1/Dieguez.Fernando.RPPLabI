#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#define MAX_DATE_LENGTH 11

typedef struct {
    int day;
    int month;
    int year;
} eDate;

/** \brief pasandole el mes devuelve la cantidad de dias maximos
 *
 * \param month int valor del mes en que se encuentra
 * \return int retorna 0 si es invalido, 1 si es valido
 *
 */
int validateDay(int value, int month);



/** \brief toma 3 enteros y los muestra con formato de fecha dd/MM/aaaa
 *
 * \param day int dia
 * \param month int mes
 * \param year int año
 * \return void
 *
 */
void printDate(int day, int month, int year);

/** \brief Pide al usuario una fecha
 *
 * \param date struct de date para guardar la fecha resultante
 * \return int -1 si fallo, 1 si funciono correctamente
 *
 */
int getDate(eDate *date);

#endif // DATE_H_INCLUDED
