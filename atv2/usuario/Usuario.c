#include <stdio.h>
#include "usuario.h"

void cadastrarUsuario(Usuario usuarios[], int *total) {
    printf("\nID do usuário: ");
    scanf("%d", &usuarios[*total].id);

    printf("Nome: ");
    scanf(" %[^\n]", usuarios[*total].nome);

    (*total)++;
    printf("Usuário cadastrado com sucesso!\n");
}
