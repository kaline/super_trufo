#include <stdio.h>
#include <string.h>

#define MAX 5  // número máximo de cartas

typedef struct {
    char nomeCidade[50];
    char pais[50];
    unsigned long populacao;
    float pib;  // em bilhões
    float area; // em km²
    float densidade; // calculada
} Carta;

void cadastrarCartas(Carta cartas[], int *qtd) {
    if (*qtd >= MAX) {
        printf("Limite de cartas atingido!\n");
        return;
    }

    printf("\nCadastro da carta %d:\n", *qtd + 1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cartas[*qtd].nomeCidade);
    printf("País: ");
    scanf(" %[^\n]", cartas[*qtd].pais);
    printf("População: ");
    scanf("%lu", &cartas[*qtd].populacao);
    printf("PIB (em bilhões): ");
    scanf("%f", &cartas[*qtd].pib);
    printf("Área (km²): ");
    scanf("%f", &cartas[*qtd].area);

    // Cálculo com operadores matemáticos
    if (cartas[*qtd].area > 0) {
        cartas[*qtd].densidade = cartas[*qtd].populacao / cartas[*qtd].area;
    } else {
        cartas[*qtd].densidade = 0;
    }

    (*qtd)++;
}

void exibirCartas(Carta cartas[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Carta %d ---\n", i + 1);
        printf("Cidade: %s\n", cartas[i].nomeCidade);
        printf("País: %s\n", cartas[i].pais);
        printf("População: %lu\n", cartas[i].populacao);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade);
    }
}

void compararCartas(Carta a, Carta b) {
    printf("\nComparação entre %s e %s:\n", a.nomeCidade, b.nomeCidade);

    // Operadores relacionais
    if (a.pib > b.pib)
        printf("-> %s tem maior PIB.\n", a.nomeCidade);
    else if (b.pib > a.pib)
        printf("-> %s tem maior PIB.\n", b.nomeCidade);
    else
        printf("-> Ambas têm o mesmo PIB.\n");

    if (a.densidade > b.densidade)
        printf("-> %s é mais densa.\n", a.nomeCidade);
    else if (b.densidade > a.densidade)
        printf("-> %s é mais densa.\n", b.nomeCidade);
    else
        printf("-> Ambas têm a mesma densidade populacional.\n");
}

int main() {
    Carta cartas[MAX];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=== Super Trunfo de Países ===\n");
        printf("1. Cadastrar carta\n");
        printf("2. Exibir cartas\n");
        printf("3. Comparar duas cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCartas(cartas, &qtd);
                break;
            case 2:
                exibirCartas(cartas, qtd);
                break;
            case 3:
                if (qtd < 2) {
                    printf("Cadastre ao menos duas cartas primeiro.\n");
                } else {
                    int i, j;
                    printf("Digite os números das cartas a comparar (1 a %d):\n", qtd);
                    scanf("%d %d", &i, &j);
                    if (i > 0 && i <= qtd && j > 0 && j <= qtd && i != j) {
                        compararCartas(cartas[i - 1], cartas[j - 1]);
                    } else {
                        printf("Índices inválidos.\n");
                    }
                }
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
