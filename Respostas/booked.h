// booked.h
// Definição do TAD bookED
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#ifndef booked_h
#define booked_h

#include "leitor.h"
#include "livro.h"
#include "recomendacao.h"
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

/**
 * @brief Cria uma estrutura do tipo bookED, preenchendo todos seus atributos
 * @param caminho_comum string contendo o caminho base do diretório que contém os arquivos .txt necessários (pode ser inicializada como "" para acessar a pasta raiz)
 * @return A estrutura bookED corretamente alocada e inicializada
 */
bookED *criabookED(char *caminho_comum);

/**
 * @brief Lê todos os comandos (contendo ids) e chama todas as funções correspondentes
 * @param alexandria a estrutura bookED já inicializada
 */
void executabookED(bookED *alexandria);

/**
 * @brief Executa o comando de adicionar o livro lido à lista de determinado leitor
 * @param alexandria a estrutura bookED já inicializada
 * @param id1 id para o leitor
 * @param id2 id para o livro
 */
void adicionaLivroLido(bookED *alexandria, int id1, int id2);

/**
 * @brief Executa o comando de adicionar o livro desejado à lista de determinado leitor
 * @param alexandria a estrutura bookED já inicializada
 * @param id1 id para o leitor
 * @param id2 id para o livro
 */
void adicionaLivroDesejado(bookED *alexandria, int id1, int id2);

/**
 * @brief Executa o comando de um leitor recomendar o livro para outro leitor
 * @param alexandria a estrutura bookED já inicializada
 * @param id1 id para o leitor recomendador
 * @param id2 id para o livro
 * @param id3 id para o leitor que destinatário
 */
void recomendarLivroED(bookED *alexandria, int id1, int id2, int id3);

/**
 * @brief Executa o comando de um leitor aceitar ou rejeitar o livro para outro leitor
 * @param alexandria a estrutura bookED já inicializada
 * @param id3 id para o leitor recomendador
 * @param id2 id para o livro
 * @param id1 id para o leitor que destinatário
 * @param yesno inteiro que corresponde à resposta da recomendação (1 se for aceita, 0 se for recusada)
 */
void processarRecomendacaoED(bookED *alexandria, int id3, int id2, int id1, int yesno);

/**
 * @brief Executa o comando de buscar todos os livros que dois leitores tem em comum
 * @param alexandria a estrutura bookED já inicializada
 * @param id1 id para o primeiro leitor da comparação
 * @param id2 id para o segundo leitor da comparação
 */
void buscaLivrosEmComum(bookED *alexandria, int id1, int id2);

/**
 * @brief Executa o comando de imprimir todas as informações da bookED
 * @param cairo a estrutura bookED já inicializada
 */
void imprimebookED(bookED *cairo);

/**
 * @brief Libera toda a memória alocada pelo código
 * @param leituraa estrutura bookED que será liberada
 */
void liberabookED(bookED *leitura);

#endif