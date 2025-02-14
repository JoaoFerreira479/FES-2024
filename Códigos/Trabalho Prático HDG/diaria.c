#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "diaria.h"
#include "localeptbr.h"

// ===================== Função Auxiliar =====================
bool validarData(const char *data)
{
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/')
    {
        return false;
    }

    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        return false;
    }

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900)
    {
        return false;
    }

    return true;
}

// Converte string de data para struct tm (usado para calcular a diferença)
struct tm converterData(const char *data)
{
    struct tm dataConvertida = {0}; // Inicialização
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    dataConvertida.tm_mday = dia;
    dataConvertida.tm_mon = mes - 1;     // Meses começam do 0
    dataConvertida.tm_year = ano - 1900; // Anos começam de 1900
    return dataConvertida;
}

// ===================== Cálculo de Diárias =====================
int calcularDiarias(const char *data_entrada, const char *data_saida)
{
    configurarLocale();

    if (!validarData(data_entrada) || !validarData(data_saida))
    {
        printf("\nErro: Data inválida! Use o formato dd/mm/aaaa.\n");
        return -1;
    }

    struct tm entrada = converterData(data_entrada);
    struct tm saida = converterData(data_saida);

    time_t t_entrada = mktime(&entrada);
    time_t t_saida = mktime(&saida);

    if (t_saida <= t_entrada)
    {
        printf("\nErro: A data de saída deve ser após a data de entrada.\n");
        return -1;
    }

    // Calcula a diferença de dias corretamente
    double diferenca = difftime(t_saida, t_entrada) / (60 * 60 * 24);

    return (int)diferenca;
}
