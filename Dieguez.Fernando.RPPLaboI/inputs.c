#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "ui.h"

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
                  maximo, int reintentos)
{
    fflush(stdin);
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s ",mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 1;
                break;
            }
        }
        printf("%s ",mensajeError);
    }
    return retorno;
}

int getString(char* pResultado)
{
    int retorno=-1;
    char buffer[4096];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0)
        {
            strcpy(pResultado, buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int askForString(char resultingString[], char title[], int maxLength)
{
    int ret = 0;
    if (resultingString != NULL && title != NULL && maxLength > 0)
    {
        printf("%s", title);
        fflush(stdin);
        getString(resultingString);
        if (strlen(resultingString) <= maxLength){
            ret = 1;
        }
    }
    return ret;
}

int askSex(char *pSex, char title[])
{
    int ret= 0;
    char inputChar;
    printf("%s", title);
    fflush(stdin);
    scanf("%c", &inputChar);
    inputChar = tolower(inputChar);
    while (!(inputChar == 'm' || inputChar == 'f'))
    {
        showError(title);
        fflush(stdin);
        scanf("%c", &inputChar);
        inputChar = tolower(inputChar);
    }
    ret = 1;
    *pSex = inputChar;
    return ret;
}

int stringToLower(char str[])
{
    int ret = 0;
    if (str != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = tolower(str[i]);
            ret = 1;
        }
    }
    return ret;
}
int stringToUpper(char str[])
{
    int ret = 0;
    if (str != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = toupper(str[i]);
        }
    }
    return ret;
}



int isFloat(char* str)
{
    int i=0;
    int ret = 1;
    int flagComma = 0;
    if(str != NULL && strlen(str) > 0)
    {
        while(str[i] != '\0')
        {
            if (str[i] == ',' || str[i] == '.') //permitir solo una coma o punto, guardar como punto
            {
                if (flagComma)
                {
                    ret = 0;
                    break;
                }
                else
                {
                    str[i] = '.';
                    flagComma = 1;
                    i++;
                    continue;//ir a proxima iteracion
                }
            }
            /*if (i == 0 && str[i] == '-') //TO DO permitir negativos y manejar en conversion atof
            {
                i++;
                continue;//ir a proxima iteracion
            }*/
            if(str[i] < '0' || str[i] > '9')//permitir 0-9 unicamente
            {
                ret = 0;
                break;
            }
            i++;
        }
        if (!flagComma)
        {
            return 0;
        }
    }
    return ret;
}

int getFloat(float* resultingFloat)
{
    int ret=-1;
    char buffer[64];
    float resultFloat;
    if(resultingFloat != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && isFloat(buffer))
        {
            resultFloat = atof(buffer);
            *resultingFloat = resultFloat;
            ret = 0;
        }
    }
    return ret;
}


float myGetFloat(float* resultingFloat, char* message, char* errorMessage, float minF, float
                 maxF, int attemps)
{
    fflush(stdin);
    float bufferFloat;
    int ret = -1;
    while(attemps>0)
    {
        attemps--;
        printf("%s ",message);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minF && bufferFloat <= maxF)
            {
                *resultingFloat = bufferFloat;
                ret = 1;
                break;
            }
        }
        printf("%s ",errorMessage);
    }
    return ret;
}

int compareDates(eDate dateA, eDate dateB) //1 mayor 0 igual -1 menor
{
    int ret = 0;
    if (dateA.year > dateB.year)
    {
        ret = 1;
    }
    else if (dateA.year < dateB.year)
    {
        ret = -1;
    }
    else  //año igual
    {
        if (dateA.month > dateB.month)
        {
            ret = 1;
        }
        else if (dateA.month < dateB.month)
        {
            ret = -1;
        }
        else  //mes igual
        {
            if (dateA.day > dateB.day)
            {
                ret = 1;
            }
            else if (dateA.day < dateB.day)
            {
                ret = -1;
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
}

