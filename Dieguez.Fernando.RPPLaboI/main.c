#include <stdio.h>
#include <stdlib.h>

#include "Randomizer.h"
#include "juego.h"
#include "cliente.h"
#include "alquiler.h"
#include "localidad.h"
#include "ui.h"
#include "inputs.h"
#include "informes.h"

#define SIZE_J 20
#define SIZE_C 5
#define SIZE_CLT 10
#define SIZE_A 10
#define SIZE_L 5

int main()
{
    startRandomizer();
    int juegosId = 1;
    int categoriasId = 1;
    int localidadesId = 1;
    int alquileresId = 1;
    int clientesId = 1;
    int continuar = 1;
    int opcion;
    int opcionOk;
    int confirm;
    int place;
    int id;
    int idOk;
    int conteoClientes = 0;
    int conteoJuegos = 0;
    int conteoCategorias = 0;
    int conteoAlquileres = 0;
    int conteoLocalidades = 0;

    eJuego juegos[SIZE_J];
    eCategoria categorias[SIZE_C];
    eCliente clientes[SIZE_CLT];
    eCliente selectedCliente;
    eAlquiler alquileres[SIZE_A];
    eLocalidad localidades[SIZE_L];

    hardcodeJuegos(juegos, SIZE_J, &juegosId, categoriasId, &conteoJuegos);
    hardcodeCategorias(categorias, SIZE_C, &categoriasId, &conteoCategorias);
    hardcodeLocalidades(localidades, SIZE_L, &localidadesId, &conteoLocalidades);
    initializeClientes(clientes, SIZE_CLT);
    initializeAlquileres(alquileres,SIZE_A);
    hardcodeClientes(clientes,SIZE_CLT,&clientesId,&conteoClientes);
    hardcodeAlquileres(alquileres,SIZE_A,&alquileresId, clientes, juegos, &conteoAlquileres);
    while (continuar)
    {
        showMenu();
        opcionOk = utn_getNumero(&opcion,"Ingrese una opcion: ", "Error, opcion invalida ", 1,29,100);
        if (opcionOk)
        {
            system("cls");
            switch(opcion)
            {
            case 1: //MOSTRAR JUEGOS
                if (conteoJuegos > 0)
                {
                    showJuegos(juegos, SIZE_J, categorias, SIZE_C);
                }
                else
                {
                    showError("No hay juegos cargados");
                }
                break;
            case 2://MOSTRAR CATEGORIAS
                if (conteoCategorias> 0)
                {
                    showCategorias(categorias, SIZE_C);
                }
                else
                {
                    showError("No hay categorias cargadas");
                }
                break;
            case 3://Alta Cliente
                place = findPlaceInClienteArray(clientes, SIZE_CLT);
                if (place != -1)
                {
                    int addOk = addCliente(clientes, place, &clientesId, &conteoClientes, localidades, SIZE_L);
                    if (addOk)
                    {
                        printf("Carga correcta de cliente correcta con id: %d \n", clientes[place].codigo);
                    }
                    else
                    {
                        showError("Fallo la carga de cliente");
                    }
                }
                else
                {
                    showError("No se encontro un lugar para la carga de cliente, verifique no estar superando el maximo de cargas");
                    printf("Maximo de cargas: %d\n", SIZE_CLT);
                }
                break;
            case 4://Modificacion Cliente
                if (conteoClientes > 0)
                {
                    showClientes(clientes, SIZE_CLT, localidades, SIZE_L);
                    idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la edicion", "Error al ingresar el numero", 1, 999999, 100);
                    int clienteOk = findClienteById(clientes, SIZE_CLT, id, &selectedCliente);
                    while(!clienteOk)
                    {
                        showError("Cliente no encontrado");
                        idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la edicion", "Error al ingresar el numero", 1, 999999, 100);
                        clienteOk = findClienteById(clientes, SIZE_CLT, id, &selectedCliente);
                    }
                    if (idOk)
                    {
                        int editOk = editClienteById(clientes,SIZE_CLT,id, &selectedCliente,categorias, SIZE_C);
                        if (editOk)
                        {
                            printf("Edicion exitosa, id: %d\n", selectedCliente.codigo);
                        }
                        else
                        {
                            showError("Problema al modificar el cliente");
                        }
                    }
                    else
                    {
                        showError("Demasiados intentos, abortando la operacion");
                    }
                }
                else
                {
                    showError("No hay clientes cargados");
                }
                break;
            case 5://Baja Cliente
                if (conteoClientes > 0)
                {
                    showClientes(clientes, SIZE_CLT, localidades, SIZE_L);
                    idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la baja", "Error al ingresar el numero", 1, 999999, 100);
                    int clienteOk = findClienteById(clientes, SIZE_CLT, id, &selectedCliente);
                    while(!clienteOk)
                    {
                        showError("Cliente no encontrado");
                        idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la baja", "Error al ingresar el numero", 1, 999999, 100);
                        clienteOk = findClienteById(clientes, SIZE_CLT, id, &selectedCliente);
                    }
                    if (idOk)
                    {
                        int deleteOk = deleteClienteById(clientes,SIZE_CLT,id, &selectedCliente, &conteoClientes);
                        if (deleteOk)
                        {
                            int eliminadoDeAlquileres = deleteAlquileresByClienteId(alquileres, SIZE_A, id, &conteoAlquileres);
                            if (eliminadoDeAlquileres == -1)
                            {
                                printf("Error al dar de baja alquileres para este cliente\n");
                            }
                            else if (eliminadoDeAlquileres == 0)
                            {
                                printf("El cliente: %d no poseia alquileres vinculados\n", id);
                            }
                            else
                            {
                                printf("Alquileres relacionados al cliente: %d eliminados exitosamente\n", id);
                            }
                            printf("Baja logica de cliente exitosa, id: %d\n", selectedCliente.codigo);
                        }
                        else
                        {
                            showError("Cliente no encontrado, revise el numero ingresado e intente nuevamente");
                        }
                    }
                    else
                    {
                        showError("Demasiados intentos, abortando la operacion");
                    }
                }
                else
                {
                    showError("No hay clientes cargados");
                }
                break;
            case 6://Listar Clientes por apellido y nombre
                if (conteoClientes > 0)
                {
                    orderByFullName(clientes,SIZE_CLT,0);
                    showClientes(clientes, SIZE_CLT, localidades, SIZE_L);
                }
                else
                {
                    showError("No hay clientes cargados");
                }
                break;
            case 7://Cargar alquileres
                if(conteoClientes > 0 && conteoCategorias > 0 && conteoJuegos > 0)
                {
                    place = findPlaceInAlquilerArray(alquileres, SIZE_A);
                    if (place != -1)
                    {
                        int addOk = addAlquiler(alquileres, place, &alquileresId, clientes, SIZE_C, juegos, SIZE_J, categorias, SIZE_C, &conteoAlquileres, localidades, SIZE_L);
                        if (addOk)
                        {
                            printf("Carga correcta de alquiler correcta con id: %d \n", alquileres[place].id);
                        }
                        else
                        {
                            showError("Fallo la carga de alquiler");
                        }
                    }
                    else
                    {
                        showError("No se encontro un lugar para la carga de alquiler, verifique no estar superando el maximo de cargas");
                    }
                }
                else
                {
                    showError("Para cargar alquileres, deben existir empleados, categorias y juegos");
                }
                break;
            case 8://Listar alquileres
                if (conteoClientes > 0)
                {
                    if (conteoAlquileres > 0)
                    {
                        showAlquileres(alquileres,SIZE_A, juegos, SIZE_J, clientes, SIZE_CLT, localidades, SIZE_L);
                    }
                    else
                    {
                        showError("No hay alquileres cargados");
                    }
                }
                else
                {
                    showError("No hay clientes cargados");
                }
                break;
            case 9://Mostrar Juegos de categoría de mesa
                if(conteoJuegos > 0)
                {
                    mostrarJuegosDeMesa(juegos,SIZE_J, categorias, SIZE_C);
                }
                break;
            case 10://Mostrar los alquileres efectuados por algun cliente seleccionado
                if(conteoClientes > 0 && conteoAlquileres > 0)
                {
                    mostrarAlquileresPorCliente(clientes,SIZE_CLT,juegos, SIZE_J, alquileres, SIZE_A, localidades, SIZE_L);
                }
                else
                {
                    showError("Para mostrar este informe, se necesitan clientes y alquileres");
                }
                break;

            case 11://Mostrar el total de todos los importes pagados por el cliente seleccionado
                if(conteoClientes > 0)
                {
                    mostrarRecaudacionPorCliente(clientes,SIZE_CLT,juegos, SIZE_J, alquileres, SIZE_A, localidades, SIZE_L);
                }
                else
                {
                    showError("Para mostrar este informe, se necesitan clientes");
                }
                break;
            case 12://Listar los clientes que no alquilaron juegos
                if(conteoClientes > 0)
                {
                    listarClientesSinAlquileres(clientes, SIZE_CLT, juegos, SIZE_J, alquileres, SIZE_A, localidades, SIZE_L);
                }
                else
                {
                    showError("Para mostrar este informe, se necesitan clientes");
                }
                break;
            case 13://Listar los juegos que no han sido alquilados
                if(conteoJuegos > 0)
                {
                    listarJuegosNoAlquilados(juegos, SIZE_J, alquileres, SIZE_A, categorias, SIZE_C);
                }
                else
                {
                    showError("Para mostrar este informe, se necesitan clientes");
                }
                break;

            case 14:
                if(conteoAlquileres > 0)
                {
                    listarTelefonosClientesPorFecha(alquileres,SIZE_A,clientes,SIZE_CLT, localidades, SIZE_L);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 15://juegos alquiilados por mujeres
                if(conteoAlquileres > 0)
                {
                    listarJuegosAlquiladosPorMujeres(alquileres,SIZE_A,clientes,SIZE_CLT, juegos, SIZE_J, localidades, SIZE_L);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 16://juegos mas alquilados por hombres
                if(conteoAlquileres > 0)
                {
                    mostrarJuegoMasAlquiladorPorHombres(alquileres,SIZE_A,clientes, SIZE_CLT,juegos, SIZE_J);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 17://clientes por juego seleccionado
                if(conteoAlquileres > 0)
                {
                    listarClientesPorDeterminadoJuego(juegos, SIZE_J, alquileres, SIZE_A, clientes, SIZE_CLT, categorias, SIZE_C, localidades, SIZE_L);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 18://recaudacion por fecha
                if(conteoAlquileres > 0)
                {
                    mostrarRecaudacionPorFecha(alquileres, SIZE_A, juegos, SIZE_J, clientes, SIZE_CLT);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 19://recaudacion por localidad
                if(conteoLocalidades > 0 && conteoAlquileres > 0)
                {
                    mostrarRecaudacionPorLocalidad(localidades, SIZE_L, alquileres, SIZE_A, clientes, SIZE_CLT, juegos, SIZE_J);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 20://listar clientes por localidad
                if(conteoLocalidades > 0 && conteoClientes > 0)
                {
                    conteoClientesPorLocalidad(localidades,SIZE_L,alquileres,SIZE_A,clientes,SIZE_CLT,juegos,SIZE_J);
                }
                else
                {
                    showError("No hay ningun cliente cargado");
                }
                break;
            case 21://listar hombres por localidad
                if(conteoLocalidades > 0 && conteoClientes > 0)
                {
                    hombresPorLocalidad(localidades,SIZE_L,clientes,SIZE_CLT);
                }
                else
                {
                    showError("No hay ningun cliente cargado");
                }
                break;
            case 22:
                if(conteoAlquileres > 0)
                {
                    listarLocalidadesSinAlquileres(clientes, SIZE_CLT, juegos, SIZE_J, alquileres, SIZE_A, localidades, SIZE_L);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;
            case 23:
                if(conteoJuegos > 0)
                {
                    acumularImportePorJuego(clientes, SIZE_CLT, juegos, SIZE_J, alquileres, SIZE_A, localidades, SIZE_L,categorias, SIZE_C);
                }
                else
                {
                    showError("No hay ningun alquiler cargado");
                }
                break;

            case 24:
                if(conteoJuegos > 0)
                {
                    mostrarJuegosDeMagia(juegos,SIZE_J, categorias, SIZE_C);
                }
                break;
            case 25:
                if(conteoJuegos > 0)
                {
                    listarLocalidadesPorDeterminadoJuego(juegos, SIZE_J, alquileres, SIZE_A, clientes, SIZE_CLT, categorias, SIZE_C, localidades, SIZE_L);
                }
                break;
            case 26://listar categorias alquiler hombres
                if(conteoJuegos > 0)
                {
                    listarCategoriasAlquiladosPorHombres(clientes, SIZE_CLT,juegos, SIZE_J, alquileres, SIZE_A, categorias, SIZE_C);
                }
                break;
            case 27://listar juegos de azar
               if(conteoJuegos > 0)
                {
                    mostrarJuegosDeAzar(juegos,SIZE_J, categorias, SIZE_C);
                }
                break;
            case 28://listar juegos de salon
               if(conteoJuegos > 0)
                {
                    mostrarJuegosDeSalon(juegos,SIZE_J, categorias, SIZE_C);
                }
                break;
            case 29://Salir
                confirm = showAlert("Esta seguro que desea salir?");
                if (confirm)
                {
                    continuar = 0;
                    printf("Programa finalizado\n");
                }
                break;
            }

        }
        else
        {
            showError("Demasiados intentos, cerrando programa");
            continuar = 0;
        }
        system("pause");
    }
    return 0;
}
