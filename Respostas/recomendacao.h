// recomendacao.h
// Definição do TAD Recomendacao
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté Carvalho Trento
// Parte do trabalho 1 da disciplina Estutura de Dados, lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef recomendacao_h
#define recomendacao_h

#include "uteis.h"
#include "leitor.h"
#include "livro.h"

/**
 * Estrutura do tipo Recomendacao, contendo:
 *  leitor que recomenda
 *  livro recomendado
 *  leitor que recebe a recomendacao
 */
typedef struct recomendacao Recomendacao;

/**
 * @brief Cria uma estrutura do tipo Recomendacao, preenchendo todos seus atributos
 * @param le_isso_po leitor que recomenda
 * @param recomendacao livro recomendado
 * @param sei_nao leitor que recebe a recomendacao
 * @return  A estrutura Recomendacao corretamente alocada e inicializada
 */
Recomendacao *criaRecomendacao(Leitor *le_isso_po, Livro *recomendacao, Leitor *sei_nao);

/**
 * @brief Obtém o nome do livro de determinada recomendacao
 * @param faz_exercicio_po uma recomendacao
 * @return Nome do livro de faz_exercicio_po
 */
char *getLivroRecomendado(Recomendacao *faz_exercicio_po);

/**
 * @brief Imprime a mensagem da recomendação no momento que ela é feita
 * @param drome_mais_po uma recomendacao
 */
void imprimeRecomendacaoFeita(Recomendacao *drome_mais_po);

/**
 * @brief Imprime a mensagem da recomendação, caso ela tenha sido aceita
 * @param bebe_agua_po uma recomendacao
 * @param yesno resposta à recomendacao
 */
void imprimeRecomendacaoAceita(Recomendacao *bebe_agua_po, int yesno);

/**
 * @brief Libera a recomendacao da memoria, desalocando apenas ela mesma
 * @param ajeita_a_postura_po uma recomendacao
 */
void liberaRecomendacao(Recomendacao *ajeita_a_postura_po);

#endif
