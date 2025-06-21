
#include "leitor.h"

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

Leitor *criaLeitor(int id, char *nome, char preferencias[][200], int npref)
{
    Leitor *lei = (Leitor *)malloc(sizeof(Leitor));
    lei->id = id;
    lei->nome = strdup(nome);
    lei->preferencias = (char **)malloc(npref * sizeof(char *));
    lei->npref = npref;
    for (int i = 0; i < npref; i++)
    {
        lei->preferencias[i] = strdup(preferencias[i]);
    }
    lei->desejados = criaLista();
    lei->recomendacoes = criaLista();
    lei->lidos = criaLista();
    lei->afinidades = criaLista();
    return lei;
}

int getIdLeitor(void *lei)
{
    if (!lei)
    {
        printf("ERRO em ponteiro de leitor\n");
        return -1;
    }
    
    Leitor *reader = (Leitor *) lei;
    return reader->id;
}

void imprimeLeitor(void *leis)
{
Leitor *lei = (Leitor*) leis;
    printf("Leitor: %s\n", lei->nome);
    printf("Lidos:");
    imprimeLista(lei->lidos,LIVRO);
    printf("Desejados:");
    imprimeLista(lei->desejados,LIVRO);
    printf("Recomendacoes:");
    imprimeLista(lei->recomendacoes,LIVRO);
    printf("Afinidades:\n");
    imprimeLista(lei->afinidades,AFINIDADES);
}

void adicionarLidos(Leitor *lei, Livro *liv)
{
    insereNaLista(lei->lidos, liv, LIVRO);
}

void adicionarDesejos(Leitor *lei, Livro *liv)
{
    insereNaLista(lei->desejados, liv, LIVRO);
}

void recomendarLivro(Leitor *lei, Livro *liv)
{
    insereNaLista(lei->recomendacoes, liv, LIVRO);
}

void removerRecomendacao(Leitor *lei, Livro *liv)
{
    retiraDaLista(lei->recomendacoes, getIdLivro(liv), LIVRO);
}

void processarRecomendacao(Leitor *lei, Livro *liv, int yesno)
{
    if (yesno == 1)
    {
        adicionarDesejos(lei, liv);
    }
    removerRecomendacao(lei, liv);
}

void desalocaLeitor(Leitor *lei)
{
    free(lei->nome);
    for (int i = 0; i < lei->npref; i++)
    {
        free(lei->preferencias[i]);
    }
    free(lei->preferencias);
    liberaLista(lei->lidos);
    liberaLista(lei->recomendacoes);
    liberaLista(lei->desejados);
    free(lei);
}

char* getNomeLeitor(void *lei){
    Leitor *le = (Leitor*) lei;
    return le->nome;
}

void adicionarAfinidade(Leitor *destino, Leitor *afinidade){
    insereNaLista(destino->afinidades, afinidade, LEITOR);
}

Leitor *leLeitor(FILE *fLeitor, int *foi_lido){
    int id;
    int npref;
    char nome[MAX_STRING] = "a";
int *foi_lido2;
    *foi_lido = fscanf(fLeitor, "%d;%[^;];%d;", &id, nome, &npref);
     char preferencias[npref][MAX_STRING];
for(int i=0;i<npref;i++){
  *foi_lido2 = fscanf(fLeitor, "%200[^;\n]",preferencias[i]);
}
    Leitor *lelei = criaLeitor(id, nome, preferencias, npref);

    return lelei;
}

