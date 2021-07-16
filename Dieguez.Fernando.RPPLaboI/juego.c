#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "juego.h"
#include "datawarehouse.h"
#include "inputs.h"
#include "ui.h"
#include "Randomizer.h"

int hardcodeJuegos(eJuego juegoArray[], int sizeJ, int* juegoId, int categoriaId, int* conteoJuegos)
{
    int ret = 0;
    int catId = categoriaId;
    for (int i =0; i < sizeJ; i++)
    {
        juegoArray[i].codigo = *juegoId;
        strcpy(juegoArray[i].descripcion, descripcionJuegos[i]);
        juegoArray[i].idCategoria = getRandomNumber(1,5);
        juegoArray[i].importe = foodprices[getRandomNumber(1,5)];
        catId++;
        ret = 1;
        (*juegoId)++;
        (*conteoJuegos)++;
    }
    return ret;
}

int getJuegoId(int *resultingId, eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    int ret = -1;
    if(juegos != NULL && sizeJ > 0 && categorias != NULL && sizeC > 0)
    {
        ret = 0;
        showJuegos(juegos, sizeJ, categorias, sizeC);
        utn_getNumero(resultingId, "Ingrese el codigo de juego: ", "Error, juego invalido. ", 1, 999, 10);
        for(int i = 0; i < sizeJ; i++)
        {
            if (*resultingId == juegos[i].codigo)
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int getJuegoById(eJuego juegos[], int sizeJ, int id,eJuego* resultingJuego)
{
    int ret = -1;
    if (juegos != NULL && sizeJ > 0 && id > 0)
    {
        ret = 0;
        for(int i = 0; i < sizeJ; i++)
        {
            if (juegos[i].codigo == id)
            {
                *resultingJuego = juegos[i];
                ret = 1;
                break;
            }
        }
    }
    return ret;
}


void showJuegos(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    showTitlesForJuegos();
    for(int i = 0; i < sizeJ; i++)
    {
        showJuego(juegos[i], 0, categorias, sizeC);
    }
}
void showJuego(eJuego juego, int showTitles, eCategoria categorias[], int sizeC)
{
    if (showTitles)
    {
        showTitlesForJuegos();
    }
    eCategoria categoria;
    int categoriaOk = findCategoriaById(categorias,sizeC, juego.idCategoria, &categoria);
    char categoriaDesc[20];
    if (categoriaOk)
    {
        strcpy(categoriaDesc, categoria.descripcion);
        printf("|       %3d       |      %20s     |  %15.2f  |    %13s    |\n", juego.codigo, juego.descripcion, juego.importe, categoriaDesc);
    }
    else
    {
        showError("Problemas al mostrar el juego, no se logro cargar la descripcion de la categoria");
        printf("Error en juego id: %d", juego.codigo);
    }


}

int findJuegoById(eJuego juegos[], int sizeJ,int id)
{
    int ret = -1;
    if(juegos != NULL && sizeJ > 0)
    {
        for(int i = 0; i < sizeJ ; i++)
        {
            if(juegos[i].codigo == id)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
