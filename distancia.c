#include <stdlib.h>
#include <stdio.h>
#include "distancia.h"


struct distancia
{
    Ponto* p1;
    Ponto* p2;
    double dist;
};

Distancia* initVetDistancia(int n){
    int tam = ((n-1) * n)/2;
    Distancia* vetdist = (Distancia*) malloc (sizeof(Distancia) * tam);

    return vetdist;       
}

Distancia* initDistancia(Ponto* p1, Ponto* p2){
    double dist = calculaDistanciaEntrePontos(p1, p2);

    Distancia* distancia = (Distancia*) malloc (sizeof(Distancia));

    distancia->p1 = p1;
    distancia->p2 = p2;
    distancia->dist = dist;

    return distancia;
}

void liberaDistancia(Distancia* vetDistancia){
    for (int i = 0; i < tam; i++)
    {
        
    }
    
}