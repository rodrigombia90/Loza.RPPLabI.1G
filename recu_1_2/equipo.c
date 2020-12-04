#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equipo.h"

int mostrarEquipos(eEquipo equipos[], int tam_e)
{
    int error = 1;

    if(equipos!= NULL && tam_e > 0)
    {

        system("cls");
        printf("-----------LISTADO DE equipo------\n");
        printf("-------------------------------------\n");
        printf("--ID      nombre            ---\n");
        printf("-------------------------------------\n");
        for(int i=0; i<tam_e; i++)
        {
            if(equipos[i].id!=0)
            {
                mostrarEquipo(equipos[i]);
            }
        }
        printf("--------------------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}



void mostrarEquipo(eEquipo unEquipo)
{
    printf("- %-4d   %-12s \n",unEquipo.id,unEquipo.nombre);
}
