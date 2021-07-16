#define ARRAYS_LENGTH 20
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 21

#include "date.h"

int ages[ARRAYS_LENGTH] = {23,21,22,30,28,19,18,20,19,32,30,7,50,60,87,24,66,54,45,41};

char names[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Henry", "Alexander", "Sabrina", "Abigail", "Ned","Cherry","Kelsey","Alen","James","Rebecca",
                                              "Victor", "Gianna","Caroline","Alisa","Nicole","Chelsea","Edward","Agata","Roland","Dexter"
                                             };
char lastnames[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Watson", "Ellis", "West", "Sullivan", "Elliott","Morrison","Thomas","Williams","Elliott","Evans",
                                              "Crawford", "Kelly","Owens","Ellis","Jones","Elliott","Campbell","Murphy","Morrison","Bailey"
                                             };


char sexs[ARRAYS_LENGTH] = {'m','m','f','f','m','f','f','m','m','f','m','f','f','f','f','f','m','f','m','m'};

float salaries[ARRAYS_LENGTH] = {35000.20, 25000.00, 23000.00, 11000.00, 99000.00, 23000.00, 14000.00, 65000.00, 75000.00, 30000.00,
                                 10000.00, 96000.00, 45000, 43500.00, 11000.00, 99000.00, 23000.00, 14000.00, 65000.00, 75000.00
                                };

eDate dates[ARRAYS_LENGTH] = {{14,1,2002}, {20,3,2010}, {25,12,1999}, {23,12,2003}, {9,8,2004}, {10,1,2000}, {11,11,2001}, {16,12,1999}, {1,1,1990}, {2,3,2003},
    {30,9,1956}, {10,8,1988}, {31,5,1997}, {5,5,2000}, {6,11,2020}, {4,4,2021}, {2,4,2013}, {2,6,1980}, {2,10,1993},
};

int sectorsId[ARRAYS_LENGTH] = {404,500,406,200,402,404,500,200,200,200,404,500,500,200,406,404,500,402,200,406};

char sectorNames[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"RRHH", "Administracion", "Legales", "Sistemas", "Contabilidad","RRHH", "RRHH", "Sistemas", "Sistemas",
                                                    "Contabilidad","RRHH", "Administracion", "Legales", "Sistemas", "Sistemas","RRHH", "Contabilidad", "Legales", "Legales", "Contabilidad"
                                                   };

char foodNames[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Milanesas", "Pollo", "Churrasco", "Ensalada", "Chimichurri puro","Milanesas", "Pollo", "Churrasco", "Ensalada", "Chimichurri puro","Milanesas", "Pollo", "Churrasco", "Ensalada", "Chimichurri puro","Milanesas", "Pollo", "Churrasco", "Ensalada", "Chimichurri puro"};

float foodprices[ARRAYS_LENGTH] = {115.50, 125, 110.50, 101, 99,115.50, 125, 110.50, 101, 99,115.50, 125, 110.50, 101, 99,115.50, 125, 110.50, 101, 99};

char descripcionJuegos[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Monopoly","Dados", "TEG","Bingo","Trucos","DOOM","Generala", "CS GO","Minecraft","Los Sims","SimCity","Ludo", "TEG 2","Monkey loco","Castillo inflable","Mario bross","NeedForSpeed", "Battlefield","Adivina quien","batalla naval"};

char descripcionCategorias[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Mesa", "Azar", "Estrategia", "salon", "Magia","Mesa", "Azar", "Estrategia", "salon", "Magia","Mesa", "Azar", "Estrategia", "salon", "Magia","Mesa", "Azar", "Estrategia", "salon", "Magia"};

char phones[ARRAYS_LENGTH][MAX_PHONE_LENGTH]= {"1134334400","1526310452","1592982453","1135544254","1171004456","1134334400","1526310452","1592982453","1135544254","1171004456","1134334400","1526310452","1592982453","1135544254","1171004456","1134334400","1526310452","1592982453","1135544254","1171004456"};

char localidades[ARRAYS_LENGTH][MAX_NAME_LENGTH] = {"Lomas de Zamora", "Banfield", "Lanus", "Sarandi", "Temperley","Lanus","Avellaneda","Lanus","Lomas de Zamora","Avellaneda",
                                              "Banfield", "Lomas de Zamora","Banfield","Lomas de Zamora","Lanus","Lomas de Zamora","Lomas de Zamora","Avellaneda","Avellaneda","Sarandi"};
