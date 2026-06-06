#include <stdlib.h>
#include <string.h>

char** solution(const char* line, int* out_size) {
    int len = strlen(line);
    char* copy = (char*)malloc(len + 1);
    strcpy(copy, line);

    char* stack[100];
    int top = 0;

    char* token = strtok(copy, ",");
    while (token != NULL) {
        if (strcmp(token, "BACK") == 0) {
            if (top > 0) top--;
        } else if (strcmp(token, "PEEK") == 0) {
            // stack మారదు, continue
        } else {
            stack[top++] = token;
        }
        token = strtok(NULL, ",");
    }

    char** result = (char*)malloc(sizeof(char));
    if (top == 0) {
        result[0] = (char*)malloc(6);
        strcpy(result[0], "EMPTY");
    } else {
        result[0] = (char*)malloc(strlen(stack[top-1]) + 1);
        strcpy(result[0], stack[top-1]);
    }
    *out_size = 1;
    free(copy);
    return result;
}
