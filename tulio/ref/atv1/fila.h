#ifndef FILA_H
#define FILA_H

typedef struct elemento {
    int num;
    struct elemento *prox;
} Elemento;

typedef struct fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

// Protótipos das funções
Fila* cria_fila();
void insere_elemento(Fila *fi);
void consulta_fila(Fila *fi);
void remove_elemento_fila(Fila *fi);
void libera_fila(Fila *fi);

#endif
