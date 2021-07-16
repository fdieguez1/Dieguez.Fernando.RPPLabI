#include <stdio.h>
#include <string.h>
#include "datawarehouse.h"
#include "localidad.h"
#include "inputs.h"
#include "ui.h"

int hardcodeLocalidades(eLocalidad localidadArray[], int sizeS, int* localidadesId, int* conteoLocalidades)
{
    int ret = 0;
    for (int i =0; i < sizeS; i++)
    {
        localidadArray[i].id = *localidadesId;
        strcpy(localidadArray[i].descripcion, localidades[i]);
        ret = 1;
        (*localidadesId)++;
        (*conteoLocalidades)++;
    }
    return ret;
}

int getLocalidadId(int *resultingId, eLocalidad localidades[], int sizeS)
{
    int ret = 0;
    showLocalidades(localidades, sizeS);
    utn_getNumero(resultingId, "Ingrese el ID de localidad: ", "Error, localidad invalido. ", 1, 999, 10);
    for(int i = 0; i < sizeS; i++)
    {
        if (*resultingId == localidades[i].id)
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

int findLocalidadById(eLocalidad localidades[], int sizeL,int id, eLocalidad *resultingLocalidad)
{
    int ret = -1;
    if (localidades != NULL && sizeL > 0)
    {
        ret = 0;
        if (localidades != NULL && sizeL > 0 && id > 0)
        {
            ret = 0;
            for(int i = 0; i < sizeL; i++)
            {
                if (localidades[i].id == id)
                {
                    *resultingLocalidad = localidades[i];
                    ret = 1;
                    break;
                }
            }
        }
    }
    return ret;
}

void showLocalidades(eLocalidad localidades[], int sizeL)
{
    showTitlesForLocalidades();
    for(int i = 0; i < sizeL; i++)
    {
        showLocalidad(localidades[i], 0);
    }
}
void showLocalidad(eLocalidad localidad, int showTitles)
{
    if (showTitles)
    {
        showTitlesForLocalidades();
    }
    printf("|         %10d          |    %50s    |\n", localidad.id, localidad.descripcion);

}
