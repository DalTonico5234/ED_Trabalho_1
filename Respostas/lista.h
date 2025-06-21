
#ifndef lista_h
#define lista_h

#include "lista.h"
#include "livro.h"
#include "leitor.h"
#include "uteis.h"

typedef struct lista Lista;
Lista *criaLista();
void insereNaLista(Lista *list, void *dado, int tipo);
void *retiraDaLista(Lista *list, int id, int tipo);
void imprimeLista(Lista *list, int tipo);
void liberaLista(Lista *list);
#endif