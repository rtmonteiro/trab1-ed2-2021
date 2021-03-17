#ifndef DIST_H
    #define DIST_H

    #include "ponto.h"
    #include "uf.h"
    
    // define o tipo opaco Distancia
    typedef struct distancia Distancia;

    /**
     * Ordena crescentemente o vetor de distancia
     * @param {int}n tamando do vetor
     * @param {Distancia**}vetDist vetor de Distancia
     * @return nada
     * @pre vetor de Distancia alocado
     * @post vetor de Distancia ordenado
    **/
    void ordenaVetDistancia(Distancia** vetDist, int n);

    /**
     * Inicializa um vetor de Distancias
     * @param {int}tam tamando do vetor
     * @return estrutura Distancia inicializada
     * @pre inteiro existe
     * @post vetor de Distancia alocado
    **/
    Distancia** initVetDistancia(int tam);

    /**
     * Inicializa uma Distancia
     * @param {Ponto*}p1
     * @param {Ponto*}p2
     * @param {int}m dimensão do ponto
     * @return estrutura Distancia inicializada
     * @pre Pontos alocados
     * @post Estrutura Distancia alocada
    **/
    Distancia* initDistancia(Ponto* p1, Ponto* p2, int m);


    /**
     * Compara duas distancias
     * @param {const void*}d1 estrutura Distancia 
     * @param {const void*}d2 estrutura Distancia 
     * @return 0 se iguais; 1 se d1 > d2; -1 se d1 < d2
     * @pre Distancias alocadas
     * @post nada
    **/
    int comparaDistancia(const void* d1, const void* d2);

    /**
     * Agrupa as distancias na estrutura UF
     * @param {UF*}uf estrutura de agrupamento
     * @param {Distancia**}vetDistancia vetor de distâncias
     * @param {int}n número de pontos
     * @param {int}tamPA tamanho do vetor de Distancia
     * @param {int}k número de grupos a serem criados
     * @return nada
     * @pre vetor de Distancia e uf alocados
     * @post valores de uf modificados
    **/
    void agrupaCaminhos(UF* uf, Distancia** vetDistancia, int n, int tamPA, int k);

    /**
     * Libera a memória alocada pelo vetor distancia
     * @param {Distancia**}vetDistancia
     * @param {int}tam tamanho do vetor
     * @return nada
     * @pre vetor e suas posições alocados
     * @post memória liberada
    **/
    void liberaDistancia(Distancia** vetDistancia, int tam);  

#endif
