#include <stdio.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

int main() {
    Livro livros[50];
    Usuario usuarios[50];
    Emprestimo emprestimos[50];

    int totalLivros = 0, totalUsuarios = 0, totalEmprestimos = 0;
    int opcao, id;

    do {
        printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Cadastrar Usuário\n");
        printf("3 - Registrar Empréstimo\n");
        printf("4 - Listar Empréstimos por Usuário\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, &totalLivros);
                break;

            case 2:
                cadastrarUsuario(usuarios, &totalUsuarios);
                break;

            case 3:
                registrarEmprestimo(emprestimos, &totalEmprestimos,
                                    usuarios, totalUsuarios,
                                    livros, totalLivros);
                break;

            case 4:
                printf("ID do usuário: ");
                scanf("%d", &id);
                listarEmprestimosUsuario(emprestimos, totalEmprestimos, id);
                break;
        }

    } while (opcao != 0);

    return 0;
}
