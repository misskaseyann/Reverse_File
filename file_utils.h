//
// Created by Kasey Stowell on 9/28/17 based on Ira Woodring's 343 homework and lectures.
//

#ifndef REVERSEFILE_FILE_UTILS_H
#define REVERSEFILE_FILE_UTILS_H

// Reads a .txt file into a buffer.
int read_file(char* filename, char **buffer);

// Writes text from file backwards and saves as a .txt file.
int write_file(char* filename, char *buffer, int size);

#endif // REVERSEFILE_FILE_UTILS_H