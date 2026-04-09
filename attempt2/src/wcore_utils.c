#include "wcore_utils.h"
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "fatal: malloc failed!??\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}



