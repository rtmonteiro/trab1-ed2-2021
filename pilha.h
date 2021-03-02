#ifndef PILHA_H
    #define PILHA_H

    #include "ponto.h"
    #include "distancia.h"

    /**
     * Define o tipo opaco Pilha
     * Possui lista de ponto, quantidade de pontos e quantidade de coordenadas 
     **/ 
    typedef struct pilha Pilha;

    /**
    * Inicializa uma pilha vazia
    * input: void*
    * output: Pilha*
    * pré-condição: nada
    * pós-condição: estrutura pilha alocada
    **/ 
    Pilha* initPilha (void);

    /**
    * Coloca ponto como o ultimo elemento da pilha
    * input: Pilha*, void*
    * output: void
    * pré-condição: pilha e ponto não estão vazios
    * pós-condição: ponto é adicionado ao início da lista na pilha e o topo é incrementado 1
    **/ 
    void push (Pilha* pilha, Ponto* ponto);

    /**
    * Retira o ultimo elemento da pilha
    * input: Pilha*
    * output: void* 
    * pré-condição: pilha existe
    * pós-condição: ultimo ponto adicionado a lista eh retirado
    **/ 
    Ponto* pop (Pilha* pilha);

    /** 
    * Percorre a pilha de forma que ponto1 != ponto2 e aplica a funcao func
    * input: Pilha*
    * output: void*
    * pré-condição: pilha nao eh vazia
    * pós-condição: vetor com distancias entre os pontos existe
    **/ 
    Distancia** distanciasPilha (Pilha* pilha);

    /** 
    * Retorna quantidade de elementos na pilha
    * input: Pilha*
    * output: int
    * pré-condição: pilha esta alocada
    * pós-condição: nada
    **/ 
    int getQtd(Pilha* pilha);

    /** 
    * Retorna a quantidade de coordenadas dos pontos
    * input: Pilha*
    * output: int
    * pré-condição: pilha esta alocada
    * pos-condição: nada
    **/ 
    int getDimensao(Pilha* pilha);

    void setDimensao(Pilha* pilha, int m);
    
    /** 
    * Libera memoria alocada pela pilha
    * input: void*
    * output: Pilha* 
    * pré-condição: pilha existe
    * pós-condição: memoria alocada para pontos da pilha e a pilha eh liberada
    **/ 
    void liberaPilha (Pilha* pilha);

#endif