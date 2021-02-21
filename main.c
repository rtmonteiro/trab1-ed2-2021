#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto ponto;
typedef struct Lista lista;
typedef struct Celula celula;

struct Ponto {
    char *id;
    int *pontos;
};

struct Lista {
    celula *prim;
};

struct Celula {
    void *conteudo;
    celula *prox;
};

int main(int argc, char** argv ) {

    char *FILENAME = argv[1];

    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", FILENAME);
        return EXIT_FAILURE;
    }

    int m = -1;
    /* Get the first line of the file. */
    getline(&line_buf, &line_buf_size, fp);
    char *token = strtok(line_buf, ",");
    printf("ponto %s: ", token);
    while (token) {
        token = strtok(NULL, ",");
        double coord;
        if (token) {
            coord = strtod(token, NULL);
            printf("%f ", coord);
        }
        m++;
    }
    printf("\n");

    getline(&line_buf, &line_buf_size, fp);

    /* Loop through until we are done with the file. */
    while (!feof(fp)) {
        /* Increment our line count */
        line_count++;

        /* Show the line details */
        // printf("line[%06d]: contents: %s", line_count, line_buf);
        token = NULL;
        token = strtok(line_buf, ",");
        printf("ponto %s: ", token);
        for (int i = 0; i < m; ++i) {
            token = strtok(NULL, ",");
            double coord = strtod(token, NULL);
            printf("%f ", coord);
        }
        printf("\n");

        /* Get the next line */
        getline(&line_buf, &line_buf_size, fp);

    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;

    /* Close the file now that we are done with it */
    fclose(fp);

    return EXIT_SUCCESS;
}
