#include <stdio.h>
#include "read_write.h"
#include "piecetable.h"


int main(int argc, char *argv[])
{
  BufferContainer* myBuffContainer = wed_initialize();
  i_addToExistingContainer("./testfiles/LibOfBabel.txt", myBuffContainer); 
  printf("%d\n",pt());
  printf("Hello, World");
  containerCleanup(myBuffContainer);
  return 0;
}
