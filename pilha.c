#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "ponto.h"
#include "distancia.h"

typedef struct celula Cel;
struct celula {
    Ponto* ponto;
    Cel *prox;
};

struct pilha {
    int qtd;
    int coord;
    Cel* pontos;
};

Pilha* initPilha (void) {
    Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
    pilha->qtd = pilha->coord = 0;
    pilha->pontos = NULL;
    return pilha;
}

void push (Pilha* pilha, Ponto* ponto) {
    if (pilha == NULL || ponto == NULL) {
        printf("Pilha ou ponto nao inicializado\n");
        exit(1);
    }
    
    Cel* aux = (Cel*) malloc (sizeof(Cel));
    aux->ponto = ponto;

    if (pilha->qtd > -1) {
        aux->prox = pilha->pontos;
    } else {
        aux->prox = NULL;
    }

    pilha->pontos = aux;
    pilha->qtd++;
}

// WIP
Ponto* pop (Pilha* pilha) {
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
Distancia** distanciasPilha (Pilha* pilha) {
    Distancia** dist = initVetDistancia(pilha->qtd);
    int i = 0;

    // Percore pilha de forma que ponto1 é sempre diferente de ponto2 
    // ponto2 eh o ponto apos ponto1
    for(Cel* ponto1 = pilha; ponto1 != NULL ; ponto1=ponto1->prox) {
        for (Cel* ponto2 = ponto1->prox; ponto2 != NULL; ponto2 = ponto2->prox, i++) {
            // Calcula a distancia entre ponto1 e ponto2 e armazena num vetor
            dist[i] = initDistancia(ponto1->ponto, ponto2->ponto, pilha->coord);
        }
    }

    return dist;
}

// WIP
static void liberaPontos (Cel* cel) {
    Cel* aux1 = cel,* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        // freePonto(aux1);
        aux1 = aux2;
    }
}

void liberaPilha (Pilha* pilha) {
    liberaPontos(pilha->pontos);
    free(pilha);
}