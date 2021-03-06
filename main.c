#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "pilha.h"
#include "distancia.h"
#include "leArquivo.h"
#include "uf.h"

int main(int argc, char** argv ) {
    if (argc < 4) exit(1);

    char *FILENAMEINPUT = argv[1];
    char *FILENAMEOUTPUT = argv[3];

    int k = (int) strtod(argv[2], NULL);
    
    Pilha *pilhaPontos = initPilha();
    pilhaPontos = leArquivo(FILENAMEINPUT, pilhaPontos);

    Distancia **vetorDistancias = distanciasPilha(pilhaPontos);

    int tam = getQtd(pilhaPontos);
    int tamPA = tam * (tam - 1) / 2;

    UF* unionFind = initUnionFind(tam);
    //mostraUnionFind(unionFind);
    agrupaCaminhos(unionFind, vetorDistancias, tam, tamPA, k);
    //mostraUnionFind(unionFind);

    //region Apresenta Grupos

    //endregion

    //region Libera
    liberaPilha(pilhaPontos);
    liberaDistancia(vetorDistancias, tam);
    liberaUnionFind(unionFind);
    //endregion

    //printf("IUPI!");
    return EXIT_SUCCESS;
}
