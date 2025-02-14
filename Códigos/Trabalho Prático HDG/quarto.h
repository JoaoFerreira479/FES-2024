#ifndef QUARTO_H
#define QUARTO_H

#include <stdbool.h> 

typedef struct
{
    int numero;
    int qtd_hospedes;
    float valor_diaria;
    int status; // 0 = desocupado, 1 = ocupado
} Quarto;

// Funções para manipulação de quartos
void cadastrarQuarto(Quarto *quartos, int *numQuartos);
bool verificarQuarto(const Quarto *quartos, int numQuartos, int numero);
Quarto *obterQuartoPorNumero(Quarto *quartos, int numQuartos, int numero);

#endif
