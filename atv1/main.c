#include <stdio.h>
#include "aluno.h"
#include "turma.h"

#define MAX_TURMAS 10

void cadastrarTurma(Turma turmas[], int *total) {
    printf("\nCódigo da turma: ");
    scanf("%d", &turmas[*total].codigo);

    printf("Nome da turma: ");
    scanf(" %[^\n]", turmas[*total].nome);

    turmas[*total].qtdAlunos = 0;
    (*total)++;

    printf("Turma cadastrada com sucesso!\n");
}

void cadastrarAluno(Turma turmas[], int totalTurmas) {
    int codigo, i;
    Aluno a;

    printf("\nCódigo da turma: ");
    scanf("%d", &codigo);

    for (i = 0; i < totalTurmas; i++) {
        if (turmas[i].codigo == codigo) {

            if (turmas[i].qtdAlunos >= MAX_ALUNOS) {
                printf("Turma cheia!\n");
                return;
            }

            printf("ID do aluno: ");
            scanf("%d", &a.id);

            printf("Nome do aluno: ");
            scanf(" %[^\n]", a.nome);

            printf("Nota do aluno: ");
            scanf("%f", &a.nota);

            turmas[i].alunos[turmas[i].qtdAlunos] = a;
            turmas[i].qtdAlunos++;

            printf("Aluno cadastrado na turma com sucesso!\n");
            return;
        }
    }

    printf("Turma não encontrada!\n");
}

void listarAlunos(Turma turmas[], int totalTurmas) {
    int codigo, i, j;

    printf("\nCódigo da turma: ");
    scanf("%d", &codigo);

    for (i = 0; i < totalTurmas; i++) {
        if (turmas[i].codigo == codigo) {

            printf("\nAlunos da turma %s:\n", turmas[i].nome);

            for (j = 0; j < turmas[i].qtdAlunos; j++) {
                printf("ID: %d | Nome: %s | Nota: %.2f\n",
                       turmas[i].alunos[j].id,
                       turmas[i].alunos[j].nome,
                       turmas[i].alunos[j].nota);
            }
            return;
        }
    }

    printf("Turma não encontrada!\n");
}

int main() {
    Turma turmas[MAX_TURMAS];
    int totalTurmas = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE GERENCIAMENTO ESCOLAR ===\n");
        printf("1 - Cadastrar Turma\n");
        printf("2 - Cadastrar Aluno em Turma\n");
        printf("3 - Listar Alunos de uma Turma\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTurma(turmas, &totalTurmas);
                break;

            case 2:
                cadastrarAluno(turmas, totalTurmas);
                break;

            case 3:
                listarAlunos(turmas, totalTurmas);
                break;
        }

    } while (opcao != 0);

    return 0;
}
