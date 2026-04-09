#pragma once
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "piecetable.h"



typedef struct {
    char *data;      // ptr 
    size_t size;     // size 
    FILE *stream;    // getline file ptr 
    int fd;          // mmap file descritor 
    bool is_mapped;  // munmap() or free() 
} FileHandle;



int i_addToExistingContainer(const char *path, BufferContainer* buffContainer);
void i_munmap(Buffer *rb);


// bool fw_open_read(FileHandle *h, const char *path);
// char* fw_read_line(FileHandle *h); // getline wrap
// bool fw_map_file(FileHandle *h, const char *path); // mmap wrap 
// void fw_close(FileHandle *h); // cleaner
//
//

