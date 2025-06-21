#include "livro.h"
#include "uteis.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char caminho_livro[MAX_STRING];
    strcpy(caminho_livro, argv[argc-1]);
    strcat(caminho_livro, "livros.txt");
    FILE *fLivro = fopen(caminho_livro, "r");

    Livro *livros[15];
    char primeira_linha[MAX_STRING];
    fscanf(fLivro, "%[^\n]\n", primeira_linha);
    int foi_lido;
    int i=0;
    do
    {
        livros[i] = leLivro(fLivro, &foi_lido);
        i++;
    } while (foi_lido != EOF);

    int j;
    for (j=0; j < i-1; j++)
    {
        printf("%d;%s;%s;%s;%d\n", getIdLivro(livros[j]), getTituloLivro(livros[j]), getAutorLivro(livros[j]), getGeneroLivro(livros[j]), getAnoPubliLivro(livros[j]));
    }

    for (j=0; j < i; j++)
    {
        liberaLivro(livros[j]);
    }

    fclose(fLivro);
}