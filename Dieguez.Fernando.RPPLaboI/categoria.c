#include <stdio.h>
#include <string.h>
#include "categoria.h"
#include "datawarehouse.h"
#include "inputs.h"
#include "ui.h"

int hardcodeCategorias(eCategoria categoriaArray[], int sizeS, int* categoriasId, int* conteoCategorias)
{
    int ret = 0;
    for (int i =0; i < sizeS; i++)
    {
        categoriaArray[i].id = *categoriasId;
        strcpy(categoriaArray[i].descripcion, descripcionCategorias[i]);
        ret = 1;
        (*categoriasId)++;
        (*conteoCategorias)++;
    }
    return ret;
}

int getCategoriaId(int *resultingId, eCategoria categorias[], int sizeS)
{
    int ret = -1;
    if (categorias != NULL && sizeS > 0)
    {
        ret = 0;
        showCategorias(categorias, sizeS);
        utn_getNumero(resultingId, "Ingrese el ID de categoria: ", "Error, categoria invalido. ", 1, 999, 10);
        for(int i = 0; i < sizeS; i++)
        {

            if (*resultingId == categorias[i].id)
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int findCategoriaById(eCategoria categorias[], int sizeC,int id, eCategoria *resultingCategoria)
{
    int ret = -1;
    if (categorias != NULL && sizeC > 0 && id > 0)
    {
        ret = 0;
        for(int i = 0; i < sizeC; i++)
        {
            if (categorias[i].id == id)
            {
                *resultingCategoria = categorias[i];
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

void showCategorias(eCategoria categorias[], int sizeS)
{
    showTitlesForCategorias();
    for(int i = 0; i < sizeS; i++)
    {
        showCategoria(categorias[i], 0);
    }
}
void showCategoria(eCategoria categoria, int showTitles)
{
    if (showTitles)
    {
        showTitlesForCategorias();
    }
    printf("|         %10d          |    %53s    |\n", categoria.id, categoria.descripcion);

}
