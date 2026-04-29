#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* cria_fila() {
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void insere_cliente(Fila *fi) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) return;

    printf("\nID do cliente: ");
    scanf("%d", &novo->id);
    printf("Tempo estimado de atendimento (min): ");
    scanf("%d", &novo->tempo);
    novo->prox = NULL;

    if (fi->inicio == NULL) {
        fi->inicio = novo;
    } else {
        fi->fim->prox = novo;
    }
    fi->fim = novo;
    printf("Cliente %d entrou na fila.\n", novo->id);
}

void atende_cliente(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nFila vazia! Nenhum cliente para atender.\n");
        return;
    }
    Elemento *aux = fi->inicio;
    printf("\nAtendendo cliente ID: %d...", aux->id);
    
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL) {
        fi->fim = NULL;
    }
    free(aux);
    printf(" Pronto!\n");
}

void exibe_fila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nFila vazia.\n");
        return;
    }
    Elemento *aux = fi->inicio;
    printf("\n--- Clientes em Espera ---");
    while (aux != NULL) {
        printf("\nID: %d | Tempo: %d min", aux->id, aux->tempo);
        aux = aux->prox;
    }
    printf("\n--------------------------\n");
}

void calcula_tempo_total(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nTempo total de espera: 0 minutos.\n");
        return;
    }
    Elemento *aux = fi->inicio;
    int total = 0;
    while (aux != NULL) {
        total += aux->tempo;
        aux = aux->prox;
    }
    printf("\nTempo total de espera dos clientes na fila: %d minutos.\n", total);
}

void libera_fila(Fila *fi) {
    if (fi != NULL) {
        Elemento *aux;
        while (fi->inicio != NULL) {
            aux = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(aux);
        }
        free(fi);
    }
}

int main() {
    Fila *banco = cria_fila();
    int op;

    do {
        printf("\n1-Chegada Cliente | 2-Atender | 3-Exibir Fila | 4-Tempo Total | 0-Sair\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: insere_cliente(banco); break;
            case 2: atende_cliente(banco); break;
            case 3: exibe_fila(banco); break;
            case 4: calcula_tempo_total(banco); break;
            case 0: libera_fila(banco); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}
