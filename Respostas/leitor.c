// leitor.c
// Implmentação do TAD Leitor
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "leitor.h"
#include "recomendacao.h"
struct Leitor
{
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
                   int npref)
{
  Leitor *lei = (Leitor *)malloc(sizeof(Leitor));
  lei->id = id;
  lei->nome = strdup(nome);
  lei->preferencias = (char **)malloc(npref * sizeof(char *));
  lei->npref = npref;
  for (int i = 0; i < lei->npref; i++)
  {
    lei->preferencias[i] = strdup(preferencias[i]);
  }
  lei->desejados = criaLista();
  lei->recomendacoes = criaLista();
  lei->lidos = criaLista();
  lei->afinidades = criaLista();
  return lei;
}

Leitor *leLeitor(FILE *fLeitor, int *foi_lido)
{
  int id = 0;
  int npref = 1;
  char nome[MAX_STRING] = "a";
  *foi_lido = fscanf(fLeitor, "%d;%[^;];%d;", &id, nome, &npref);
  if (*foi_lido == EOF)
  {
    return NULL;
  }
  if (*foi_lido == 0)
  {
    printf("ERRO ao ler arquivo de leitores\n");
  }
  char preferencias[npref][MAX_STRING];
  for (int i = 0; i < npref; i++)
  {
    preferencias[i][1] = '\0';
  }
  for (int i = 0; i < npref; i++)
  {
    if (i != (npref - 1))
    {
      *foi_lido = fscanf(fLeitor, "%200[^;];", preferencias[i]);
    }
    else
    {
      *foi_lido = fscanf(fLeitor, "%200[^\n]\n", preferencias[i]);
    }
    if (*foi_lido == EOF)
    {
      return NULL;
    }
  }
  // papando os espaços: funciona :)))
  for (int i = 0; i < npref; i++)
  {
    for (int caracter = 0; caracter < (int)strlen(preferencias[i]);
         caracter++)
    {
      if (preferencias[i][caracter] == ' ')
      {
        for (int caracter2 = caracter; caracter2 < (int)strlen(preferencias[i]);
             caracter2++)
        {
          preferencias[i][caracter2] = preferencias[i][caracter2 + 1];
        }
      }
    }
  }

  Leitor *lelei = criaLeitor(id, nome, preferencias, npref);

  return lelei;
}

int getIdLeitor(void *lei)
{
  if (!lei)
  {
    printf("ERRO em ponteiro de leitor\n");
    return -1;
  }
  Leitor *reader = (Leitor *)lei;
  return reader->id;
}

char *getNomeLeitor(void *lei)
{
  if (!lei)
  {
    printf("ERRO em ponteiro de leitor\n");
    return NULL;
  }

  Leitor *le = (Leitor *)lei;
  return le->nome;
}

Recomendacao *getRecomendacaoId(Leitor *lei, int id)
{
  Recomendacao *recomendacao = (Recomendacao *)buscaDadoNaLista(
      lei->recomendacoes, id, getIdRecomendacao);

  return recomendacao;
}

Livro *getLivroLidoId(Leitor *lei, int id)
{
  Livro *livro = (Livro *)buscaDadoNaLista(lei->lidos, id, getIdLivro);

  return livro;
}

Livro *getLivroDesejadoId(Leitor *lei, int id)
{
  Livro *livro = (Livro *)buscaDadoNaLista(lei->desejados, id, getIdLivro);

  return livro;
}

char *getPreferenciaLeitor(Leitor *lei, int id)
{
  return lei->preferencias[id];
}

void comparaLeitores(Leitor *lei1, Leitor *lei2, FILE *fSaida)
{
  comparaDadosLista(lei1->lidos, lei2->lidos, fSaida);
}

void imprimeLeitor(void *leis, FILE *fSaida)
{
  if (!leis)
  {
    printf("ERRO em ponteiro de leitor\n");
    return;
  }
  Leitor *lei = (Leitor *)leis;

  fprintf(fSaida, "Leitor: %s\n", lei->nome);
  fprintf(fSaida, "Lidos:");
  imprimeLista(lei->lidos, LIVRO, fSaida);
  fprintf(fSaida, "Desejados:");
  if (ehListaVazia(lei->desejados))
  {
    fprintf(fSaida, " ");
  }
  imprimeLista(lei->desejados, LIVRO, fSaida);
  fprintf(fSaida, "Recomendacoes:");
  if (ehListaVazia(lei->recomendacoes))
  {
    fprintf(fSaida, " ");
  }
  imprimeLista(lei->recomendacoes, RECOMENDACAO, fSaida);
  fprintf(fSaida, "Afinidades:");
  if (ehListaVazia(lei->afinidades))
  {
    fprintf(fSaida, " ");
  }
  imprimeLista(lei->afinidades, AFINIDADES, fSaida);
  fprintf(fSaida, "\n");
}

void adicionarLidos(Leitor *lei, Livro *liv)
{
  insereNaLista(lei->lidos, liv, LIVRO);
  if (buscaDadoNaLista(lei->desejados, getIdLivro(liv), getIdLivro))
  {
    retiraDaLista(lei->desejados, getIdLivro(liv), LIVRO);
  }
}

void adicionarDesejos(Leitor *lei, Livro *liv)
{
  insereNaLista(lei->desejados, liv, LIVRO);
}

void recomendarLivro(Leitor *lei, Recomendacao *Rec)
{
  insereNaLista(lei->recomendacoes, Rec, RECOMENDACAO);
}

void removerRecomendacao(Leitor *lei, Recomendacao *Rec)
{
  retiraDaLista(lei->recomendacoes, getIdRecomendacao(Rec), RECOMENDACAO);
}

void processarRecomendacao(Leitor *lei, Recomendacao *Rec, int yesno)
{
  if (yesno == 1)
  {
    adicionarDesejos(lei, retornaLivroRecomendado(Rec));
  }
  removerRecomendacao(lei, Rec);
}

void adicionarAfinidade(Leitor *destino, Leitor *afinidade)
{
  insereNaLista(destino->afinidades, afinidade, LEITOR);
}

void preencheAfinidadeDireta(void *leiDes, void *leiOri)
{
  Leitor *lei1 = (Leitor *)leiDes;
  Leitor *lei2 = (Leitor *)leiOri;

  for (int i = 0; i < lei1->npref; i++)
  {
    for (int j = 0; j < lei2->npref; j++)
    {
      if (strcmp(lei1->preferencias[i], lei2->preferencias[j]) == 0)
      {
        adicionarAfinidade(lei1, lei2);
        return;
      }
    }
  }
}

int verificaAfinidade(Leitor *lei1, Leitor *lei2, void *visitado)
{
  Lista *visitados = (Lista *)visitado;
  insereNaLista(visitados, lei1, LEITOR);
  return procuraAfinidade(lei1->afinidades, lei2, visitados);
}

void liberaLeitor(void *le)
{
  Leitor *lei = (Leitor *)le;
  free(lei->nome);
  for (int i = 0; i < lei->npref; i++)
  {
    free(lei->preferencias[i]);
  }
  free(lei->preferencias);
  liberaLista(lei->lidos, 0);
  liberaLista(lei->recomendacoes, 1);
  liberaLista(lei->desejados, 0);
  liberaLista(lei->afinidades, 0);
  free(lei);
}