#include <locale.h>
#include <stdio.h>
#include "localeptbr.h"

void configurarLocale()
{
    if (setlocale(LC_ALL, "Portuguese_Brazil") == NULL)
    {
        printf("Erro: Não foi possível configurar o locale para Português do Brasil.\n");
    }
}
