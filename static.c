#include <stdio.h>
#include <stdlib.h>

int main() {
    char* t = (char*)malloc(0);
    char* n = (char*)malloc(0);
    char* r = (char*)malloc(0);
    char* d = (char*)malloc(0);
    printf("%d %d %d\n", (int)(d - r), (int)(r - n), (int)(n - t));
    return 0;
}