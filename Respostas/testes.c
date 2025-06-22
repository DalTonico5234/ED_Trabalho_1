// testes.c
// Código para testes gerais da funcionalidades do trabalho
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté Carvalho Trento
// Parte do trabalho 1 da disciplina Estutura de Dados, lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "livro.h"
#include "leitor.h"
#include "lista.h"
#include "uteis.h"

int main(int argc, char *argv[])
{
    char caminho_Leitor[MAX_STRING];
    strcpy(caminho_Leitor, argv[argc-1]);
    strcat(caminho_Leitor, "leitores.txt");
    FILE *fLeitor = fopen(caminho_Leitor, "r");

    Leitor *Leitors[3];
    char primeira_linha[MAX_STRING];
    fscanf(fLeitor, "%[^\n]\n", primeira_linha);
    int foi_lido;
    int i=0;
    do
    {
        Leitors[i] = leLeitor(fLeitor, &foi_lido);
        i++;
    } while (foi_lido != EOF);

    int j;
    for (j=0; j < i-1; j++)
    {
        imprimeLeitor(Leitors[i]);
    }

    for (j=0; j < i; j++)
    {
        liberaLeitor(Leitors[j]);
    }

    fclose(fLeitor);
}