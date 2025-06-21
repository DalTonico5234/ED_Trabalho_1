
#ifndef _LISTALIVROS_H
#define _LISTALIVROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

typedef struct Lista Lista;

Lista* criaLista();

void insereNaLista(Lista *lis, Livro *liv);

void retiraDaLista(Lista *lis, char *nome);

void desalocaLista(Lista *lis);

void imprimeLista(Lista *lis);

#endif