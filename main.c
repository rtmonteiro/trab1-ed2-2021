#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

    int m = 0;
    /* Get the first line of the file. */
    getline(&line_buf, &line_buf_size, fp);
    char *token = strtok(line_buf, ","); /* pega o id do  */
    printf("ponto %s: ", token);
    double *coord = NULL;
    while (token) {
        token = strtok(NULL, ",");
        if (token) {
            m++; /* Ao ler uma nova coordenada, atualiza a dimensão dos pontos */
            coord = (double *) realloc(coord, sizeof(double) * (m + 1));
            coord[m] = strtod(token, NULL);
            printf("%f ", coord[m]);
        }
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
        double *coords = (double*) malloc(sizeof(double) * m);
        for (int i = 0; i < m; ++i) {
            token = strtok(NULL, ",");
            coords[i] = strtod(token, NULL);
            printf("%f ", coords[i]);
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
