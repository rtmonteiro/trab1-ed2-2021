#include <stdlib.h>
#include <stdio.h>
#include "distancia.h"
#include <time.h>
#include "uf.h"

struct distancia {
    Ponto* p1;
    Ponto* p2;
    double dist; // distancia entre os pontos
};


void ordenaVetDistancia(Distancia** vetDist, int n) {
    int tam = ((n-1) * n)/2;

    // ordena o vetor de forma crescente de acordo com as distancias
    qsort(vetDist, tam, sizeof(Distancia*), comparaDistancia);
}

Distancia** initVetDistancia(int tam) {
    Distancia** vetdist = (Distancia**) malloc (sizeof(Distancia*) * tam);

    return vetdist;       
}

Distancia* initDistancia(Ponto* p1, Ponto* p2, int m) {
    double dist = calculaDistanciaEntrePontos(p1, p2, m);

    Distancia* distancia = (Distancia*) malloc (sizeof(Distancia));

    distancia->p1 = p1;
    distancia->p2 = p2;
    distancia->dist = dist;

    return distancia;
}

int comparaDistancia(const void* d1, const void* d2) {
    const Distancia* pri = *(const Distancia**) d1;
    const Distancia* seg = *(const Distancia**) d2;
    return (pri->dist > seg->dist) - (pri->dist < seg->dist);
}

static int agrupaCaminhoPontos (UF* uf, Distancia* distancia, int n) {
    int id1 = getRaizPonto(distancia->p1);
    int id2 = getRaizPonto(distancia->p2);
    return criaUniao(uf, id1, id2);
}

void agrupaCaminhos (UF* uf, Distancia** vetDistancia, int n, int tamPA, int k) {
    int caminhos = 0;
    clock_t start_t, end_t;

    start_t = clock();
    // Rodando o vetor de distancias e criand n-k conexoes nos pontos de uf
    for (int i = 0; i < tamPA - 1 && caminhos < n - k; i++) {
        caminhos += agrupaCaminhoPontos(uf, vetDistancia[i], i);
    }
    end_t = clock();

    printf("MST = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

    start_t = clock();
    // Forçando path comprassion no vetor de pontos de uf
    for (int i = 0; i < n; i++) {
        getRaiz(uf, i);
    }
    end_t = clock();
    printf("Identificação dos caminhos = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

}

void liberaDistancia(Distancia** vetDistancia, int tam) {
    for (int i = 0; i < tam; i++) {
        free(vetDistancia[i]);
    }

    free(vetDistancia);
}

void imprimeVetDist(Distancia** vet, int n) {
    // Função auxiliar usada para analisar a comparação e ordenação
    for (int i = 0; i < n; i++) {
        printf("p1 %d p2 %d %lf\n", getRaizPonto(vet[i]->p1), getRaizPonto(vet[i]->p2), vet[i]->dist);
    }
    printf("\n");
}