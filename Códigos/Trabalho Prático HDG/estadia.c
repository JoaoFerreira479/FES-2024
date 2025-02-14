#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadia.h"
#include "arquivo.h"
#include "localeptbr.h"

// ===================== Verificação de Sobreposição =====================
bool verificarSobreposicaoEstadia(const Estadia *estadias, int numEstadias, int numero_quarto, const char *data_entrada, const char *data_saida)
{
    for (int i = 0; i < numEstadias; i++)
    {
        if (estadias[i].numero_quarto == numero_quarto)
        {
            // Verifica se há sobreposição das datas
            if (!(strcmp(data_saida, estadias[i].data_entrada) <= 0 || strcmp(data_entrada, estadias[i].data_saida) >= 0))
            {
                return true;
            }
        }
    }
    return false;
}

// ===================== Cadastro de Estadia =====================
void cadastrarEstadia(Cliente *clientes, int numClientes, Quarto *quartos, int numQuartos, Estadia *estadias, int *numEstadias)
{
    configurarLocale();

    int codigo_cliente, qtd_hospedes;
    char data_entrada[11], data_saida[11];

    printf("\nDigite o código do cliente: ");
    scanf("%d", &codigo_cliente);
    getchar(); 

    if (!verificarCliente(clientes, numClientes, codigo_cliente))
    {
        printf("\nErro: Cliente não encontrado!\n");
        return;
    }

    printf("Digite a quantidade de hóspedes: ");
    scanf("%d", &qtd_hospedes);
    getchar();

    printf("Digite a data de entrada (dd/mm/aaaa): ");
    fgets(data_entrada, sizeof(data_entrada), stdin);
    data_entrada[strcspn(data_entrada, "\n")] = '\0';

    printf("Digite a data de saída (dd/mm/aaaa): ");
    fgets(data_saida, sizeof(data_saida), stdin);
    data_saida[strcspn(data_saida, "\n")] = '\0';

    if (!validarData(data_entrada) || !validarData(data_saida))
    {
        printf("\nErro: Formato de data inválido!\n");
        return;
    }

    // Verifica disponibilidade do quarto
    int quarto_encontrado = -1;
    for (int i = 0; i < numQuartos; i++)
    {
        if (quartos[i].qtd_hospedes >= qtd_hospedes && quartos[i].status == 0 &&
            !verificarSobreposicaoEstadia(estadias, *numEstadias, quartos[i].numero, data_entrada, data_saida))
        {
            quarto_encontrado = quartos[i].numero;
            break;
        }
    }

    if (quarto_encontrado == -1)
    {
        printf("\nErro: Não há quartos disponíveis para o período selecionado!\n");
        return;
    }

    // Cria a estadia
    Estadia novaEstadia = {
        .codigo = *numEstadias + 1,
        .codigo_cliente = codigo_cliente,
        .numero_quarto = quarto_encontrado};
    strcpy(novaEstadia.data_entrada, data_entrada);
    strcpy(novaEstadia.data_saida, data_saida);
    novaEstadia.qtd_diarias = calcularDiarias(data_entrada, data_saida);

    estadias[*numEstadias] = novaEstadia;
    (*numEstadias)++;

    // Atualiza status do quarto para ocupado
    for (int i = 0; i < numQuartos; i++)
    {
        if (quartos[i].numero == quarto_encontrado)
        {
            quartos[i].status = 1;
            break;
        }
    }

    salvarEstadias(estadias, *numEstadias);
    salvarQuartos(quartos, numQuartos);
    printf("\nEstadia cadastrada com sucesso!\n");
}

// ===================== Dar Baixa em Estadia =====================
void darBaixaEstadia(Estadia *estadias, int *numEstadias, Quarto *quartos, int numQuartos)
{
    configurarLocale();
    int codigo_estadia;
    printf("\nDigite o código da estadia: ");
    scanf("%d", &codigo_estadia);
    getchar();

    for (int i = 0; i < *numEstadias; i++)
    {
        if (estadias[i].codigo == codigo_estadia)
        {
            int numero_quarto = estadias[i].numero_quarto;
            float valor_total = 0;

            for (int j = 0; j < numQuartos; j++)
            {
                if (quartos[j].numero == numero_quarto)
                {
                    valor_total = quartos[j].valor_diaria * estadias[i].qtd_diarias;
                    quartos[j].status = 0;
                    break;
                }
            }

            printf("Valor total a ser pago: R$%.2f\n", valor_total);

            // Remove estadia
            for (int j = i; j < *numEstadias - 1; j++)
            {
                estadias[j] = estadias[j + 1];
            }
            (*numEstadias)--;

            salvarEstadias(estadias, *numEstadias);
            salvarQuartos(quartos, numQuartos);
            printf("\nBaixa na estadia realizada com sucesso!\n");
            return;
        }
    }

    printf("\nErro: Estadia não encontrada!\n");
}

// ===================== Cálculo de Pontos de Fidelidade =====================
void calcularPontosFidelidade(const Cliente *clientes, int numClientes, const Estadia *estadias, int numEstadias)
{
    configurarLocale();
    int codigo_cliente;
    printf("\nDigite o código do cliente: ");
    scanf("%d", &codigo_cliente);
    getchar();

    if (!verificarCliente(clientes, numClientes, codigo_cliente))
    {
        printf("\nErro: Cliente não encontrado!\n");
        return;
    }

    int pontos = 0;
    for (int i = 0; i < numEstadias; i++)
    {
        if (estadias[i].codigo_cliente == codigo_cliente)
        {
            pontos += estadias[i].qtd_diarias * 10;
        }
    }

    printf("\nO cliente %d tem %d pontos de fidelidade.\n", codigo_cliente, pontos);
}
