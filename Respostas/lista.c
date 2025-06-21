
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct celula Celula;

typedef int (*fGetIdDado)(void *);

struct celula
{
    Celula *prox;
    Celula *ant;
    void *dado;
    int tipo;
};

struct lista
{
    Celula *prim;
    Celula *ult;
};

Lista *criaLista()
{
    Lista *list = (Lista *) malloc (sizeof(Lista));
   
    list->prim = NULL;
    list->ult = NULL;
   
    return list;
}

void insereNaLista(Lista *list, void *dado, int tipo);

static Celula *buscaNaLista(Lista *list, int id, fGetIdDado getId)
{
    Celula *temp;
    for (temp = list->prim; temp != NULL; temp = temp->prox)
    {
        if (getId(temp->dado) == id)
        {
            return temp;
        }
    }
    return NULL;
}

void liberaLista(Lista *list);
