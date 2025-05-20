#include <stdio.h>

// Função auxiliar para imprimir o menu dos atributos
void mostrarMenu(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Número de Pontos Turísticos\n");
    if (ignorar != 5) printf("5 - Densidade Demográfica (MENOR vence!)\n");
}

int main() {
    // ----------VARIÁVEIS CARTAS-----------
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // ----------ENTRADA DE DADOS----------
    printf("Digite os dados da Carta 1:\n");
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ----------CÁLCULOS AUXILIARES----------
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // ----------ESCOLHA DE DOIS ATRIBUTOS----------
    int atributo1 = 0, atributo2 = 0;

    mostrarMenu(0);
    printf("Escolha o 1º atributo (1 a 5): ");
    scanf("%d", &atributo1);

    while (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &atributo1);
    }

    mostrarMenu(atributo1);
    printf("Escolha o 2º atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);

    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &atributo2);
    }

    // ----------COMPARAÇÃO DOS ATRIBUTOS----------
    float valor1A = 0, valor1B = 0, valor2A = 0, valor2B = 0;
    char nomeA1[50], nomeA2[50];

    // Função para mapear o atributo para valor
    for (int i = 1; i <= 2; i++) {
        int attr = (i == 1) ? atributo1 : atributo2;
        float *v1 = (i == 1) ? &valor1A : &valor1B;
        float *v2 = (i == 1) ? &valor2A : &valor2B;
        char *nome = (i == 1) ? nomeA1 : nomeA2;

        switch (attr) {
            case 1:
                *v1 = populacao1;
                *v2 = populacao2;
                sprintf(nome, "População");
                break;
            case 2:
                *v1 = area1;
                *v2 = area2;
                sprintf(nome, "Área");
                break;
            case 3:
                *v1 = pib1;
                *v2 = pib2;
                sprintf(nome, "PIB");
                break;
            case 4:
                *v1 = pontosTuristicos1;
                *v2 = pontosTuristicos2;
                sprintf(nome, "Pontos Turísticos");
                break;
            case 5:
                *v1 = densidade1;
                *v2 = densidade2;
                sprintf(nome, "Densidade Demográfica");
                break;
        }
    }

    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Exibir resultados
    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");
    printf("Carta 1 - %s\n", nomeCidade1);
    printf("Carta 2 - %s\n\n", nomeCidade2);

    printf("Atributo 1: %s\n", nomeA1);
    printf("%s: %.2f\n", nomeCidade1, valor1A);
    printf("%s: %.2f\n\n", nomeCidade2, valor2A);

    printf("Atributo 2: %s\n", nomeA2);
    printf("%s: %.2f\n", nomeCidade1, valor1B);
    printf("%s: %.2f\n\n", nomeCidade2, valor2B);

    // Ajustar Densidade (MENOR vence): inverter valor comparado para soma
    if (atributo1 == 5) {
        soma1 -= 2 * valor1A;
        soma2 -= 2 * valor2A;
    }
    if (atributo2 == 5) {
        soma1 -= 2 * valor1B;
        soma2 -= 2 * valor2B;
    }

    printf("Soma ajustada dos atributos:\n");
    printf("%s: %.2f\n", nomeCidade1, soma1);
    printf("%s: %.2f\n", nomeCidade2, soma2);

    // Resultado final
    printf("\nResultado Final: ");
    printf((soma1 > soma2) ? "%s venceu!\n" :
           (soma2 > soma1) ? "%s venceu!\n" :
           "Empate!\n", (soma1 > soma2) ? nomeCidade1 : nomeCidade2);

    return 0;
}
