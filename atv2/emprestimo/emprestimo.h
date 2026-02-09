#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "usuario.h"
#include "livro.h"

typedef struct {
    Usuario usuario;
    Livro livro;
    char data[11]; 
} Emprestimo;

void registrarEmprestimo(Emprestimo emprestimos[], int *total,
     Usuario usuarios[], int totalUsuarios,
  Livro livros[], int totalLivros);

void listarEmprestimosUsuario(Emprestimo emprestimos[], int total, int idUsuario);

#endif
