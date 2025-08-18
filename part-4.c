#include <stdio.h>
#include <stdlib.h>

/*

MATRIZES Faça um programa em C que armazene numa matriz de inteiros (de tamanho m x 6) os seguintes
dados COVID referentes a m municípios:
a. A primeira coluna guarda o código do município;
b. A segunda coluna guarda a quantidade de habitantes do município;
c. A terceira coluna guarda o total de casos confirmados;
d. A quarta coluna guarda o total de óbitos;
e. A quinta coluna guarda a incidência de casos a cada 100 mil habitantes;
f. A sexta coluna guarda a mortalidade a cada 100 mil habitantes.

Exemplo: um município com 283 mil habitantes, 52 mil casos e 850 óbitos, tem uma incidência de 18374
casos por 100 mil habitantes e uma mortalidade de 300 óbitos por 100 mil habitantes.
Faça um programa em C que:
a. Leia e preencha as quatro primeiras colunas da matriz;
b. Calcule e armazene as duas últimas colunas da matriz;
c. Imprima toda a matriz;
d. Mostre qual o código do município que tem a maior mortalidade;
e. Mostre qual o código do município que tem a maior incidência de casos.
Cada um dos itens acima deve ser uma função separada.

*/


int** criarMatriz(int m, int n) {
    int** matriz = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }
    return matriz;
}

int variaJ(int j) {
    int valor;
    switch (j) {
        case 0:
            printf("Digite o código do município: ");
            break;
        case 1:
            printf("Digite a quantidade de habitantes: ");
            break;
        case 2:
            printf("Digite o total de casos confirmados: ");
            break;
        case 3:
            printf("Digite o total de óbitos: ");
            break;
        default:
            printf("Digite o valor da coluna %d: ", j);
            break;
    }
    scanf("%d", &valor);
    return valor;
}

void preencherMatriz(int** matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Município %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {  
            matriz[i][j] = variaJ(j);
        }
    }
}

void calcularIncidenciaMort(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        int habitantes = matriz[i][1];
        int casos = matriz[i][2];
        int obitos = matriz[i][3];
        matriz[i][4] = (casos * 100000) / habitantes;     // incidência por 100 mil
        matriz[i][5] = (obitos * 100000) / habitantes;    // mortalidade por 100 mil
    }
}

void imprimaDetalhes(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        printf("Municipio codigo: %d\n", matriz[i][0]);
        printf("  Habitantes: %d\n", matriz[i][1]);
        printf("  Casos confirmados: %d\n", matriz[i][2]);
        printf("  Óbitos: %d\n", matriz[i][3]);
        printf("  Incidência (por 100 mil): %d\n", matriz[i][4]);
        printf("  Mortalidade (por 100 mil): %d\n\n", matriz[i][5]);
    }
}

void imprimaMatriz(int** matriz, int m, int n) {
    printf("\nMatriz completa:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    imprimaDetalhes(matriz, m);
}

int maiorMortalidade(int** matriz, int m) {
    int maior = matriz[0][5];
    int codigo = matriz[0][0];
    for (int i = 1; i < m; i++) {
        if (matriz[i][5] > maior) {
            maior = matriz[i][5];
            codigo = matriz[i][0];
        }
    }
    return codigo;
}

int maiorIncidencia(int** matriz, int m) {
    int maior = matriz[0][4];
    int codigo = matriz[0][0];
    for (int i = 1; i < m; i++) {
        if (matriz[i][4] > maior) {
            maior = matriz[i][4];
            codigo = matriz[i][0];
        }
    }
    return codigo;
}

int main() {
    int m, n = 6;
    printf("Digite quantos municipios serao armazenados:\n");
    scanf("%d", &m);

    int** matriz = criarMatriz(m, n);
    preencherMatriz(matriz, m, n);
    calcularIncidenciaMort(matriz, m);
    imprimaMatriz(matriz, m, n);

    int codMortalidade = maiorMortalidade(matriz, m);
    int codIncidencia = maiorIncidencia(matriz, m);

    printf("Municipio com maior mortalidade: %d\n", codMortalidade);
    printf("Municipio com maior incidencia: %d\n", codIncidencia);

    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
