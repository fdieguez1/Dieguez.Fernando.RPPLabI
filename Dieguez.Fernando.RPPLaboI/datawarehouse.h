#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

#define ARRAYS_LENGTH 20
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 21
#include "date.h"

int ages[ARRAYS_LENGTH];

char names[ARRAYS_LENGTH][MAX_NAME_LENGTH];
char lastnames[ARRAYS_LENGTH][MAX_NAME_LENGTH];

char sexs[ARRAYS_LENGTH];

float salaries[ARRAYS_LENGTH];

eDate dates[ARRAYS_LENGTH];

int sectorsId[5];

char sectorNames[5][MAX_NAME_LENGTH];

char foodNames[ARRAYS_LENGTH][MAX_NAME_LENGTH];

float foodprices[5];

char descripcionJuegos[5][MAX_NAME_LENGTH];

char descripcionCategorias[5][MAX_NAME_LENGTH];

char phones[5][MAX_PHONE_LENGTH];

char localidades[ARRAYS_LENGTH][MAX_NAME_LENGTH];

#endif // DATAWAREHOUSE_H_INCLUDED
