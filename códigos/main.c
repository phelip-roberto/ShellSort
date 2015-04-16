/* 
 * File:   main.c
 * Author: igor
 *
 * Created on 10 de Abril de 2015, 02:37
 */

#include <stdio.h>
#include <stdlib.h>

#include "EntradaSaida.h"
#include "Medicoes.h"
#include "ShellSort.h"
#include "Insercao.h"

#define N50 50
#define N1K 1000
#define N50K 50000
#define N500K 500000
/*
 * 
 */

int main(int argc, char** argv) {
    if(argc != 4){
        printf("[Uso]: %s <semente> <arquivoEntrada.txt> <arquivoSaida.txt>\n", 
                argv[0]);
        return;
    }
    srand(atoi(argv[1]));
    int *vet;
    Dados dados;
    Tempo tempo;  
    vet = (int*)calloc(N500K, sizeof(int));   
    if(!vet){
        printf("[Erro]: Nao foi possivel alocar memoria!\n");
        return;
    }
    criaArquivoEntrada(argv[2], N500K);    
    
    vet = obtemDados(vet, N50, argv[2], argv[3], SHELLSORT, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N1K, argv[2], argv[3], SHELLSORT, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N50K, argv[2], argv[3], SHELLSORT, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N500K, argv[2], argv[3], SHELLSORT, atoi(argv[1]), &dados,
            &tempo);
    
    vet = obtemDados(vet, N50, argv[2], argv[3], INSERCAO, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N1K, argv[2], argv[3], INSERCAO, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N50K, argv[2], argv[3], INSERCAO, atoi(argv[1]), &dados,
            &tempo);
    vet = obtemDados(vet, N500K, argv[2], argv[3], INSERCAO, atoi(argv[1]), &dados,
            &tempo);
    
    free(vet);   

    return (EXIT_SUCCESS);
}

