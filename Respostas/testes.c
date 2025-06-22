// testes.c
// Código para testes gerais da funcionalidades do trabalho
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "leitor.h"
#include "lista.h"
#include "livro.h"
#include "uteis.h"

int main(int argc, char *argv[]) {
  char caminho_Leitor[MAX_STRING];
  strcpy(caminho_Leitor, argv[argc - 1]);
  strcat(caminho_Leitor, "leitores.txt");
  FILE *fLeitor = fopen(caminho_Leitor, "r");

  Leitor *Leitors[3];
  char primeira_linha[MAX_STRING];
  int x = fscanf(fLeitor, "%[^\n]\n", primeira_linha);
  if (x == EOF) {
    printf("ERRO ao ler arquivo de leitores\n");
  }
  int foi_lido;
  for (int i = 0; i < 3; i++) {
    Leitors[i] = leLeitor(fLeitor, &foi_lido);
  }
  int j;
  for (j = 0; j < 3; j++) {
    imprimeLeitor(Leitors[j]);
  }

  for (j = 0; j < 3; j++) {
    liberaLeitor(Leitors[j]);
  }

  fclose(fLeitor);
}