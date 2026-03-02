#include <stdio.h>
#include <time.h>

long long chamadas = 0;

// Recursivo (Exponencial)
long long fib_rec(int n){
    chamadas++;
    if(n <= 1)
        return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

// Dinâmico (Linear)
long long fib_dp(int n){
    if(n <= 1)
        return n;

    long long dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main(){
    int n = 40;

    // Recursivo
    chamadas = 0;
    clock_t inicio1 = clock();
    long long r1 = fib_rec(n);
    clock_t fim1 = clock();

    double tempo1 = (double)(fim1 - inicio1)/CLOCKS_PER_SEC;

    // Dinâmico
    clock_t inicio2 = clock();
    long long r2 = fib_dp(n);
    clock_t fim2 = clock();

    double tempo2 = (double)(fim2 - inicio2)/CLOCKS_PER_SEC;

    printf("n = %d\n", n);
    printf("Recursivo -> Resultado: %lld | Chamadas: %lld | Tempo: %.6f s\n", r1, chamadas, tempo1);
    printf("Dinamico  -> Resultado: %lld | Tempo: %.6f s\n", r2, tempo2);

    return 0;
}