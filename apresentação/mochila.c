#include <stdio.h>
#include <time.h>

long long chamadas = 0;

int max(int a, int b){
    return (a > b) ? a : b;
}

// Força Bruta (Exponencial)
int knapsack_rec(int n, int W, int peso[], int valor[]){
    chamadas++;
    if(n == 0 || W == 0)
        return 0;

    if(peso[n-1] > W)
        return knapsack_rec(n-1, W, peso, valor);

    return max(
        valor[n-1] + knapsack_rec(n-1, W - peso[n-1], peso, valor),
        knapsack_rec(n-1, W, peso, valor)
    );
}

// Programação Dinâmica
int knapsack_dp(int n, int W, int peso[], int valor[]){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(peso[i-1] <= w)
                dp[i][w] = max(valor[i-1] + dp[i-1][w-peso[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main(){

    int peso[] = {2,3,4,5,9,7,3,6,4,8};
    int valor[] = {3,4,8,8,10,7,4,5,3,9};
    int n = 10;
    int W = 20;

    // Força Bruta
    chamadas = 0;
    clock_t inicio1 = clock();
    int r1 = knapsack_rec(n, W, peso, valor);
    clock_t fim1 = clock();
    double tempo1 = (double)(fim1 - inicio1)/CLOCKS_PER_SEC;

    // DP
    clock_t inicio2 = clock();
    int r2 = knapsack_dp(n, W, peso, valor);
    clock_t fim2 = clock();
    double tempo2 = (double)(fim2 - inicio2)/CLOCKS_PER_SEC;

    printf("Itens: %d\n", n);
    printf("Forca Bruta -> Resultado: %d | Chamadas: %lld | Tempo: %.6f s\n", r1, chamadas, tempo1);
    printf("DP          -> Resultado: %d | Tempo: %.6f s\n", r2, tempo2);

    return 0;
}