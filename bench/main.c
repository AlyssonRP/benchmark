#include <stdio.h>
#include "geracao_numeros.h"
#include "algoritmos_busca.h"
#include "algoritmos_ordenacao.h"

int main() {
    const char *nome_arquivo = "numeros_aleatorios.txt";
    int qtd_numeros;

    printf("Digite a quantidade de números a serem gerados: ");
    scanf("%d", &qtd_numeros);
    
    gerar_numeros_aleatorios(qtd_numeros, nome_arquivo);
    int *numeros = ler_numeros_do_arquivo(nome_arquivo);

    while (1) {
        printf("Menu Principal:\n");
        printf("1. Operações de busca de elemento\n");
        printf("2. Operações de classificação de elementos\n");
        printf("4. Sair\n");
        
        int opcao;
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Operações de Busca
            int alvo;
            double tempo = 0;

            printf("Digite o elemento a ser buscado: ");
            scanf("%d", &alvo);

            // Chama a busca linear
            int posicao = busca_linear(numeros, qtd_numeros, alvo, &tempo);

            if (posicao != -1) {
                printf("Elemento encontrado na posição: %d\n", posicao);
            } else {
                printf("Elemento não encontrado na lista.\n");
            }
        } else if (opcao == 2) {
            // Operações de Classificação

            // Chama o Bubble Sort para ordenar os números
            bubble_sort(numeros, qtd_numeros);

            printf("Números ordenados:\n");
            for (int i = 0; i < qtd_numeros; i++) {
                printf("%d ", numeros[i]);
            }
            printf("\n");
        } else if (opcao == 4) {
            // Encerra o programa
            break;
        } else {
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    }

    // Free fora do loop
    free(numeros);
    return 0;
}

