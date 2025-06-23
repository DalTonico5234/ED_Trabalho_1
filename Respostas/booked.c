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

    FILE *fLivros = fopen(caminho_livros, "r");
    FILE *fLeitores = fopen(caminho_leitores, "r");
    library->fComandos = fopen(caminho_comandos, "r");
    library->fSaida = fopen(caminho_saida, "w");

    int foi_lido = 0;
    Livro *registrado;
    char primeira_linha[MAX_STRING];
    fscanf(fLivros, "%[^\n]\n", primeira_linha);
    do
    {
        registrado = leLivro(fLivros, &foi_lido);
        if (foi_lido == EOF)
        {
            liberaLivro(registrado);
        }
        else
        {
            insereNaLista(library->livros, registrado, LIVRO);
        }
    } while (foi_lido != EOF);

    fclose(fLivros);
    fclose(fLeitores);

    return library;
}

void executabookED(bookED *alexandria)
{
    fprintf(alexandria->fSaida, "Criou com sucesso: olha:\n");
    imprimebookED(alexandria);
}

void imprimebookED(bookED *cairo)
{
    imprimeLista(cairo->livros, LIVRO, cairo->fSaida);
}

void liberabookED(bookED *leitura)
{
    liberaLista(leitura->livros, 1);
    liberaLista(leitura->leitores, 1);

    fclose(leitura->fComandos);
    fclose(leitura->fSaida);

    free(leitura);
}
