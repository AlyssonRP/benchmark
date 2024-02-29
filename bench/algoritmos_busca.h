#ifndef ALGORITMOS_BUSCA_H
#define ALGORITMOS_BUSCA_H

int busca_linear(const int *lista, int tamanho, int alvo, double *tempo);
int busca_sentinela(int *lista, int tamanho, int alvo, double *tempo);
int busca_binaria(const int *lista, int tamanho, int alvo, double *tempo);

#endif
