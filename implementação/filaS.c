#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* proximo;
} No;


typedef struct {
    No* frente;
    No* tras;
    int tamanho;
} Fila;

// 1. Criar Fila
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
    return f;
}


int estaVazia(Fila* f) {
    return (f->frente == NULL);
}


void inserir(Fila* f, int x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = x;
    novo->proximo = NULL;

    if (estaVazia(f)) {
        f->frente = novo;
    } else {
        f->tras->proximo = novo;
    }
    f->tras = novo;
    f->tamanho++;
}

int remover(Fila* f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    No* temp = f->frente;
    int valor = temp->valor;
    
    f->frente = f->frente->proximo;
    if (f->frente == NULL) f->tras = NULL;
    
    free(temp);
    f->tamanho--;
    return valor;
}


void exibirFila(Fila* f) {
    No* atual = f->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


int contarElementos(Fila* f) {
    return f->tamanho;
}


int consultarPrimeiro(Fila* f) {
    if (estaVazia(f)) return -1;
    return f->frente->valor;
}


int main() {
    Fila* f = criarFila();
    
    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 30);
    
    exibirFila(f);
    printf("Primeiro: %d\n", consultarPrimeiro(f));
    printf("Tamanho: %d\n", contarElementos(f));
    
    printf("Removido: %d\n", remover(f));
    exibirFila(f);

    return 0;
}
