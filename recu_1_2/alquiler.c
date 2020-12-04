#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "cliente.h"
#include "alquiler.h"

int inicializarAlquileres(eAlquiler alquileres[], int tam_alq)
{
    int error = 1;
    if (alquileres!=NULL && tam_alq > 0)
    {
        for(int i=5; i<tam_alq; i++)
        {
            alquileres[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}



int buscarLibreAlquiler(eAlquiler alquileres[], int tam_alq)
{
    int indice = -1;
    for(int i = 0; i < tam_alq; i++)
    {
        if(alquileres[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int mostrarAlquileres(eAlquiler alquileres[], int tam_alq)
{
    int error = 1;

    if(alquileres!= NULL && tam_alq > 0)
    {

        system("cls");
        printf("-----------LISTADO DE CLIENTES------\n");
        printf("-------------------------------------\n");
        printf("--ID      Nombre      Sexo      DNI--\n");
        printf("-------------------------------------\n");
        for(int i=0; i<tam_alq; i++)
        {
            if(alquileres[i].idAlquiler!=0 && alquileres[i].isEmpty==0)
            {
                mostrarAlquiler(alquileres);
            }
        }
        printf("--------------------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}


void mostrarAlquiler(eAlquiler unAlquiler)
{
    printf("- %-4d   %-2d    %-4d  \n",unAlquiler.idAlquiler,unAlquiler.idCliente,unAlquiler.idEquipo);
}


int buscarAlquiler(eAlquiler alquileres[],int tam_alq,int idAlquiler)
{
    int indice=-1;

    for(int i=0; i<tam_alq; i++)
    {
        if(alquileres[i].idAlquiler==idAlquiler &&alquileres[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}



int asociadoConMasAlquiler(eAlquiler alquileres[], int tam_alq, eCliente clientes[], int tam_cli)
{
    int error=1;
    int mayor;
    int contadores[tam_cli];
    int flag=0;
    for(int i=0; i<tam_alq; i++)
    {
        contadores[i]=0;
    }
    if(alquileres!=NULL&&clientes!=NULL&&tam_alq>0&&tam_cli>0)
    {
        system("cls");
        printf("*** asociado con mas alquileres ***\n");
        for(int c=0; c<tam_cli; c++)
        {

            for(int m=0; m<tam_alq; m++)
            {
                if(alquileres[m].isEmpty==0&&alquileres[m].idCliente==clientes[c].id)
                {
                   contadores[c]++;
                }
            }
        }

        for(int i=0;i<tam_cli;i++)
        {
            if(contadores[i]>mayor || flag==0)

            {
                mayor=contadores[i];
                flag=1;
            }
        }
        printf("El o los colores con mas alquiler es: \n\n");
        for(int i=0;i<tam_cli;i++)
        {
            if(contadores[i] == mayor)
            {
                printf("nombre: %s apellido: %s\n",clientes[i].nombre,clientes[i].apellido);
            }
        }

        printf("\n\n");
        error=0;
    }
    return error;
}

