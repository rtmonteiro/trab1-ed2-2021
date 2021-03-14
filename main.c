#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "planoR.h"
#include "distancia.h"
#include "leArquivo.h"
#include "uf.h"
#include "pilha.h"

int main(int argc, char** argv ) {
    if (argc < 4) exit(1);

    char *FILENAMEINPUT = argv[1];
    char *FILENAMEOUTPUT = argv[3];

    int k = (int) strtod(argv[2], NULL);
    
    Pilha* pilha = initPilha();
    pilha = leArquivo(FILENAMEINPUT, pilha);

    int m = getDimensaoPilha(pilha);
    int n = getQtdPilha(pilha);
    PlanoR *plano = initPlanoR(n, m);
    pilhaParaPlanoR(pilha, plano);

    Distancia **vetorDistancias = distanciasPontos(plano);

    int tam = getQtd(plano);
    int tamDist = tam * (tam - 1) / 2;

    UF* unionFind = initUnionFind(getPontos(plano), tam);
    // mostraUnionFind(unionFind);
    agrupaCaminhos(unionFind, vetorDistancias, tam, tamDist, k);
    // // mostraUnionFind(unionFind);

    imprimeAgrupamentos(unionFind, FILENAMEOUTPUT);

    //region Libera
    liberaPilha(pilha);
    liberaPlano(plano);
    liberaDistancia(vetorDistancias, tam);
    liberaUnionFind(unionFind);
    //endregion

    return EXIT_SUCCESS;
}
