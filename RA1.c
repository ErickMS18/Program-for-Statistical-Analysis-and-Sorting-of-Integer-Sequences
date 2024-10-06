#include <stdio.h>
#include <stdlib.h>

#define MAX 108

void bubbleSort(int vetor[], int amount) {
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {

                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *input;
    FILE *outputEstatisticas;
    int vetor[MAX];
    int amount;
    int i;
    int positivos = 0, negativos = 0, zeros = 0;
    int pares = 0, impares = 0;

    input = fopen("dados.txt", "r");
    if (input == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    fscanf(input, "%d", &amount);
    if (amount > MAX) {
        printf("Erro: o arquivo contem mais numeros que a capacidade do vetor.\n");
        fclose(input);
        return 1;
    }

    if (amount < 30) {
        printf("Erro: o arquivo deve conter pelo menos 30 numeros.\n");
        fclose(input);
        return 1;
    }

    for (i = 0; i < amount; i++) {
        fscanf(input, "%d", &vetor[i]);

        if (vetor[i] > 0) {
            positivos++;
        } else if (vetor[i] < 0) {
            negativos++;
        } else {
            zeros++;
        }

        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    fclose(input);

    outputEstatisticas = fopen("estatisticas.txt", "w");
    if (outputEstatisticas == NULL) {
        printf("Erro ao criar o arquivo de estatisticas.\n");
        return 1;
    }

    fprintf(outputEstatisticas, "Quantidade de numeros positivos: %d\n", positivos);
    fprintf(outputEstatisticas, "Quantidade de numeros negativos: %d\n", negativos);
    fprintf(outputEstatisticas, "Quantidade de numeros iguais a zero: %d\n", zeros);
    fprintf(outputEstatisticas, "Quantidade de numeros pares: %d\n", pares);
    fprintf(outputEstatisticas, "Quantidade de numeros impares: %d\n", impares);

    fclose(outputEstatisticas);
    printf("Arquivo estatisticas.txt criado com sucesso!\n");

    
    int distintos[MAX];
    int count_distintos = 0;

    for (i = 0; i < amount; i++) {
        int existe = 0;
        for (int j = 0; j < count_distintos; j++) {
            if (vetor[i] == distintos[j]) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            distintos[count_distintos] = vetor[i];
            count_distintos++;
        }
    }

    FILE *outputDistintos = fopen("distintos.txt", "w");
    if (outputDistintos == NULL) {
        printf("Erro ao criar o arquivo distintos.txt.\n");
        return 1;
    }

    for (i = 0; i < count_distintos; i++) {
        fprintf(outputDistintos, "%d ", distintos[i]);
    }
    fclose(outputDistintos);
    printf("Arquivo distintos.txt criado com sucesso!\n");

    
    bubbleSort(vetor, amount);

    
    FILE *outputOrdenado = fopen("ordenado.txt", "w");
    if (outputOrdenado == NULL) {
        printf("Erro ao criar o arquivo ordenado.txt.\n");
        return 1;
    }

    for (i = 0; i < amount; i++) {
        fprintf(outputOrdenado, "%d ", vetor[i]);
    }
    fclose(outputOrdenado);
    printf("Arquivo ordenado.txt criado com sucesso!\n");

    
    bubbleSort(distintos, count_distintos);

    
    FILE *outputDistintosOrdenado = fopen("distintos_ordenado.txt", "w");
    if (outputDistintosOrdenado == NULL) {
        printf("Erro ao criar o arquivo distintos_ordenado.txt.\n");
        return 1;
    }

    for (i = 0; i < count_distintos; i++) {
        fprintf(outputDistintosOrdenado, "%d ", distintos[i]);
    }
    fclose(outputDistintosOrdenado);
    printf("Arquivo distintos_ordenado.txt criado com sucesso!\n");

    return 0;
}



