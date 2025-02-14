#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdbool.h> 

typedef struct
{
    int codigo;
    char nome[100];
    char telefone[15];
    char cargo[50];
    float salario;
} Funcionario;

// Funções para manipulação de funcionários
void cadastrarFuncionario(Funcionario *funcionarios, int *numFuncionarios);
bool verificarFuncionario(const Funcionario *funcionarios, int numFuncionarios, int codigo);
void pesquisarFuncionario(const Funcionario *funcionarios, int numFuncionarios);
Funcionario *obterFuncionarioPorCodigo(Funcionario *funcionarios, int numFuncionarios, int codigo);

#endif
