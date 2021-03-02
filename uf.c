#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"

struct uf {
    int *id;
    int *tam;
    int N;
};

UF* unionFindInit (int N) {
    UF *id = (UF*) malloc (sizeof(UF));
    id->N = N;
    
    id->id = (int*) malloc (sizeof(int) * N);
    id->tam = (int*) malloc (sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        id->id[i] = i;
        id->tam[i] = 1;
    }

    return id;
}

int getID (UF *id, int i) {
    return id->id[i];
}

void setID (UF* id, int i, int j) {
    id->id[i] = j;
}

int getTamArv (UF* id, int i) {
    return id->tam[i];
}

void aumentaTam(UF* id, int i, int j) {
    id->tam[i] += id->tam[j];
}

int getRaiz (UF *id, int i) {
    while (getID(id, i) != i)  {
        i = getID(id, i);
    }

    return i;
}

int find(UF* id, int p, int q) {
    return getRaiz(id, p) == getRaiz(id, q);   
}

void criaUniao(UF* id, int p, int q) {
    int i = getRaiz(id, p);
    int j = getRaiz(id, q);

    if (getTamArv(id, p) < getTamArv(id, q)) {
        putID(id, i, j);
        aumentaTamArv(id, j, i);
    } else {
        setID(id, j, i);
        aumentaTamArv(id, i, j);
    }
}

int todosObjetosConectados(UF* id) {
    for (int i = 0; i < id->N - 1; i++) {
        if (getRoot(id, i) != getRoot(id, i+1)) 
            return 0;
    }

    return 1;
}

void mostraUnionFind (UF* id) {
    for (int i = 0; i < id->N; i++){
        printf("%d ", getID(id, i));
    }

    printf("\n");
}

void liberaUnionFind(UF* id) {
    free(id->id);
    free(id);
}