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

    int n = getQtdPilha(pilha);
    PlanoR *plano = initPlanoR(n, getDimensaoPilha(pilha));
    pilhaParaPlanoR(pilha, plano);

    int tamDist = n * (n - 1) / 2;

    Distancia **vetorDistancias = distanciasPontos(plano, tamDist);

    UF* unionFind = initUnionFind(getPontos(plano), n);
    agrupaCaminhos(unionFind, vetorDistancias, n, tamDist, k);

    imprimeAgrupamentos(unionFind, FILENAMEOUTPUT);

    liberaPilha(pilha);
    liberaPlano(plano);
    liberaDistancia(vetorDistancias, tamDist);
    liberaUnionFind(unionFind);

    return EXIT_SUCCESS;
}
