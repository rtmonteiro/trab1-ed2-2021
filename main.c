#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ponto.h"
#include "planoR.h"
#include "distancia.h"
#include "leArquivo.h"
#include "uf.h"
#include "pilha.h"

int main(int argc, char** argv ) {
    clock_t prog_start_t, prog_end_t;
    prog_start_t = clock();
    if (argc < 4) exit(1);

    char *FILENAMEINPUT = argv[1];
    char *FILENAMEOUTPUT = argv[3];
    int k = (int) strtod(argv[2], NULL);

    clock_t start_t, end_t;
    Pilha* pilha = initPilha();
    start_t = clock();
    pilha = leArquivo(FILENAMEINPUT, pilha);
    end_t = clock();
    printf("Leitura do arquivo = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

    int n = getQtdPilha(pilha);
    PlanoR *plano = initPlanoR(n, getDimensaoPilha(pilha));
    pilhaParaPlanoR(pilha, plano);

    int tamDist = n * (n - 1) / 2;

    Distancia **vetorDistancias = distanciasPontos(plano, tamDist);

    UF* unionFind = initUnionFind(getPontos(plano), n);
    agrupaCaminhos(unionFind, vetorDistancias, n, tamDist, k);

    start_t = clock();
    imprimeAgrupamentos(unionFind, FILENAMEOUTPUT);
    end_t = clock();
    printf("Escrita dos grupos = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

    liberaPilha(pilha);
    liberaPlano(plano);
    liberaDistancia(vetorDistancias, tamDist);
    liberaUnionFind(unionFind);

    prog_end_t = clock();
    printf("Tempo total = %lfs\n", (double)(prog_end_t - prog_start_t) / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
