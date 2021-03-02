//
// Created by Pichau on 02/03/2021.
//

#ifndef TRAB1_ED2_2021_LEARQUIVO_H
#define TRAB1_ED2_2021_LEARQUIVO_H

#include "pilha.h"

FILE *iniciaLeitura(char * nomeDoArquivo);

Pilha *lePrimeiroPonto(FILE* fp, Pilha *p);

Pilha *leArquivo(FILE *fp, Pilha *p);

#endif //TRAB1_ED2_2021_LEARQUIVO_H
