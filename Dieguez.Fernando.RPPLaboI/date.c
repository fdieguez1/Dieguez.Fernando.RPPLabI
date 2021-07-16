#include <stdio.h>
#include "date.h"
#include "inputs.h"

int getMaxDayForMonth(int month)
{
    int ret = 0;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        ret = 31;
        break;
    case 2:
        ret = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        ret = 30;
        break;
    }
    return ret;
}

void printDate(int day, int month, int year)
{
    printf("%02d/%02d/%04d", day, month, year);
}

int getDate(eDate *date)
{
    int ret = -1;
    ret = utn_getNumero(&date->year, "Ingrese anio: ", "Error, ingrese un anio valido", 1000 , 9999, 10);
    ret = utn_getNumero(&date->month, "Ingrese mes: ", "Error, ingrese un mes valido", 1 , 12, 10);
    int maxDays = getMaxDayForMonth(date->month);
    ret = utn_getNumero(&date->day, "Ingrese dia: ", "Error, ingrese un dia valido", 1 , maxDays, 10);
    return ret;
}

