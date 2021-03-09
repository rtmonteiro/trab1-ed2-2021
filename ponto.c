#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    int raiz; // raiz do ponto, usado no uf
    char *id; // id do ponto
    double *coords; // coordenadas do ponto
};

Ponto* initPonto(char *id, double *coords, int raiz){
    Ponto* novo = (Ponto*) malloc(sizeof(Ponto));
    novo->id = id;
    novo->raiz = raiz;
    novo->coords = coords;

    return novo;
}

double calculaDistanciaEntrePontos(Ponto* p1, Ponto* p2, int m) {
    double sum = 0;
    for (int i = 0; i < m; i++) {
        // Soma o quadrado das diferencas das coordenadas dos dois pontos
        sum += pow((p1->coords[i] - p2->coords[i]), 2);
    }
    return sqrt(sum);
}

void setRaizPonto(Ponto* p, int raiz) {
    p->raiz = raiz;
}

int getRaizPonto(Ponto* p) {
    return p->raiz;
}

char* getIdPonto(Ponto* p) {
    return p->id;
}

void liberaPonto(Ponto* p) {
    free(p->id);
    free(p->coords);
    free(p);
}
