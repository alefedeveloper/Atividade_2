#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *total);

#endif
