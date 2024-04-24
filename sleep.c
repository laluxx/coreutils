#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        return 0;
    }

    if (strchr(argv[1], '.') != NULL) {
        float time = atof(argv[1]);
        usleep(time * 1000000);
    } else {
        int time = atoi(argv[1]);
        sleep(time);
    }
    
    return 0;
}
