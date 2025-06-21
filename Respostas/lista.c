
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
    Lista *list = (Lista *)malloc(sizeof(Lista));

    list->prim = NULL;
    list->ult = NULL;

    return list;
}

void insereNaLista(Lista *list, void *dado, int tipo)
{
    if (!list)
    {
        printf("ERRO em ponteiro de lista\n");
        return;
    }
    if (!dado)
    {
        printf("ERRO em ponteiro de dado a ser inserido\n");
        return;
    }
    Celula *nova = (Celula *) malloc (sizeof(Celula));
    nova->dado = dado;
    nova->tipo = tipo;

    if (!list->ult)
    {
        list->prim = list->ult = nova;
    }
    else
    {
        list->ult->prox = nova;
        list->ult = nova;
    }
    nova->prox = NULL;
}

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

void *retiraDaLista(Lista *list, int id, int tipo)
{
    Celula *procura_se;
    if (tipo == LIVRO)
    {
        procura_se = buscaNaLista(list, id, getIdLivro);
    }
    else if (tipo == LEITOR)
    {
        procura_se = buscaNaLista(list, id, getIdLeitor);
    }

    return NULL;
}

void liberaLista(Lista *list);
