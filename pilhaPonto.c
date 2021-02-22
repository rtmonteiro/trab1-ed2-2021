#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaPonto.h"

typedef struct celula Cel;
struct celula {
    void* ponto;
    Cel *prox;
};

struct pilha {
    int qtd;
    Cel* pontos;
};

Pilha* initPilha (void) {
    Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
    pilha->qtd = 0;
    pilha->pontos = NULL;
    return pilha;
}

// WIP
void push (Pilha* pilha, void* ponto) {
    if (pilha == NULL || ponto == NULL) {
        printf("Pilha ou ponto nao inicializado\n");
        exit(1);
    }
    
    Cel* aux = (Cel*) malloc (sizeof(Cel));
    aux->ponto = ponto;

    if (pilha->qtd > -1) {
        aux->prox = s->pontos;
    } else {
        aux->prox = NULL;
    }

    pilha->pontos = aux;
    pilha->qtd++;
}

// WIP
void* pop (Pilha* pilha) {
    if (pilha == NULL || pilha->qtd > 0) {
        printf("Pilha NULL ou vazia\n");
        return NULL;
    } 

    Cel* aux = pilha->pontos;
    pilha->pontos = pilha->pontos->prox;
    pilha->qtd--;
    aux->prox = NULL;

    return aux->ponto;
}

// WIP
void* distancias (Pilha* pilha, void (*func)(Ponto*, Ponto*)) {
    // Percore pilha de forma que ponto1 é sempre diferente de ponto2
    for(Cel* ponto1 = pilha; ponto1 != NULL ; ponto1=ponto1->prox) {
        for (Cel* ponto2 = ponto1->prox; ponto2 != NULL; ponto2 = ponto2->prox ) {
            // Calcula a distancia entre ponto1 e ponto2 e armazena numa lista
            // Distancias* todasDistancias = func(ponto1->ponto, ponto2->ponto);
        }
    }
}

// WIP
static void freePontos (Cel* cel) {
    Cel* aux1 = cel,* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        freePonto(aux1);
        aux1 = aux2;
    }
}

void freePilha (Pilha* pilha) {
    freePontos(pilha->pontos);
    free(pilha);
}