#include "EntradaSaida.h"

void criaArquivoEntrada(const char *nomeArq, int tamArq){
    FILE *fp;
    if((fp = fopen(nomeArq, "r")) != NULL){
        return;
    }
    if((fp = fopen(nomeArq, "w")) == NULL){
        printf("Erro ao criar o arquivo %s\n", nomeArq);
        return;
    }
    int i;
    for(i = 0; i < tamArq; i++){
        fprintf(fp, "%d\n", rand());
    }
    fclose(fp);
    
    return;
}

int *leituraArquivo(const char *nomeArq, int *vet, int tamVet){
    FILE *fp;
    if((fp = fopen(nomeArq, "r")) == NULL){
        return NULL;
    }
    int i;
    vet = (int*)calloc(tamVet, sizeof(int));    
    for(i = 0; i < tamVet; i++){
        fscanf(fp, "%d\n", &vet[i]);
    }
    
    return vet;
 }

void criaArquivoSaida(const char *nomeArq, int semente, const char *nomeScript, 
        int tamVet, Dados *dados, Tempo *tempo, const char *vetOrd){
    FILE *fp;
    if((fp = fopen(nomeArq, "a")) == NULL){
        printf("Nao foi possivel criar o arquivo %s!\n", nomeArq);
        return;
    }
    fprintf(fp, "Semente utilizada: %d\n", semente);
    fprintf(fp, "Script utilizado: %s\n", nomeScript);
    fprintf(fp, "Tamanho do vetor: %d\n", tamVet);
    fprintf(fp, "Numero de comparacoes de chaves: %llu\n", dados->comparacoes);
    fprintf(fp, "Numero de copias de registro: %llu\n", dados->copias);
    fprintf(fp, "Vetor ordenado (pior caso): %s\n", vetOrd);
    fprintf(fp, "Tempo de processamento para a ordenacao: %.30f\n", tempo->
            tempo_usado_cpu);
    fprintf(fp, "\n\n");
    
    return;
}