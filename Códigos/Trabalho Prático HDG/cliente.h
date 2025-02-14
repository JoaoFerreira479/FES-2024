#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h> 

typedef struct
{
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[15];
} Cliente;

// Funções para manipulação de clientes
void cadastrarCliente(Cliente *clientes, int *numClientes);
bool verificarCliente(const Cliente *clientes, int numClientes, int codigo);
void pesquisarCliente(const Cliente *clientes, int numClientes);
Cliente *obterClientePorCodigo(Cliente *clientes, int numClientes, int codigo);

#endif
