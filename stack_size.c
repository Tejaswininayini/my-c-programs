#include <stdlib.h>
#include <string.h>

char** solution(const char* line, int* out_size) {
    int len = strlen(line);
    char* copy = (char*)malloc(len + 1);
    strcpy(copy, line);

    int top = 0;

    char* token = strtok(copy, ",");
    while (token != NULL) {
        if (strcmp(token, "BACK") == 0) {
            if (top > 0) top--;
        } else if (strcmp(token, "PEEK") == 0) {
            // do nothing
        } else {
            top++;
        }
        token = strtok(NULL, ",");
    }

    char** result = (char*)malloc(sizeof(char));
    result[0] = (char*)malloc(12);
    sprintf(result[0], "%d", top);
    *out_size = 1;
    free(copy);
    return result;
}
