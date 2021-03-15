#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leArquivo.h"
#include "planoR.h"

#define TAM 10


static int leM(FILE* fp) {

    //le a primeira linha e retorna m
    char* line_buf = NULL;
    size_t line_buf_size = 0;

    int m = 0;

    getline(&line_buf, &line_buf_size, fp);

    char* token = strtok(line_buf, ","); // pega o id do ponto 

    while (token) {
        token = strtok(NULL, ",");
        if (token) 
            m++; // Ao ler uma nova coordenada, atualiza a dimensão dos pontos
    }

    free(line_buf);

    return m;
}

Pilha *leArquivo(char* FILENAMEINPUT, Pilha *p) {
    FILE* fp = fopen(FILENAMEINPUT, "r");
    if (!fp) {
        fprintf(stderr, "Erro ao abrir arquivo '%s'\n", FILENAMEINPUT);
        exit(1);
    }

    int m = leM(fp);

    fclose(fp);

    //le o arquivo de novo e retorna o vetor com os pontos

    fp = fopen(FILENAMEINPUT, "r");
    if (!fp) {
        fprintf(stderr, "Erro ao abrir arquivo '%s'\n", FILENAMEINPUT);
        exit(1);
    }

    setDimensaoPilha(p, m);
//     //le o resto do arquivo e retorna n
    char* line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;

    getline(&line_buf, &line_buf_size, fp);

    /* Loop through until we are done with the file. */
    while (!feof(fp)) {
        /* Increment our line count */
        line_count++;

        /* Show the line details */
        // printf("line[%06d]: contents: %s", line_count, line_buf);
        char *token = strtok(line_buf, ",");
        char* idPonto = strdup(token);

        double* coords = (double*) malloc(sizeof(double) * m);
        for (int i = 0; i < m; ++i) {
            token = strtok(NULL, ",");
            coords[i] = strtod(token, NULL);
        }

        Ponto* novoPonto = initPonto(idPonto, coords, line_count-1);
        push(p, novoPonto);

        /* Get the next line */
        getline(&line_buf, &line_buf_size, fp);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;
    fclose(fp);
    return p;
}
