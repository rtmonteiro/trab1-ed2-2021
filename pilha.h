#ifndef PILHA_H
    #define PILHA_H

    #include "ponto.h"
    #include "distancia.h"
    #include "planoR.h"

    // Define o tipo opaco Pilha
    typedef struct pilha Pilha;

    /**
     * Inicializa uma pilha vazia
     * @return estrutura Pilha inicializada
     * @pre nada
     * @post pilha alocada
    **/ 
    Pilha* initPilha ();

    /**
    * Coloca ponto como o ultimo elemento da pilha
    * @param {Pilha*}pilha
    * @param {Ponto*}ponto ponto que será inserido na pilha
    * @return nada
    * @pre pilha e ponto inicializados
    * @post ponto é adicionado ao início da lista na pilha e o topo é incrementado 1
    **/ 
    void push (Pilha* pilha, Ponto* ponto);

    /**
    * Retira o ultimo elemento da pilha
    * @param {Pilha*}pilha
    * @return nada 
    * @pre pilha inicializada
    * @post ultimo ponto adicionado a lista é retirado
    **/ 
    Ponto* pop (Pilha* pilha);

    /** 
    * Retorna quantidade de elementos na pilha
    * @param {Pilha*}pilha
    * @return int quantidade de itens na pilha
    * @pre pilha inicializada e não vazia
    * @post nada
    **/ 
    int getQtdPilha(Pilha* pilha);

    /** 
    * Retorna a dimensão de coordenadas dos pontos
    * @param {Pilha*}pilha
    * @return int dimensão dos pontos da pilha
    * @pre pilha inicializada e não vazia
    * @post nada
    **/ 
    int getDimensaoPilha(Pilha* pilha);

    /** 
    * Modifica a dimensão de coordenadas dos pontos da pilha
    * @param {Pilha*}pilha
    * @param {int}m dimensão dos ponto
    * @return int dimensão dos pontos da pilha
    * @pre pilha inicializada e não vazia
    * @post dimensao modificada
    **/ 
    void setDimensaoPilha(Pilha* pilha, int m);

    /** 
    * Preenche o vetor de pontos do PlanoR com base na pilha
    * @param {Pilha*}pilha
    * @param {PlanoR*}plano 
    * @return nada
    * @pre pilha inicializada e não vazia, plano alocado
    * @post vetor de pontos de PlanoR preenchido
    **/ 
    void pilhaParaPlanoR(Pilha* pilha, PlanoR* plano);

    /** 
    * Libera memoria alocada pela pilha
    * @param {Pilha*}pilha
    * @return nada
    * @pre pilha inicializada 
    * @post memoria alocada para pontos da pilha e a pilha eh liberada
    **/ 
    void liberaPilha(Pilha* pilha);

#endif
