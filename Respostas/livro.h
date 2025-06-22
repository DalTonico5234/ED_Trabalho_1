// livro.h
// Definição do TAD livro
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté Carvalho Trento
// Parte do trabalho 1 da disciplina Estutura de Dados, lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef livro_h
#define livro_h

#include "uteis.h"

/**
 * Estrutura do tipo Livro, contendo:
 *  id
 *  titulo
 *  autor
 *  genero
 *  ano de publicacao
 */
typedef struct livro Livro;

/**
 * @brief Cria uma estrutura do tipo Livro, preenchendo todos seus atributos
 * @param id Identificador único
 * @param ano_publi Ano de publicação
 * @param titulo Nome do livro
 * @param autor Nome do autor
 * @param genero Genero do livro
 * @return A estrutura Livro corretamente alocada e inicializada
 */
Livro *criaLivro(int id, int ano_publi, char *titulo, char *autor, char *genero);

/**
 * @brief Lê uma única estrutura do tipo Livro, e a cria usando criaLivro
 * @param fLivro Ponteiro para o arquivo do qual se deve ler o livro
 * @param foi_lido váriável que guarda o retorno do fscanf para uso na leitura de arquivos
 * @return A estrutura Livro corretamente lida e criada
 */
Livro *leLivro(FILE *fLivro, int *foi_lido);

/**
 * @brief Obtém o ano de publicação do livro
 * @param dom_peixote O livro
 * @return ano de publicação de dom_peixote
 */
int getAnoPubliLivro(Livro *dom_peixote);

/**
 * @brief Obtém o id do livro
 * @param senhor_dos_pasteis O livro
 * @return id de senhor_dos_pasteis
 */
int getIdLivro(void *senhor_dos_pasteis);

/**
 * @brief Obtém o genero do livro
 * @param vidas_molhadas O livro
 * @return genero de book
 */
char *getAutorLivro(Livro *vidas_molhadas);

/**
 * @brief Obtém o genero do livro
 * @param game_of_cones O livro
 * @return genero de game_of_cones
 */
char *getGeneroLivro(Livro *game_of_cones);

/**
 * @brief Obtém o titulo do livro
 * @param memorias_vividas_de_bras_cubos O livro
 * @return titulo de memorias_vividas_de_bras_cubos
 */
char *getTituloLivro(void *memorias_vividas_de_bras_cubos);

/**
 * @brief Libera o livro da memoria, desalocando todos os atributos necessários
 * @param perseu_jaquin O livro
 */
void liberaLivro(Livro *perseu_jaquin);

#endif