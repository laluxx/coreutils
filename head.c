#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// TODO fix -c flag add -q/--quiet add -v/--verbose  add z/--zero-terminated

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Concatenate Files\nusage: cat [FILE]...\n");
        return 0;
    } else {
        FILE *file;

        bool skip = false;
        int maxlines = 10;
        int nfiles = argc;
        int bytes = 0;
        int maxbytes = 0;
        bool shouldUseBytes = 0;

        for (int i = 1; i < argc; i++) {
            if (i == 1) {
                bytes = 0;
            }
            
            if (skip) {
                nfiles--;
                skip = false;
                if (shouldUseBytes) {
                    maxbytes = atoi(argv[i]);
                } else {
                    maxlines = atoi(argv[i]);
                }
                continue;
            }
            
            if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--lines") == 0) {
                nfiles--;
                skip = true;
                continue;
            }

            if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
                nfiles--;
                skip = true;
                shouldUseBytes = true;
                continue;
            }

            file = fopen(argv[i], "r");
            if (file == NULL) {
                perror(argv[i]);
                continue;
            }

            if (nfiles > 3) {
                printf("==> %s <==\n", argv[i]);
            }

            int c;
            int linecount = 0;
            while (linecount < maxlines && (c = fgetc(file)) != EOF) {
                if (bytes == maxbytes) {
                    putchar('\n');
                    break;
                }
                bytes++;
                
                if (c == 10) linecount++;
                putchar(c);
            }
            putchar('\n');
            printf("Bytes = %d", bytes);
            fclose(file);
        }
    }
    return 0;
}
