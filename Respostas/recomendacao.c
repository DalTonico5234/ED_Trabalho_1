// recomendacao.h
// Definição do TAD Recomendacao
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté Carvalho Trento
// Parte do trabalho 1 da disciplina Estutura de Dados, lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "recomendacao.h"

struct recomendacao
{
    Leitor *le_isso_po;
    Livro *recomendacao;
    Leitor *sei_nao;
};

Recomendacao *criaRecomendacao(Leitor *le_isso_po, Livro *recomendacao, Leitor *sei_nao)
{
    Recomendacao *se_diverte_po = (Recomendacao *)malloc(sizeof(Recomendacao));

    se_diverte_po->le_isso_po = le_isso_po;
    se_diverte_po->recomendacao = recomendacao;
    se_diverte_po->sei_nao = sei_nao;

    return se_diverte_po;
}

char *getLivroRecomendado(Recomendacao *faz_exercicio_po)
{
    return getTituloLivro(faz_exercicio_po->recomendacao);
}

void imprimeRecomendacaoFeita(Recomendacao *drome_mais_po)
{
    printf("%s recomenda \"%s\" para %s\n", getNomeLeitor(drome_mais_po->le_isso_po), getTituloLivro(drome_mais_po->recomendacao), getNomeLeitor(drome_mais_po->sei_nao));
}

void imprimeRecomendacaoAceita(Recomendacao *bebe_agua_po, int yesno)
{
    if (yesno)
    {
        printf("%s aceita recomendação \"%s\" de %s\n", getNomeLeitor(bebe_agua_po->le_isso_po), getTituloLivro(bebe_agua_po->recomendacao), getNomeLeitor(bebe_agua_po->sei_nao));
    }
    else
    {
        printf("%s rejeita recomendação \"%s\" de %s\n", getNomeLeitor(bebe_agua_po->le_isso_po), getTituloLivro(bebe_agua_po->recomendacao), getNomeLeitor(bebe_agua_po->sei_nao));
    }
}

void liberaRecomendacao(Recomendacao *ajeita_a_postura_po)
{
    free(ajeita_a_postura_po);
}