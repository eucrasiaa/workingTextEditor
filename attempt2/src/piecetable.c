#include "piecetable.h"
#include "read_write.h"
int pt(){
  return 1;
}

Buffer* initAddBuffer(){
    Buffer *addBuff=safe_malloc(sizeof(Buffer));
    addBuff->data=safe_malloc(sizeof(char)*BUFFINCR);

    addBuff->capacity=BUFFINCR;
    addBuff->size=0;
    addBuff->fd=0;
    return addBuff;
}

BufferContainer* wed_initialize(){
  BufferContainer *theInit = safe_malloc(sizeof(BufferContainer));
  theInit->addBuffer=NULL;
  theInit->originalBuffer=NULL;
  theInit->addBuffer=initAddBuffer();

  return theInit;

}

int buff_append(Buffer *toAddBuff, const char *to_add, size_t len) {
    if (toAddBuff->size + len > toAddBuff->capacity) {
        size_t new_cap = toAddBuff->capacity * 2 + len; 
        
        char *temp = realloc(toAddBuff->data, new_cap);
        if (!temp) return -1; 
        toAddBuff->data = temp;
        toAddBuff->capacity = new_cap;
    }
    memcpy(toAddBuff->data + toAddBuff->size, to_add, len);
    toAddBuff->size += len;
    return 0; // Success
}


int containerCleanup(BufferContainer* buffCont){
  if(buffCont==NULL){
    return -1;
  }
  if (buffCont->originalBuffer != NULL){
    i_munmap(buffCont->originalBuffer);    
  }
  if(buffCont->addBuffer !=NULL){
    if(buffCont->addBuffer->data !=NULL){
      free(buffCont->addBuffer->data);
    }
    free(buffCont->addBuffer);
  }
  free(buffCont);
  return 0; 
}
