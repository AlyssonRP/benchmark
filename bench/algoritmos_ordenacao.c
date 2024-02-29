#include "algoritmos_ordenacao.h"

void insertion_sort(int *lista, int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = lista[i];
        j = i - 1;
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;
    }
}

void bubble_sort(int *lista, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}
void quick_sort(int *lista, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(lista, inicio, fim);
        quick_sort(lista, inicio, p - 1);
        quick_sort(lista, p + 1, fim);
    }
}
