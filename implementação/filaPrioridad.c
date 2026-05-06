#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* frente;
    No* final;
} Fila;



void inicializarFila(Fila* f) {
    f->frente = NULL;
    f->final = NULL;
}

int filaVazia(Fila* f) {
    return f->frente == NULL;
}

void liberarFila(Fila* f) {
    No* atual = f->frente;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    f->frente = NULL;
    f->final = NULL;
}


void inserirPrioridade(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de memória\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = NULL;

    
    if (filaVazia(f) || valor < f->frente->valor) {
        novo->proximo = f->frente;
        f->frente = novo;
        if (filaVazia(f) || f->final == NULL) { 
             f->final = novo;
        }
    } else {
        
        No* atual = f->frente;
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }
        
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        
        
        if (atual == f->final) {
            f->final = novo;
        }
    }
}



void inverterAux(Fila* f, No* atual) {
    if (atual == NULL) return;

    
    No* proximo = atual->proximo;

  
    if (f->frente == atual) {
        f->frente = f->frente->proximo;
        if (f->frente == NULL) f->final = NULL;
        else atual->proximo = NULL; // Desconecta
    }

  
    if (!filaVazia(f)) {
        inverterAux(f, f->frente);
    }

    
    if (f->final != NULL) {
        f->final->proximo = atual;
        f->final = atual;
        f->final->proximo = NULL;
    } else {
        
        f->frente = atual;
        f->final = atual;
        atual->proximo = NULL;
    }
}

void inverterFila(Fila* f) {
    if (!filaVazia(f)) {
        inverterAux(f, f->frente);
    }
}


Fila copiarFila(Fila* origem) {
    Fila copia;
    inicializarFila(&copia);
    
    No* atual = origem->frente;
    while (atual != NULL) {
        inserirPrioridade(&copia, atual->valor); 
        
        atual = atual->proximo;
    }
    return copia;
}


Fila copiarFilaFiel(Fila* origem) {
    Fila copia;
    inicializarFila(&copia);
    
    No* atual = origem->frente;
    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = atual->valor;
        novo->proximo = NULL;
        
        if (copia.final != NULL) {
            copia.final->proximo = novo;
            copia.final = novo;
        } else {
            copia.frente = novo;
            copia.final = novo;
        }
        atual = atual->proximo;
    }
    return copia;
}


Fila concatenarFilas(Fila* f1, Fila* f2) {
    Fila resultado;
    inicializarFila(&resultado);

    
    No* atual = f1->frente;
    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = atual->valor;
        novo->proximo = NULL;
        
        if (resultado.final != NULL) {
            resultado.final->proximo = novo;
            resultado.final = novo;
        } else {
            resultado.frente = novo;
            resultado.final = novo;
        }
        atual = atual->proximo;
    }

  
    atual = f2->frente;
    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = atual->valor;
        novo->proximo = NULL;
        
        if (resultado.final != NULL) {
            resultado.final->proximo = novo;
            resultado.final = novo;
        } else {
            resultado.frente = novo;
            resultado.final = novo;
        }
        atual = atual->proximo;
    }

    return resultado;
}


void imprimirFila(Fila* f) {
    printf("[ ");
    No* atual = f->frente;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}


int main() {
    Fila f1;
    inicializarFila(&f1);

   
    printf("=== 1. Fila com Prioridade (Menor valor primeiro) ===\n");
    inserirPrioridade(&f1, 10);
    inserirPrioridade(&f1, 5);
    inserirPrioridade(&f1, 20);
    inserirPrioridade(&f1, 2);
    inserirPrioridade(&f1, 15);
    printf("Inseridos: 10, 5, 20, 2, 15\n");
    printf("Fila ordenada: ");
    imprimirFila(&f1); 
   
    printf("\n=== 2. Inverter Fila ===\n");
    printf("Antes: ");
    imprimirFila(&f1);
    inverterFila(&f1);
    printf("Depois: ");
    imprimirFila(&f1);
    
    printf("\n=== 3. Copiar Fila ===\n");
    Fila f2 = copiarFilaFiel(&f1);
    printf("Cópia: ");
    imprimirFila(&f2);
    
    liberarFila(&f2);

    
    printf("\n=== 4. Concatenar Filas ===\n");
    Fila fA, fB;
    inicializarFila(&fA);
    inicializarFila(&fB);
    
    
    No* n1 = (No*)malloc(sizeof(No)); n1->valor = 1; n1->proximo = NULL;
    No* n2 = (No*)malloc(sizeof(No)); n2->valor = 2; n2->proximo = NULL;
    fA.frente = n1; fA.final = n2; n1->proximo = n2;


    No* n3 = (No*)malloc(sizeof(No)); n3->valor = 3; n3->proximo = NULL;
    No* n4 = (No*)malloc(sizeof(No)); n4->valor = 4; n4->proximo = NULL;
    fB.frente = n3; fB.final = n4; n3->proximo = n4;

    printf("Fila A: "); imprimirFila(&fA);
    printf("Fila B: "); imprimirFila(&fB);

    Fila fC = concatenarFilas(&fA, &fB);
    printf("Concatenada (A + B): ");
    imprimirFila(&fC);
   
    liberarFila(&f1);
    liberarFila(&fC);
   
    No* temp;
    temp = fA.frente; while(temp) { temp = temp->proximo; free(temp); }
    temp = fB.frente; while(temp) { temp = temp->proximo; free(temp); }

    return 0;
}