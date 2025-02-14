#include <stdio.h>
#include <stdlib.h>
#include "localeptbr.h"
#include "cliente.h"
#include "funcionario.h"
#include "estadia.h"
#include "quarto.h"
#include "arquivo.h"

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 100
#define MAX_ESTADIAS 100
#define MAX_QUARTOS 100

// ===================== Função Genérica para Exibir Menus =====================
void exibirMenu(const char *titulo, const char *opcoes[], int numOpcoes)
{
    printf("\n-------- %s --------\n", titulo);
    for (int i = 0; i < numOpcoes; i++)
    {
        printf("%s\n", opcoes[i]);
    }
    printf("\nEscolha uma opção: ");
}

// ===================== Menu Principal =====================
void menuPrincipal()
{
    const char *opcoes[] = {
        "1. Gerenciar Clientes",
        "2. Gerenciar Funcionários",
        "3. Gerenciar Estadias",
        "4. Gerenciar Quartos",
        "0. Sair"};
    exibirMenu("Hotel Descanso Garantido", opcoes, 5);
}

// ===================== Menu Clientes =====================
void menuClientes()
{
    const char *opcoes[] = {
        "1. Cadastrar Cliente",
        "2. Pesquisar Cliente",
        "0. Voltar"};
    exibirMenu("Menu Clientes", opcoes, 3);
}

// ===================== Menu Funcionários =====================
void menuFuncionarios()
{
    const char *opcoes[] = {
        "1. Cadastrar Funcionário",
        "2. Pesquisar Funcionário",
        "0. Voltar"};
    exibirMenu("Menu Funcionários", opcoes, 3);
}

// ===================== Menu Estadias =====================
void menuEstadias()
{
    const char *opcoes[] = {
        "1. Cadastrar Estadia",
        "2. Dar Baixa na Estadia",
        "3. Mostrar Estadias por Cliente",
        "4. Calcular Pontos de Fidelidade",
        "0. Voltar"};
    exibirMenu("Menu Estadias", opcoes, 5);
}

// ===================== Menu Quartos =====================
void menuQuartos()
{
    const char *opcoes[] = {
        "1. Cadastrar Quarto",
        "0. Voltar"};
    exibirMenu("Menu Quartos", opcoes, 2);
}

// ===================== Função Principal =====================
int main()
{
    configurarLocale();

    // Estruturas de dados
    Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;
    Estadia estadias[MAX_ESTADIAS];
    int numEstadias = 0;
    Quarto quartos[MAX_QUARTOS];
    int numQuartos = 0;

    // Carregar dados do arquivo
    carregarClientes(clientes, &numClientes);
    carregarFuncionarios(funcionarios, &numFuncionarios);
    carregarEstadias(estadias, &numEstadias);
    carregarQuartos(quartos, &numQuartos);

    int opcao;
    do
    {
        menuPrincipal();
        if (scanf("%d", &opcao) != 1)
        {
            printf("\nEntrada inválida! Por favor, escolha uma opção numérica.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcao)
        {
        case 1:
        {
            int opcaoClientes;
            do
            {
                menuClientes();
                if (scanf("%d", &opcaoClientes) != 1)
                {
                    printf("\nEntrada inválida! Por favor, escolha uma opção numérica.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                switch (opcaoClientes)
                {
                case 1:
                    cadastrarCliente(clientes, &numClientes);
                    break;
                case 2:
                    pesquisarCliente(clientes, numClientes);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpção inválida!\n");
                }
            } while (opcaoClientes != 0);
            break;
        }

        case 2:
        {
            int opcaoFuncionarios;
            do
            {
                menuFuncionarios();
                if (scanf("%d", &opcaoFuncionarios) != 1)
                {
                    printf("\nEntrada inválida! Por favor, escolha uma opção numérica.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                switch (opcaoFuncionarios)
                {
                case 1:
                    cadastrarFuncionario(funcionarios, &numFuncionarios);
                    break;
                case 2:
                    pesquisarFuncionario(funcionarios, numFuncionarios);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpção inválida!\n");
                }
            } while (opcaoFuncionarios != 0);
            break;
        }

        case 3:
        {
            int opcaoEstadias;
            do
            {
                menuEstadias();
                if (scanf("%d", &opcaoEstadias) != 1)
                {
                    printf("\nEntrada inválida! Por favor, escolha uma opção numérica.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                switch (opcaoEstadias)
                {
                case 1:
                    cadastrarEstadia(clientes, numClientes, quartos, numQuartos, estadias, &numEstadias);
                    break;
                case 2:
                    darBaixaEstadia(estadias, &numEstadias, quartos, numQuartos);
                    break;
                case 3:
                    mostrarEstadiasCliente(clientes, numClientes, estadias, numEstadias);
                    break;
                case 4:
                    calcularPontosFidelidade(clientes, numClientes, estadias, numEstadias);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpção inválida!\n");
                }
            } while (opcaoEstadias != 0);
            break;
        }

        case 4:
        {
            int opcaoQuartos;
            do
            {
                menuQuartos();
                if (scanf("%d", &opcaoQuartos) != 1)
                {
                    printf("\nEntrada inválida! Por favor, escolha uma opção numérica.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                switch (opcaoQuartos)
                {
                case 1:
                    cadastrarQuarto(quartos, &numQuartos);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpção inválida!\n");
                }
            } while (opcaoQuartos != 0);
            break;
        }

        case 0:
            salvarClientes(clientes, numClientes);
            salvarFuncionarios(funcionarios, numFuncionarios);
            salvarEstadias(estadias, numEstadias);
            salvarQuartos(quartos, numQuartos);
            printf("\nSaindo do programa...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
