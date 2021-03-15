#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "ponto.h"
#include "planoR.h"
#include "distancia.h"

typedef struct celula Cel;
struct celula {
    Ponto* ponto;
    Cel *prox;
};

struct pilha {
    int qtd; // quantidade de pontos na pilha
    int dimensao; // dimensao das coordenadas do ponto
    Cel* pontos; 
};


Pilha* initPilha() {
    Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
    pilha->qtd = pilha->dimensao = 0;
    pilha->pontos = NULL;
    return pilha;
}


void push(Pilha* pilha, Ponto* ponto) {
    if (pilha == NULL || ponto == NULL) {
        printf("Pilha ou ponto nao inicializado\n");
        exit(1);
    }
    
    Cel* aux = (Cel*) malloc (sizeof(Cel));
    aux->ponto = ponto;

    if (pilha->qtd > 0) {
        aux->prox = pilha->pontos;
    } else {
        aux->prox = NULL;
    }

    pilha->pontos = aux;
    pilha->qtd++;
}


Ponto* pop(Pilha* pilha) {
    if (pilha == NULL || pilha->qtd < 0) {
        printf("Pilha NULL ou vazia\n");
        return NULL;
    } 

    Cel* aux = pilha->pontos;
    pilha->pontos = pilha->pontos->prox;
    pilha->qtd--;
    aux->prox = NULL;

    return aux->ponto;
}

int getQtdPilha(Pilha* pilha) {
    return pilha->qtd;
}


int getDimensaoPilha(Pilha* pilha) {
    return pilha->dimensao;
}


void setDimensaoPilha(Pilha* pilha, int m) {
    pilha->dimensao = m;
}

void pilhaParaPlanoR(Pilha* pilha, PlanoR* plano) {
    Cel *aux = pilha->pontos;
    for (int i = pilha->qtd - 1; i >= 0; i--) {

        Ponto* ponto = aux->ponto;
        insere(plano, ponto, i);
        aux = aux->prox;
    }
}

void liberaPilha (Pilha* pilha) {
    Cel *aux1 = pilha->pontos;
    Cel *aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
    free(pilha);
}
