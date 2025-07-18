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
 * @brief Cria uma estrutura do tipo Livro, preenchendo todos seus atributos
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
 * @brief Obtém uma recomendação do leitor, buscando-a na lista de recomendações
 * por um id
 * @param lei O leitor
 * @param id identificador único de recomendação
 * @return Recomendação que tem id encontrada, NULL caso não esteja cadastrada
 */
Recomendacao *getRecomendacaoId(Leitor *lei, int id);

/**
 * @brief Obtém um livro lido do leitor, buscando-a na lista de lidos por um id
 * @param lei O leitor
 * @param id identificador único de livro
 * @return Livro que tem id encontrado, NULL caso não esteja cadastrado
 */
Livro *getLivroLidoId(Leitor *lei, int id);

/**
 * @brief Obtém um livro desejado do leitor, buscando-a na lista de desejados por um id
 * @param lei O leitor
 * @param id identificador único de livro
 * @return livro que tem id encontrado, NULL caso não esteja cadastrado
 */
Livro *getLivroDesejadoId(Leitor *lei, int id);

/**
 * @brief Obtém uma prefência (string) do leitor, buscando-a no vetor de preferências por um id
 * @param lei O leitor
 * @param id indíce da preferência desejada
 * @return preferência no índice id, se encontrada
 */
char *getPreferenciaLeitor(Leitor *lei, int id);

/**
 * @brief Busca livros lidos em comum entre dois leitores e os imprime
 * @param lei1 um dos leitores que será comparado
 * @param lei1 um dos leitores que será comparado
 * @param fSaida ponteiro para o arquivo saidas.txt
 */
void comparaLeitores(Leitor *lei1, Leitor *lei2, FILE *fSaida);

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
 * @brief Adiciona um leitor à afinidade de outro caso tenham a mesma preferência
 * @param leiDes leitor onde será adicionada a afinidade, caso exista
 * @param leiOri leitor que será avaliado para adicionar afinidade
 */
void preencheAfinidadeDireta(void *leiDes, void *leiOri);

/**
 * @brief verifica se existe afinidade direta ou indireta entre dois leitores, salvando todos que já foram vistos em uma lista de visitados
 * @param lei1 leitor de origem da afinidade, a partir do qual se deve verificar se é possível chegam em:
 * @param lei2 leitor de destino
 * @param visitados lista que salva os leitores que já foram verificados pela função, para evitar loop circular infinito
 * @return 1 se é possível chegar a lei2 a partir de lei1, 0 caso contrário
 */
int verificaAfinidade(Leitor *lei1, Leitor *lei2, void *visitados);

/**
 * @brief Libera o leitor da memoria, desalocando todos os atributos necessários
 * @param lei O leitor
 */
void liberaLeitor(void *lei);

#endif