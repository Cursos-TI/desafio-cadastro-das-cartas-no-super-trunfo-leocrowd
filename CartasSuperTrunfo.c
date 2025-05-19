
#include <stdio.h>

int main() {
    // ----------VARIÁVEIS-----------
    // Carta 1
    char estado1; //Estado da cidade
    char codigo1[4]; //Código da carta
    char nomeCidade1[50]; //Nome da cidade
    unsigned long int populacao1; //População da cidade
    float area1; //Área da cidade
    float pib1; //Pib da cidade
    int pontosTuristicos1; //Quantidade de pontos turísticos da cidade
    float densidade1;
    float pibPerCapita1;
    float superPoder1;
    

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;


    // ----------ENTRADA DE DADOS CARTA 1----------
    printf("Digite os dados da Carta 1:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // O %[^\n] lê tudo até o Enter.

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // ----------ENTRADA DE DADOS CARTA 2----------
    printf("\nDigite os dados da Carta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2); 

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ----------CÁLCULOS----------
    densidade1 = populacao1 / area1; //Cálculo para saber a densidade da cidade, dividindo população pela área.
    pibPerCapita1 = pib1 / populacao1; ////Cálculo para saber o Pib per capita da cidade, dividindo o pib pela população.

    densidade2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;
    
    superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // ----------SAÍDA DE DADOS----------
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // ----------COMPARAÇÃO----------
    printf("\nComparação de cartas (Atributo: Área):\n");
    printf("Carta 1 - %.2f km²\n", area1);
    printf("Carta 2 - %.2f km²\n", area2);

    if (area1 > area2)
        printf("Resultado: Carta 1 venceu!\n");
    else if (area2 > area1)
        printf("Resultado: Carta 2 venceu!\n");
    else
        printf("Resultado: Empate!\n");

    return 0;
}
