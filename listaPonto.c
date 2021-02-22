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
};

Lista* initLista (void) {
    Lista* lista = (Lista*) malloc (sizeof(lista));
    lista->prim = lista->ult = NULL;
}

void insereListaIni (Lista* lista, void* ponto) {
    if(lista == NULL)
        exit(1);
    if(ponto == NULL)
        exit(1);

    Cel* nova = (Cel*) malloc (sizeof(Cel));
    
    nova->ponto = ponto;
    nova->prox = lista->prim;
    lista->prim = nova;

    // Se a lista estiver vazia anteriormente
    if (lista->ult == NULL) {
        lista->ult = nova;
    }
}

void insereListaFim (Lista* lista, void* ponto) {
    if(lista == NULL)
        exit(1);
    if(ponto == NULL)
        exit(1);
        
    Cel* nova = (Cel*) malloc (sizeof(Cel));
    nova->ponto = ponto;
    nova->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = nova;
        lista->ult = lista->prim;
    } else {
        lista->ult->prox = nova;
        lista->ult = nova;
    }
}

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