#include <stdio.h>

void _write_in_json_file() {
    char *text, *base;
    text = malloc(10 * sizeof(char));
    base = malloc(10 * sizeof(char));

    sprintf(text, "%d", 1);
    strcat(base, "tree");
    strcat(base, text);
    strcat(base, ".json");

    FILE *file;
    file = fopen(base, "a");

    if (file == NULL) {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    } else {
        fprintf(file, "%s", json);
    }

    fclose(file);
    free(base);
    free(text);
}