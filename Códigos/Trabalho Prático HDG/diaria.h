#ifndef DIARIA_H
#define DIARIA_H

#include <stdbool.h> // Para retornar verdadeiro/falso

// Calcula a quantidade de diárias com base nas datas de entrada e saída
int calcularDiarias(const char *data_entrada, const char *data_saida);

// Valida se a data inserida está no formato correto (dd/mm/aaaa)
bool validarData(const char *data);

#endif
