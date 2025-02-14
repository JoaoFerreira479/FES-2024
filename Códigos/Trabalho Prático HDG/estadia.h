#ifndef ESTADIA_H
#define ESTADIA_H

#include "cliente.h"
#include "quarto.h"
#include "diaria.h"
#include <stdbool.h>

typedef struct
{
    int codigo;
    int codigo_cliente;
    int numero_quarto;
    char data_entrada[11];
    char data_saida[11];
    int qtd_diarias;
} Estadia;

// Funções para manipulação de estadias
void cadastrarEstadia(Cliente *clientes, int numClientes, Quarto *quartos, int numQuartos, Estadia *estadias, int *numEstadias);
void darBaixaEstadia(Estadia *estadias, int *numEstadias, Quarto *quartos, int numQuartos);
void mostrarEstadiasCliente(const Cliente *clientes, int numClientes, const Estadia *estadias, int numEstadias);
void calcularPontosFidelidade(const Cliente *clientes, int numClientes, const Estadia *estadias, int numEstadias);

// Verifica se um quarto já está ocupado no período desejado
bool verificarSobreposicaoEstadia(const Estadia *estadias, int numEstadias, int numero_quarto, const char *data_entrada, const char *data_saida);

#endif
