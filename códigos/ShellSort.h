/* 
 * File:   ShellSort.h
 * Author: igor
 *
 * Created on 11 de Abril de 2015, 01:34
 */

#ifndef SHELLSORT_H
#define	SHELLSORT_H

#include <stdio.h>
#include <stdlib.h>
#include "Medicoes.h"

void shellSort(int *vet, int tamVet);
void shellSortMedicao(int *vet, int tamVet, Dados *dados);
void imprimeVet(int *vet, int tamVet);

#endif	/* SHELLSORT_H */

