#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

void showMenu()
{
    system("cls");//sacar para ver los hardcodeos, limpia los residuos de ejecuciones anteriores
    printDivisor();
    centerText("Gestion de clientes y alquileres de juegos", UI_WIDTH);
    printf("\n");
    printDivisor();
    printTableDivisor();
    printf("%c ", LIST_THUMBNAIL);
    printf("1-Mostrar juegos\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("2-Mostrar categorias\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("3-Alta Cliente\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("4-Modificacion Cliente\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("5-Baja Cliente\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("6-Listar Clientes\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("7-Cargar alquileres\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("8-Listar alquileres\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("9-Mostrar juegos de la categoria de mesa\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("10-Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("11-Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("12-Listar los clientes que no alquilaron juegos\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("13-Listar los juegos que no han sido alquilados\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("14-Listar los telefonos de los clientes que alquilaron juegos en una determinada fecha\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("15-Listar los juegos alquilados por mujeres\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("16-Mostrar el o los juegos mas alquilados por hombres\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("17-Listar los clientes que alquilaron un determinado juego\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("18-Mostrar la recaudacion de una fecha en particular\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("19-Mostrar la recaudacion por localidad\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("20-Mostrar los clientes por localidad\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("21-Mostrar los hombres por localidad\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("22-Localidades sin alquiler\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("23-Importe acumulador por juego\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("24-Mostrar juegos de la categoria de magia\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("25-Listar las localidades con clientes que alquilaron un determinado juego\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("26-Listar las categorias con alquileres de hombres\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("27-Mostrar juegos de la categoria de azar\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("28-Mostrar juegos de la categoria de salon\n");
    printDivisor();
    printf("%c ", LIST_THUMBNAIL);
    printf("29-Salir\n");
    printDivisor();
}

void showError(char errorMsg[])
{
    printf("\n");
    printDivisor();
    printf("\nERROR\n%s\n", errorMsg);
    printf("\n");
    printDivisor();
    printf("\n");
}

int showAlert(char alertMsg[])
{
    int ret = 0;
    char input;
    printDivisor();
    printTableDivisor();
    printf("\n\nAVISO\n%s\n", alertMsg);
    printf("%c ", LIST_THUMBNAIL);
    printf("Si: S \t No: N \n\n");
    printTableDivisor();
    printDivisor();
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &input);
    if (input == 's' || input == 'S')
    {
        ret = 1;
    }
    return ret;
}

void showTitlesForJuegos(){
    centerText("Juegos", UI_WIDTH);
    printf("\n");
    printTableDivisor();
    printf("|     Codigo      |          Descripcion          |      Importe      |       Categoria     |\n");
    printTableDivisor();
}
void showTitlesForClientes(){
    centerText("Clientes", UI_WIDTH);
    printf("\n");
    printTableDivisor();
    printf("|  Codigo   |     Nombre     |    Apellido    |    Telefono    |  Sexo   |     Localidad    |\n");
    printTableDivisor();

}
void showTitlesForCategorias(){
    centerText("Categorias", UI_WIDTH);
    printf("\n");
    printTableDivisor();
    printf("|            Id               |                          Descripcion                        |\n");
    printTableDivisor();
}

void showTitlesForLocalidades(){
    centerText("Localidades", UI_WIDTH);
    printf("\n");
    printTableDivisor();
    printf("|            Id               |                          Descripcion                        |\n");
    printTableDivisor();
}

void showTitlesForAlquileres(){
    centerText("Alquileres", UI_WIDTH);
    printf("\n");
    printTableDivisor();
    printf("|     Id      |     Cliente      |        Juego        |       Fecha       |    Localidad   |\n");
    printTableDivisor();
}

void showEditOptions(){
    printDivisor();
    centerText("Edicion de Cliente", UI_WIDTH);
    printf("\n");
    printDivisor();
    printTableDivisor();
    printf("%c ", LIST_THUMBNAIL);
    printf("1-Editar nombre\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("2-Editar apellido\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("3-Editar telefono\n");
}

void printDivisor()
{
    //Imprimo una division en pantalla (ASCII)
    for(int i = 0; i < UI_WIDTH; i++)
    {
        printf("%c", 254);
    }
    printf("\n");
}
void printTableDivisor()
{
    //Imprimo una division en pantalla (ASCII)
    for(int i = 0; i < UI_WIDTH; i++)
    {
        printf("%c", 176);
    }
    printf("\n");
}
void centerText(char* text, int totalWidth)
{
    int size = strlen(text);
    int spaces = totalWidth - size;
    int leftMargin = spaces / 2;
    for(int i = 0; i < leftMargin; i ++)
    {
        printf(" ");
    }
    printf("%s", text);
}
