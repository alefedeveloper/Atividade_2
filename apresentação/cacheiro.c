#include <stdio.h>
#include <limits.h>
#include <time.h>

#define N 8

long long permutacoes = 0;

int min(int a, int b){
    return (a < b) ? a : b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calcular_custo(int grafo[N][N], int caminho[]){
    int custo = 0;
    for(int i=0;i<N-1;i++)
        custo += grafo[caminho[i]][caminho[i+1]];
    custo += grafo[caminho[N-1]][caminho[0]];
    return custo;
}

void permutar(int grafo[N][N], int caminho[], int inicio, int fim, int *min_custo){
    if(inicio == fim){
        permutacoes++;
        int custo = calcular_custo(grafo, caminho);
        *min_custo = min(*min_custo, custo);
        return;
    }

    for(int i=inicio;i<=fim;i++){
        swap(&caminho[inicio], &caminho[i]);
        permutar(grafo, caminho, inicio+1, fim, min_custo);
        swap(&caminho[inicio], &caminho[i]);
    }
}

int main(){

    int grafo[N][N] = {0};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i!=j)
                grafo[i][j] = (i+j)%10 + 1;

    int caminho[N];
    for(int i=0;i<N;i++)
        caminho[i] = i;

    int min_custo = INT_MAX;

    clock_t inicio = clock();
    permutar(grafo, caminho, 0, N-1, &min_custo);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;

    printf("Cidades: %d\n", N);
    printf("Permutacoes: %lld\n", permutacoes);
    printf("Tempo: %.6f s\n", tempo);
    printf("Custo minimo: %d\n", min_custo);

    return 0;
}