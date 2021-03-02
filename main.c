#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "pilha.h"
#include "distancia.h"
#include "leArquivo.h"


int main(int argc, char** argv ) {

    char *FILENAME = argv[1];

    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", FILENAME);
        return EXIT_FAILURE;
    }

    Pilha *pilhaPontos = initPilha();
    pilhaPontos = leArquivo(fp, pilhaPontos);


    liberaPilha(pilhaPontos);

    printf("IUPI!");
    return EXIT_SUCCESS;
}
