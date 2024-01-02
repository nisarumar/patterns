#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t require_bytes, size_t alignment)
{
    void** p2;
    
    size_t offset = alignment - 1 + sizeof(void*);

    void * p = malloc(require_bytes+ offset);

    if (p==NULL)
        return NULL;

    p2 = (void**) ( ( (size_t) p + offset ) & ~(alignment-1) );

    p2[-1] = p;

    return p2;
}

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}


int main ()
{
    void * p3;
    p3 = aligned_malloc(100, 16);
    aligned_free(p3);
    return 0;
}
