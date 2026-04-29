#ifndef FILA_H
#define FILA_H

// Definição do nó da fila
typedef struct Elemento {
    int id;
    int tempo;
    struct Elemento *prox;
} Elemento;

// Definição da estrutura de controle da fila
typedef struct Fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

// Protótipos das funções
Fila* cria_fila();
void insere_cliente(Fila *fi);
void atende_cliente(Fila *fi);
void exibe_fila(Fila *fi);
void calcula_tempo_total(Fila *fi);
void libera_fila(Fila *fi);

#endif
