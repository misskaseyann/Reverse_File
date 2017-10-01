//
// Created by Kasey Stowell on 9/28/17.
//

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int bytes;
    char* buffer;

    // read file
    bytes = read_file(argv[1], &buffer);
    printf("Now reversing file:\n\n%s\n", buffer);

    // write file
    write_file(argv[2], buffer, bytes);
    printf("\nFile is now reversed and saved as %s in current folder.\n\n", argv[2]);

    // free memory
    free(buffer);

    return 0;
}