#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "ui.h"
#include "inputs.h"

#define INFORMS_WIDTH 93

void mostrarJuegosDeMesa(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    int categoriaId = -1;
    for(int i = 0; i < sizeC; i ++)
    {
        if (strcmp(strlwr(categorias[i].descripcion),"mesa") == 0)
        {
            categoriaId = categorias[i].id;
        }
    }
    if(categoriaId != -1)
    {
        printDivisor();
        centerText("Juegos de categoria mesa:",INFORMS_WIDTH);
        printf("\n");
        printDivisor();
        for(int i = 0; i < sizeJ; i++)
        {
            if (juegos[i].idCategoria == categoriaId)
                showJuego(juegos[i], 0, categorias, sizeC);
        }
    }
    else
    {
        printf("Error al buscar juegos de la categoria 'mesa'");
    }
}
void mostrarAlquileresPorCliente(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL)
{
    showClientes(clientes, sizeCLT, localidades, sizeL);
    eCliente selectedCliente;
    int primerPrint = 0;
    int id;
    int idOk = utn_getNumero(&id,"Ingrese el numero de empleado para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int clienteOk = findClienteById(clientes, sizeCLT, id, &selectedCliente);
    while(!clienteOk)
    {
        showError("Cliente no encontrado");
        idOk = utn_getNumero(&id,"Ingrese el numero de empleado para el informe", "Error al ingresar el numero", 1, 999999, 100);
        clienteOk = findClienteById(clientes, sizeCLT, id, &selectedCliente);
    }
    if (idOk)
    {
        printDivisor();
        centerText("JUEGOS ALQUILADOS POR CLIENTE", INFORMS_WIDTH);
        printf("\n");
        printf("Cliente: %s %s\n", selectedCliente.nombre, selectedCliente.apellido );
        for(int i = 0; i < sizeA; i ++)
        {
            if (alquileres[i].clienteId == id)
            {
                if (primerPrint == 0)
                {
                    primerPrint++;
                    showAlquiler(alquileres[i],1,juegos,sizeJ,clientes,sizeCLT, localidades, sizeL);
                }
                else
                {
                    showAlquiler(alquileres[i],0,juegos,sizeJ,clientes,sizeCLT, localidades, sizeL);
                }
            }
        }
    }
}

void mostrarRecaudacionPorCliente(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL)
{
    printDivisor();
    centerText("Recaudacion POR CLIENTE:", INFORMS_WIDTH);
    printf("\n");

    showClientes(clientes, sizeCLT, localidades, sizeL);
    eCliente selectedCliente;
    float recaudacionTotal = 0;
    int id;
    int idOk = utn_getNumero(&id,"Ingrese el numero de empleado para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int clienteOk = findClienteById(clientes, sizeCLT, id, &selectedCliente);
    while(!clienteOk)
    {
        showError("Cliente no encontrado");
        idOk = utn_getNumero(&id,"Ingrese el numero de empleado para el informe", "Error al ingresar el numero", 1, 999999, 100);
        clienteOk = findClienteById(clientes, sizeCLT, id, &selectedCliente);
    }
    if (idOk)
    {

        for(int i = 0; i < sizeA; i ++)
        {

            if (alquileres[i].clienteId == selectedCliente.codigo)
            {

                for(int j = 0; j < sizeJ; j++)
                {

                    if(juegos[j].codigo == alquileres[i].juegoId)
                    {
                        recaudacionTotal += juegos[i].importe;
                    }
                }
            }
        }
        eLocalidad localidad;
        int localidadOk = findLocalidadById(localidades,sizeL, selectedCliente.localidadId, &localidad);
        char localidadDesc[20];
        if (localidadOk)
        {
            strcpy(localidadDesc, localidad.descripcion);
        }
        else
        {
            showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
            printf("Error en cliente id: %d\n", selectedCliente.codigo);
        }

        printf("\nRecaudacion total Cliente %s %s: $%.2f Localidad: %s\n\n",selectedCliente.nombre, selectedCliente.apellido, recaudacionTotal, localidadDesc);
    }
}

void listarClientesSinAlquileres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL)
{
    printDivisor();
    centerText("clientes SIN ALQUILERES:\n\n", INFORMS_WIDTH);
    printf("\n");
    int primerPrint = 0;
    for(int i = 0; i < sizeCLT; i++)
    {
        int alquilerPorCliente = 0;
        for(int j = 0; j < sizeA; j++)
        {
            if(clientes[i].codigo == alquileres[j].clienteId && !clientes[i].isEmpty)
            {
                alquilerPorCliente++;
                break;//Encuentra un alquiler, se va al proximo cliente
            }
        }
        if (alquilerPorCliente == 0)
        {
            if(primerPrint == 0)
            {
                primerPrint++;
                showCliente(clientes[i],1,localidades,sizeL);
            }
            else
            {
                showCliente(clientes[i],0,localidades,sizeL);
            }
        }
    }
    if (primerPrint == 0)
    {
        printf("No se encontraron datos\n\n");
    }
}

void listarJuegosNoAlquilados(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCategoria categorias[], int sizeC)
{
    printDivisor();
    centerText("Juegos SIN ALQUILER:\n\n", INFORMS_WIDTH);
    printf("\n");
    int huboAlquileres = 0;
    int alquilerPorJuego = 0;
    for(int i = 0; i < sizeJ; i ++)
    {
        alquilerPorJuego = 0;
        for(int j = 0; j < sizeA; j++)
        {
            if (alquileres[j].juegoId == juegos[i].codigo && !alquileres[j].isEmpty)
            {
                alquilerPorJuego = 1;
                huboAlquileres  = 1;
            }
        }
        if (!alquilerPorJuego)
        {
            printf("\nJuego: %s, sin alquileres\n\n", juegos[i].descripcion);
        }
    }
    if (!huboAlquileres)
    {
        showAlert("No hubo alquileres");
    }
}

void listarTelefonosClientesPorFecha(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL)
{
    eDate auxDate;
    int dateOk = getDate(&auxDate);
    int huboAlquileres= 0;
    if(dateOk)
    {
        printDivisor();
        centerText("Telefonos de clientes por fecha\n\n", INFORMS_WIDTH);
        printf("\n Fecha ");
        printDate(auxDate.day, auxDate.month, auxDate.year);
        printf(":\n\n");
        for(int i = 0; i < sizeA; i++)
        {
            if(compareDates(alquileres[i].date, auxDate) == 0)
            {
                for(int j = 0; j < sizeCLT; j++)
                {
                    if(alquileres[i].clienteId == clientes[j].codigo)
                    {
                        eLocalidad localidad;
                        int localidadOk = findLocalidadById(localidades,sizeL, clientes[j].localidadId, &localidad);
                        char localidadDesc[20];
                        if (localidadOk)
                        {
                            strcpy(localidadDesc, localidad.descripcion);
                        }
                        else
                        {
                            showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
                            printf("Error en cliente id: %d\n", clientes[j].codigo);
                        }

                        printf("\nTelefono: %10s Cliente: %s %s Localidad: %s\n\n", clientes[j].telefono, clientes[j].nombre, clientes[j].apellido, localidadDesc);
                        huboAlquileres++;
                    }
                }
            }
        }
        if(!huboAlquileres)
        {
            printf("No hubo alquileres para esta fecha\n\n");
        }
    }
}

void listarJuegosAlquiladosPorMujeres(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eLocalidad localidades[], int sizeL)
{
    printDivisor();
    centerText("Juegos alquilados por mujeres:\n\n", INFORMS_WIDTH);
    printf("\n");
    int huboAlquileres = 0;
    int alquilerPorJuego = 0;
    for(int i = 0; i < sizeJ; i ++)
    {
        alquilerPorJuego = 0;
        for(int j = 0; j < sizeA; j++)
        {
            if (alquileres[j].juegoId == juegos[i].codigo && !alquileres[j].isEmpty)
            {
                for(int k = 0; k < sizeCLT; k++)
                {
                    if(clientes[k].sex == 'f' && clientes[k].codigo == alquileres[j].clienteId)
                    {
                        eLocalidad localidad;
                        int localidadOk = findLocalidadById(localidades,sizeL, clientes[k].localidadId, &localidad);
                        char localidadDesc[20];
                        if (localidadOk)
                        {
                            strcpy(localidadDesc, localidad.descripcion);
                        }
                        else
                        {
                            showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
                            printf("Error en cliente id: %d\n", clientes[k].codigo);
                        }

                        alquilerPorJuego = 1;
                        huboAlquileres  = 1;
                        printf("\nJuego: %s, alquilado por %s %s Localidad: %s\n\n", juegos[i].descripcion, clientes[k].nombre, clientes[k].apellido, localidadDesc);
                    }
                }

            }
        }
        if (!alquilerPorJuego)
        {
            printf("\nJuego: %s, sin alquileres de mujeres\n\n", juegos[i].descripcion);
        }
    }
    if (!huboAlquileres)
    {
        showAlert("No hubo alquileres");
    }
}

void mostrarJuegoMasAlquiladorPorHombres(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ)
{
    printDivisor();
    centerText("Juego/s mas alquilado/s por hombres:\n\n", INFORMS_WIDTH);
    printf("\n");
    int contadorJuegos[sizeJ];
    for(int i=0; i<sizeJ; i++)
    {
        contadorJuegos[i]= 0;
    }
    int indiceJuego = -1;
    int flag = 0;
    for(int i = 0; i < sizeCLT; i++)//clientes
    {
        if (clientes[i].sex == 'm') //hombres
        {
            for(int j = 0; j < sizeA; j++)
            {
                if (alquileres[j].clienteId == clientes[i].codigo && !alquileres[j].isEmpty)
                {
                    for(int k = 0; k < sizeJ; k++) //juegos
                    {
                        if (juegos[k].codigo == alquileres[j].juegoId)
                        {
                            indiceJuego = findJuegoById(juegos, sizeJ, alquileres[j].juegoId);
                            if (indiceJuego != -1) //acumulo
                            {
                                contadorJuegos[indiceJuego]++;
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int mayor = contadorJuegos[0];
    int mayorIndex = 0;
    for(int i = 0; i < sizeJ; i++)
    {
        if (contadorJuegos[i] > mayor)
        {
            mayor = contadorJuegos[i];
            mayorIndex = i;
        }
    }
    if (flag)
    {
        printf("\nJuego mas alquilado por hombres: %s \n\n", juegos[mayorIndex].descripcion);
    }
    else
    {
        printf("No hubo juegos alquilados por hombres\n\n");
    }
}

void listarClientesPorDeterminadoJuego(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eCategoria categorias[], int sizeC, eLocalidad localidades[], int sizeL)
{
    showJuegos(juegos, sizeJ, categorias, sizeC);
    eJuego resultingJuego;
    int id;
    int idOk = utn_getNumero(&id,"Ingrese el numero de juego para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int juegoIndexOk = getJuegoById(juegos, sizeJ, id, &resultingJuego );
    int contadorJuego = 0;
    while(!juegoIndexOk)
    {
        showError("Juego no encontrado");
        idOk = utn_getNumero(&id,"Ingrese el numero de juego para el informe", "Error al ingresar el numero", 1, 999999, 100);
        juegoIndexOk = findJuegoById(juegos, sizeJ, id);
    }
    if (idOk)
    {
        contadorJuego = 0;
        printDivisor();
        centerText("Clientes por juego", INFORMS_WIDTH);
        printf("\n");
        printf("Juego: %s \n", resultingJuego.descripcion);
        for(int i = 0; i < sizeJ; i ++)
        {
            if (alquileres[i].juegoId == id)
            {
                for(int j = 0; j < sizeCLT; j++)
                {
                    if(clientes[j].codigo == alquileres[i].clienteId && !clientes[j].isEmpty && !alquileres[i].isEmpty)
                    {
                        eLocalidad localidad;
                        int localidadOk = findLocalidadById(localidades,sizeL, clientes[j].localidadId, &localidad);
                        char localidadDesc[20];
                        if (localidadOk)
                        {
                            strcpy(localidadDesc, localidad.descripcion);
                        }
                        else
                        {
                            showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
                            printf("Error en cliente id: %d\n", clientes[j].codigo);
                        }

                        printf("Cliente: %s %s Localidad: %s\n", clientes[j].nombre, clientes[j].apellido, localidadDesc);
                        contadorJuego++;
                    }
                }

            }
        }
        if(contadorJuego == 0)
        {
            printf("No se encontraron clientes para este juego\n");
        }
    }
}

void mostrarRecaudacionPorFecha(eAlquiler alquileres[], int sizeA, eJuego juegos[], int sizeJ, eCliente clientes[], int sizeCLT)
{
    eDate auxDate;
    int dateOk = getDate(&auxDate);
    int huboAlquileres= 0;
    float acumuladorRecaudacion = 0;
    if(dateOk)
    {
        printDivisor();
        centerText("Recaudacion por fecha\n\n", INFORMS_WIDTH);
        printf("\n Fecha ");
        printDate(auxDate.day, auxDate.month, auxDate.year);
        printf(":\n\n");
        for(int i = 0; i < sizeA; i++)
        {
            if(compareDates(alquileres[i].date, auxDate) == 0)
            {
                for(int j = 0; j < sizeCLT; j++)
                {
                    if(alquileres[i].clienteId == clientes[j].codigo)
                    {
                        for(int k = 0; k < sizeJ; k++)
                        {
                            if (juegos[k].codigo == alquileres[i].juegoId)
                            {
                                acumuladorRecaudacion += juegos[k].importe;
                                huboAlquileres++;
                            }
                        }

                    }
                }
            }
        }
        printf("Recaudacion del dia: %.2f\n\n", acumuladorRecaudacion);
        if(!huboAlquileres)
        {
            printf("No hubo alquileres para esta fecha\n\n");
        }
    }
}

void mostrarRecaudacionPorLocalidad(eLocalidad localidades[], int sizeL, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ)
{
    showLocalidades(localidades, sizeL);
    eLocalidad resultingLocalidad;
    int id;
    float acumuladorLocalidad = 0;
    int idOk = utn_getNumero(&id,"Ingrese el numero de localidad para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int localidadOk = findLocalidadById(localidades, sizeJ, id, &resultingLocalidad);
    while(!localidadOk)
    {
        showError("Localidad no encontrada");
        idOk = utn_getNumero(&id,"Ingrese el numero de localidad para el informe", "Error al ingresar el numero", 1, 999999, 100);
        localidadOk = findLocalidadById(localidades, sizeJ, id, &resultingLocalidad);
    }
    if (idOk)
    {
        printDivisor();
        centerText("Recaudacion por localidad", INFORMS_WIDTH);
        printf("\n");
        printf("Localidad: %s \n", resultingLocalidad.descripcion);
        for(int i = 0; i < sizeCLT; i ++) //recorro clientes
        {
            if(clientes[i].localidadId == resultingLocalidad.id)
            {
                for(int j = 0; j < sizeA; j++) //recorro alquileres
                {
                    if(clientes[i].codigo == alquileres[j].clienteId)
                    {
                        for(int k = 0; k < sizeJ; k++) //recorro juegos
                        {
                            if(juegos[k].codigo == alquileres[j].juegoId)
                            {
                                acumuladorLocalidad += juegos[k].importe;
                            }
                        }
                    }
                }
            }
        }
        printf("recaudacion total: %.2f\n", acumuladorLocalidad);
    }
}

void conteoClientesPorLocalidad(eLocalidad localidades[], int sizeL, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ)
{
    int contadorLocalidad = 0;

    int flag = 0;
    printDivisor();
    centerText("Conteo de clientes por localidad", INFORMS_WIDTH);
    printf("\n");
    for(int a = 0; a < sizeL; a++)
    {
        contadorLocalidad = 0;
        for(int i = 0; i < sizeCLT; i ++) //recorro clientes
        {
            if(clientes[i].localidadId == localidades[a].id)
            {
                for(int j = 0; j < sizeA; j++) //recorro alquileres
                {
                    if(clientes[i].codigo == alquileres[j].clienteId && !clientes[i].isEmpty && !alquileres[j].isEmpty)
                    {
                        contadorLocalidad++;
                        flag++;
                    }
                }
            }
        }
        if(contadorLocalidad > 0)
        {
            printf("Localidad: %s Conteo de clientes: %d\n", localidades[a].descripcion, contadorLocalidad);

        }
        else
        {
            printf("No se encontraron clientes en Localidad: %s\n", localidades[a].descripcion);
        }

    }
    if (flag < 1)
    {
        printf("No se encontraron clientes en ninguna localidad");
    }
}

void hombresPorLocalidad(eLocalidad localidades[], int sizeL, eCliente clientes[], int sizeCLT)
{
    int contadorLocalidad = 0;

    int flag = 0;
    printDivisor();
    centerText("Conteo de hombres por localidad", INFORMS_WIDTH);
    printf("\n");
    for(int a = 0; a < sizeL; a++)
    {
        contadorLocalidad = 0;
        for(int i = 0; i < sizeCLT; i ++) //recorro clientes
        {
            if(clientes[i].localidadId == localidades[a].id)
            {
                if(!clientes[i].isEmpty && clientes[i].sex == 'm')
                {
                    contadorLocalidad++;
                    flag++;
                }
            }
        }
        if(contadorLocalidad > 0)
        {
            printf("Localidad: %s Conteo de hombres: %d\n", localidades[a].descripcion, contadorLocalidad);

        }
        else
        {
            printf("No se encontraron clientes hombres en Localidad: %s\n", localidades[a].descripcion);
        }

    }
    if (flag < 1)
    {
        printf("No se encontraron clientes en ninguna localidad");
    }
}

void clientesPorLocalidad(eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL)
{
    int contadorLocalidad = 0;

    int flag = 0;
    printDivisor();
    centerText("Conteo de hombres por localidad", INFORMS_WIDTH);
    printf("\n");
    for(int a = 0; a < sizeL; a++)
    {
        contadorLocalidad = 0;
        for(int i = 0; i < sizeCLT; i ++) //recorro clientes
        {
            if(clientes[i].localidadId == localidades[a].id)
            {
                if(!clientes[i].isEmpty)
                {
                    contadorLocalidad++;
                    flag++;
                }
            }
        }
        if(contadorLocalidad > 0)
        {
            printf("Localidad: %s Conteo de clientes: %d\n", localidades[a].descripcion, contadorLocalidad);

        }
        else
        {
            printf("No se encontraron clientes en Localidad: %s\n", localidades[a].descripcion);
        }

    }
    if (flag < 1)
    {
        printf("No se encontraron clientes en ninguna localidad");
    }
}

void listarLocalidadesSinAlquileres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL)
{
    printDivisor();
    centerText("Localidades SIN ALQUILER:\n\n", INFORMS_WIDTH);
    printf("\n");
    int huboAlquileres = 0;
    int alquilerPorLocalidad = 0;
    int contadorLlenas = 0;
    for(int i = 0; i < sizeL; i ++)
    {
        alquilerPorLocalidad = 0;
        for(int j = 0; j < sizeCLT; j++)
        {
            if(clientes[j].localidadId == localidades[i].id)
            {
                for(int k = 0; k < sizeA; k++)
                {
                    if(alquileres[k].clienteId == clientes[j].codigo)
                    {

                        alquilerPorLocalidad = 1;
                        huboAlquileres = 1;

                    }
                }
            }
        }

        if (!alquilerPorLocalidad)
        {
            printf("\nLocalidad: %s, sin alquileres\n\n", localidades[i].descripcion);
        }
        else
        {
            contadorLlenas++;
        }
    }
    if (!huboAlquileres)
    {
        showAlert("No hubo alquileres");
    }
    if(contadorLlenas == sizeL)
    {
        printf("No hubo localidades vacias");
    }
}

void acumularImportePorJuego(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL, eCategoria categorias[], int sizeC)
{
    int idJuego;
    printDivisor();
    centerText("Importe por juego:\n\n", INFORMS_WIDTH);
    printf("\n");
    float total;
    showJuegos(juegos, sizeJ, categorias, sizeC);
    int idOk = utn_getNumero(&idJuego,"Ingrese el numero de juego para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int juegoOk = findJuegoById(juegos, sizeJ, idJuego);
    while(juegoOk == -1)
    {
        juegoOk = utn_getNumero(&idJuego, "Ingrese el codigo del juego: ", "Error, valor incorrecto", 199, 5000, 10);
    }
    if(idOk)
    {
        for(int i = 0; i < sizeA; i++)
        {
            if (alquileres[i].juegoId == idJuego && !alquileres[i].isEmpty)
            {
                for(int j= 0; j < sizeJ; j++)
                {
                    if (juegos[j].codigo == alquileres[i].juegoId)
                    {
                        total += juegos[j].importe;
                    }
                }
            }
        }


        printf("\nEl total por este juego es %.2f\n", total);

    }
}

void mostrarJuegosDeMagia(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    int categoriaId = -1;
    for(int i = 0; i < sizeC; i ++)
    {
        if (strcmp(strlwr(categorias[i].descripcion),"magia") == 0)
        {
            categoriaId = categorias[i].id;
        }
    }
    if(categoriaId != -1)
    {
        printDivisor();
        centerText("Juegos de categoria magia:",INFORMS_WIDTH);
        printf("\n");
        printDivisor();
        for(int i = 0; i < sizeJ; i++)
        {
            if (juegos[i].idCategoria == categoriaId)
                showJuego(juegos[i], 0, categorias, sizeC);
        }
    }
    else
    {
        printf("Error al buscar juegos de la categoria 'magia'");
    }
}

void listarLocalidadesPorDeterminadoJuego(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eCategoria categorias[], int sizeC, eLocalidad localidades[], int sizeL)
{
    showJuegos(juegos, sizeJ, categorias, sizeC);
    eJuego resultingJuego;
    int id;
    int idOk = utn_getNumero(&id,"Ingrese el numero de juego para el informe", "Error al ingresar el numero", 1, 999999, 100);
    int juegoIndexOk = getJuegoById(juegos, sizeJ, id, &resultingJuego );
    int contadorLocalidad = 0;
    while(!juegoIndexOk)
    {
        showError("Juego no encontrado");
        idOk = utn_getNumero(&id,"Ingrese el numero de juego para el informe", "Error al ingresar el numero", 1, 999999, 100);
        juegoIndexOk = findJuegoById(juegos, sizeJ, id);
    }
    if (idOk)
    {
        contadorLocalidad = 0;
        printDivisor();
        centerText("Clientes por juego", INFORMS_WIDTH);
        printf("\n");
        printf("Juego: %s \n", resultingJuego.descripcion);
        for(int i = 0; i < sizeJ; i ++)
        {
            if (alquileres[i].juegoId == id)
            {
                for(int j = 0; j < sizeCLT; j++)
                {
                    if(clientes[j].codigo == alquileres[i].clienteId && !clientes[j].isEmpty && !alquileres[i].isEmpty)
                    {
                        eLocalidad localidad;
                        int localidadOk = findLocalidadById(localidades,sizeL, clientes[j].localidadId, &localidad);
                        char localidadDesc[20];
                        if (localidadOk)
                        {
                            strcpy(localidadDesc, localidad.descripcion);
                        }
                        else
                        {
                            showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
                            printf("Error en cliente id: %d\n", clientes[j].codigo);
                        }

                        printf("Localidad: %s\n", localidadDesc);
                        contadorLocalidad++;
                    }
                }

            }
        }
        if(contadorLocalidad == 0)
        {
            printf("No se encontraron localidades para este juego\n");
        }
    }
}


void listarCategoriasAlquiladosPorHombres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCategoria categorias[], int sizeC)
{
    int flagPorHombre = 0;
    for (int i = 0; i < sizeCLT; i++)//Clientes
    {
        flagPorHombre = 0;
        if ((clientes[i].sex == 'm') && !clientes[i].isEmpty)
        {
            printf("\t\tCliente %s:\n", clientes[i].nombre);
            for(int j = 0; j < sizeA; j++) //alquileres
            {
                if (clientes[i].codigo == alquileres[j].clienteId && !alquileres[j].isEmpty)
                {
                    for(int k = 0; k < sizeJ; k ++) //juegos
                    {
                        if (juegos[k].codigo == alquileres[j].juegoId)
                        {
                            for(int a = 0; a < sizeC; a++)
                            {
                                if(juegos[k].idCategoria == categorias[a].id)
                                {
                                    printf(" Categoria: %s\n", categorias[a].descripcion);
                                    flagPorHombre = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (flagPorHombre)
        {
            printTableDivisor();
        }
    }
}

void mostrarJuegosDeAzar(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    int categoriaId = -1;
    for(int i = 0; i < sizeC; i ++)
    {
        if (strcmp(strlwr(categorias[i].descripcion),"azar") == 0)
        {
            categoriaId = categorias[i].id;
        }
    }
    if(categoriaId != -1)
    {
        printDivisor();
        centerText("Juegos de categoria azar:",INFORMS_WIDTH);
        printf("\n");
        printDivisor();
        for(int i = 0; i < sizeJ; i++)
        {
            if (juegos[i].idCategoria == categoriaId)
                showJuego(juegos[i], 0, categorias, sizeC);
        }
    }
    else
    {
        printf("Error al buscar juegos de la categoria 'azar'");
    }
}

void mostrarJuegosDeSalon(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC)
{
    int categoriaId = -1;
    for(int i = 0; i < sizeC; i ++)
    {
        if (strcmp(strlwr(categorias[i].descripcion),"salon") == 0)
        {
            categoriaId = categorias[i].id;
        }
    }
    if(categoriaId != -1)
    {
        printDivisor();
        centerText("Juegos de categoria salon:",INFORMS_WIDTH);
        printf("\n");
        printDivisor();
        for(int i = 0; i < sizeJ; i++)
        {
            if (juegos[i].idCategoria == categoriaId)
                showJuego(juegos[i], 0, categorias, sizeC);
        }
    }
    else
    {
        printf("Error al buscar juegos de la categoria 'salon'");
    }
}
