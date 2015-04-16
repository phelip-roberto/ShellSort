#include "Insercao.h"
#include "Medicoes.h"

void insercao(int *vet, int tamVet){
    int marcador, pos, aux;
    for(marcador = 1; marcador<tamVet; marcador++){
        pos = marcador - 1;
        aux = vet[marcador];
        while((pos >= 0) && (aux < vet[pos])){
            vet[pos+1] = vet[pos];
            pos--;
        }
        vet[pos+1] = aux;
    }
    return;
}

void insercaoMedicao(int *vet, int tamVet, Dados *dados){
    int marcador, pos, aux;
    for(marcador = 1; marcador<tamVet; marcador++){
        pos = marcador - 1;
        aux = vet[marcador];
        while((pos >= 0) && (aux < vet[pos])){
            dados->comparacoes = dados->comparacoes + 1;
            vet[pos+1] = vet[pos];
            dados->copias = dados->copias + 1;
            pos--;
        }
        if(pos >= 0){
            dados->comparacoes = dados->comparacoes + 1;
        }
        vet[pos+1] = aux;
        dados->copias = dados->copias + 1;
    }
    return;
}
