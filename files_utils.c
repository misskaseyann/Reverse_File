//
// Created by Kasey Stowell on 9/28/17.
//

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//
// Reads a .txt file into a buffer.
// Returns size of file if successful.
//
int read_file(char* filename, char **buffer) {
    // load file so it is readable
    FILE *file;
    file = fopen(filename, "r");

    // error check for null value
    if (file == NULL) {
        printf("\n\nERROR: Not an existing file. Please provide an existing filename.\n\n");
    } else {
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
    }

    return size;
}

//
// Take a text file loaded into a buffer and reverse it.
// Saves as a .txt with the given file name.
//
int write_file(char* filename, char *buffer, int size) {
    // create writable file
    FILE *file;
    file = fopen(filename, "w+");

    // error check for null value
    if(file == NULL) {
        printf("\n\nERROR: Needs a new filename. Please provide a filename.\n\n");
    } else {
        // write from buffer backwards
        for(int i = size; i >= 0; i--)
            fwrite(&buffer[i], sizeof(char), 1, file);

        // clean up and close file
        fclose(file);
    }

    return 0;
}