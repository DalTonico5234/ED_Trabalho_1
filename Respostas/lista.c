// lista.c
// Implementação do TAD lista
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté Carvalho Trento
// Parte do trabalho 1 da disciplina Estutura de Dados, lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "lista.h"

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

void insereNaLista(Lista *list, void *dado, int tipo) //no final
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
    Celula *nova = (Celula *)malloc(sizeof(Celula));
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
    Celula *procura_se;
    for (procura_se = list->prim; procura_se != NULL; procura_se = procura_se->prox)
    {
        if (getId(procura_se->dado) == id)
        {
            return procura_se;
        }
    }
    return NULL;
}

void *retiraDaLista(Lista *list, int id, int tipo)
{
    // busca da célula de acordo com o tipo
    Celula *procura_se = NULL;
    if (tipo == LIVRO)
    {
        procura_se = buscaNaLista(list, id, getIdLivro);
    }
    else if (tipo == LEITOR)
    {
        procura_se = buscaNaLista(list, id, getIdLeitor);
    }
    
    //caso não tenha sido encontrada
    if (procura_se == NULL)
    {
        return NULL;
    }
    
    //caso tenha sido encontrada, retirada do elemento
    if (procura_se == list->prim && procura_se == list->ult) //único elemento da lista
    {
        list->prim = list->ult = NULL;
        void *dado = procura_se->dado;
        free(procura_se);
        return dado;
    }
    if (procura_se == list->prim) //primeiro elemento da lista
    {
        list->prim = procura_se->prox;
        list->prim->ant = NULL;
        void *dado = procura_se->dado;
        free(procura_se);
        return dado;
    }
    if (procura_se == list->ult) //último elemento da lista
    {
        list->ult = list->ult->ant;
        list->ult->prox = NULL;
        void *dado = procura_se->dado;
        free(procura_se);
        return dado;
    }
    else //caso geral
    {
        procura_se->ant->prox = procura_se->prox;
        procura_se->prox->ant = procura_se->ant;
        void *dado = procura_se->dado;
        free(procura_se);
        return dado;
    }
}

void imprimeLista(Lista *list, int tipo)
{
    Celula *temp = list->prim;
    while (temp != NULL)
    {
        if (tipo == LIVRO)
        {
            printf(" %s", getTituloLivro(temp->dado));
            if (temp != list->ult)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }
        else if (tipo == AFINIDADES)
        {
            printf(" %s", getNomeLeitor(temp->dado));
            if (temp != list->ult)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }
        else if (tipo == LEITOR)
        {
            imprimeLeitor(temp->dado);
            printf("\n");
        }
        temp = temp->prox;
    }
}
void liberaLista(Lista *list)
{
    Celula *temp = list->prim;
    Celula *prox;
    while (temp != NULL)
    {
        prox = temp->prox;
        free(temp);
        temp = prox;
    }
    list->prim = NULL;
    list->ult = NULL;
    free(list);
}