#include "algoritmos_busca.h"

int busca_linear(const int *lista, int tamanho, int alvo, double *tempo) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == alvo) {
            *tempo = i;  // Armazena o índice onde o elemento foi encontrado
            return i;  // Retorna a posição do elemento se for encontrado
        }
    }
    *tempo = -1;  // Atualiza o tempo com -1 se o elemento não for encontrado
    return -1;  // Retorna -1 se o elemento não for encontrado
}


int busca_sentinela(int *lista, int tamanho, int alvo, double *tempo) {
    int *lista_modificavel = malloc(tamanho * sizeof(int)); // Cria uma cópia modificável
    if (lista_modificavel == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    
    // Copia os elementos para a lista modificável
    for (int i = 0; i < tamanho; i++) {
        lista_modificavel[i] = lista[i];
    }

    int ultimo = lista_modificavel[tamanho - 1];  // Guarda o último elemento
    lista_modificavel[tamanho - 1] = alvo;  // Substitui o último elemento pelo alvo

    int i = 0;
    while (lista_modificavel[i] != alvo) {
        i++;
    }

    lista_modificavel[tamanho - 1] = ultimo;  // Restaura o último elemento

    if (i < tamanho - 1 || lista_modificavel[tamanho - 1] == alvo) {
        *tempo = (i != tamanho - 1) ? i : -1;  // Armazena o índice onde o elemento foi encontrado ou -1 se não encontrado
        free(lista_modificavel); // Libera a lista modificável
        return (i != tamanho - 1) ? i : -1;  // Retorna a posição do elemento se for encontrado, caso contrário -1
    }

    *tempo = -1;  // Atualiza o tempo com -1 se o elemento não for encontrado
    free(lista_modificavel); // Libera a lista modificável
    return -1;  // Retorna -1 se o elemento não for encontrado
}




int busca_binaria(const int *lista, int tamanho, int alvo, double *tempo) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista[meio] == alvo) {
            *tempo = meio;  // Armazena o índice onde o elemento foi encontrado
            return meio;  // Retorna a posição do elemento se for encontrado
        }
        if (lista[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    *tempo = -1;  // Atualiza o tempo com -1 se o elemento não for encontrado
    return -1;  // Retorna -1 se o elemento não for encontrado
}

