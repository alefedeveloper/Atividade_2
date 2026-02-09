#include <stdio.h>
#include "cliente.h"

void cadastrarCliente(Cliente clientes[], int *total) {
    printf("\nID do cliente: ");
    scanf("%d", &clientes[*total].id);

    printf("Nome do cliente: ");
    scanf(" %[^\n]", clientes[*total].nome);

    (*total)++;
    printf("Cliente cadastrado com sucesso!\n");
}
