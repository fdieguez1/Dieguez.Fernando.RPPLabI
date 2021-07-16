#include <ctype.h>
#include "datawarehouse.h"
#include "cliente.h"
#include "inputs.h"
#include "validations.h"
#include "ui.h"
#include "randomizer.h"

int initializeClientes(eCliente clientes[], int sizeCLT)
{
    int ret = 0;
    if (clientes != NULL && sizeCLT > 0)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            clientes[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}

int findPlaceInClienteArray(eCliente clientes[], int sizeCLT )
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            if (clientes[i].isEmpty)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int addCliente(eCliente clientes[], int index, int *newId, int* conteoClientes, eLocalidad localidades[], int sizeL)
{
    int allOk = 0;
    char name[MAX_CLIENT_LENGTH];
    char lastname[MAX_CLIENT_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char sex;
    int localidadId;

    //Cargo ID
    clientes[index].codigo = *newId;
    //Pido el nombre
    int nameOk = askForString(name, "Ingrese un nombre: ", MAX_CLIENT_LENGTH);
    while(!validateStringNotEmpty(name))
    {
        nameOk = askForString(name, "Error -> Ingrese un nombre: ", MAX_CLIENT_LENGTH);
    }
    int lastnameOk = askForString(lastname, "Ingrese un apellido: ", MAX_CLIENT_LENGTH);
    while(!validateStringNotEmpty(lastname))
    {
        lastnameOk = askForString(lastname, "Error -> Ingrese un apellido: ", MAX_CLIENT_LENGTH);
    }
    int phoneOk = askForString(phone, "Ingrese un telefono: ", MAX_PHONE_LENGTH);
    while(!validateStringNotEmpty(phone) || !validateIsOnlyNumbers(phone))
    {
        phoneOk = askForString(phone, "El telefono es requerido, solo se aceptan numeros, Ingrese un telefono: ", MAX_PHONE_LENGTH);
    }
//Pido el sexo
    int sexOk = askSex(&sex, "Ingrese un sexo m/f: ");
//Pido la localidad
    int localidadOk = getLocalidadId(&localidadId, localidades, sizeL);
    while(!localidadOk)
    {
        printf("Localidad no encontrada, reingrese: ");
        localidadOk = getLocalidadId(&localidadId, localidades, sizeL);
    }
    if (nameOk && sexOk && lastnameOk && phoneOk )
    {
        clientes[index].codigo = *newId;
        strcpy(clientes[index].nombre, name);
        strcpy(clientes[index].apellido, lastname);
        strcpy(clientes[index].telefono, phone);
        clientes[index].isEmpty = 0;
        clientes[index].sex = sex;
        allOk = 1;
        (*newId)++;
        (*conteoClientes)++;
    }
    else
    {
        showError("Error en uno o mas datos, abortando la carga de empleado");
    }
    return allOk;
}

void showClientes(eCliente clientes[],int sizeCLT, eLocalidad localidades[], int sizeL)
{
    showTitlesForClientes();
    for(int i = 0; i < sizeCLT; i++)
    {
        if (!clientes[i].isEmpty)
        {
            showCliente(clientes[i], 0, localidades, sizeL);
        }
    }
}
void showCliente(eCliente cliente, int showTitles, eLocalidad localidades[], int sizeL)
{
    if (showTitles)
    {
        showTitlesForClientes();
    }
    eLocalidad localidad;
    int localidadOk = findLocalidadById(localidades,sizeL, cliente.localidadId, &localidad);
    char localidadDesc[20];
    if (localidadOk)
    {
        strcpy(localidadDesc, localidad.descripcion);
        printf("| %9d | %14s | %14s |",cliente.codigo, cliente.nombre, cliente.apellido);
        printf(" %14s | %7c | %16s |\n", cliente.telefono, cliente.sex, localidadDesc);
    }
    else
    {
        showError("Problemas al mostrar el cliente, no se logro cargar la descripcion de la localidad");
        printf("Error en cliente id: %d\n", cliente.codigo);
    }
}


int hardcodeClientes(eCliente clienteArray[], int sizeCLT, int* id, int* conteoClientes)
{
    int ret = 0;
    if (clienteArray != NULL && sizeCLT > 0 && id > 0)
    {
        ret = 1;
        for (int i =0; i < sizeCLT; i++)
        {
            clienteArray[i].codigo = *id;
            strcpy(clienteArray[i].nombre, names[i]);
            strcpy(clienteArray[i].apellido, lastnames[i]);
            strcpy(clienteArray[i].telefono, phones[i]);
            clienteArray[i].isEmpty = 0;
            clienteArray[i].sex = sexs[i];
            clienteArray[i].localidadId = getRandomNumber(1,5);
            (*id)++;
            (*conteoClientes)++;
        }
    }
    return ret;
}
int editClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente, eCategoria categorias[], int sizeS)
{
    system("cls");
    int ret = -1;
    showEditOptions();

    char name[MAX_CLIENT_LENGTH];
    char lastname[MAX_CLIENT_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    int editOption;
    int nameOk;
    int lastnameOk;
    int phoneOk;


    int optionOk = utn_getNumero(&editOption, "Ingrese una opcion: ", "Error, opcion invalida", 1,6,100);
    if (optionOk)
    {
        if (clientes != NULL && sizeCLT > 0 && id > 0 && resultingCliente != NULL)
        {
            for(int i = 0; i < sizeCLT; i++)
            {
                int codigo = clientes[i].codigo;
                if (codigo == id)
                {
                    *resultingCliente = clientes[i];
                    if (!clientes[i].isEmpty)
                    {
                        switch(editOption)
                        {
                        case 1://Pido el nombre
                            nameOk = askForString(name, "Ingrese un nombre: ", MAX_CLIENT_LENGTH);
                            while(!validateStringNotEmpty(name))
                            {
                                nameOk = askForString(name, "Ingrese un nombre: ", MAX_CLIENT_LENGTH);
                            }
                            if (nameOk)
                            {
                                strcpy(clientes[i].nombre,name);
                            }
                            break;

                        case 2://Pido el apellido
                            lastnameOk = askForString(lastname, "Ingrese un apellido: ", MAX_CLIENT_LENGTH);
                            while(!validateStringNotEmpty(lastname))
                            {
                                lastnameOk = askForString(lastname, "Ingrese un apellido: ", MAX_CLIENT_LENGTH);
                            }
                            if (lastnameOk)
                            {
                                strcpy(clientes[i].apellido,lastname);
                            }
                            break;
                        case 3://Pido el telefono
                            phoneOk = askForString(phone, "Ingrese un telefono: ", MAX_PHONE_LENGTH);
                            while(!validateStringNotEmpty(phone) || !validateIsOnlyNumbers(phone))
                            {
                                phoneOk = askForString(phone, "Ingrese un telefono: ", MAX_PHONE_LENGTH);
                            }
                            if (phoneOk)
                            {
                                strcpy(clientes[i].telefono,phone);
                            }
                            break;
                        }
                        ret = 1;
                    }
                }
            }
        }
    }
    return ret;
}

int deleteClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente, int* conteoClientes)
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0 && id > 0 && resultingCliente != NULL)
    {
        for(int i = 0; i < sizeCLT; i++)
        {
            int codigo = clientes[i].codigo;
            if (codigo == id)
            {
                *resultingCliente = clientes[i];
                if (!clientes[i].isEmpty)
                {
                    clientes[i].isEmpty = 1;
                    ret = 1;
                    (*conteoClientes)--;
                }
                break;
            }
            ret = 0;
        }
    }
    return ret;
}

int findClienteById(eCliente clientes[], int sizeCLT,int id, eCliente *resultingCliente)
{
    int ret = -1;
    if (clientes != NULL && sizeCLT > 0 && id > 0)
    {
        ret = 0;
        for(int i = 0; i < sizeCLT; i++)
        {
            if (clientes[i].codigo == id)
            {
                *resultingCliente = clientes[i];
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int swapCliente(eCliente *clienteA, eCliente *clienteB)
{
    int ret = 0;
    if (clienteA != NULL && clienteB != NULL)
    {
        eCliente aux;
        aux = *clienteA;
        *clienteA = *clienteB;
        *clienteB = aux;
        ret = 1;
    }
    return ret;
}
int orderByFullName(eCliente clientes[], int sizeCLT, int descending)
{
    int ret=0;
    eCliente aux;
    char nombre1[MAX_NAME_LENGTH];
    char nombre2[MAX_NAME_LENGTH];
    char apellido1[MAX_NAME_LENGTH];
    char apellido2[MAX_NAME_LENGTH];
    if(clientes != NULL && sizeCLT > 0)
    {
        for(int i = 0; i < sizeCLT-1; i++)
        {
            for(int j = i + 1; j  <sizeCLT; j++)
            {
                strcpy(nombre1, clientes[i].nombre);
                strcpy(nombre2, clientes[j].nombre);
                strcpy(apellido1, clientes[i].apellido);
                strcpy(apellido2, clientes[j].apellido);
                strlwr(nombre1);
                strlwr(nombre2);
                strlwr(apellido1);
                strlwr(apellido2);
                if (strcmp(apellido1, apellido2) > 0 ||
                        (strcmp(apellido1, apellido2) == 0 && strcmp(nombre1, nombre2) > 0))
                {//swap
                    aux = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = aux;
                }
            }
        }
        ret = 1;
    }
    return ret;
}

int getClienteId(int *resultingId, eCliente clientes[], int sizeCLT, eLocalidad localidades[], int sizeL)
{
    int ret = -1;
    if(resultingId != NULL && clientes != NULL && sizeCLT > 0 && localidades != NULL && sizeL > 0)
    {
        ret = 0;
        showClientes(clientes, sizeCLT, localidades, sizeL);
        utn_getNumero(resultingId, "Ingrese el ID de empleado: ", "Error, empleado invalido. ", 1, 999, 10);
        for(int i = 0; i < sizeCLT; i++)
        {
            if (*resultingId == clientes[i].codigo)
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}
