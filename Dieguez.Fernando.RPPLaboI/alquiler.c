#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "datawarehouse.h"
#include "ui.h"
#include "Randomizer.h"

int initializeAlquileres(eAlquiler alquileres[], int sizeA)
{
    int ret = 0;
    if (alquileres != NULL && sizeA > 0)
    {
        for(int i = 0; i < sizeA; i++)
        {
            alquileres[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}

int findPlaceInAlquilerArray(eAlquiler alquileres[], int sizeA )
{
    int ret = -1;
    if (alquileres != NULL && sizeA > 0)
    {
        for(int i = 0; i < sizeA; i++)
        {
            if (alquileres[i].isEmpty)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int addAlquiler(eAlquiler alquileres[], int index, int *alquilerId, eCliente clientes[], int sizeE, eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC, int* conteoAlquiler, eLocalidad localidades[], int sizeL)
{
    int allOk = 0;
    eDate date;
    int clienteId;
    int juegoId;
    //Cargo ID
    alquileres[index].id = *alquilerId;
    //Pido la fecha de alquiler
    int dateOk = getDate(&date) == -1 ? 0 : 1;
    //Pido el clienteId
    int clienteIdOk = getClienteId(&clienteId, clientes, sizeE, localidades, sizeL);
    while(!clienteIdOk)
    {
        printf("Cliente no encontrado, reingrese: ");
        clienteIdOk = getClienteId(&clienteId, clientes, sizeE, localidades, sizeL);
    }
    int juegoOk = getJuegoId(&juegoId, juegos, sizeJ, categorias, sizeC);
    while(!juegoOk)
    {
        printf("Juego no encontrado, reingrese: ");
        juegoOk = getJuegoId(&juegoId, juegos, sizeJ, categorias, sizeC);
    }
    if (dateOk && clienteIdOk && juegoOk)
    {
        alquileres[index].id = *alquilerId;
        alquileres[index].isEmpty = 0;
        alquileres[index].date = date;
        alquileres[index].clienteId = clienteId;
        alquileres[index].juegoId = juegoId;
        allOk = 1;
        (*alquilerId)++;
        (*conteoAlquiler)++;
    }
    else
    {
        showError("Error en uno o mas datos, abortando la carga de alquiler");
    }
    return allOk;
}

void showAlquileres(eAlquiler alquileres[],int sizeA, eJuego juegos[], int sizeJ, eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL)
{
    showTitlesForAlquileres();
    for(int i = 0; i < sizeA; i++)
    {
        if (!alquileres[i].isEmpty)
        {
            showAlquiler(alquileres[i], 0, juegos, sizeJ, clientes, sizeCLT, localidades, sizeL);
        }
    }
}
void showAlquiler(eAlquiler alquiler, int showTitles, eJuego juegos[], int sizeJ, eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL)
{
    if (showTitles)
    {
        showTitlesForAlquileres();
    }
    eJuego juego;
    eCliente cliente;
    int juegoOk = getJuegoById(juegos,sizeJ,alquiler.juegoId, &juego);
    int clienteOk = findClienteById(clientes,sizeCLT, alquiler.clienteId, &cliente);
    char fullName[20];
    char juegoDesc[20];
    eLocalidad localidad;
    int localidadOk = findLocalidadById(localidades,sizeL, cliente.localidadId, &localidad);
    char localidadDesc[20];
    if (clienteOk && juegoOk && localidadOk)
    {
        strcpy(localidadDesc, localidad.descripcion);
        strcpy(fullName, cliente.nombre);
        strcat(fullName, " ");
        strcat(fullName, cliente.apellido);
        strcpy(juegoDesc, juego.descripcion);
        printf("| %11d | %16s | %19s |     ", alquiler.id, fullName, juegoDesc);
        printDate(alquiler.date.day, alquiler.date.month, alquiler.date.year);
        printf("    |%16s|\n", localidadDesc);
    }
    else
    {
        printf("\n Error al obtener los datos para el alquiler de id: %d", alquiler.id);
    }
}

int getAlquilerById(eAlquiler alquileres[], int sizeA, int id, eAlquiler* alquilerResultante)
{
    int ret = -1;
    if (alquileres != NULL && sizeA > 0)
    {
        for(int i = 0; i < sizeA; i++)
        {
            if (alquileres[i].id == id)
            {
                ret = 1;
                *alquilerResultante = alquileres[i];
                break;
            }
        }
    }
    return ret;
}


int hardcodeAlquileres(eAlquiler alquilerArray[], int sizeA, int* id, eCliente clientes[], eJuego juegos[], int* conteoAlquileres)
{
    int ret = 0;
    if (alquilerArray != NULL && sizeA > 0 && id > 0)
    {
        ret = 1;
        for (int i =0; i < sizeA; i++)
        {
            alquilerArray[i].id = *id;
            alquilerArray[i].date = dates[i];
            alquilerArray[i].isEmpty = 0;
            alquilerArray[i].clienteId = clientes[i].codigo;
            alquilerArray[i].juegoId = getRandomNumber(1,20);
            (*id)++;
            (*conteoAlquileres)++;
        }
    }
    return ret;
}

int deleteAlquileresByClienteId(eAlquiler alquileres[], int sizeA, int clienteId, int* conteoAlquileres)
{
    int ret = -1;
    if (alquileres != NULL && sizeA >0 && clienteId >0)
    {
        ret = 0;
        for(int i = 0; i < sizeA; i++)
        {
            if(alquileres[i].clienteId == clienteId)
            {
                alquileres[i].isEmpty = 1;
                ret = 1;
                (*conteoAlquileres)--;
            }
        }
    }
    return ret;
}
