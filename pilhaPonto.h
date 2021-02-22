#ifndef PILHA_H
#define PILHA_H
// include "ponto.h"

typedef struct pilha Pilha;

/* 
 * Inicializa uma pilha vazia
 * input: void*
 * output: Pilha* 
 */ 
Pilha* initPilha (void);

/* 
 * Coloca ponto como o ultimo elemento da pilha
 * input: Pilha*, void*
 * output: void
 */ 
void push (Pilha* pilha, void* ponto);

/* 
 * Retira o ultimo elemento da pilha
 * input: Pilha*
 * output: void* 
 */ 
void* pop (Pilha* pilha);

/* 
 * Percorre a pilha de forma que ponto1 != ponto2 e aplica a funcao func
 * input: Pilha*, void (Ponto*, Ponto*)
 * output: void*
 */ 
void* distancias (Pilha* pilha, void (*func)(Ponto*, Ponto*));

/* 
 * Libera memoria alocada pela pilha
 * input: void*
 * output: Pilha* 
 */ 
void freePilha (Pilha* pilha);

#endif