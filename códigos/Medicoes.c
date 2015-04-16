#include "Medicoes.h"
#include "ShellSort.h"
#include "Insercao.h"

void inicializaDados(Dados *dados){
    dados->comparacoes = dados->copias = 0;
    return;    
}

void calculaTempo(int *vet, int tamVet, int script, Tempo *tempo){
    if(script == SHELLSORT){
        tempo->inicio = clock();
        shellSort(vet, tamVet);
        tempo->fim = clock();
        tempo->tempo_usado_cpu = ((double)(tempo->fim - tempo->inicio)) / 
                CLOCKS_PER_SEC;
    }
    else if(script == INSERCAO){
        tempo->inicio = clock();
        insercao(vet, tamVet);
        tempo->fim = clock();
        tempo->tempo_usado_cpu = ((double)(tempo->fim - tempo->inicio)) / 
                CLOCKS_PER_SEC;
    }
}

int *obtemDados(int *vet, int tamVet, const char *nomeArqEntrada, const char 
*nomeArqSaida, int script, int semente, Dados *dados, Tempo *tempo){
    inicializaDados(dados);
    vet = leituraArquivo(nomeArqEntrada, vet, tamVet);    
    calculaTempo(vet, tamVet, script, tempo);
    vet = leituraArquivo(nomeArqEntrada, vet, tamVet); 
    if(script == SHELLSORT){
        shellSortMedicao(vet, tamVet, dados);
        criaArquivoSaida(nomeArqSaida, semente, "ShellSort", tamVet, dados, tempo, 
            "Nao");
    }
    else{
        insercaoMedicao(vet, tamVet, dados);
        criaArquivoSaida(nomeArqSaida, semente, "Insercao", tamVet, dados, tempo, 
            "Nao");        
    }
    inicializaDados(dados);
    calculaTempo(vet, tamVet, script, tempo);
    if(script == SHELLSORT){
        shellSortMedicao(vet, tamVet, dados);  
        criaArquivoSaida(nomeArqSaida, semente, "ShellSort", tamVet, dados, tempo, 
            "Sim"); 
    }
    else{
        insercaoMedicao(vet, tamVet, dados);  
        criaArquivoSaida(nomeArqSaida, semente, "Insercao", tamVet, dados, tempo, 
            "Sim");   
    }
    return vet;
}