#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

struct ponto {
    int raiz; // raiz do ponto, usado no uf
    char *id; // id do ponto
    double *coords; // coordenadas do ponto
};

Ponto* initPonto(char *id, double *coords, int raiz) {
    Ponto* novo = (Ponto*) malloc(sizeof(Ponto));
    novo->id = id;
    novo->raiz = raiz;
    novo->coords = coords;

    return novo;
}

double calculaDistanciaEntrePontos(Ponto* p1, Ponto* p2, int m) {
    double sum = 0, dif;
    for (int i = 0; i < m; i++) {
        dif = p1->coords[i] - p2->coords[i];
        // Soma o quadrado das diferencas das coordenadas dos dois pontos
        sum += (dif * dif);
    }
    return sqrt(sum);
}

int comparaId(const void* p1, const void* p2) {
    const Ponto* pri = *(const Ponto**) p1;
    const Ponto* seg = *(const Ponto**) p2;
    
    return strcmp(pri->id, seg->id);
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
