// main.c
// arquivo principal do trabalho
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "booked.h"

int main(int argc, char *argv[]) {
  bookED *biblioteca = criabookED(argv[argc - 1]);
  executabookED(biblioteca);
  liberabookED(biblioteca);
}
