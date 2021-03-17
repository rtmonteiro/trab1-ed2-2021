#ifndef PLANO_R_H
    #define PLANO_R_H

    #include "ponto.h"
    #include "distancia.h"


    // Define o tipo opaco PlanoR
    typedef struct planoR PlanoR;

    /**
     * Inicializa uma plano vazio
     * @return estrutura PlanoR vazia inicializada
     * @pre nada
     * @post plano alocado
    **/ 
    PlanoR* initPlanoR (int N, int M);

    /**
    * Coloca ponto como o ultimo elemento do vetor de pontos do plano
    * @param {PlanoR*} plano
    * @param {Ponto*} ponto que sera inserido na planoR
    * @param {int}i posição do vetor em que o ponto sera adicionado
    * @return nada
    * @pre plano e ponto inicializados
    * @post ponto eh adicionado ao final do vetor de pontos do plano
    **/ 
    void insere (PlanoR* plano, Ponto* ponto, int i);

    /** 
    * Percorre a plano de forma que ponto1 != ponto2 e calcula distancias
    * @param {PlanoR*}plano
    * @param {int}tam tamanho do vetor de distancias
    * @return nada
    * @pre plano inicializada e nao vazia
    * @post vetor com distancias entre os pontos existe
    **/ 
    Distancia** distanciasPontos (PlanoR* plano, int tam);

    /** 
    * Retorna vetor de pontos do plano
    * @param {PlanoR**}plano
    * @return vetor de pontos do plano
    * @pre plano inicializada e não vazia
    * @post nada
    **/ 
    Ponto** getPontos(PlanoR* plano);

    /** 
    * Libera memoria alocada pela planoR
    * @param {PlanoR*}planoR
    * @return nada
    * @pre planoR inicializada 
    * @post memoria alocada para pontos da planoR e a planoR eh liberada
    **/ 
    void liberaPlano (PlanoR* plano);

#endif
