#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    int pos;
    char *id;
    double *coords;
};

Ponto* initPonto(char *id, double *coords, int pos){
    Ponto* new = (Ponto*) malloc(sizeof(Ponto));
    new->id = id;
    new->pos = pos;
    new->coords = coords;

    return new;
}

/**
 * @param p1
 * @param p2
 * @param m
 * @example https://en.wikipedia.org/wiki/Euclidean_distance
 * @return distancia entre pontos em Rm
 */

double calculaDistanciaEntrePontos(Ponto* p1, Ponto* p2, int m) {
    double sum;
    for (int i = 0; i < m; ++i) {
        sum += pow((p1->coords[i] - p2->coords[i]), 2);
    }
    return sqrt(sum);
}



