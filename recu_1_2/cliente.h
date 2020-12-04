#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int isEmpty;
} eCliente;

#endif // CLIENTE_H_INCLUDED


int obtenerNombreCliente(eCliente clientes[], int tam_cli, int idCliente, char nombreCliente[]);
int getIdCliente(eCliente clientes[],int tam_cli);
int mostrarClientes(eCliente clientes[], int tam_cli);
void mostrarCliente(eCliente unCliente);
int buscarCliente(eCliente clientes[],int tam_cli,int idCliente);
int buscarLibre(eCliente clientes[], int tam_cli);
