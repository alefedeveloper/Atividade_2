#include <stdio.h>
#include "emprestimo.h"

void registrarEmprestimo(Emprestimo emprestimos[], int *total,
                          Usuario usuarios[], int totalUsuarios,
                          Livro livros[], int totalLivros) {

    int id, codigo, i;

    printf("\nID do usuário: ");
    scanf("%d", &id);

    printf("Código do livro: ");
    scanf("%d", &codigo);

    for (i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == id) {
            emprestimos[*total].usuario = usuarios[i];
            break;
        }
    }

    for (i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigo) {
            emprestimos[*total].livro = livros[i];
            break;
        }
    }

    printf("Data do empréstimo (dd/mm/aaaa): ");
    scanf("%s", emprestimos[*total].data);

    (*total)++;
    printf("Empréstimo registrado com sucesso!\n");
}

void listarEmprestimosUsuario(Emprestimo emprestimos[], int total, int idUsuario) {
    int i;
    printf("\nLivros emprestados:\n");

    for (i = 0; i < total; i++) {
        if (emprestimos[i].usuario.id == idUsuario) {
            printf("Livro: %s | Autor: %s | Data: %s\n",
                   emprestimos[i].livro.titulo,
                   emprestimos[i].livro.autor,
                   emprestimos[i].data);
        }
    }
}
