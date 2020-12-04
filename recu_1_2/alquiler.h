#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{

    int idAlquiler;
	int idEquipo;
	int idCliente;
	int idOperador;
	float tiempoAlquiler;
	char estado[10];
	int isEmpty;

}eAlquiler;

#endif // ALQUILER_H_INCLUDED

int asociadoConMasAlquiler(eAlquiler alquileres[], int tam_alq, eCliente clientes[], int tam_cli);
