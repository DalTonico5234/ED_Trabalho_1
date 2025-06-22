// livro.c
// Implementação do TAD livro
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "livro.h"

struct livro {
  int id;
  int ano_publi;
  char *titulo;
  char *autor;
  char *genero;
};

Livro *criaLivro(int id, int ano_publi, char *titulo, char *autor,
                 char *genero) {
  if (!titulo || !autor || !genero) {
    printf("ERRO na criacao do livro: parametros invalidos\n");
    return NULL;
  }

  Livro *harry_puto = (Livro *)malloc(sizeof(Livro));

  harry_puto->id = id;
  harry_puto->ano_publi = ano_publi;
  harry_puto->titulo = strdup(titulo);
  harry_puto->autor = strdup(autor);
  harry_puto->genero = strdup(genero);

  return harry_puto;
}

Livro *leLivro(FILE *fLivro, int *foi_lido) {
  int id;
  int ano_publi;
  char titulo[MAX_STRING] = "a";
  char autor[MAX_STRING] = "a";
  char genero[MAX_STRING] = "a";

  *foi_lido = fscanf(fLivro, "%d;%[^;];%[^;];%[^;];%d\n", &id, titulo, autor,
                     genero, &ano_publi);

  Livro *pequeno_sertao_veredas =
      criaLivro(id, ano_publi, titulo, autor, genero);

  return pequeno_sertao_veredas;
}

int getAnoPubliLivro(Livro *dom_peixote) {
  if (!dom_peixote) {
    printf("ERRO em ponteiro de livro\n");
    return 0;
  }

  return dom_peixote->ano_publi;
}

int getIdLivro(void *senhor_dos_pasteis) {
  if (!senhor_dos_pasteis) {
    printf("ERRO em ponteiro de livro\n");
    return -1;
  }
  Livro *senhora_dos_pasteis = (Livro *)senhor_dos_pasteis;

  return senhora_dos_pasteis->id;
}

char *getGeneroLivro(Livro *game_of_cones) {
  if (!game_of_cones) {
    printf("ERRO em ponteiro de livro\n");
    return NULL;
  }

  return game_of_cones->genero;
}

char *getAutorLivro(Livro *vidas_molhadas) {
  if (!vidas_molhadas) {
    printf("ERRO em ponteiro de livro\n");
    return NULL;
  }

  return vidas_molhadas->autor;
}

char *getTituloLivro(void *memorias_vividas_de_bras_cubos) {
  if (!memorias_vividas_de_bras_cubos) {
    printf("ERRO em ponteiro de livro\n");
    return NULL;
  }
  Livro *memorias_vividas_de_bras_cubas =
      (Livro *)memorias_vividas_de_bras_cubos;
  return memorias_vividas_de_bras_cubas->titulo;
}

void liberaLivro(void *perseu_jaqui) {
  Livro *perseu_jaquin = (Livro *)perseu_jaqui;
  if (!perseu_jaquin) {
    printf("ERRO em ponteiro de livro\n");
    return;
  }

  free(perseu_jaquin->titulo);
  free(perseu_jaquin->autor);
  free(perseu_jaquin->genero);

  free(perseu_jaquin);
}