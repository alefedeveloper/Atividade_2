#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
} Livro;

void cadastrarLivro(Livro livros[], int *total);

#endif

