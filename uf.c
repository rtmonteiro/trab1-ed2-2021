#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"

struct uf {
    int *id;
    int *sz;
    int N;
};

UF* unionFindInit (int N) {
    UF *id = (UF*) malloc (sizeof(UF));
    id->N = N;
    
    id->id = (int*) malloc (sizeof(int) * N);
    id->sz = (int*) malloc (sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        id->id[i] = i;
        id->sz[i] = 1;
    }

    return id;
}

int getID (UF *id, int i) {
    return id->id[i];
}

void putID (UF* id, int i, int j) {
    id->id[i] = j;
}

int getSize (UF* id, int i) {
    return id->sz[i];
}

void increaseSize (UF* id, int i, int j) {
    id->sz[i] += id->sz[j];
}

int getRoot (UF *id, int i) {
    while (getID(id, i) != i)  {
        i = getID(id, i);
    }

    return i;
}

bool connected (UF* id, int p, int q) {
    return getRoot(id, p) == getRoot(id, q);   
}

void createUnion (UF* id, int p, int q) {
    int i = getRoot(id, p);
    int j = getRoot(id, q);

    if (getSize(id, p) < getSize(id, q)) {
        putID(id, i, j);
        increaseSize(id, j, i);
    } else {
        putID(id, j, i);
        increaseSize(id, i, j);
    }
}

bool allObjectsConnected (UF* id) {
    for (int i = 0; i < id->N - 1; i++) {
        if (getRoot(id, i) != getRoot(id, i+1)) 
            return false;
    }

    return true;
}

void showUnionFind (UF* id) {
    for (int i = 0; i < id->N; i++){
        printf("%d ", getID(id, i));
    }

    printf("\n");
}

void freeUnionFind(UF* id) {
    free(id->id);
    free(id);
}