#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO When there is only one argument // it should listen to std-in
// TODO Unfinished

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }
    if (argc > 1 && strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Concatenate Files\nusage: cat [FILE]...\n");
        return 0;
    } else {
        FILE *file;
        int shift = 0;
        for (int i = 1; i < argc; i++) {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                perror(argv[i]);
                continue;
            }
            int c;
            while ((c = fgetc(file)) != EOF) {
                putchar(c);
            }
            putchar('\n');
            fclose(file);
        }
    }
    return 0;
}
