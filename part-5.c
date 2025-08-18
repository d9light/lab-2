#include <stdio.h>
#include <stdlib.h>

/*

STRUCTS Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados: idade
e quantidade de livros que leu no ano. Faça um programa que leia os dados de n usuários. Depois, calcule e
imprima:
a. A quantidade total de livros lidos pelos entrevistados menores de 18 anos;
b. A média de livros lidos pelos entrevistados.

Deve ser usada a seguinte struct:
struct usuario
{
    int idade;
    int qtdade;
};
typedef struct usuario Usuario;

Os dados devem ser armazenados em um vetor de usuários. O programa deve ser estruturado nas seguintes
funções:

void leVetor (int n, Usuario* vet);
// esta função recebe o tamanho do vetor e o endereço do primeiro elemento do vetor; preenche o vetor com
// dados digitados pelo usuário

int calculaQtidadeLivros (int n, Usuario* vet);
// esta função recebe o tamanho do vetor e o endereço do primeiro elemento do vetor; calcula a quantidade total
// de livros lidos pelos entrevistados menores de 18 anos, e retorna esta quantidade para o main

float calculaMedia (int n, Usuario* vet);
// esta função recebe o tamanho do vetor e o endereço do primeiro elemento do vetor; calcula a média de livros
// lidos pelos entrevistados e retorna esta quantidade para o main.

Ao final, o main mostra na tela os valores calculados.

*/

struct usuario {
    int idade;
    int qtdade;
};
typedef struct usuario Usuario;

void leVetor(int n, Usuario* vet) {
    for (int i = 0; i < n; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("Digite a idade: ");
        scanf("%d", &vet[i].idade);
        printf("Digite a quantidade de livros lidos no ano: ");
        scanf("%d", &vet[i].qtdade);
        printf("\n");
    }
}

int calculaQtidadeLivros(int n, Usuario* vet) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i].idade < 18) {
            total += vet[i].qtdade;
        }
    }
    return total;
}

float calculaMedia(int n, Usuario* vet) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += vet[i].qtdade;
    }
    return (float)soma / n;
}

int main() {
    int n;

    printf("Digite o numero de usuarios a serem cadastrados: ");
    scanf("%d", &n);

    Usuario* vet = (Usuario*) malloc(n * sizeof(Usuario));
    if (vet == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    leVetor(n, vet);

    int totalLivrosMenores18 = calculaQtidadeLivros(n, vet);
    float mediaLivros = calculaMedia(n, vet);

    printf("Quantidade total de livros lidos por entrevistados menores de 18 anos: %d\n", totalLivrosMenores18);
    printf("Media de livros lidos por entrevistados: %.2f\n", mediaLivros);

    free(vet);

    return 0;
}
