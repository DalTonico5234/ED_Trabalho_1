#include "leitor.h"
struct Leitor{
    char *nome;
    int id;
    int npref;
    char **preferencias;
    Lista *lidos;
    Lista *desejados;
    Lista *recomendacoes;
    void *temporario;
};
Leitor *criaLeitor(int id, char* nome, char** preferencias, int npref){
Leitor *lei = (Leitor*) malloc(sizeof(Leitor));
scanf("%d;",&lei->id);
lei->id=id;
lei->nome=strdup(nome);
lei->preferencias= (char**) malloc(npref*sizeof(char*));
lei->npref=npref;
for(int i=0;i<npref;i++){
lei->preferencias[i]=strdup(preferencias[i]);
}
lei->desejados=criaLista();
lei->recomendacoes=criaLista();
lei->lidos=criaLista();
return lei;
}
void imprimeLeitor(Leitor *lei){
    printf("Leitor: %s\n",lei->nome);
    printf("Lidos:");
    imprimeLista(lei->lidos);
     printf("Desejados:");
    imprimeLista(lei->desejados);
     printf("Recomendacoes:");
    imprimeLista(lei->recomendacoes);
 printf("Afinidades:\n");

}
void adicionarLidos(Leitor *lei, Livro *liv){
    insereNaLista(lei->lidos,liv);
}
void adicionarDesejos(Leitor *lei, Livro *liv){
    insereNaLista(lei->desejados,liv);
}
void recomendarLivro(Leitor *lei, Livro *liv){
    insereNaLista(lei->recomendacoes,liv);
}
void removerRecomendacao(Leitor *lei, Livro *liv){
    retiraDaLista(lei->recomendacoes,getNomeLivro(liv));
}
void processarRecomendacao(Leitor *lei, Livro *liv, int yesno){
    if(yesno==1){
        adicionarDesejos(lei,liv);
    }
     removerRecomendacao(lei,liv);
}
void desalocaLeitor(Leitor *lei){
free(lei->nome);
for(int i=0;i<lei->npref;i++){
free(lei->preferencias[i]);
}
free(lei->preferencias);
desalocaLista(lei->lidos);
desalocaLista(lei->recomendacoes);
desalocaLista(lei->desejados);
free(lei);
}