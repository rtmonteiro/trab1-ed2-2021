#include <stdlib.h>
#include <stdio.h>
#include "distancia.h"


struct distancia
{
    Ponto* p1;
    Ponto* p2;
    double dist; // distancia entre os pontos
};

size_t sizeOfDistancia() {
    return sizeof(Distancia);
}

void print(Distancia** vet, int n){
    // int tam = ((n-1) * n)/2;
    
    for (int i = 0; i < n; i++)
    {
        printf("%lf ", vet[i]->dist);
    }
    printf("\n");
}

void ordenaVetDistancia(Distancia** vetDist, int n){
    int tam = ((n-1) * n)/2;
    size_t size = sizeof(vetDist)/sizeof(Distancia*);
    print(vetDist, tam);
    printf("\n");
    qsort(vetDist, tam, sizeof(Distancia*), comparaDistancia);

    print(vetDist, tam);
}

Distancia** initVetDistancia(int n){
    int tam = ((n-1) * n)/2;
    Distancia** vetdist = (Distancia**) malloc (sizeof(Distancia*) * tam);

    return vetdist;       
}

Distancia* initDistancia(Ponto* p1, Ponto* p2, int m){
    double dist = calculaDistanciaEntrePontos(p1, p2, m);

    Distancia* distancia = (Distancia*) malloc (sizeof(Distancia));

    distancia->p1 = p1;
    distancia->p2 = p2;
    distancia->dist = dist;

    return distancia;
}

int comparaDistancia(const void* d1, const void* d2){
    const Distancia pri = *(const Distancia*) d1;
    const Distancia seg = *(const Distancia*) d2;

    if(pri.dist > seg.dist)
        return 1;
    return -1;
}

void liberaDistancia(Distancia** vetDistancia, int n){
    int tam = ((n-1) * n)/2;

    for (int i = 0; i < tam; i++)
    {
        free(vetDistancia[i]);
    }
    free(vetDistancia);
}


