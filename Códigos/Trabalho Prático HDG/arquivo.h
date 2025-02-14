#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "cliente.h"
#include "funcionario.h"
#include "estadia.h"
#include "quarto.h"

// Funções de manipulação de arquivos para Clientes
void carregarClientes(Cliente *clientes, int *numClientes);
void salvarClientes(const Cliente *clientes, int numClientes);

// Funções de manipulação de arquivos para Funcionários
void carregarFuncionarios(Funcionario *funcionarios, int *numFuncionarios);
void salvarFuncionarios(const Funcionario *funcionarios, int numFuncionarios);

// Funções de manipulação de arquivos para Estadias
void carregarEstadias(Estadia *estadias, int *numEstadias);
void salvarEstadias(const Estadia *estadias, int numEstadias);

// Funções de manipulação de arquivos para Quartos
void carregarQuartos(Quarto *quartos, int *numQuartos);
void salvarQuartos(const Quarto *quartos, int numQuartos);

#endif