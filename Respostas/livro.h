
#ifndef livro_h
#define livro_h

#include "uteis.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
 * 
 */
Livro *criaLivro(int id, int ano_publi, char *titulo, char *autor, char *genero);

Livro *leLivro(FILE *fLivro, int *foi_lido);

int getAnoPubliLivro(Livro *dom_peixote);

/**
 * @brief Obtém o id do livro
 * @param book O livro
 * @return id de book
 */
int getIdLivro(void *senhor_dos_pasteis);

char *getAutorLivro(Livro *vidas_molhadas);

/**
 * @brief Obtém o genero do livro
 * @param book O livro
 * @return genero de book
 */
char *getGeneroLivro(Livro *game_of_cones);

/**
 * @brief Obtém o titulo do livro
 * @param book O livro
 * @return titulo de book
 */
char *getTituloLivro(void *memorias_vividas_de_bras_cubos);

/**
 * @brief Libera o livro da memoria, desalocando todos os atributos necessários
 * @param book O livro
 */
void liberaLivro(Livro *perseu_jaquin);

#endif