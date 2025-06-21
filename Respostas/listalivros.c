
#include "listalivros.h"

typedef struct Celula Celula;

struct Celula
{
    Celula *prox;
    Livro *liv;
};

struct Lista
{
    Celula *prim;
    Celula *ult;
};

Lista *criaLista()
{
    Lista *lis = (Lista *)malloc(sizeof(Lista));
    lis->prim = lis->ult = NULL;
    return lis;
}

void insereNaLista(Lista *lis, Livro *liv)
{
    if (!lis|| !liv)
    {
        printf("ERRO em ponteiro de lista ou livro\n");
        return;
    }
    
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->liv = liv;
    
    if (!lis->ult)
    {
        lis->prim = lis->ult = nova;
    }
    else
    {
        lis->ult->prox = nova;
        lis->ult = nova;
    }
    nova->prox = NULL;
}

void retiraDaLista(Lista *lis, int id)
{
    Celula *ant;
    Celula *temp = lis->prim;
    while (!temp && id != getIdLivro(temp->liv))
    {
        ant = temp;
        temp = temp->prox;
    }
    if (temp == NULL)
    {
        return;
    }
    if (temp == lis->prim && temp == lis->ult)
    {
        lis->prim = lis->ult = NULL;
        free(temp);
        return;
    }
    if (temp == lis->prim)
    {
        lis->prim = temp->prox;
        free(temp);
        return;
    }
    if (temp == lis->ult)
    {
        ant->prox = NULL;
        lis->ult = ant;
        free(temp);
        return;
    }
    else
    {
        ant->prox = temp->prox;
        free(temp);
    }
}

void desalocaLista(Lista *lis)
{
    Celula *prox;
    Celula *temp = lis->prim;
    while (temp != NULL)
    {
        prox = temp->prox;
        free(temp);
        temp = prox;
    }
    free(lis);
}

void imprimeLista(Lista *lis)
{
    Celula *temp = lis->prim;
    while (temp != NULL)
    {
        printf(" %s", getTituloLivro(temp->liv));
        if (temp != lis->ult)
        {
            printf(",");
        }
        else
        {
            printf("\n");
        }
        temp = temp->prox;
    }
}