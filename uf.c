#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"
#include "ponto.h"

struct uf {
    Ponto** id;
    int* tamanhos;
    int N;
};

UF* initUnionFind(Ponto** pontos, int N)  {
    UF *id = (UF*) malloc (sizeof(UF));
    id->N = N;
    
    id->id = pontos;
    id->tamanhos = (int*) malloc (sizeof(int) * N);

    // Inicializa o vetor de tamanhos
    for (int i = 0; i < N; i++) {
        setRaizPonto(id->id[i], i);
        id->tamanhos[i] = 1;
    }

    return id;
}

int getID(UF *id, int i) {
    return getRaizPonto(id->id[i]);
}

void setID(UF* id, int i, int j) {
    setRaizPonto(id->id[i], j);
}

int getTamanho(UF* id, int i) {
    return id->tamanhos[i];
}

void aumentaTamanhos(UF* id, int i, int j) {
    id->tamanhos[i] += id->tamanhos[j];
}

int getRaiz(UF *id, int i) {
    // Realiza o path compression enquanto busca a raiz
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
    
    if (i == j) return 0;
    
    // Unindo a menor "arvore" a maior
    if (getTamanho(id, p) < getTamanho(id, q)) {
        setID(id, i, j);
        aumentaTamanhos(id, j, i);
    } else {
        setID(id, j, i);
        aumentaTamanhos(id, i, j);
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

void imprimeAgrupamentos(UF* uf, char* FILENAME){
    FILE* arq = fopen(FILENAME, "w");
    int raiz;

    // ordena lexicograficamente o vetor uf
    qsort(uf->id, uf->N, sizeof(Ponto*), comparaId);

    for (int i = 0; i < uf->N; i++) {
        raiz = getRaizPonto(uf->id[i]);

        // se raiz for igual a -1, então o nó já foi visitado
        if(raiz == -1)
              continue;

        fprintf(arq, "%s", getIdPonto(uf->id[i]));
        setRaizPonto(uf->id[i], -1); // setando a raiz para -1 pois já foi visitada
        
        // procura todos pontos que tenham mesma raiz do achado acima
        for(int j = i+1; j < uf->N; j++){
            if (getRaizPonto(uf->id[j]) == raiz){
                fprintf(arq, ",%s", getIdPonto(uf->id[j]));
                setRaizPonto(uf->id[j], -1); // setando a raiz para -1 pois já foi visitada
            }
        }
        fprintf(arq, "\n");
    }

    fclose(arq);
}

void mostraUnionFind(UF* id) {
    for (int i = 0; i < id->N; i++){
        printf("%d ", getID(id, i));
    }

    printf("\n");
}

void liberaUnionFind(UF* id) {
    free(id->tamanhos);
    free(id);
}
