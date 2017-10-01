//
// Created by Kasey Stowell on 9/28/17.
//

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

int read_file(char* filename, char **buffer) {
    // load file so it is readable
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("\n\nERROR: Not an existing file. Please provide an existing filename.\n\n");
        exit(0);
    }

    // find size of file in bytes
    fseek(file, 0, SEEK_END);
    int size = ftell(file) + 1;
    rewind(file);

    // place file into char buffer
    *buffer = (char*)malloc((size + 1) * sizeof(char));
    fread(*buffer, size, 1, file);
    buffer[size] = "\0";

    // clean up and close file
    fclose(file);

    return size;
}

int write_file(char* filename, char *buffer, int size) {
    // create writable file
    FILE *file;
    file = fopen(filename, "w+");
    if(file == NULL) {
        printf("\n\nERROR: Needs a new filename. Please provide a filename.\n\n");
        exit(0);
    }

    // write from buffer backwards
    for(int i = size; i >= 0; i--)
        fwrite(&buffer[i], sizeof(char), 1, file);

    // clean up and close file
    fclose(file);

    return 0;
}