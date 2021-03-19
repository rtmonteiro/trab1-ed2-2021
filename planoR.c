#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ponto.h"
#include "distancia.h"
#include "planoR.h"

// Define o tipo opaco planoR
struct planoR{
    Ponto** pontos; // vetor de pontos
    int dim; // dimensao dos pontos
    int qtd; // quantidade de pontos no vetor
};

PlanoR* initPlanoR(int N, int M) {
    // Plano vazio, com vetor de pontos = NULL
    PlanoR* novo = (PlanoR*) malloc (sizeof(PlanoR));
    novo->pontos = (Ponto**) malloc (sizeof(Ponto*) * N);
    novo->qtd = N;
    novo->dim = M;

    return novo;
}

void insere(PlanoR* plano, Ponto* ponto, int i) {
    plano->pontos[i] = ponto;
}

Distancia** distanciasPontos(PlanoR* plano, int tam) {
    Distancia** dist = initVetDistancia(tam);
    int i = 0;

    // Percore vetor de forma que ponto1 eh sempre diferente de ponto2
    // ponto2 eh o ponto apos ponto1
    for(int ponto1 = 0; ponto1 < plano->qtd; ponto1++) {
        for (int ponto2 = ponto1 + 1; ponto2 < plano->qtd; ponto2++, i++) {
            // Calcula a distancia entre ponto1 e ponto2 e armazena num vetor
            dist[i] = initDistancia(plano->pontos[ponto1], plano->pontos[ponto2], plano->dim);
        }
    }

    // chama funcao que ordena vetor de distancia
    ordenaVetDistancia(dist, plano->qtd);

    return dist;
}

Ponto** getPontos(PlanoR* plano) {
    return plano->pontos;
}

void liberaPlano(PlanoR* plano) {
    for (int i = 0; i < plano->qtd; i++) {
        liberaPonto(plano->pontos[i]);
    }
    
    free(plano->pontos);
    free(plano);
}
