// booked.h
// Definição do TAD bookED
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef booked_h
#define booked_h

#include "recomendacao.h"
#include "livro.h"
#include "leitor.h"
#include "uteis.h"

/**
 * Estrutura do tipo bookED, contendo:
 *  lista de leitores cadastrados
 *  lista de livros cadsatrados
 *  arquivo de livros
 *  arquivo de leitores
 *  arquivo de comandos
 *  arquivo de saida
 */
typedef struct booked bookED;

bookED *criabookED(char *caminho_comum);

void executabookED(bookED *alexandria);

void imprimebookED(bookED *cairo);

void liberabookED(bookED *leitura);


#endif