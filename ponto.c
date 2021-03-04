#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    int indice; // indice do ponto na pilha
    char *id; // id do ponto
    double *coords; // coordenadas do ponto
};


Ponto* initPonto(char *id, double *coords, int indice){
    Ponto* new = (Ponto*) malloc(sizeof(Ponto));
    new->id = id;
    new->indice = indice;
    new->coords = coords;

    return new;
}


double calculaDistanciaEntrePontos(Ponto* p1, Ponto* p2, int m) {
    double sum = 0;
    for (int i = 0; i < m; i++) {
        sum += pow((p1->coords[i] - p2->coords[i]), 2);
    }
    return sqrt(sum);
}


int getIndice(Ponto* p) {
    return p->indice;
}

char* getIdPonto(Ponto* p) {
    return p->id;
}

void liberaPonto(Ponto* p) {
    free(p->id);
    free(p->coords);
    free(p);
}
