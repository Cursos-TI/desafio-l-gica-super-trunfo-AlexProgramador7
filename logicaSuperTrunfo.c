#include <stdio.h>

// Função para determinar vencedor de um atributo
int compararAtributo(int i, float a, float b) {
    if (i == 4) return a < b ? 1 : (b < a ? 2 : 0); // densidade populacional (menor é melhor)
    return a > b ? 1 : (b > a ? 2 : 0);
}

int main() {
    // --- Dados da Carta 1 ---
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // --- Dados da Carta 2 ---
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    int atributo1, atributo2;
    float valor1A = 0, valor2A = 0, valor1B = 0, valor2B = 0;
    float somaCarta1, somaCarta2;

    // === Entrada de dados da Carta 1 ===
    printf("Cadastro da Carta 1:\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado1);

    printf("Código da carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Cálculos para a Carta 1 ---
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    printf("\n");

    // === Entrada de dados da Carta 2 ===
    printf("Cadastro da Carta 2:\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado2);

    printf("Código da carta (ex: B01): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos para a Carta 2 ---
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // === Escolha dos atributos ===
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    scanf("%d", &atributo1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1) {
                switch (i) {
                    case 1: printf("1 - População\n"); break;
                    case 2: printf("2 - Área\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Pontos Turísticos\n"); break;
                    case 5: printf("5 - Densidade Populacional\n"); break;
                    case 6: printf("6 - PIB per Capita\n"); break;
                }
            }
        }
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) printf("Os atributos não podem ser iguais!\n");
    } while (atributo2 == atributo1);

    float valoresCarta1[6] = {populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1};
    float valoresCarta2[6] = {populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2};

    valor1A = valoresCarta1[atributo1 - 1];
    valor2A = valoresCarta2[atributo1 - 1];
    valor1B = valoresCarta1[atributo2 - 1];
    valor2B = valoresCarta2[atributo2 - 1];

    somaCarta1 = valor1A + valor1B;
    somaCarta2 = valor2A + valor2B;

    printf("\n=== Resultado da Comparacão ===\n");
    printf("Carta 1 - %s\n", nomeCidade1);
    printf("  Atributo %d: %.2f\n  Atributo %d: %.2f\n  Soma: %.2f\n", atributo1, valor1A, atributo2, valor1B, somaCarta1);
    printf("Carta 2 - %s\n", nomeCidade2);
    printf("  Atributo %d: %.2f\n  Atributo %d: %.2f\n  Soma: %.2f\n", atributo1, valor2A, atributo2, valor2B, somaCarta2);

    if (somaCarta1 > somaCarta2)
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    else if (somaCarta2 > somaCarta1)
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}
