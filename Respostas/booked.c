// booked.c
// Implementação do TAD bookED
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "booked.h"

struct booked
{
    Lista *leitores;
    Lista *livros;
    FILE *fLeitores;
    FILE *fLivros;
    FILE *fComandos;
    FILE *fSaida;
};

bookED *criabookED(char *caminho_comum)
{
    bookED *library = (bookED *)malloc(sizeof(bookED));

    library->leitores = criaLista();
    library->livros = criaLista();

    char caminho_livros[MAX_STRING], caminho_leitores[MAX_STRING], caminho_comandos[MAX_STRING], caminho_saida[MAX_STRING];
    strcpy(caminho_livros, caminho_comum);
    strcpy(caminho_leitores, caminho_comum);
    strcpy(caminho_comandos, caminho_comum);
    strcpy(caminho_saida, caminho_comum);
    strcat(caminho_livros, "livros.txt");
    strcat(caminho_leitores, "leitores.txt");
    strcat(caminho_comandos, "comandos.txt");
    strcat(caminho_saida, "saida.txt");

    library->fLivros = fopen(caminho_livros, "r");
    library->fLeitores = fopen(caminho_leitores, "r");
    library->fComandos = fopen(caminho_comandos, "r");
    library->fSaida = fopen(caminho_saida, "r");

    int foi_lido = 0;
    Livro *registrado;
    char primeira_linha[MAX_STRING];
    fscanf(library->fLivros, "%[^\n]\n", primeira_linha);
    do {
        registrado = leLivro(library->fLivros, &foi_lido);
        insereNaLista(library->livros, registrado, LIVRO);
    } while (foi_lido != EOF);

    fclose(library->fLivros);
    fclose(library->fLeitores);

    return library;
}

void executabookED(bookED *alexandria)
{
    printf("Criou com sucesso: olha:\n");
    imprimebookED(alexandria);
}

void imprimebookED(bookED *cairo)
{
    imprimeLista(cairo->livros, LIVRO);
}

void liberabookED(bookED *leitura)
{
    liberaLista(leitura->livros, LIVRO);
    liberaLista(leitura->leitores, LEITOR);

    fclose(leitura->fComandos);
    fclose(leitura->fSaida);

    free(leitura);
}
