// lista.h
// Definição do TAD lista
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef lista_h
#define lista_h

#include "leitor.h"
#include "livro.h"
#include "recomendacao.h"
#include "uteis.h"
/**
 * Estrutura do tipo Lista (duplamente encadeada e genérica/heterogênea),
 * contendo: sentila:
 *  - prim
 *  - ult
 */
typedef struct lista Lista;

/**
 * @brief Cria uma estrutura do tipo Livro, inicialmente vazia
 * @return A lista corretamente alocada e inicializada
 */
Lista *criaLista();

/**
 * @brief Insere determinado elemento na lista
 * @param list lista onde será inserido
 * @param dado elemento que será inserido
 * @param tipo tipo do dado
 */
void insereNaLista(Lista *list, void *dado, int tipo);

/**
 * @brief Retira determinado elemento da lista, conforme seu tipo
 * @param list lista onde será retirado
 * @param id identificador único do elemento que será retirado
 * @param tipo tipo do elemento
 * @return O dado, caso seja encontrado, NULL caso contrário
 */
void *retiraDaLista(Lista *list, int id, int tipo);

/**
 * @brief Imprime uma string específica de cado elemento da lista, conforme seu
 * tipo
 * @param list lista que será impressa
 * @param tipo tipo dos elementos da lista
 * @param fSaida ponteiro para o arquivo saidas.txt
 */
void imprimeLista(Lista *list, int tipo, FILE *fSaida);

/**
 * @brief Libera toda a memória alocada para a lista, mas NÃO libera os dados
 * inseridos nela
 * @param list lista que será liberada
 */
void liberaLista(Lista *list, int tipo);

#endif