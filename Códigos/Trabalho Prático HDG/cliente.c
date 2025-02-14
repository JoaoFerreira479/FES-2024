#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "arquivo.h"
#include "localeptbr.h"

// ===================== Função Auxiliar =====================
Cliente *obterClientePorCodigo(Cliente *clientes, int numClientes, int codigo)
{
    for (int i = 0; i < numClientes; i++)
    {
        if (clientes[i].codigo == codigo)
        {
            return &clientes[i];
        }
    }
    return NULL; 
}

// ===================== Cadastro de Cliente =====================
void cadastrarCliente(Cliente *clientes, int *numClientes)
{
    configurarLocale();

    Cliente novoCliente;
    novoCliente.codigo = *numClientes + 1;

    printf("\nDigite o nome do cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0'; 

    printf("Digite o endereço do cliente: ");
    fgets(novoCliente.endereco, sizeof(novoCliente.endereco), stdin);
    novoCliente.endereco[strcspn(novoCliente.endereco, "\n")] = '\0';

    printf("Digite o telefone do cliente: ");
    fgets(novoCliente.telefone, sizeof(novoCliente.telefone), stdin);
    novoCliente.telefone[strcspn(novoCliente.telefone, "\n")] = '\0';

    clientes[*numClientes] = novoCliente;
    (*numClientes)++;

    salvarClientes(clientes, *numClientes);
    printf("\nCliente cadastrado com sucesso! Código: %d\n", novoCliente.codigo);
}

// ===================== Verificação de Cliente =====================
bool verificarCliente(const Cliente *clientes, int numClientes, int codigo)
{
    return obterClientePorCodigo((Cliente *)clientes, numClientes, codigo) != NULL;
}

// ===================== Pesquisa de Cliente =====================
void pesquisarCliente(const Cliente *clientes, int numClientes)
{
    configurarLocale();

    int opcao;
    printf("\nPesquisar por:\n");
    printf("1. Código do cliente\n");
    printf("2. Nome do cliente\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); 

    if (opcao == 1)
    {
        int codigo;
        printf("\nDigite o código do cliente: ");
        scanf("%d", &codigo);
        getchar(); 

        Cliente *cliente = obterClientePorCodigo((Cliente *)clientes, numClientes, codigo);
        if (cliente)
        {
            printf("\nCliente encontrado!\n");
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
                   cliente->codigo, cliente->nome, cliente->endereco, cliente->telefone);
        }
        else
        {
            printf("\nErro: Cliente não encontrado!\n");
        }
    }
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("\nDigite o nome do cliente: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < numClientes; i++)
        {
            if (strcmp(clientes[i].nome, nomeBusca) == 0)
            {
                printf("\nCliente encontrado!\n");
                printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
                       clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("\nErro: Cliente não encontrado!\n");
        }
    }
    else
    {
        printf("\nOpção inválida!\n");
    }
}
