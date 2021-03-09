//
// Created by Pichau on 02/03/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leArquivo.h"
#include "planoR.h"

#define TAM 10


static int leM(FILE *fp, PlanoR *p) {

    //le a primeira linha e retorna m
    char *line_buf = NULL;
    size_t line_buf_size = 0;

    int m = 0;

    getline(&line_buf, &line_buf_size, fp);

    char *token = strtok(line_buf, ","); /* pega o id do  */

    while (token) {
        token = strtok(NULL, ",");
        if (token) m++; /* Ao ler uma nova coordenada, atualiza a dimensão dos pontos */
    }

    free(line_buf);

    return m;
}

static int leN(FILE *fp, PlanoR *p) {
    //le o resto do arquivo e retorna n
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;

    while (!feof(fp)) {
        line_count++;
        getline(&line_buf, &line_buf_size, fp);
    }

    free(line_buf);

    return line_count;
}

PlanoR *leArquivo(char *FILENAMEINPUT, PlanoR *p) {
    FILE *fp = fopen(FILENAMEINPUT, "r");
    if (!fp) {
        fprintf(stderr, "Erro ao abrir arquivo '%s'\n", FILENAMEINPUT);
        exit(1);
    }

    int m = leM(fp, p);
    int n = leN(fp, p);

    fclose(fp);

    //le o arquivo de novo e retorna a pilha (vetor) com os pontos


    fp = fopen(FILENAMEINPUT, "r");
    if (!fp) {
        fprintf(stderr, "Erro ao abrir arquivo '%s'\n", FILENAMEINPUT);
        exit(1);
    }

    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;

    initVetorPontos (p, n, m);

    /* Loop through until we are done with the file. */
    for (int i = 0; i < n; ++i) {
        getline(&line_buf, &line_buf_size, fp);

        /* Show the line details */
        // printf("line[%06d]: contents: %s", line_count, line_buf);
        char *token = strtok(line_buf, ",");
        char *idPonto = strdup(token);

        double *coords = (double *) malloc(sizeof(double) * m);
        for (int j = 0; j < m; ++j) {
            token = strtok(NULL, ",");
            coords[j] = strtod(token, NULL);
        }

        Ponto *novoPonto = initPonto(idPonto, coords, i);
        insere(p, novoPonto, i);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;

    fclose(fp);

    return p;
}
