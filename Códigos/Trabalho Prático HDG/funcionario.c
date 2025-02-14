#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "arquivo.h"
#include "localeptbr.h"

// ===================== Função Auxiliar =====================
Funcionario *obterFuncionarioPorCodigo(Funcionario *funcionarios, int numFuncionarios, int codigo)
{
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (funcionarios[i].codigo == codigo)
        {
            return &funcionarios[i];
        }
    }
    return NULL; 
}

// ===================== Cadastro de Funcionário =====================
void cadastrarFuncionario(Funcionario *funcionarios, int *numFuncionarios)
{
    configurarLocale();

    Funcionario novoFuncionario;
    novoFuncionario.codigo = *numFuncionarios + 1;

    printf("\nDigite o nome do funcionário: ");
    fgets(novoFuncionario.nome, sizeof(novoFuncionario.nome), stdin);
    novoFuncionario.nome[strcspn(novoFuncionario.nome, "\n")] = '\0';

    printf("Digite o telefone do funcionário: ");
    fgets(novoFuncionario.telefone, sizeof(novoFuncionario.telefone), stdin);
    novoFuncionario.telefone[strcspn(novoFuncionario.telefone, "\n")] = '\0';

    printf("Digite o cargo do funcionário: ");
    fgets(novoFuncionario.cargo, sizeof(novoFuncionario.cargo), stdin);
    novoFuncionario.cargo[strcspn(novoFuncionario.cargo, "\n")] = '\0';

    printf("Digite o salário do funcionário: ");
    scanf("%f", &novoFuncionario.salario);
    getchar(); 

    funcionarios[*numFuncionarios] = novoFuncionario;
    (*numFuncionarios)++;

    salvarFuncionarios(funcionarios, *numFuncionarios);
    printf("\nFuncionário cadastrado com sucesso! Código: %d\n", novoFuncionario.codigo);
}

// ===================== Verificação de Funcionário =====================
bool verificarFuncionario(const Funcionario *funcionarios, int numFuncionarios, int codigo)
{
    return obterFuncionarioPorCodigo((Funcionario *)funcionarios, numFuncionarios, codigo) != NULL;
}

// ===================== Pesquisa de Funcionário =====================
void pesquisarFuncionario(const Funcionario *funcionarios, int numFuncionarios)
{
    configurarLocale();

    int opcao;
    printf("\nPesquisar por:\n");
    printf("1. Código do funcionário\n");
    printf("2. Nome do funcionário\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); 

    if (opcao == 1)
    {
        int codigo;
        printf("\nDigite o código do funcionário: ");
        scanf("%d", &codigo);
        getchar(); 

        Funcionario *funcionario = obterFuncionarioPorCodigo((Funcionario *)funcionarios, numFuncionarios, codigo);
        if (funcionario)
        {
            printf("\nFuncionário encontrado!\n");
            printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalário: R$%.2f\n",
                   funcionario->codigo, funcionario->nome, funcionario->telefone, funcionario->cargo, funcionario->salario);
        }
        else
        {
            printf("\nErro: Funcionário não encontrado!\n");
        }
    }
    else if (opcao == 2)
    {
        char nomeBusca[100];
        printf("\nDigite o nome do funcionário: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < numFuncionarios; i++)
        {
            if (strcmp(funcionarios[i].nome, nomeBusca) == 0)
            {
                printf("\nFuncionário encontrado!\n");
                printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalário: R$%.2f\n",
                       funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone,
                       funcionarios[i].cargo, funcionarios[i].salario);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("\nErro: Funcionário não encontrado!\n");
        }
    }
    else
    {
        printf("\nOpção inválida!\n");
    }
}
