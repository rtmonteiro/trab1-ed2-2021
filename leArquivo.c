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
    
    // pega o id do ponto 
    char* token = strtok(line_buf, ","); 

    while (token) {
        token = strtok(NULL, ",");
        // Ao ler uma nova coordenada, atualiza a dimensão dos pontos
        if (token) 
            m++; 
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
    
    //le o resto do arquivo e retorna n
    char* line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;

    // ler primeira linha fora do loop
    getline(&line_buf, &line_buf_size, fp);

    // Loop para leitura das linhas
    while (!feof(fp)) {
        // contador de linhas
        line_count++;
        
        // id do ponto
        char *token = strtok(line_buf, ",");
        char* idPonto = strdup(token);

        // coordenadas do ponto
        double* coords = (double*) malloc(sizeof(double) * m);
        for (int i = 0; i < m; ++i) {
            token = strtok(NULL, ",");
            coords[i] = strtod(token, NULL);
        }

        Ponto* novoPonto = initPonto(idPonto, coords, line_count-1);
        push(p, novoPonto);

        // pega a proxima linha
        getline(&line_buf, &line_buf_size, fp);
    }

    
    free(line_buf);
    line_buf = NULL;
    fclose(fp);

    return p;
}
