#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"
#include "arquivo.h"
#include "localeptbr.h"

// ===================== Função Auxiliar =====================
Quarto *obterQuartoPorNumero(Quarto *quartos, int numQuartos, int numero)
{
    for (int i = 0; i < numQuartos; i++)
    {
        if (quartos[i].numero == numero)
        {
            return &quartos[i];
        }
    }
    return NULL;
}

// ===================== Cadastro de Quarto =====================
void cadastrarQuarto(Quarto *quartos, int *numQuartos)
{
    configurarLocale();

    Quarto novoQuarto;
    printf("\nDigite o número do quarto: ");
    scanf("%d", &novoQuarto.numero);
    getchar(); 

    if (verificarQuarto(quartos, *numQuartos, novoQuarto.numero))
    {
        printf("\nErro: O quarto já foi cadastrado!\n");
        return;
    }

    printf("Digite a quantidade de hóspedes: ");
    scanf("%d", &novoQuarto.qtd_hospedes);
    getchar();

    printf("Digite o valor da diária: ");
    scanf("%f", &novoQuarto.valor_diaria);
    getchar();

    novoQuarto.status = 0; 

    quartos[*numQuartos] = novoQuarto;
    (*numQuartos)++;

    salvarQuartos(quartos, *numQuartos);
    printf("\nQuarto cadastrado com sucesso! Número: %d\n", novoQuarto.numero);
}

// ===================== Verificação de Quarto =====================
bool verificarQuarto(const Quarto *quartos, int numQuartos, int numero)
{
    return obterQuartoPorNumero((Quarto *)quartos, numQuartos, numero) != NULL;
}
