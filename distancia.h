#ifndef DIST_H
    #define DIST_H

    #include "ponto.h"

    // Retorna dist
    // inializa vetor -> tam = n(n-1)/2
    // insere distancias
    // ordena vetor
    
    // define o tipo opaco Distancia
    typedef struct distancia Distancia;

size_t sizeOfDistancia();


    /**
     * Inicializa um vetor de Distancias
     * input: um inteiro
     * output: estrutura Distancia inicializada
     * pré-condição: inteiro existe
     * pós-condição: Estrutura Distancia alocada
    **/
    Distancia** initVetDistancia(int n);

    /**
     * Inicializa uma Distancia
     * input: dois Pontos e um inteiro
     * output: estrutura Distancia inicializada
     * pré-condição: Pontos alocados
     * pós-condição: Estrutura Distancia alocada
    **/
    Distancia* initDistancia(Ponto* p1, Ponto* p2, int m);


    /**
     * Compara duas distancias
     * input: ?
     * output: 0 se iguais; 1 se d1 > d2; -1 se d1 < d2
     * pré-condição: Distancias alocadas
     * pós-condição: nada
    **/
    int comparaDistancia(const void* d1, const void* d2);

    /**
     * Libera a memória alocada pelo vetor distancia
     * input: vetor de Distancias e um inteiro tamanho do vetor
     * output: nada
     * pré-condição: vetor e suas posições alocados
     * pós-condição: memória libera
    **/
    void liberaDistancia(Distancia** vetDistancia, int n);
    

#endif
