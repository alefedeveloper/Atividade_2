#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int id;
    char nome[50];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *total);

#endif
