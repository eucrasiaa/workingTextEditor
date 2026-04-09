#include "read_write.h"

Buffer* i_mmap_readonly(const char *path) {
  int fd = open(path, O_RDONLY);
  if (fd == -1) return NULL;

  struct stat st;
  if (fstat(fd, &st) == -1) {
    close(fd);
    return NULL;
  }
  void *mapped = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (mapped == MAP_FAILED) {
    close(fd);
    return NULL;
  }

  Buffer *origBuff = malloc(sizeof(Buffer));
  origBuff->data = (char *)mapped;
  origBuff->size = st.st_size;
  origBuff->fd = fd;
  origBuff->capacity=st.st_size;
  return origBuff;
}

int i_addToExistingContainer(const char* path, BufferContainer* buffContainer){
  //ensure empty otherwise bad memleak?
  assert(buffContainer->originalBuffer == NULL);
  

  int fd = open(path, O_RDONLY);
  if (fd == -1) return -1;

  struct stat st;
  if (fstat(fd, &st) == -1) {
    close(fd);
    return -1;
  }
  void *mapped = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (mapped == MAP_FAILED) {
    close(fd);
    return -1;
  }

  Buffer *origBuff = safe_malloc(sizeof(Buffer));
  origBuff->data = (const char *)mapped;
  origBuff->size = st.st_size;
  origBuff->fd = fd;
  origBuff->capacity=st.st_size;
  buffContainer->originalBuffer = origBuff;
  return 0;


}


void i_munmap(Buffer *origBuff) {
  if (!origBuff) return;
  munmap((void*)origBuff->data, origBuff->size);
  close(origBuff->fd);
  free(origBuff);
}
