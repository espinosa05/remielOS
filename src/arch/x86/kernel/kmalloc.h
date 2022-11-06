#if !defined(KMALLOC_H)
#define KMALLOC_H
#include <remiel/types.h>

#include "common_attributes.h"
#define KERNEL_HEAP_MEMORY_SIZE   0x100000
#define CHUNK_FOOTER_SIGNATURE    0xaa55aa55aa55aa55U

struct chunk_header
  {
    struct chunk_header *prev;
    struct chunk_header *next;
  }__packed;

struct chunk_footer
  {
    u64 signature;
  }__packed;

struct erternal_kmalloc_stats
  {
    size_t heap_offset_tracer;
    void *pool_start;
    void *pool_end;
  }__packed;

static struct chunk_header *get_prev_header(struct chunk_header current_header);
void *kmalloc(size_t nbytes, int flags);
void *kfree(void *ptr);
bool check_signature(struct chunk_footer *end);

#endif /* KMALLOC_H */
