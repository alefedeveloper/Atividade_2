#include <stdio.h>
#include "venda.h"

void criarVenda(Venda *venda,
                Cliente clientes[], int totalClientes,
                Produto produtos[], int totalProdutos) {

    int id, codigo, i;
    char opcao;

    venda->total = 0;
    venda->qtdProdutos = 0;

    printf("\nID do cliente: ");
    scanf("%d", &id);

    for (i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            venda->cliente = clientes[i];
            break;
        }
    }

    do {
        printf("Código do produto: ");
        scanf("%d", &codigo);

        for (i = 0; i < totalProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                venda->produtos[venda->qtdProdutos] = produtos[i];
                venda->total += produtos[i].preco;
                venda->qtdProdutos++;
                break;
            }
        }

        printf("Adicionar outro produto? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' && venda->qtdProdutos < MAX_PRODUTOS);

    printf("Venda criada com sucesso!\n");
}

void exibirVenda(Venda venda) {
    int i;

    printf("\nCliente: %s\n", venda.cliente.nome);
    printf("Produtos:\n");

    for (i = 0; i < venda.qtdProdutos; i++) {
        printf("- %s | R$ %.2f\n",
               venda.produtos[i].nome,
               venda.produtos[i].preco);
    }

    printf("Valor total: R$ %.2f\n", venda.total);
}
