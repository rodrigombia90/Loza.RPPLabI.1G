#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "alquiler.h"
#include "equipo.h"

#define TAM_CLI 10
#define TAM_ALQ 10
#define TAM_E 3


char menuOpciones();

typedef struct{

	int id;
    char nombre[10];

}eOperador;

int main()
{
    eCliente clientes[TAM_CLI];
    eAlquiler alquileres[TAM_ALQ];

     eOperador datosOperador []=
    {
        {0,"ARAGORN"},
        {1,"ARWEN"},
        {2,"GANDALF"},
        {3,"LUKE"},
    };

    eEquipo datosEquipo [10]=
    {
        {1,"amoladora"},
        {2,"taladro"},
        {3,"mezcladora"},
    };
        char seguir = 's';
        char confirma;
        int idCliente=1;
       int idAlquiler=100;

    inicializarClientes(clientes,TAM_CLI);
    inicializarAlquileres(alquileres,TAM_CLI);
    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 'a':
            altacliente(clientes,TAM_CLI,idCliente);
            idCliente++;
            break;
        case 'b':
            modificarCliente(clientes,TAM_CLI);
            break;
        case 'c':
            bajaCliente(clientes,TAM_CLI);
            break;
        case 'd':
            altaAlquiler(clientes,TAM_CLI,alquileres,TAM_ALQ,idAlquiler,datosEquipo,TAM_E);
            break;
        case 'e':

            break;
        case 'f':
            listarInformes(clientes,TAM_CLI,alquileres,TAM_ALQ);
            break;
        case 'z':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while( seguir == 's');

    return 0;
}


char menuOpciones()
{
    char opcion;
    printf("*** Bienvenido a la emprese de alquiler de maquinas***\n\n");
    printf("A_ Alta del cliente\n");
    printf("B_ Modificar datos del cliente\n");
    printf("C_ Baja del cliente\n");
    printf("D_ Nuevo alquiler\n");
    printf("E_ Fin del alquiler\n");
    printf("F_ Listar Informes\n");
    printf("Z_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}



int listarInformes(eCliente clientes[],int tam_cli,eAlquiler alquileres[],int tam_alq)
{
    int error=1;
    char confirma;
    if(clientes != NULL && tam_cli > 0)
    {
        system("cls");
        printf("    ***Informes***\n\n");
        printf("A_ Nombre y apellido del asociado con mas alquileres\n");
        printf("B_ El o los quipos mas alquilados y su cantidad\n");
        printf("C_ Tiempo promedio de alquiler de los equipos\n");
        printf("D_ Todos los clientes con alquileres\n");
        printf("k_ Volver al menu principal\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma = tolower(confirma);
        system("cls");
        switch(confirma)
        {
        case 'a':
            asociadoConMasAlquiler(alquileres,tam_alq,clientes,tam_cli);
            break;
        case 'b':

            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            break;
        case 'k':
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
    }
    return error;
}



