#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "juego.h"
#include "cliente.h"
#include "categoria.h"
#include "alquiler.h"

/** \brief muestra los juegos de la categoria de mesa
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void mostrarJuegosDeMesa(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);

/** \brief muestra los alquileres por un cliente seleccionado
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquileres
 * \param sizeA int tamaño del listado de alquileres
 * \param localidades[] eLocalidad listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void mostrarAlquileresPorCliente(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL);

/** \brief muestra la recaudacion acumulada de un cliente seleccionado
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquiler
 * \param localidades[] eLocalidad listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void mostrarRecaudacionPorCliente(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param localidades[] eLocalidad
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void listarClientesSinAlquileres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void listarJuegosNoAlquilados(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCategoria categorias[], int sizeC);

/** \brief
 *
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param localidades[] eCliente listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void listarTelefonosClientesPorFecha(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param localidades[] eCliente listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void listarJuegosAlquiladosPorMujeres(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \return void
 *
 */
void mostrarJuegoMasAlquiladorPorHombres(eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ);

/** \brief
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void listarClientesPorDeterminadoJuego(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eCategoria categorias[], int sizeC, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \return void
 *
 */
void mostrarRecaudacionPorFecha(eAlquiler alquileres[], int sizeA, eJuego juegos[], int sizeJ, eCliente clientes[], int sizeCLT);

/** \brief
 *
 * \param localidades[] eLocalidad
 * \param sizeL int tamaño del listado de localidades
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \return void
 *
 */
void mostrarRecaudacionPorLocalidad(eLocalidad localidades[], int sizeL, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ);

/** \brief
 *
 * \param localidades[] eLocalidad
 * \param sizeL int tamaño del listado de localidades
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \return void
 *
 */
void conteoClientesPorLocalidad(eLocalidad localidades[], int sizeL, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ);

/** \brief
 *
 * \param localidades[] eLocalidad
 * \param sizeL int tamaño del listado de localidades
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \return void
 *
 */
void hombresPorLocalidad(eLocalidad localidades[], int sizeL, eCliente clientes[], int sizeCLT);

/** \brief
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param localidades[] eLocalidad listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void clientesPorLocalidad(eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param localidades[] eLocalidad
 * \param sizeL int tamaño del listado de localidades
 * \return void
 *
 */
void listarLocalidadesSinAlquileres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL);

/** \brief acumula los importes recaudados por cada juego
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param localidades[] eLocalidad listado de localidades
 * \param sizeL int tamaño del listado de localidades
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC inttamaño del listado de categoria
 * \return void
 *
 */
void acumularImportePorJuego(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eLocalidad localidades[], int sizeL, eCategoria categorias[], int sizeC);

/** \brief muestra los juegos de la categoria de Magia
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void mostrarJuegosDeMagia(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);

/** \brief muestra las localidades que tienen los clientes que tienen alquilados juegos
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
/** \brief lista las localidades que alquilaron un juego especifico
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \param localidades[] eLocalidad listado de localidad
 * \param sizeL int tamaño del listado de localidad
 * \return void
 *
 */
void listarLocalidadesPorDeterminadoJuego(eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCliente clientes[], int sizeCLT, eCategoria categorias[], int sizeC, eLocalidad localidades[], int sizeL);

/** \brief
 *
 * \param clientes[] eCliente listado de clientes
 * \param sizeCLT int tamaño del listado de clientes
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param alquileres[] eAlquiler listado de alquiler
 * \param sizeA int tamaño del listado de alquileres
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void listarCategoriasAlquiladosPorHombres(eCliente clientes[], int sizeCLT, eJuego juegos[], int sizeJ, eAlquiler alquileres[], int sizeA, eCategoria categorias[], int sizeC);

/** \brief muestra los juegos de la categoria de Azar
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void mostrarJuegosDeAzar(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);

/** \brief muestra los juegos de la categoria de Salon
 *
 * \param juegos[] eJuego listado de juegos
 * \param sizeJ int tamaño del listado de juegos
 * \param categorias[] eCategoria listado de categorias
 * \param sizeC int tamaño del listado de categorias
 * \return void
 *
 */
void mostrarJuegosDeSalon(eJuego juegos[], int sizeJ, eCategoria categorias[], int sizeC);

#endif // INFORMES_H_INCLUDED
