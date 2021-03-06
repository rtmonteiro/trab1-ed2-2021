#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "pilha.h"
#include "distancia.h"
#include "leArquivo.h"
#include "uf.h"

int main(int argc, char** argv ) {

    char *FILENAMEINPUT = argv[1];
    char *FILENAMEOUTPUT = argv[3];

    FILE *fp = fopen(FILENAMEINPUT, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", FILENAMEINPUT);
        exit(1);
    }

    int k = atoi(argv[2]);
    
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
