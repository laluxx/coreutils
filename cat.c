#include <stdio.h>
#include <stdlib.h>

void printFile(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    
    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror(argv[i]);
            continue;
        }
        printFile(file);
        fclose(file);
    }

    return 0;
}
