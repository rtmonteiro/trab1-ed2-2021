//
// Created by Pichau on 02/03/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leArquivo.h"

#define TAM 10

FILE *iniciaLeitura(char * nomeDoArquivo) {
    FILE *fp = fopen(nomeDoArquivo, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", nomeDoArquivo);
        return EXIT_FAILURE;
    }
    return fp;
}

Pilha *lePrimeiroPonto(FILE *fp, Pilha *p) {
    char *line_buf = NULL;
    size_t line_buf_size = 0;

    double *coord = NULL;
    int m = 0;

    /* Get the first line of the file. */
    getline(&line_buf, &line_buf_size, fp);


    char *token = strtok(line_buf, ","); /* pega o id do ponto*/
    char *idPonto = strdup(line_buf);

    while (token) {
        token = strtok(NULL, ",");
        if (token) {
            if (m % 10 == 0){
                coord = (double *) realloc(coord, sizeof(double) * (TAM + m));
            }

            m++; /* Ao ler uma nova coordenada, atualiza a dimensão dos pontos */
            coord[m] = strtod(token, NULL);
        }
    }

    Ponto* novoPonto = initPonto(idPonto, coord, 0);
    push(p, novoPonto);
}

Pilha *leArquivo(FILE *fp, Pilha *p) {
    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;

    int m = 0, n = 1;
    double *coords = NULL;

    /* Get the first line of the file. */
    getline(&line_buf, &line_buf_size, fp);

    char *token = strtok(line_buf, ","); /* pega o id do  */
    char *idPonto = strdup(token);

    while (token) {
        token = strtok(NULL, ",");
        if (token) {
            if (m % 10 == 0){
                coords = (double *) realloc(coords, sizeof(double) * (TAM + m));
            }

            coords[m] = strtod(token, NULL);
            m++; /* Ao ler uma nova coordenada, atualiza a dimensão dos pontos */
        }
    }

    Ponto* novoPonto = initPonto(idPonto, coords, 0);
    push(p, novoPonto);

    getline(&line_buf, &line_buf_size, fp);

    /* Loop through until we are done with the file. */
    while (!feof(fp)) {
        /* Increment our line count */
        line_count++;

        /* Show the line details */
        // printf("line[%06d]: contents: %s", line_count, line_buf);
        token = NULL;
        token = strtok(line_buf, ",");
        idPonto = strdup(token);

        coords = (double*) malloc(sizeof(double) * m);
        for (int i = 0; i < m; ++i) {
            token = strtok(NULL, ",");
            coords[i] = strtod(token, NULL);
        }

        novoPonto = initPonto(idPonto, coords, line_count);
        push(p, novoPonto);

        /* Get the next line */
        getline(&line_buf, &line_buf_size, fp);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;

    /* Close the file now that we are done with it */
    fclose(fp);

    return p;
}
