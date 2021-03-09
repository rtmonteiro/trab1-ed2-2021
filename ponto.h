#ifndef TRAB1_ED2_2021_PONTO_H
    #define TRAB1_ED2_2021_PONTO_H

    // define o tipo opaco Ponto
    typedef struct ponto Ponto;


    /**
     * Inicializa um ponto
     * @param {char*}id string de identificação do Ponto
     * @param {double*}coord vetor de coordenada do Ponto
     * @param {int}indice chave de identificação do Ponto
     * @return estrutura Ponto inicializada
     * @pre vetores inicializados
     * @post Estrutura ponto alocada
    **/
    Ponto* initPonto(char *id, double *coords, int indice);


    /**
     * Calcula a distância entre dois pontos.
     * @param {Ponto*}p1  1º Ponto
     * @param {Ponto*}p2  2º Ponto
     * @param {int}m  dimensão do ponto
     * @return distância entre pontos
     * @pre pontos alocados
     * @post nada
    **/
    double calculaDistanciaEntrePontos(Ponto *p1, Ponto *p2, int m);

    /**
     * Modifica a raiz do ponto
     * @param {Ponto*}p 
     * @param {int}raiz 
     * @return nada
     * @pre ponto alocado
     * @post raiz do ponto modificada
    **/
    void setRaizPonto(Ponto* p, int raiz);

    /**
     * Retorna a raiz do ponto
     * @param {Ponto*}p 
     * @return raiz do ponto (a quem está ligado)
     * @pre ponto alocado
     * @post nada
    **/
    int getRaizPonto(Ponto* p);

    char* getIdPonto(Ponto* p);
    /**  
     * Libera memória alocada por ponto
     * @param {Ponto*}p
     * @return nada
     * @pre Ponto alocado
     * @post memória do Ponto liberada
    **/
    void liberaPonto(Ponto* p);

#endif //TRAB1_ED2_2021_PONTO_H
