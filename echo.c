#include <stdio.h>

// TODO -e
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (i == argc - 1) {
            printf("%s\n", argv[i]);
        } else {
            printf("%s ", argv[i]);       
        }
    }
    return 0;
}
