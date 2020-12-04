#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alquiler.h"
#include "equipo.h"

int altacliente(eCliente clientes[],int tam_cli,int idCliente)
{
    int error=-1;
    int indice;
    eCliente nuevoCliente;

    if(clientes != NULL && tam_cli>0)
    {
        system("cls");
        indice=buscarLibre(clientes,tam_cli);

        if(indice==-1)
        {
            printf("No hay lugar");
        }
        else
        {
            nuevoCliente.isEmpty=0;
            nuevoCliente.id=idCliente;
            fflush(stdin);
            system("cls");
            printf("\n***Alta de cliente***\n");
            fflush(stdin);
            getString(nuevoCliente.nombre,sizeof(nuevoCliente.nombre),"\n\nIngrese nombre de Cliente: ","Error,ingrese nombre valido");
            getString(nuevoCliente.apellido,sizeof(nuevoCliente.apellido),"\n\nIngrese apellido de Cliente: ","Error,ingrese nombre valido");
            utn_getNumeroInt(&nuevoCliente.dni,"\n\nIngrese dni del cliente: ","Error, ingrese dni valido",1000000,99999999,5);
            clientes[indice]=nuevoCliente;
            error=0;
        }
    }

    return error;
}




int modificarCliente(eCliente clientes[], int tam_cli)
{
    int error = 1;
    int idModificar;
    int indice;
    char seguir = 's';

    if(clientes != NULL && tam_cli > 0)
    {
        system("cls");
        idModificar=getIdCliente(clientes,tam_cli);
        indice=buscarCliente(clientes,tam_cli,idModificar);
        if( indice == -1)
        {
            printf("\n\n\n Error-ID inexistente.\n\n\n");
        }
        else
        {
            system("cls");
        printf("---------------MODIFICAR CLIENTE---------------------\n");
        printf("----ID       nombre           apellido       dni-----\n");
        printf("------------------------------------------------------\n");
            mostrarCliente(clientes[indice]);
            printf("\n\n");

            do
            {
                switch(menuModificar())
                {
                case 'A':
                   modificarNombre(clientes,tam_cli,indice);
                    seguir = 'n';
                    error = 0;
                    system("cls");
                    break;
                case 'B':
                    modificarApellido(clientes,tam_cli,indice);
                    seguir = 'n';
                    error = 0;
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\n\n\nOpcion no valida\n\n\n");
                    break;
                }

            }
            while( seguir == 's');
        }
        error=0;
    }

    return error;

}




int menuModificar()
{
    char opcion;

    printf("*** INGRESE OPCION A MODIFICAR ***\n\n");
    printf("A nombre\n");
    printf("B apellido \n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = toupper(getchar());

    return opcion;

}

int modificarNombre(eCliente clientes[],int tam_cli,int indice)
{
    int error = 1;
    int confirma;
    char auxNombre[20];
    printf("\n\n");
    utn_getCadena(&auxNombre,sizeof(auxNombre),"ingrese nuevo nombre","error, ingres nombre valido",5);
    printf("\nConfirma modificacion de nombre?\n\n");
    printf("1-SI\n");
    printf("2-NO\n\n");
    utn_getNumeroInt(&confirma,"Respuesta: ","Error, ingrese opcion valida\n",1,2,5);
    if(confirma==1)
    {
        strcpy(clientes[indice].nombre,auxNombre);
        error = 0;
    }
    else
    {
        error = 2;
    }

    if(error==0)
    {
        system("cls");
        printf("\n\nModificacion de edad exitosa\n\n\n\n");
        system("pause");
    }
    else if(error==2)
    {
        system("cls");
        printf("\n\nModificacion cancelada por el usuario\n\n\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la modificacion\n\n\n\n");
        system("pause");
    }

    return error;
}



int modificarApellido(eCliente clientes[],int tam_cli,int indice)
{
    int error = 1;
    int confirma;
    char auxApellido[20];
    printf("\n\n");
    utn_getCadena(&auxApellido,sizeof(auxApellido),"ingrese nuevo apellido","error, ingres apelldio valido",5);
    printf("\nConfirma modificacion de apellido?\n\n");
    printf("1-SI\n");
    printf("2-NO\n\n");
    utn_getNumeroInt(&confirma,"Respuesta: ","Error, ingrese opcion valida\n",1,2,5);
    if(confirma==1)
    {
        strcpy(clientes[indice].apellido,auxApellido);
        error = 0;
    }
    else
    {
        error = 2;
    }

    if(error==0)
    {
        system("cls");
        printf("\n\nModificacion de edad exitosa\n\n\n\n");
        system("pause");
    }
    else if(error==2)
    {
        system("cls");
        printf("\n\nModificacion cancelada por el usuario\n\n\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la modificacion\n\n\n\n");
        system("pause");
    }

    return error;
}


int bajaCliente(eCliente clientes[],int tam_cli)
{
   int error=1;
   int idBaja;
   int indice;
   int confirma;
   if(clientes!=NULL &&tam_cli>0)
   {
       system("cls");
       printf(" *** Baja de Cliente ***");
        mostrarClientes(clientes,tam_cli);
        utn_getNumeroInt(&idBaja,"Ingrese id para dar de baja: ","error, id invalido",0,100,5);
//       printf("Ingrese id para dar de baja: ");
//       scanf("%d",&idBaja);
       indice=buscarCliente(clientes,tam_cli,idBaja);
       if(indice==-1)
       {
           printf("No existe el id");

       }
       else
        {
            system("cls");
        printf("----ID       nombre           apellido       dni         -----\n");
        printf("--------------------------------------------------------------------------------\n");
            mostrarCliente(clientes[indice]);
            printf("\n\nConfirma baja de cliente?\n\n");
            printf("1-SI\n");
            printf("2-NO\n\n");
            printf("Respuesta: ");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                clientes[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
       }
   }
   if(error==0)
    {
        system("cls");
        printf("\n\nBaja exitosa\n\n\n\n");
    }else if(error==2)
    {
        system("cls");
        printf("\n\nBaja cancelada por el usuario\n\n\n\n");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la baja\n\n\n\n");
    }

    return error;
}




int altaAlquiler(eCliente clientes[],int tam_cli,eAlquiler alquileres[],int tam_alqui,int idAlquiler,eEquipo equipos[],int tam_e)
{
    int error=-1;
    int indiceAlq;
    eAlquiler nuevoAlquiler;

    if(alquileres != NULL && tam_alqui>0)
    {
        system("cls");
        indiceAlq=buscarLibreAlquiler(alquileres,tam_alqui);
        if(indiceAlq==-1)
        {
            printf("No hay lugar para alquileres");
        }
        else
        {
            nuevoAlquiler.idCliente=getIdCliente(clientes,tam_cli);
            mostrarEquipos(equipos,tam_e);
            utn_getNumeroInt(&nuevoAlquiler.idEquipo,"ingrese id del equipo","ingrese id valido",0,2,5);
            printf("\n");
            utn_getNumeroInt(&nuevoAlquiler.idOperador,"ingrese id del operador","ingrese id valido",0,2,5);
            utn_getNumeroFloat(&nuevoAlquiler.tiempoAlquiler,"ingrese tiempo estimado en HS", "error, ingres hs entre 0 y 96 valido",0,96,5);
            system("cls");
            nuevoAlquiler.isEmpty=0;
            nuevoAlquiler.idAlquiler=idAlquiler;
            strcpy(nuevoAlquiler.estado,"ALQUILADO");
            alquileres[indiceAlq]=nuevoAlquiler;
        }
        error=0;
    }
    return error;
}



int bajaAlquiler(eAlquiler alquileres[],int tam_alq)
{
   int error=1;
   int idBaja;
   int indice;
   int confirma;
   printf("no entro");
   if(alquileres!=NULL &&tam_alq>0)
   {    printf("SI entro");
       system("cls");
       printf(" *** Baja Alquiler ***");
       mostrarAlquileres(alquileres,tam_alq);
       printf("Ingrese id para dar de baja: ");
       scanf("%d",&idBaja);
       indice=buscarAlquiler(alquileres,tam_alq,idBaja);
       if(indice==-1)
       {
           printf("No existe el id");

       }
       else
        {
            system("cls");
        printf("----ID       nombre           tipo           color       edad       Cliente-----\n");
        printf("--------------------------------------------------------------------------------\n");
            mostrarAlquileres(alquileres,tam_alq);
            printf("\n\nConfirma baja de alquiler?\n\n");
            printf("1-SI\n");
            printf("2-NO\n\n");
            printf("Respuesta: ");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                alquileres[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
       }
   }
   if(error==0)
    {
        system("cls");
        printf("\n\nBaja exitosa\n\n\n\n");
    }else if(error==2)
    {
        system("cls");
        printf("\n\nBaja cancelada por el usuario\n\n\n\n");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la baja\n\n\n\n");
    }

    return error;
}


