#ifndef TRAB1_ED2_2021_PONTO_H
    #define TRAB1_ED2_2021_PONTO_H

    // define o tipo opaco Ponto
    typedef struct ponto Ponto;


    /**
     * Inicializa um ponto
     * input: string referente ao id, vetor de doubles (coordenadas)
     * output: estrutura Ponto inicializada
     * pré-condição: vetores inicializados
     * pós-condição: Estrutura ponto alocada
    **/
    Ponto* initPonto(char *id, double *coords, int pos);

    /**
     * Calcula a distância entre dois pontos
     * input: um inteiro e dois pontos
     * output: double referente a distância
     * pré-condição: pontos alocados
     * pós-condição: nada
    **/
    double calculaDistanciaEntrePontos(Ponto *p1, Ponto *p2, int m);

#endif //TRAB1_ED2_2021_PONTO_H
