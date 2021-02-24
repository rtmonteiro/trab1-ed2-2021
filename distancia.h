#ifndef DIST_H
    #define DIST_H

    // Retorna dist
    // inializa vetor -> tam = n(n-1)/2
    // insere distancias
    // ordena vetor
    
    typedef struct distancia Distancia;

    Distancia* initVetDistancia(int n);

    Distancia* initDistancia(Ponto* p1, Ponto* p2);
    

#endif