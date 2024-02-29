#ifndef GERACAO_NUMEROS_H
#define GERACAO_NUMEROS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_numeros_aleatorios(int qtd_numeros, const char *nome_arquivo);
int *ler_numeros_do_arquivo(const char *nome_arquivo);

#endif
