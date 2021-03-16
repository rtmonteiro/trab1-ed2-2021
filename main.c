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

    // Inicializando a pilha auxiliar de leitura
    clock_t start_t, end_t;
    Pilha* pilha = initPilha();

    // Lendo o arquivo e preenchendo a pilha com pontos
    start_t = clock();
    pilha = leArquivo(FILENAMEINPUT, pilha);
    end_t = clock();
    printf("Leitura do arquivo = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);


    // Inicializando o plano e o preenchendo com os pontos da pilha
    int n = getQtdPilha(pilha);
    PlanoR *plano = initPlanoR(n, getDimensaoPilha(pilha));
    pilhaParaPlanoR(pilha, plano);

    // Calculo da PA (tam do vetor de Distancias)
    int tamDist = n * (n - 1) / 2;

    // Inicializando e preenchendo o vetor com as distancias entre os pontos (ordenado)
    Distancia **vetorDistancias = distanciasPontos(plano, tamDist);

    // Inicializa uf e cria os grupos
    UF* unionFind = initUnionFind(getPontos(plano), n);
    agrupaCaminhos(unionFind, vetorDistancias, n, tamDist, k);

    // Imprime os grupos no arquivo de saida
    start_t = clock();
    imprimeAgrupamentos(unionFind, FILENAMEOUTPUT);
    end_t = clock();
    printf("Escrita dos grupos = %lfs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);


    // Libera toda memória alocada
    liberaPilha(pilha);
    liberaPlano(plano);
    liberaDistancia(vetorDistancias, tamDist);
    liberaUnionFind(unionFind);

    prog_end_t = clock();
    printf("Tempo total = %lfs\n", (double)(prog_end_t - prog_start_t) / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
