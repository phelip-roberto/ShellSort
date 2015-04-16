#include "ShellSort.h"

void shellSort(int *vet, int tamVet) {
    int i , j , valor;
    int intervalo = 1;
    while(intervalo < tamVet) {
        intervalo = 3*intervalo+1;
    }
    while (intervalo > 1) {
        intervalo /= 3;
        for(i = intervalo; i < tamVet; i++) {
            valor = vet[i];
            j = i - intervalo;
            while (j >= 0 && valor < vet[j]) {
                vet [j + intervalo] = vet[j];
                j -= intervalo;
            }
            vet [j + intervalo] = valor;
        }
    }
}

void shellSortMedicao(int *vet, int tamVet, Dados *dados) {
    int i , j , valor;
    int intervalo = 1;
    while(intervalo < tamVet) {
        intervalo = 3*intervalo+1;
    }
    while (intervalo > 1) {
        intervalo /= 3;
        for(i = intervalo; i < tamVet; i++) {
            valor = vet[i];
            j = i - intervalo;
            while (j >= 0 && valor < vet[j]) {
                dados->comparacoes = dados->comparacoes + 1;
                vet [j + intervalo] = vet[j];
                dados->copias = dados->copias + 1;
                j -= intervalo;
            }
            if(j >= 0){
                dados->comparacoes = dados->comparacoes + 1;
            }
            vet [j + intervalo] = valor;
            dados->copias = dados->copias + 1;
        }
    }
}

void imprimeVet(int *vet, int tamVet){
    int i;
    for(i = 0; i < tamVet; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
    return;
}

