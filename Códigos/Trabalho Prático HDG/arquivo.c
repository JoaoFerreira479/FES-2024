#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

// Função genérica para abrir arquivos e tratar erros
FILE *abrirArquivo(const char *nomeArquivo, const char *modo)
{
    FILE *file = fopen(nomeArquivo, modo);
    if (file == NULL)
    {
        perror("Erro ao abrir arquivo");
        return NULL;
    }
    return file;
}

// ================== MANIPULAÇÃO DE CLIENTES ==================
void carregarClientes(Cliente *clientes, int *numClientes)
{
    FILE *file = abrirArquivo("clientes.bin", "rb");
    if (!file)
    {
        *numClientes = 0;
        return;
    }
    fread(numClientes, sizeof(int), 1, file);
    fread(clientes, sizeof(Cliente), *numClientes, file);
    fclose(file);
}

void salvarClientes(const Cliente *clientes, int numClientes)
{
    FILE *file = abrirArquivo("clientes.bin", "wb");
    if (!file)
        return;
    fwrite(&numClientes, sizeof(int), 1, file);
    fwrite(clientes, sizeof(Cliente), numClientes, file);
    fclose(file);
}

// ================== MANIPULAÇÃO DE FUNCIONÁRIOS ==================
void carregarFuncionarios(Funcionario *funcionarios, int *numFuncionarios)
{
    FILE *file = abrirArquivo("funcionarios.bin", "rb");
    if (!file)
    {
        *numFuncionarios = 0;
        return;
    }
    fread(numFuncionarios, sizeof(int), 1, file);
    fread(funcionarios, sizeof(Funcionario), *numFuncionarios, file);
    fclose(file);
}

void salvarFuncionarios(const Funcionario *funcionarios, int numFuncionarios)
{
    FILE *file = abrirArquivo("funcionarios.bin", "wb");
    if (!file)
        return;
    fwrite(&numFuncionarios, sizeof(int), 1, file);
    fwrite(funcionarios, sizeof(Funcionario), numFuncionarios, file);
    fclose(file);
}

// ================== MANIPULAÇÃO DE ESTADIAS ==================
void carregarEstadias(Estadia *estadias, int *numEstadias)
{
    FILE *file = abrirArquivo("estadias.bin", "rb");
    if (!file)
    {
        *numEstadias = 0;
        return;
    }
    fread(numEstadias, sizeof(int), 1, file);
    fread(estadias, sizeof(Estadia), *numEstadias, file);
    fclose(file);
}

void salvarEstadias(const Estadia *estadias, int numEstadias)
{
    FILE *file = abrirArquivo("estadias.bin", "wb");
    if (!file)
        return;
    fwrite(&numEstadias, sizeof(int), 1, file);
    fwrite(estadias, sizeof(Estadia), numEstadias, file);
    fclose(file);
}

// ================== MANIPULAÇÃO DE QUARTOS ==================
void carregarQuartos(Quarto *quartos, int *numQuartos)
{
    FILE *file = abrirArquivo("quartos.bin", "rb");
    if (!file)
    {
        *numQuartos = 0;
        return;
    }
    fread(numQuartos, sizeof(int), 1, file);
    fread(quartos, sizeof(Quarto), *numQuartos, file);
    fclose(file);
}

void salvarQuartos(const Quarto *quartos, int numQuartos)
{
    FILE *file = abrirArquivo("quartos.bin", "wb");
    if (!file)
        return;
    fwrite(&numQuartos, sizeof(int), 1, file);
    fwrite(quartos, sizeof(Quarto), numQuartos, file);
    fclose(file);
}
