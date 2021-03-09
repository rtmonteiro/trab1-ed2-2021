#ifndef PLANO_R_H
    #define PLANO_R_H

    #include "ponto.h"
    #include "distancia.h"


    // Define o tipo opaco PlanoR
    typedef struct planoR PlanoR;

    /**
     * Inicializa uma planoR vazia
     * @param {int}N quantidade de pontos no plano
     * @param {int}M dimensao do plano
     * @return estrutura PlanoR inicializada
     * @pre nada
     * @post plano alocada
    **/ 
    PlanoR* initPlanoR (int N, int M);

    /**
    * Coloca ponto como o ultimo elemento do vetor de pontos do plano
    * @param {PlanoR*} plano
    * @param {Ponto*} ponto que será inserido na planoR
    * @param {int}i posição do vetor em que o ponto será adicionado
    * @return nada
    * @pre plano e ponto inicializados
    * @post ponto é adicionado ao final do vetor de pontos do plano
    **/ 
    void insere (PlanoR* plano, Ponto* ponto, int i);

    /** 
    * Percorre a plano de forma que ponto1 != ponto2 e calcula distancias
    * @param {PlanoR*} plano
    * @return nada
    * @pre plano inicializada e não vazia
    * @post vetor com distancias entre os pontos existe
    **/ 
    Distancia** distanciasPontos (PlanoR* plano);

    /** 
    * Retorna quantidade de elementos na plano
    * @param {PlanoR*}plano
    * @return int quantidade de itens na planoR
    * @pre plano inicializada e não vazia
    * @post nada
    **/ 
    int getQtd(PlanoR* plano);

    /** 
    * Modifica a quantidade de elementos na plano
    * @param {PlanoR*}plano
    * @param {int}N tamanho do vetor de pontos (quantidade de pontos no plano)
    * @return nada
    * @pre plano inicializada e não vazia
    * @post quantidade modificada
    **/ 
    void setQtd(PlanoR* plano, int N);

    /** 
    * Retorna a dimensão de coordenadas dos pontos
    * @param {PlanoR*}plano
    * @return int dimensão dos pontos da plano
    * @pre plano inicializada e não vazia
    * @post nada
    **/ 
    int getDimensao(PlanoR* plano);

    /** 
    * Modifica a dimensão de coordenadas dos pontos da planoR
    * @param {PlanoR*}plano
    * @param {int}M dimensão dos ponto
    * @return int dimensão dos pontos da planoR
    * @pre plano inicializada e não vazia
    * @post dimensao modificada
    **/ 
    void setDimensao(PlanoR* plano, int M);
    
    /** 
    * Libera memoria alocada pela planoR
    * @param {PlanoR*}planoR
    * @return nada
    * @pre planoR inicializada 
    * @post memoria alocada para pontos da planoR e a planoR eh liberada
    **/ 
    void liberaPilha (PlanoR* plano);

#endif
