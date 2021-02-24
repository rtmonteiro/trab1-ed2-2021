//
// Created by Pichau on 24/02/2021.
//

#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct Ponto {
    int pos;
    char *id;
    double *coords;
};

ponto *initPonto(char *id, double *coords, int pos){
    ponto *new = (ponto *) malloc(sizeof(ponto));
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
double calculaDistanciaEntrePontos(ponto *p1, ponto *p2, int m) {
    double sum;
    for (int i = 0; i < m; ++i) {
        sum += pow((p1->coords[i] - p2->coords[i]), 2);
    }
    return sqrt(sum);
}



