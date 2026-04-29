#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *cria_fila() {
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) return;

    printf("\nDigite o numero a ser inserido na fila: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;

    if (fi->inicio == NULL) {
        fi->inicio = novo;
    } else {
        fi->fim->prox = novo;
    }
    fi->fim = novo;

    printf("Numero %d inserido com sucesso!\n", novo->num);
}

void consulta_fila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nA fila esta vazia!!\n");
        return;
    }
    
    Elemento *aux = fi->inicio;
    printf("\n--- Elementos na Fila ---");
    while (aux != NULL) {
        printf("\n [%d] ", aux->num);
        aux = aux->prox;
    }
    printf("\n-------------------------\n");
}

void remove_elemento_fila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nFila Vazia, nada para remover!!\n");
        return;
    }
    
    Elemento *aux = fi->inicio;
    printf("\nNumero %d removido!", aux->num);
    
    fi->inicio = fi->inicio->prox;
    
    // Se a fila ficou vazia, o fim também deve ser NULL
    if (fi->inicio == NULL) {
        fi->fim = NULL;
    }
    
    free(aux);
}

// Função importante para não deixar lixo na memória do PC
void libera_fila(Fila *fi) {
    if (fi != NULL) {
        Elemento *aux;
        while (fi->inicio != NULL) {
            aux = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(aux);
        }
        free(fi);
        printf("\nMemoria da fila liberada.");
    }
}

int main() {
    Fila *fi = cria_fila();

    // Testando o fluxo
    insere_elemento(fi);
    insere_elemento(fi);
    insere_elemento(fi);
    
    consulta_fila(fi);
    
    remove_elemento_fila(fi);
    
    printf("\n\nFila apos a remocao:");
    consulta_fila(fi);

    libera_fila(fi);
    
    return 0;
}
