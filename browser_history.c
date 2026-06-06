#include <stdlib.h>
#include <string.h>

char** solution(const char* line, int* out_size) {
    int len = strlen(line);
    char* copy = (char*)malloc(len + 1);
    strcpy(copy, line);
    
    char* last = copy;
    char* p = copy;
    
    while (*p) {
        if (*p == ',') last = p + 1;
        p++;
    }
    
    char** result = (char*)malloc(sizeof(char));
    result[0] = (char*)malloc(strlen(last) + 1);
    strcpy(result[0], last);
    *out_size = 1;
    
    free(copy);
    return result;
}
