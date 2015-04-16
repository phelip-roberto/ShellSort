/* 
 * File:   Medicoes.h
 * Author: igor
 *
 * Created on 11 de Abril de 2015, 02:07
 */

#ifndef MEDICOES_H
#define	MEDICOES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SHELLSORT 1
#define INSERCAO 2

typedef struct{
    unsigned long long int comparacoes, copias; 
}Dados;

typedef struct{
    clock_t inicio, fim;
    double tempo_usado_cpu;
}Tempo;

void inicializaDados(Dados *dados);
void calculaTempo(int *vet, int tamVet, int script, Tempo *tempo);
int *obtemDados(int *vet, int tamVet, const char *nomeArqEntrada, const char 
*nomeArqSaida, int script, int semente, Dados *dados, Tempo *tempo);

#endif	/* MEDICOES_H */

