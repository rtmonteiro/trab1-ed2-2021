#include <string.h>
#include <stdlib.h>
#include "ponto.h"
#include "planoR.h"
#include "pilha.h"
#include "leArquivo.h"
#include "uf.h"

int main(int argc, char** argv ) {
    if (argc < 4) exit(1);

    char *FILENAMEINPUT = argv[1];
    char *FILENAMEOUTPUT = argv[3];
    int k = (int) strtod(argv[2], NULL);

    // Inicializando a pilha auxiliar de leitura
    Pilha* pilha = initPilha();

    // Lendo o arquivo e preenchendo a pilha com pontos
    pilha = leArquivo(FILENAMEINPUT, pilha);


    // Inicializando o plano e o preenchendo com os pontos da pilha
    int n = getQtdPilha(pilha);
    PlanoR *plano = initPlanoR(n, getDimensaoPilha(pilha));
    pilhaParaPlanoR(pilha, plano);
    liberaPilha(pilha);

    // Calculo da PA (tam do vetor de Distancias)
    int tamDist = n * (n - 1) / 2;

    // Inicializando e preenchendo o vetor com as distancias entre os pontos (ordenado)
    Distancia **vetorDistancias = distanciasPontos(plano, tamDist);

    // Inicializa uf e cria os grupos
    UF* unionFind = initUnionFind(getPontos(plano), n);
    agrupaCaminhos(unionFind, vetorDistancias, n, tamDist, k);

    // Imprime os grupos no arquivo de saida
    imprimeAgrupamentos(unionFind, FILENAMEOUTPUT, k);


    // Libera toda memória alocada
    liberaPlano(plano);
    liberaDistancia(vetorDistancias, tamDist);
    liberaUnionFind(unionFind);

    return EXIT_SUCCESS;
}
