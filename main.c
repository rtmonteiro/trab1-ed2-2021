#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "pilha.h"
#include "distancia.h"
#include "leArquivo.h"
#include "uf.h"

int main(int argc, char** argv ) {

    char *FILENAME = argv[2];

    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", FILENAME);
        exit(1);
    }

    int k = atoi(argv[1]);
    Pilha *pilhaPontos = initPilha();
    pilhaPontos = leArquivo(fp, pilhaPontos);

    Distancia **vetorDistancias = distanciasPilha(pilhaPontos);
    int tam = getQtd(pilhaPontos);
    int tamPA = tam * (tam - 1) / 2;
    UF* unionFind = initUnionFind(tam);
    mostraUnionFind(unionFind);
    agrupaCaminhos(unionFind, vetorDistancias, tam, tamPA, k);
    mostraUnionFind(unionFind);
    liberaPilha(pilhaPontos);
    liberaDistancia(vetorDistancias, tam);
    liberaUnionFind(unionFind);
    printf("IUPI!");
    return EXIT_SUCCESS;
}
