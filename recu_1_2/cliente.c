#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int inicializarClientes(eCliente clientes[], int tam_cli)
{
    int error = 1;
    if (clientes!=NULL && tam_cli > 0)
    {
        for(int i=0; i<tam_cli; i++)
        {
            clientes[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}


/** \brief muestra un cliente
 *
 * \param unCliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente)
{
    printf("- %-4d   %-12s    %-4s  %-6d\n",unCliente.id,unCliente.nombre,unCliente.apellido,unCliente.dni);
}


int getIdCliente(eCliente clientes[],int tam_cli)
{
    int auxId;
    mostrarClientes(clientes,tam_cli);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarCliente(clientes,tam_cli,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}


int mostrarClientes(eCliente clientes[], int tam_cli)
{
    int error = 1;

    if(clientes!= NULL && tam_cli > 0)
    {

        system("cls");
        printf("-----------LISTADO DE CLIENTES------\n");
        printf("-------------------------------------\n");
        printf("--ID      Nombre    apellido    DNI--\n");
        printf("-------------------------------------\n");
        for(int i=0; i<tam_cli; i++)
        {
            if(clientes[i].id!=0 && clientes[i].isEmpty==0)
            {
                mostrarCliente(clientes[i]);
            }
        }
        printf("--------------------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}

 int buscarCliente(eCliente clientes[],int tam_cli,int idCliente)
{
    int indice=-1;

    for(int i=0; i<tam_cli; i++)
    {
        if(clientes[i].id==idCliente &&clientes[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


int buscarLibre(eCliente clientes[], int tam_cli)
{
    int indice = -1;
    for(int i = 0; i < tam_cli; i++)
    {
        if(clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


