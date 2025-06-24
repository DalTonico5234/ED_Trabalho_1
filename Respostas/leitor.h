// leitor.h
// Definição do TAD Leitor
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef leitor_h
#define leitor_h

#include "lista.h"
#include "livro.h"
#include "uteis.h"

typedef struct recomendacao Recomendacao;

/**
 * Estrutura do tipo Leitor, contendo:
 *  id
 *  nome
 *  número de preferências
 *  vetor de preferências
 *  lista de livros lidos
 *  lista de livros desejados
 *  lista de recomendações
 *  lista de afinidadas
 */
typedef struct Leitor Leitor;

/**
 * Cria uma estrutura do tipo Livro, preenchendo todos seus atributos
 * @param id Identificador único
 * @param nome Nome do Leitor
 * @param preferencias Vetor de preferências (strings)
 * @param npref Número de preferências
 * @return A estrutura Livro corretamente alocada e inicializada
 */
Leitor *criaLeitor(int id, char *nome, char preferencias[][MAX_STRING],
                   int npref);

/**
 * @brief Lê uma única estrutura do tipo Leitor, e a cria usando criaLeitor
 * @param fLivro Ponteiro para o arquivo do qual se deve ler o Leitor
 * @param foi_lido váriável que guarda o retorno do fscanf para uso na leitura
 * de arquivos
 * @return A estrutura Leitor corretamente lida e criada
 */
Leitor *leLeitor(FILE *fLeitor, int *foi_lido);

/**
 * @brief Obtém o id do leitor
 * @param lei O leitor
 * @return id de lei
 */
int getIdLeitor(void *lei);

/**
 * @brief Obtém o nome do leitor
 * @param lei O leitor
 * @return nome de lei
 */
char *getNomeLeitor(void *lei);

/**
 * @brief Imprime um leitor e todos seus atributos
 * @param leis leitor a ser impresso
 * @param fSaida ponteiro para o arquivo saidas.txt
 */
void imprimeLeitor(void *leis, FILE *fSaida);

/**
 * @brief Adiciona determinado livro à lista de lidos de um leitor
 * @param lei leitor que leu
 * @param liv livro que foi lido
 */
void adicionarLidos(Leitor *lei, Livro *liv);

/**
 * @brief Adiciona determinado livro à lista de desejados de um leitor
 * @param lei leitor que deseja ler
 * @param liv livro que deseja ser livro
 */
void adicionarDesejos(Leitor *lei, Livro *liv);

/**
 * @brief adiciona uma recomendação à lista de recomendações de um leitor
 * @param lei leitor que recebeu a recomendação
 * @param rec recomendação recebida
 */
void recomendarLivro(Leitor *lei, Recomendacao *Rec);

/**
 * @brief Verifica a resposta à recomendação e faz os ajustes caso seja aceita
 * @param lei leitor que tem a recomendação
 * @param liv livro que foi recomendado
 * @param yesno resposta à recomendação (aceita ou recusa)
 */
void processarRecomendacao(Leitor *lei, Recomendacao *Rec, int yesno);

/**
 * @brief Remove a recomendação da lista
 * @param lei leitor que tem a recomendação
 * @param liv livro que foi recomendado
 */
void removerRecomendacao(Leitor *lei, Recomendacao *Rec);

/**
 * @brief Adiciona determinado leitor à lista de afinidades de outro
 * @param destino leitor que ganhará afinidade
 * @param afinidade leitor que é a a afinidade
 */
void adicionarAfinidade(Leitor *destino, Leitor *afinidade);

/**
 * @brief Libera o leitor da memoria, desalocando todos os atributos necessários
 * @param lei O leitor
 */
void liberaLeitor(void *lei);

Recomendacao *getRecomendacaoId(Leitor *lei, int id);

Livro *getLivroLidoId(Leitor *lei, int id);

Livro *getLivroDesejadoId(Leitor *lei, int id);

void comparaLeitores(Leitor *lei1, Leitor *lei2, FILE *fSaida);

#endif