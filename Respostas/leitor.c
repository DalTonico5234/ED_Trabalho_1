// leitor.c
// Implmentação do TAD Leitor
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "leitor.h"

struct Leitor {
  char *nome;
  int id;
  int npref;
  char **preferencias;
  Lista *lidos;
  Lista *desejados;
  Lista *recomendacoes;
  Lista *afinidades;
};

Leitor *criaLeitor(int id, char *nome, char preferencias[][MAX_STRING],
                   int npref) {
  Leitor *lei = (Leitor *)malloc(sizeof(Leitor));
  lei->id = id;
  lei->nome = strdup(nome);
  lei->preferencias = (char **)malloc(npref * sizeof(char *));
  lei->npref = npref;
  for (int i = 0; i < lei->npref; i++) {
    lei->preferencias[i] = strdup(preferencias[i]);
  }
  lei->desejados = criaLista();
  lei->recomendacoes = criaLista();
  lei->lidos = criaLista();
  lei->afinidades = criaLista();
  return lei;
}

Leitor *leLeitor(FILE *fLeitor, int *foi_lido) {
  int id = 0;
  int npref = 1;
  char nome[MAX_STRING] = "a";
  *foi_lido = fscanf(fLeitor, "%d;%[^;];%d;", &id, nome, &npref);
  if (*foi_lido == 0) {
    printf("ERRO ao ler arquivo de leitores\n");
  }
  printf("id lido: %d; nome lido: %s; npref lido: %d;\n", id, nome, npref);
  char preferencias[npref][MAX_STRING];
  for (int i = 0; i < npref; i++) {
    preferencias[i][1] = '\0';
  }
  for (int i = 0; i < npref; i++) {
    if (i != (npref - 1)) {
      *foi_lido = fscanf(fLeitor, "%200[^;];", preferencias[i]);
      printf("preferencia lida: %s\n", preferencias[i]);
    } else {
      *foi_lido = fscanf(fLeitor, "%200[^\n]\n", preferencias[i]);
      printf("preferencia lida: %s\n", preferencias[i]);
    }
  }

  Leitor *lelei = criaLeitor(id, nome, preferencias, npref);

  return lelei;
}

int getIdLeitor(void *lei) {
  if (!lei) {
    printf("ERRO em ponteiro de leitor\n");
    return -1;
  }
  Leitor *reader = (Leitor *)lei;
  return reader->id;
}

char *getNomeLeitor(void *lei) {
  if (!lei) {
    printf("ERRO em ponteiro de leitor\n");
    return NULL;
  }

  Leitor *le = (Leitor *)lei;
  return le->nome;
}

void imprimeLeitor(void *leis) {
  if (!leis) {
    printf("ERRO em ponteiro de leitor\n");
    return;
  }
  Leitor *lei = (Leitor *)leis;

  printf("Leitor: %s\n", lei->nome);
  printf("Lidos:");
  imprimeLista(lei->lidos, LIVRO);
  printf("Desejados:");
  imprimeLista(lei->desejados, LIVRO);
  printf("Recomendacoes:");
  imprimeLista(lei->recomendacoes, LIVRO);
  printf("Afinidades:\n");
  imprimeLista(lei->afinidades, AFINIDADES);
}

void adicionarLidos(Leitor *lei, Livro *liv) {
  insereNaLista(lei->lidos, liv, LIVRO);
}

void adicionarDesejos(Leitor *lei, Livro *liv) {
  insereNaLista(lei->desejados, liv, LIVRO);
}

// LEMBRETE: AJUSTAR APÓS TAD RECOMENDACOES
void recomendarLivro(Leitor *lei, Livro *liv) {
  insereNaLista(lei->recomendacoes, liv, LIVRO);
}

// LEMBRETE: AJUSTAR APÓS TAD RECOMENDACOES
void removerRecomendacao(Leitor *lei, Recomendacao *Rec) {
  retiraDaLista(lei->recomendacoes, getIdLivro(retornaLivroRecomendado(Rec)),
                LIVRO);
}

// LEMBRETE: AJUSTAR APÓS TAD RECOMENDACOES
void processarRecomendacao(Leitor *lei, Recomendacao *Rec, int yesno) {
  if (yesno == 1) {
    adicionarDesejos(lei, retornaLivroRecomendado(Rec));
  }
  removerRecomendacao(lei, Rec);
}

void adicionarAfinidade(Leitor *destino, Leitor *afinidade) {
  insereNaLista(destino->afinidades, afinidade, LEITOR);
}

void liberaLeitor(Leitor *lei) {
  free(lei->nome);
  for (int i = 0; i < lei->npref; i++) {
    free(lei->preferencias[i]);
  }
  free(lei->preferencias);
  liberaLista(lei->lidos);
  liberaLista(lei->recomendacoes);
  liberaLista(lei->desejados);
  free(lei);
}