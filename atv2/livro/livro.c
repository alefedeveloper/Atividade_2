#include <stdio.h>
#include "livro.h"

void cadastrarLivro(Livro livros[], int *total) {
    printf("\nCódigo do livro: ");
    scanf("%d", &livros[*total].codigo);

    printf("Título: ");
    scanf(" %[^\n]", livros[*total].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livros[*total].autor);

    (*total)++;
    printf("Livro cadastrado com sucesso!\n");
}
