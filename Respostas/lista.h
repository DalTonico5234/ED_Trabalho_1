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

typedef int (*fGetIdDado)(void *);

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
 * @brief Busca determinado dado em uma lista, de qualquer tipo
 * @param list lista onde será inserido
 * @param id identificador único do elemento que será retirado
 * @param getId função que retorna id do tipo de dado que está sendo procurado
 * @return Dado com id encontrado em list, NULL caso não seja encontrado
 */
void *buscaDadoNaLista(Lista *list, int id, fGetIdDado getId);

/**
 * @brief Imprime os livros lidos em comum entre dois leitores, a partir de suas
 * listas de lidos
 * @param list1 lista de livros lidos do leitor1
 * @param list2 lista de livros lidos do leitor2
 * @param fSaida ponteiro para o arquivo saidas.txt
 */
void comparaDadosLista(Lista *list1, Lista *list2, FILE *fSaida);

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
 * @brief Preenche todas as afinidades diretas de uma lista de leitores
 * @param leitores lista com todos os leitores cadastrados
 */
void preencheAfinidadesDiretas(Lista *leitores);

/**
 * @brief Função recursiva que verifica se, a partir de uma lista de afinidades é possível chegar a determinado leitor
 * @param afinidades lista de leitores cadastrados na afinidade do leitor de origem
 * @param des leitor de destino ao qual se deseja chegar
 * @param visitados lista que salva os leitores que já foram verificados pela função, para evitar loop circular infinito
 * @return 1 se é possível chegar a lei2 a partir de lei1, 0 caso contrário
 */
int procuraAfinidade(Lista *afinidades, Leitor *des, Lista *visitados);

/**
 * @brief Verifica se determinada lista não tem nenhum elemento (está vazia)
 * @param list lista a ser verificada
 * @return 1 se list for vazia, 0 caso contrário
 */
int ehListaVazia(Lista *list);

/**
 * @brief Libera toda a memória alocada para a lista
 * Se modo for 1, libera também os dados de acordo com a função específica para
 * cada dado Se modo for diferente de 1, libera apenas a estrutura da lista
 * @param list lista que será liberada
 * @param modo inteiro que armazena a opção de liberação
 */
void liberaLista(Lista *list, int modo);

#endif