#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    const char *file1 = *(const char **)a;
    const char *file2 = *(const char **)b;
    return strcmp(file1, file2);
}

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    char *entries[1024];
    int count = 0;
    bool show_all = false;
    const char *path = ".";  // Default path is the current directory

    // Check arguments for -a flag and directory path
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            show_all = true;
        } else {
            path = argv[i];
        }
    }

    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory '%s': %s\n", path, strerror(errno));
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL && count < 1024) {
        if (show_all || entry->d_name[0] != '.') {  // Skip hidden files unless -a is specified
            entries[count++] = strdup(entry->d_name); // Duplicate and store the name
        }
    }
    closedir(dir);

    // Sort the entries alphabetically
    qsort(entries, count, sizeof(char *), compare);

    // Print sorted directory entries
    for (int i = 0; i < count; i++) {
        printf("%s  ", entries[i]);  // Adjust the formatting if necessary
        free(entries[i]); // Free the duplicated strings
    }
    printf("\n");  // Print a newline at the end

    return EXIT_SUCCESS;
}






/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <dirent.h> */
/* #include <errno.h> */
/* #include <string.h> */

/* int compare(const void *a, const void *b) { */
/*     // Helper function for sorting directory entries alphabetically */
/*     const char *file1 = *(const char **)a; */
/*     const char *file2 = *(const char **)b; */
/*     return strcmp(file1, file2); */
/* } */

/* int main(int argc, char **argv) { */
/*     DIR *dir; */
/*     struct dirent *entry; */
/*     const char *path = (argc > 1) ? argv[1] : "."; */
/*     char *entries[1024]; // Array to store directory entries */
/*     int count = 0; */

/*     dir = opendir(path); */
/*     if (dir == NULL) { */
/*         fprintf(stderr, "Error opening directory '%s': %s\n", path, strerror(errno)); */
/*         return EXIT_FAILURE; */
/*     } */

/*     while ((entry = readdir(dir)) != NULL && count < 1024) { */
/*         if (entry->d_name[0] != '.') {  // Skip hidden files */
/*             entries[count++] = strdup(entry->d_name); // Duplicate and store the name */
/*         } */
/*     } */
/*     closedir(dir); */

/*     // Sort the entries alphabetically */
/*     qsort(entries, count, sizeof(char *), compare); */

/*     // Print sorted directory entries */
/*     for (int i = 0; i < count; i++) { */
/*         printf("%s  ", entries[i]); */
/*         free(entries[i]); // Free the duplicated strings */
/*     } */

/*     return EXIT_SUCCESS; */
/* } */
