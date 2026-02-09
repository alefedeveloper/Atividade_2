#include <stdio.h>
#include "produto.h"

void cadastrarProduto(Produto produtos[], int *total) {
    printf("\nCódigo do produto: ");
    scanf("%d", &produtos[*total].codigo);

    printf("Nome do produto: ");
    scanf(" %[^\n]", produtos[*total].nome);

    printf("Preço: ");
    scanf("%f", &produtos[*total].preco);

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}
