#include <stdlib.h>
#include "ponto.h"
#include "distancia.h"
#include "planoR.h"

// Define o tipo opaco PlanoR
struct planoR{
    Ponto** pontos;
    int dim;
    int qtd;
};

PlanoR* initPlanoRVazio () {
    PlanoR* novo = (PlanoR*) malloc (sizeof(PlanoR));
    novo->pontos = NULL; 
    novo->qtd = novo->qtd = 0;

    return novo;
}

void initVetorPontos (PlanoR* plano, int N, int M) {
    plano->pontos = (Ponto**) malloc (sizeof(Ponto*) * N);
    plano->qtd = N;
    plano->dim = M;
}

void insere (PlanoR* plano, Ponto* ponto, int i) {
    plano->pontos[i] = ponto;
}

Distancia** distanciasPontos (PlanoR* plano) {
    Distancia** dist = initVetDistancia(plano->qtd);
    int i = 0;

    // Percore pilha de forma que ponto1 é sempre diferente de ponto2 
    // ponto2 eh o ponto apos ponto1
    for(int ponto1 = 0; i < plano->qtd; ponto1++) {
        for (int ponto2 = ponto1 + 1; ponto2 < plano->qtd; ponto2++, i++) {
            // Calcula a distancia entre ponto1 e ponto2 e armazena num vetor
            dist[i] = initDistancia(plano->pontos[ponto1], plano->pontos[ponto2], plano->dim);
        }
    }

    ordenaVetDistancia(dist, plano->qtd);

    return dist;
}

int getQtd(PlanoR* plano) {
    return plano->qtd;
}

void setQtd(PlanoR* plano, int N) {
    plano->qtd = N;
}

int getDimensao(PlanoR* plano) {
    return plano->dim;
}

void setDimensao(PlanoR* plano, int M) {
    plano->dim = M;
}

void liberaPlano (PlanoR* plano) {
    for (int i = 0; i < plano->qtd; i++) {
        liberaPonto(plano->pontos[i]);
    }
    
    free(plano->pontos);
    free(plano);
}