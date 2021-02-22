#ifndef LISTA_PONTO_H
#define LISTA_PONTO_H

// #include "ponto.h"

/*
 * Lista com sentinela de pontos
 */ 
typedef struct lista Lista;

/* 
 * Inicializa uma lista vazia
 * input: void
 * output: Lista* 
 */ 
Lista* initLista (void);

/* 
 * Insere um ponto no inicio da lista
 * input: void
 * output: Lista* 
 */
void insereListaIni (Lista* lista, void* ponto);

/* 
 * Insere um ponto no final da lista
 * input: void
 * output: Lista* 
 */
void insereListaFim (Lista* lista, void* ponto);

/*
 * Libera a memoria alocada
 * input: Lista*
 * output: void
 */ 
void liberaLista (Lista* lista);

#endif