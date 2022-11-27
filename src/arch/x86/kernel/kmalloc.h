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

struct kmalloc_stats
  {
    size_t available_heap_memory;
    size_t heap_memory_size;
  };

struct internal_kmalloc_stats
  {
    size_t available_memory;
    u32   nchunks;
    u32   (*get_chunk_offset)(int);
    void  *pool_start;
    void  *pool_end;
  };

struct internal_erternal_kmalloc_stats
  {
    signed heap_offset_tracer;
    void *pool_start;
    void *pool_end;
  };

static struct internal_erternal_kmalloc_stats get_internal_eternal_kmalloc_stats();
static struct intenal_kmalloc_stats get_internal_kmalloc_stats();
static struct chunk_header *get_prev_header(struct chunk_header current_header);
void *kmalloc(size_t nbytes, int flags);
void *kfree(void *ptr);
u32 __get_chunk_offset(int chunk_selector);
bool is_valid_chunk_selector(int chunk_selector);
bool check_signature(struct chunk_footer *end);

#endif /* KMALLOC_H */
