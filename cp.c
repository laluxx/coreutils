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

    // Loop through each file provided in the arguments
    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror(argv[i]); // Print error if file can't be opened
            continue;
        }
        printFile(file);
        fclose(file);
    }

    return 0;
}
