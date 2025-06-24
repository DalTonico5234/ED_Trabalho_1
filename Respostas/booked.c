// booked.c
// Implementação do TAD bookED
// Criado e desenvolvido por Leonardo Cheregati de Oliveira Roxo e Matteo Chisté
// Carvalho Trento Parte do trabalho 1 da disciplina Estutura de Dados,
// lecionada por Patricia Dockhorn Costa, da UFES, no período 2025/1

#include "booked.h"

struct booked {
  Lista *leitores;
  Lista *livros;
  FILE *fComandos;
  FILE *fSaida;
};

bookED *criabookED(char *caminho_comum) {
  bookED *library = (bookED *)malloc(sizeof(bookED));

  library->leitores = criaLista();
  library->livros = criaLista();

  char caminho_livros[MAX_STRING], caminho_leitores[MAX_STRING],
      caminho_comandos[MAX_STRING], caminho_saida[MAX_STRING];
  strcpy(caminho_livros, caminho_comum);
  strcpy(caminho_leitores, caminho_comum);
  strcpy(caminho_comandos, caminho_comum);
  strcpy(caminho_saida, caminho_comum);
  strcat(caminho_livros, "livros.txt");
  strcat(caminho_leitores, "leitores.txt");
  strcat(caminho_comandos, "comandos.txt");
  strcat(caminho_saida, "saida.txt");

  FILE *fLivros = fopen(caminho_livros, "r");
  FILE *fLeitores = fopen(caminho_leitores, "r");
  library->fComandos = fopen(caminho_comandos, "r");
  library->fSaida = fopen(caminho_saida, "w");

  int foi_lido = 0;
  Livro *registrado;
  char primeira_linha[MAX_STRING];
  foi_lido = fscanf(fLivros, "%[^\n]\n", primeira_linha);
  foi_lido = fscanf(library->fComandos, "%[^\n]\n", primeira_linha);
  do {
    registrado = leLivro(fLivros, &foi_lido);
    if (foi_lido == EOF) {
      liberaLivro(registrado);
    } else {
      insereNaLista(library->livros, registrado, LIVRO);
    }
  } while (foi_lido != EOF);

  Leitor *leia;
  foi_lido = fscanf(fLeitores, "%[^\n]\n", primeira_linha);
  do {
    leia = leLeitor(fLeitores, &foi_lido);
    if (leia != NULL) {
      if (foi_lido == EOF) {
        liberaLeitor(leia);
      } else {
        insereNaLista(library->leitores, leia, LEITOR);
      }
    }

  } while (foi_lido != EOF);

  fclose(fLivros);
  fclose(fLeitores);

  return library;
}

void adicionaLivroLido(bookED *alexandria, int id1, int id2) {
  Leitor *leitor =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id1, getIdLeitor);
  Livro *livro = (Livro *)buscaDadoNaLista(alexandria->livros, id2, getIdLivro);

  if (!leitor) {
    fprintf(alexandria->fSaida, "Erro: Leitor com ID %d não encontrado\n", id1);
  } else if (!livro) {
    fprintf(alexandria->fSaida, "Erro: Livro com ID %d não encontrado\n", id2);
  } else if (livro == getLivroLidoId(leitor, id2)) {
    fprintf(alexandria->fSaida, "%s já leu \"%s\"\n", getNomeLeitor(leitor),
            getTituloLivro(livro));
  } else {
    adicionarLidos(leitor, livro);
    fprintf(alexandria->fSaida, "%s leu \"%s\"\n", getNomeLeitor(leitor),
            getTituloLivro(livro));
  }
}

void adicionaLivroDesejado(bookED *alexandria, int id1, int id2) {
  Leitor *leitor =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id1, getIdLeitor);
  Livro *livro = (Livro *)buscaDadoNaLista(alexandria->livros, id2, getIdLivro);

  if (!leitor) {
    fprintf(alexandria->fSaida, "Erro: Leitor com ID %d não encontrado\n", id1);
  } else if (!livro) {
    fprintf(alexandria->fSaida, "Erro: Livro com ID %d não encontrado\n", id2);
  } else if (livro == getLivroDesejadoId(leitor, id2)) {
    fprintf(alexandria->fSaida, "%s já deseja ler \"%s\"\n",
            getNomeLeitor(leitor), getTituloLivro(livro));
  } else {
    adicionarDesejos(leitor, livro);
    fprintf(alexandria->fSaida, "%s deseja ler \"%s\"\n", getNomeLeitor(leitor),
            getTituloLivro(livro));
  }
}

void recomendarLivroED(bookED *alexandria, int id1, int id2, int id3) {
  Leitor *leitor1 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id1, getIdLeitor);
  Livro *livro = (Livro *)buscaDadoNaLista(alexandria->livros, id2, getIdLivro);
  Leitor *leitor2 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id3, getIdLeitor);

  if (!leitor2) {
    fprintf(alexandria->fSaida,
            "Erro: Leitor destinatário com ID %d não encontrado\n", id3);
  } else if (!leitor1) {
    fprintf(alexandria->fSaida,
            "Erro: Leitor recomendador com ID %d não encontrado\n", id1);
  } else if (!livro) {
    fprintf(alexandria->fSaida, "Erro: Livro com ID %d não encontrado\n", id2);
  }

  else if (id1 == id3) {
    fprintf(alexandria->fSaida, "%s não pode recomendar livros para si mesmo\n",
            getNomeLeitor(leitor1));
  } else if (livro == getLivroLidoId(leitor2, id2)) {
    fprintf(alexandria->fSaida,
            "%s não precisa da recomendação de \"%s\" pois já leu este livro\n",
            getNomeLeitor(leitor2), getTituloLivro(livro));
  } else if (livro == getLivroDesejadoId(leitor2, id2)) {
    fprintf(alexandria->fSaida,
            "%s já deseja ler \"%s\", recomendação desnecessária\n",
            getNomeLeitor(leitor2), getTituloLivro(livro));
  } else {
    int id = 1000000 * id1 + 1000 * id2 + id3;
    Recomendacao *recomendacao = criaRecomendacao(leitor1, livro, leitor2, id);
    imprimeRecomendacaoFeita(recomendacao, alexandria->fSaida);
    recomendarLivro(leitor2, recomendacao);
  }
}

void processarRecomendacaoED(bookED *alexandria, int id3, int id2, int id1,
                             int yesno) {
  Leitor *leitor1 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id1, getIdLeitor);
  Livro *livro = (Livro *)buscaDadoNaLista(alexandria->livros, id2, getIdLivro);
  Leitor *leitor2 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id3, getIdLeitor);

  if (!leitor2) {
    fprintf(alexandria->fSaida, "Erro: Leitor com ID %d não encontrado\n", id3);
    return;
  } else if (!leitor1) {
    fprintf(alexandria->fSaida,
            "Erro: Leitor recomendador com ID %d não encontrado\n", id1);
    return;
  } else {
    int id = 1000000 * id1 + 1000 * id2 + id3;
    Recomendacao *recomendacao = getRecomendacaoId(leitor2, id);
    if (!recomendacao) {
      fprintf(alexandria->fSaida,
              "%s não possui recomendação do livro ID %d feita por %s\n",
              getNomeLeitor(leitor2), id2, getNomeLeitor(leitor1));
    } else {
      imprimeRecomendacaoAceita(recomendacao, yesno, alexandria->fSaida);
    }
    return;
  }

  if (!livro) {
    fprintf(alexandria->fSaida, "Erro: Livro com ID %d não encontrado\n", id2);
  }
}
void buscaLivrosEmComum(bookED *alexandria, int id1, int id2) {
  Leitor *leitor1 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id1, getIdLeitor);
  Leitor *leitor2 =
      (Leitor *)buscaDadoNaLista(alexandria->leitores, id2, getIdLeitor);
  if (!leitor2) {
    fprintf(alexandria->fSaida, "Erro: Leitor com ID %d não encontrado\n", id2);
    return;
  } else if (!leitor1) {
    fprintf(alexandria->fSaida, "Erro: Leitor com ID %d não encontrado\n", id1);
    return;
  } else {
    fprintf(alexandria->fSaida,
            "Livros em comum entre %s e %s:", getNomeLeitor(leitor1),
            getNomeLeitor(leitor2));
    comparaLeitores(leitor1, leitor2, alexandria->fSaida);
  }
}
void executabookED(bookED *alexandria) {
  int foi_lido = 0;
  int comando, id1, id2, id3;
  do {
    foi_lido = fscanf(alexandria->fComandos, "%d;%d;%d;%d\n", &comando, &id1,
                      &id2, &id3);
    if (foi_lido == EOF) {
      break;
    }
    if (comando == 1) {
      adicionaLivroLido(alexandria, id1, id2);
    } else if (comando == 2) {
      adicionaLivroDesejado(alexandria, id1, id2);
    } else if (comando == 3) {
      recomendarLivroED(alexandria, id1, id2, id3);
    } else if (comando == 4) {
      processarRecomendacaoED(alexandria, id1, id2, id3, 1);
    } else if (comando == 5) {
      processarRecomendacaoED(alexandria, id1, id2, id3, 0);
    } else if (comando == 6) {
      buscaLivrosEmComum(alexandria, id1, id3);
    } else if (comando == 7) {
    } else if (comando == 8) {
      imprimebookED(alexandria);
    } else {
      fprintf(alexandria->fSaida, "Erro: Comando %d não reconhecido\n",
              comando);
    }
  } while (foi_lido != EOF);
}

void imprimebookED(bookED *cairo) {
  fprintf(cairo->fSaida, "Imprime toda a BookED\n\n");
  imprimeLista(cairo->leitores, LEITOR, cairo->fSaida);
}

void liberabookED(bookED *leitura) {
  liberaLista(leitura->livros, 1);
  liberaLista(leitura->leitores, 1);

  fclose(leitura->fComandos);
  fclose(leitura->fSaida);

  free(leitura);
}