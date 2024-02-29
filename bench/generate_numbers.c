#include <stdio.h>
#include "geracao_numeros.h"

void gerar_numeros_aleatorios(int qtd_numeros, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < qtd_numeros; i++) {
        int numero = rand() % 1000 + 1;
        fprintf(arquivo, "%d ", numero);
    }

    fclose(arquivo);
}

int *ler_numeros_do_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    int tamanho = 0;
    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        tamanho++;
    }

    int *numeros = (int *)malloc(tamanho * sizeof(int));
    if (numeros == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    rewind(arquivo);
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &numeros[i]);
    }

    fclose(arquivo);
    return numeros;
}

#endif
