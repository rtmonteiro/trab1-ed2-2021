#ifndef DIST_H
    #define DIST_H

    #include "ponto.h"

    // Retorna dist
    // inializa vetor -> tam = n(n-1)/2
    // insere distancias
    // ordena vetor
    
    // define o tipo opaco Distancia
    typedef struct distancia Distancia;

    /**
     * Inicializa um vetor de Distancias
     * input: um inteiro
     * output: estrutura Distancia inicializada
     * pré-condição: inteiro existe
     * pós-condição: Estrutura Distancia alocada
    **/
    Distancia* initVetDistancia(int n);

    /**
     * Inicializa uma Distancia
     * input: dois Pontos
     * output: estrutura Distancia inicializada
     * pré-condição: Pontos alocados
     * pós-condição: Estrutura Distancia alocada
    **/
    Distancia* initDistancia(Ponto* p1, Ponto* p2);
    

#endif