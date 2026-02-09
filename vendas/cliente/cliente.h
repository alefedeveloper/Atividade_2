#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int id;
    char nome[50];
} Cliente;

void cadastrarCliente(Cliente clientes[], int *total);

#endif
