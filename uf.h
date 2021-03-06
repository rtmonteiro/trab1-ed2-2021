#ifndef UF_H
    #define UF_H

    typedef struct uf UF;

    /**
     * Inicializa union-conectado.
     * @param {int}N - Tamanho de elementos.
     * @example https://algs4.cs.princeton.edu/15uf/
     * @return estrutura UF (union-conectado) inicializado.
     * @pre nada.
     * @post estrutura UF alocada.
    **/
    UF* initUnionFind(int N);

    /**
     * Retorna o valor armazenado no índice i. 
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}i - Índice que quer acessar
     * @return valor armazenado no índice i
     * @pre estrutura UF existe
     * @post nada
    **/
    int getID(UF *id, int i);

    /**
     * Modifica o valor no índice i para j 
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}i - Índice que quer acessar
     * @param {int}j - Valor novo
     * @return void
     * @pre estrutura UF existe
     * @post nada
    **/
    void setID(UF* id, int i, int j);

    /**
     * Retorna a altura do nó no índice i 
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}i - Índice que quer acessar
     * @return altura da arvore do nó no índice i
     * @pre estrutura UF existe
     * @post nada
    **/
    int getAltura(UF* id, int i);

    /**
     * Modifica a altura do nó do elemento i (soma com a altura do elemento j)
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}i - Índice que o valor será modificado
     * @param {int}j - Índice que o valor será somado
     * @return void
     * @pre estrutura UF existe
     * @post altura da árvore é modificada
    **/
    void aumentaTamanho(UF* id, int i, int j);

    /**
     * Retorna a raiz do elemento i
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}i - Índice do elemento
     * @return valor da raiz
     * @pre estrutura UF existe
     * @post nada
    **/
    int getRaiz (UF *id, int i);

    /**
     * Verifica se há caminho entre os elementos
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}p - Elemento
     * @param {int}q - Elemento
     * @return 1 ou 0, se tem caminho ou se não tem caminho
     * @pre estrutura UF existe
     * @post nada
    **/
    int conectado(UF* id, int p, int q);

    /**
     * Une dois elementos
     * @param {UF*}id - Estrutura de union-conectado.
     * @param {int}p - Elemento
     * @param {int}q - Elemento
     * @return void
     * @pre estrutura UF existe
     * @post estrutura UF é modificada
    **/
    int criaUniao(UF* id, int p, int q);

    /**
     * Verifica se todos objetos estão conectados
     * @param {UF*}id - Estrutura de union-conectado.
     * @return 1 ou 0, se todos estão conectados ou não
     * @pre estrutura UF existe
     * @post nada
    **/
    int todosObjetosConectados(UF* id);

    /**
     * Impressão do vetor do UF
     * @param {UF*}id - Estrutura de union-conectado.
     * @return void
     * @pre estrutura UF existe
     * @post vetor é impresso no terminal
    **/
    void mostraUnionFind (UF* id);

    /**
     * Libera memória alocada pelo union-conectado
     * @param {UF*}id - Estrutura de union-conectado.
     * @return void
     * @pre estrutura UF existe
     * @post memória é liberada
    **/
    void liberaUnionFind(UF* id);

#endif
