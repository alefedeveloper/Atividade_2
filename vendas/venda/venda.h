#ifndef VENDA_H
#define VENDA_H

#include "cliente.h"
#include "produto.h"

#define MAX_PRODUTOS 10

typedef struct {
    Cliente cliente;
    Produto produtos[MAX_PRODUTOS];
    int qtdProdutos;
    float total;
} Venda;

void criarVenda(Venda *venda,
                Cliente clientes[], int totalClientes,
                Produto produtos[], int totalProdutos);

void exibirVenda(Venda venda);

#endif
