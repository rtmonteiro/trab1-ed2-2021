#include <stdio.h>
#include "listaPonto.h"

typedef struct celula Cel;
struct celula {
    Cel *prox;
    void* ponto;
};

struct lista{
    Cel* prim;
    Cel* ult;
    int qtd;
};

Lista* initLista (void) {
    Lista* lista = (Lista*) malloc (sizeof(lista));
    lista->prim = lista->ult = NULL;
    lista->qtd = 0;
    return lista;
}

// WIP
void insereListaIni (Lista* lista, void* ponto) {
    if(lista == NULL)
        exit(1);
    if(ponto == NULL)
        exit(1);

    Cel* nova = (Cel*) malloc (sizeof(Cel));
    
    nova->ponto = ponto;
    nova->prox = lista->prim;
    lista->prim = nova;

    // Se a lista estiver vazia inicialmente
    if (lista->ult == NULL) {
        lista->ult = nova;
    }

    lista->qtd++;
}

// WIP
void insereListaFim (Lista* lista, void* ponto) {
    if(lista == NULL)
        exit(1);
    if(ponto == NULL)
        exit(1);
        
    Cel* nova = (Cel*) malloc (sizeof(Cel));
    nova->ponto = ponto;
    nova->prox = NULL;

    // Se a lista tiver vazia inicialmente
    if (lista->prim == NULL) {
        lista->prim = nova;
        lista->ult = lista->prim;
    } else {
        lista->ult->prox = nova;
        lista->ult = nova;
    }

    lista->qtd++;
}

// WIP
void* distancias (Lista* lista, void (*func)(Ponto*, Ponto*)) {
    // Percore lista de forma que ponto1 é sempre diferente de ponto2
    for(Cel* ponto1 = lista->prim; ponto1 != NULL ; ponto1=ponto1->prox) {
     for (Cel* ponto2 = ponto1->prox; ponto2 != NULL; ponto2 = ponto2->prox ) {
            // Calcula a distancia entre ponto1 e ponto2 e armaena numa lista
            // Distancias* todasDistancias = func(getPonto(ponto1), getPonto(ponto2));
     }
}

// WIP
void liberaLista (Lista* lista) {
    Cel* aux1,* aux2;
    
    aux1 = lista->prim;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        // liberaPonto(aux1->ponto);
        free(aux1);
        aux1 = aux2;
    }

    free(lista);
}