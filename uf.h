#ifndef UF_H
    #define UF_H
    #include <stdbool.h>
    typedef struct uf UF;

    UF* unionFindInit (int N);

    int getID (UF *id, int i);

    void setID (UF* id, int i, int j);

    int getTamArv (UF* id, int i);

    void aumentaTam(UF* id, int i, int j);

    int getRaiz (UF *id, int i);

    int find(UF* id, int p, int q);

    void criaUniao(UF* id, int p, int q);

    int todosObjetosConectados(UF* id);

    void mostraUnionFind (UF* id);

    void liberaUnionFind(UF* id);

#endif