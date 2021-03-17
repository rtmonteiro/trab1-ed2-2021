#ifndef UF_H
    #define UF_H
    #include "ponto.h"
    
    typedef struct uf UF;

    /**
     * Inicializa union-find.
     * @param {Ponto**}pontos Vetor de pontos
     * @param {int}N Tamanho de elementos.
     * @example https://algs4.cs.princeton.edu/15uf/
     * @return estrutura UF (union-conectado) inicializado.
     * @pre nada.
     * @post estrutura UF e seus itens alocados
    **/
    UF* initUnionFind(Ponto** pontos, int N) ;

    /**
     * Retorna o valor armazenado no índice i. 
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}i Índice que quer acessar
     * @return valor armazenado no índice i
     * @pre estrutura UF existe
     * @post nada
    **/
    int getID(UF *id, int i);

    /**
     * Modifica o valor no índice i para j 
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}i Índice que quer acessar
     * @param {int}j Valor novo
     * @return void
     * @pre estrutura UF existe
     * @post nada
    **/
    void setID(UF* id, int i, int j);

    /**
     * Retorna o tamanho do nó no índice i 
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}i Índice que quer acessar
     * @return tamanho da arvore do nó no índice i
     * @pre estrutura UF existe
     * @post nada
    **/
    int getTamanho(UF* id, int i);

    /**
     * Modifica o tamanho do nó do elemento i (soma com o tamanho do elemento j)
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}i Índice que o valor será modificado
     * @param {int}j Índice que o valor será somado
     * @return void
     * @pre estrutura UF existe
     * @post tamanho da árvore é modificada
    **/
    void aumentaTamanho(UF* id, int i, int j);

    /**
     * Retorna a raiz do elemento i
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}i Índice do elemento
     * @return valor da raiz
     * @pre estrutura UF existe
     * @post nada
    **/
    int getRaiz(UF *id, int i);

    /**
     * Une dois elementos
     * @param {UF*}id Estrutura de union-conectado.
     * @param {int}p Elemento
     * @param {int}q Elemento
     * @return void
     * @pre estrutura UF existe
     * @post estrutura UF é modificada
    **/
    int criaUniao(UF* id, int p, int q);

    /**
     * Imprime no arquivo os grupos feitos
     * @param {UF*}uf Estrutura de union-conectado.
     * @param {char*}FILENAME nome do arquivo de impressão
     * @return nada
     * @pre estrutura UF e nome do arquivo existem
     * @post arquivo contém as impressões
    **/
    void imprimeAgrupamentos(UF *uf, char *FILENAME, int k);

    /**
     * Impressão do vetor do UF
     * @param {UF*}id Estrutura de union-conectado.
     * @return void
     * @pre estrutura UF existe
     * @post vetor é impresso no terminal
    **/
    void mostraUnionFind(UF* id);

    /**
     * Libera memória alocada pelo union-conectado
     * @param {UF*}id Estrutura de union-conectado.
     * @return void
     * @pre estrutura UF existe
     * @post memória é liberada
    **/
    void liberaUnionFind(UF* id);

#endif
