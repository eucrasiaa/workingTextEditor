#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "wcore_utils.h"

#define BUFFINCR 1028

enum BufferType{
  Original,
  Add,
};


typedef struct {
  // enum BufferType buffType;
  char *data;  // ptr to
  size_t size; // yea
  size_t capacity;  // for addbuffer
  int fd; // OR CAPACITY ON THE ADD BUFFER
} Buffer;

typedef struct {
  enum BufferType buffType;
  const char *buffer; 
  size_t start;
  size_t length;
} Piece;


typedef struct {
  Buffer* originalBuffer;
  Buffer* addBuffer;
} BufferContainer;



BufferContainer* wed_initialize();
Buffer* initAddBuffer();
int containerCleanup(BufferContainer* buffCont);
int pt();
