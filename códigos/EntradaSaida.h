/* 
 * File:   EntradaSaida.h
 * Author: igor
 *
 * Created on 10 de Abril de 2015, 02:39
 */

#ifndef ENTRADASAIDA_H
#define	ENTRADASAIDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicoes.h"

void criaArquivoEntrada(const char *nomeArq, int tamArq);
int *leituraArquivo(const char *nomeArq, int *vet, int tamVet);
void criaArquivoSaida(const char *nomeArq, int semente, const char *nomeScript, 
        int tamVet, Dados *dados, Tempo *tempo, const char *vetOrd);

#endif	/* ENTRADASAIDA_H */

