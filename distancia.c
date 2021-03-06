#include <stdlib.h>
#include <stdio.h>
#include "distancia.h"
#include "uf.h"

struct distancia {
    Ponto* p1;
    Ponto* p2;
    double dist; // distancia entre os pontos
};

void print(Distancia** vet, int n) {
    // int tam = ((n-1) * n)/2;

    for (int i = 0; i < n; i++)
    {
        printf("%lf ", vet[i]->dist);
    }
    printf("\n");
}

void ordenaVetDistancia(Distancia** vetDist, int n) {
    int tam = ((n-1) * n)/2;
    qsort(vetDist, tam, sizeof(Distancia*), comparaDistancia);
}

Distancia** initVetDistancia(int n) {
    int tam = ((n-1) * n)/2;
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
    int id1 = getIndice(distancia->p1);
    int id2 = getIndice(distancia->p2);
    if(!conectado(uf, id1, id2)) {
        //printf("\nPontos: %s e %s\n", getIdPonto(distancia->p1), getIdPonto(distancia->p2));
        criaUniao(uf, id1, id2);
        return 1;
    }

    return 0;
}

void agrupaCaminhos (UF* uf, Distancia** vetDistancia, int n, int tamPA, int k) {
    int caminhos = 0;
    for (int i = 0; i < tamPA - 1 && caminhos < n - k; i++) {
        caminhos += agrupaCaminhoPontos(uf, vetDistancia[i], i);
    }
}

void liberaDistancia(Distancia** vetDistancia, int n) {
    int tam = ((n-1) * n)/2;

    for (int i = 0; i < tam; i++) {
        free(vetDistancia[i]);
    }

    free(vetDistancia);
}
