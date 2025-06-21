#ifndef _LEITOR_H
#define _LEITOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listalivros.h"
#include "livro.h"
typedef struct Leitor Leitor;
Leitor *criaLeitor(int id, char* nome, char** preferencias);
void imprimeLeitor(Leitor *lei);
void adicionarLidos(Leitor *lei, Livro *liv);
void adicionarDesejos(Leitor *lei, Livro *liv);
void recomendarLivro(Leitor *lei, Livro *liv);
void processarRecomendacao(Leitor *lei, Livro *liv, int yesno);
void removerRecomendacao(Leitor *lei, Livro *liv);
#endif