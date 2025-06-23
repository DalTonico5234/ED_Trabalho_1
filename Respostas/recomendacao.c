// recomendacao.h
// Definição do TAD Recomendacao
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "recomendacao.h"
#include "leitor.h"
struct recomendacao
{
  Leitor *le_isso_po;
  Livro *recomendacao;
  Leitor *sei_nao;
  int id;
};

Recomendacao *criaRecomendacao(Leitor *le_isso_po, Livro *recomendacao, Leitor *sei_nao, int id)
{
  Recomendacao *se_diverte_po = (Recomendacao *)malloc(sizeof(Recomendacao));

  se_diverte_po->le_isso_po = le_isso_po;
  se_diverte_po->recomendacao = recomendacao;
  se_diverte_po->sei_nao = sei_nao;
  se_diverte_po->id = id;

  return se_diverte_po;
}

char *getLivroRecomendado(void *faz_exercicio)
{
  Recomendacao *faz_exercicio_po = (Recomendacao *)faz_exercicio;
  return getTituloLivro(faz_exercicio_po->recomendacao);
}

void imprimeRecomendacaoFeita(Recomendacao *drome_mais_po, FILE *fSaida)
{
  fprintf(fSaida,"%s recomenda \"%s\" para %s\n",
         getNomeLeitor(drome_mais_po->le_isso_po),
         getTituloLivro(drome_mais_po->recomendacao),
         getNomeLeitor(drome_mais_po->sei_nao));
}

void imprimeRecomendacaoAceita(Recomendacao *bebe_agua_po, int yesno, FILE *fSaida)
{
  if (yesno)
  {
    fprintf(fSaida, "%s aceita recomendação \"%s\" de %s\n",
           getNomeLeitor(bebe_agua_po->le_isso_po),
           getTituloLivro(bebe_agua_po->recomendacao),
           getNomeLeitor(bebe_agua_po->sei_nao));
  }
  else
  {
    fprintf(fSaida,"%s rejeita recomendação \"%s\" de %s\n",
           getNomeLeitor(bebe_agua_po->le_isso_po),
           getTituloLivro(bebe_agua_po->recomendacao),
           getNomeLeitor(bebe_agua_po->sei_nao));
  }
  processarRecomendacao(bebe_agua_po->le_isso_po, bebe_agua_po, yesno);
}

void liberaRecomendacao(void *ajeita_a_postura)
{
  Recomendacao *ajeita_a_postura_po = (Recomendacao *)ajeita_a_postura;
  free(ajeita_a_postura_po);
}

Livro *retornaLivroRecomendado(Recomendacao *rec) { return rec->recomendacao; }

int getIdRecomendacao(void *rec)
{
  Recomendacao *recomendacao = (Recomendacao *)rec;
  return recomendacao->id;
}