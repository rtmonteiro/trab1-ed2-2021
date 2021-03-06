#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"

struct uf {
    int *id;
    int *alturas;
    int N;
};

UF* initUnionFind(int N) {
    UF *id = (UF*) malloc (sizeof(UF));
    id->N = N;
    
    id->id = (int*) malloc (sizeof(int) * N);
    id->alturas = (int*) malloc (sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        id->id[i] = i;
        id->alturas[i] = 1;
    }

    return id;
}

int getID(UF *id, int i) {
    return id->id[i];
}

void setID(UF* id, int i, int j) {
    id->id[i] = j;
}

int getAltura(UF* id, int i) {
    return id->alturas[i];
}

void aumentaAlturas(UF* id, int i, int j) {
    id->alturas[i] += id->alturas[j];
}

int getRaiz(UF *id, int i) {
    int raiz = i;
    while (raiz != getID(id, raiz)) {
        raiz = getID(id, raiz);
    }
    while (i != raiz)  {
        int prox = getID(id, i);
        setID(id, i, raiz);
        i = prox;
    }

    return raiz;
}

int conectado(UF* id, int p, int q) {
    return getRaiz(id, p) == getRaiz(id, q);
}

int criaUniao(UF* id, int p, int q) {
    int i = getRaiz(id, p);
    int j = getRaiz(id, q);
    //printf("\nPontos: %s e %s\n", getIdPonto(distancia->p1), getIdPonto(distancia->p2));
    if (i == j) return 0;
    //printf("\nindices| %d - %d |\n", i, j);
    //printf("alturas| %d - %d |\n\n", getAltura(id, i), getAltura(id, j));
    if (getAltura(id, p) < getAltura(id, q)) {
        setID(id, i, j);
        aumentaAlturas(id, j, i);
    } else {
        setID(id, j, i);
        aumentaAlturas(id, i, j);
    }
    return 1;
}

int todosObjetosConectados(UF* id) {
    for (int i = 0; i < id->N - 1; i++) {
        if (!conectado(id, i, i+1))
            return 0;
    }

    return 1;
}

void mostraUnionFind(UF* id) {
    for (int i = 0; i < id->N; i++){
        printf("%d ", getID(id, i));
    }

    printf("\n");
}

void liberaUnionFind(UF* id) {
    free(id->id);
    free(id->alturas);
    free(id);
}
