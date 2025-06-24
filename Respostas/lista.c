// lista.c
// Implementação do TAD lista
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "lista.h"

typedef struct celula Celula;

struct celula {
  Celula *prox;
  Celula *ant;
  void *dado;
  int tipo;
};

struct lista {
  Celula *prim;
  Celula *ult;
};

Lista *criaLista() {
  Lista *list = (Lista *)malloc(sizeof(Lista));

  list->prim = NULL;
  list->ult = NULL;

  return list;
}

void insereNaLista(Lista *list, void *dado, int tipo) // no final
{
  if (!list) {
    printf("ERRO em ponteiro de lista\n");
    return;
  }
  if (!dado) {
    printf("ERRO em ponteiro de dado a ser inserido\n");
    return;
  }
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->dado = dado;
  nova->tipo = tipo;

  if (!list->ult) {
    list->prim = list->ult = nova;
  } else {
    list->ult->prox = nova;
    nova->ant = list->ult;
    list->ult = nova;
  }
  nova->prox = NULL;
}

static Celula *buscaNaLista(Lista *list, int id, fGetIdDado getId) {
  Celula *procura_se;
  for (procura_se = list->prim; procura_se != NULL;
       procura_se = procura_se->prox) {
    if (getId(procura_se->dado) == id) {
      return procura_se;
    }
  }
  return NULL;
}

void *buscaDadoNaLista(Lista *list, int id, fGetIdDado getId) {
  Celula *procura_se = buscaNaLista(list, id, getId);
  if (procura_se == NULL) {
    return NULL;
  }
  return procura_se->dado;
}

void *retiraDaLista(Lista *list, int id, int tipo) {
  // busca da célula de acordo com o tipo
  Celula *procura_se = NULL;
  if (tipo == LIVRO) {
    procura_se = buscaNaLista(list, id, getIdLivro);
  } else if (tipo == LEITOR) {
    procura_se = buscaNaLista(list, id, getIdLeitor);
  } else if (tipo == RECOMENDACAO) {
    procura_se = buscaNaLista(list, id, getIdRecomendacao);
  }

  // caso não tenha sido encontrada
  if (procura_se == NULL) {
    return NULL;
  }

  // caso tenha sido encontrada, retirada do elemento
  if (procura_se == list->prim &&
      procura_se == list->ult) // único elemento da lista
  {
    list->prim = list->ult = NULL;
    void *dado = procura_se->dado;
    free(procura_se);
    if (tipo == RECOMENDACAO) {
      liberaRecomendacao(dado);
      return NULL;
    }
    return dado;
  }
  if (procura_se == list->prim) // primeiro elemento da lista
  {
    list->prim = procura_se->prox;
    list->prim->ant = NULL;
    void *dado = procura_se->dado;
    free(procura_se);
    if (tipo == RECOMENDACAO) {
      liberaRecomendacao(dado);
      return NULL;
    }
    return dado;
  }
  if (procura_se == list->ult) // último elemento da lista
  {
    list->ult = list->ult->ant;
    list->ult->prox = NULL;
    void *dado = procura_se->dado;
    free(procura_se);
    if (tipo == RECOMENDACAO) {
      liberaRecomendacao(dado);
      return NULL;
    }
    return dado;
  } else // caso geral
  {
    procura_se->ant->prox = procura_se->prox;
    procura_se->prox->ant = procura_se->ant;
    void *dado = procura_se->dado;
    free(procura_se);
    if (tipo == RECOMENDACAO) {
      liberaRecomendacao(dado);
      return NULL;
    }
    return dado;
  }
}

void imprimeLista(Lista *list, int tipo, FILE *fSaida) {
  Celula *temp = list->prim;
  if (temp == NULL && tipo != LEITOR) {
    fprintf(fSaida, "\n");
  }
  while (temp != NULL) {
    if (tipo == LIVRO) {
      fprintf(fSaida, " %s", getTituloLivro(temp->dado));
      if (temp != list->ult) {
        fprintf(fSaida, ",");
      } else {
        fprintf(fSaida, "\n");
      }
    } else if (tipo == AFINIDADES) {
      fprintf(fSaida, " %s", getNomeLeitor(temp->dado));
      if (temp != list->ult) {
        fprintf(fSaida, ",");
      } else {
        fprintf(fSaida, "\n");
      }
    } else if (tipo == LEITOR) {
      imprimeLeitor(temp->dado, fSaida);
    } else if (tipo == RECOMENDACAO) {
      fprintf(fSaida, " %s", getLivroRecomendado(temp->dado));
      if (temp != list->ult) {
        fprintf(fSaida, ",");
      } else {
        fprintf(fSaida, "\n");
      }
    }
    temp = temp->prox;
  }
}
void liberaLista(Lista *list, int tipo) {
  Celula *temp = list->prim;
  Celula *prox;
  while (temp != NULL) {
    prox = temp->prox;
    if (temp->dado != NULL && tipo == 1) {
      if (temp->tipo == LIVRO) {
        liberaLivro(temp->dado);
      } else if (temp->tipo == LEITOR) {
        liberaLeitor(temp->dado);
      } else if (temp->tipo == RECOMENDACAO) {
        liberaRecomendacao(temp->dado);
      }
    }
    free(temp);
    temp = prox;
  }
  list->prim = NULL;
  list->ult = NULL;
  free(list);
}

void comparaDadosLista(Lista *list1, Lista *list2, FILE *fSaida) {
  Celula *temp1 = list1->prim;
  Celula *temp2;
  int qtd = 0;
  while (temp1 != NULL) {
    temp2 = list2->prim;
    while (temp2 != NULL) {
      if (getIdLivro(temp1->dado) == getIdLivro(temp2->dado)) {
        if (qtd > 0) {
          fprintf(fSaida, ",");
        }
        fprintf(fSaida, " %s", getTituloLivro(temp2->dado));
        qtd++;
      }
      temp2 = temp2->prox;
    }

    temp1 = temp1->prox;
  }
  if (qtd == 0) {
    fprintf(fSaida, " Nenhum livro em comum");
  }
  fprintf(fSaida, "\n");
}

void preencheAfinidadesDiretas(Lista *leitores) {
  Celula *temp1 = leitores->prim;
  Celula *temp2;
  while (temp1 != NULL) {
    temp2 = leitores->prim;
    while (temp2 != NULL) {
      if (temp1 != temp2) {
        preencheAfinidadeDireta(temp1->dado, temp2->dado);
      }
      temp2 = temp2->prox;
    }
    temp1 = temp1->prox;
  }
}

int procuraAfinidade(Lista *afinidades, Leitor *des, Lista *visitados) {
  Celula *temp;
  for (temp = afinidades->prim; temp != NULL; temp = temp->prox) {
    if (!buscaNaLista(visitados, getIdLeitor(temp->dado), getIdLeitor)) {
      if (getIdLeitor(temp->dado) == getIdLeitor(des)) {
        return 1;
      } else {
        if (verificaAfinidade(temp->dado, des, visitados)) {
          return 1;
        }
      }
    }
  }
  return 0;
}
