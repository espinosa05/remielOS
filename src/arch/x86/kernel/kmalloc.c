#include "kmalloc.h"
#include <memory.h>
#include <remiel/types.h>
#include <remiel/errno.h>
#include <remiel/assertions.h>

u8 kernel_heap[KERNEL_HEAP_MEMORY_SIZE] __set_section(".kernel_heap");
u8 eternal_kernel_heap[ETERNAL_KERNEL_HEAP_MEMORY_SIZE] __set_section(".kernel_heap");

static struct kmalloc_stats s_internal_kmalloc_stats = {0};
static struct eternal_kmalloc_stats s_eternal_heap_kmalloc_stats = {0};

struct internal_kmalloc_stats get_internal_kmalloc_stats()
{
  return s_internal_kmalloc_stats;
}

static struct chunk_header *get_prev_header(struct chunk_header current_header)
{
  return current_header.prev;
}

void *__kmalloc_eternal(size_t nbytes)
{
    static int eternal_heap_offset_tracer = 0;

    eternal_heap_offset_tracer += nbytes;
    if (eternal_heap_offset_tracer > eternal_heap_pool)
      {
        set_remiel_errno(-ENOMEM);
        return NULL;
      }

}

void *kmalloc(size_t nbytes)
{
  if (get_internal_kmalloc_stats().)
    {
      set_remiel_errno(-ENOMEM);
      return NULL;
    }

}

void *kfree(void *ptr)
{
  struct chunk_header header = *((struct chunk_header*)(ptr - sizeof(struct chunk_header)));
  if (header.prev != NULL)
    {
      get_prev_header(header)->next = header.next;
    }
  struct chunk_footer *chunk_end = (struct chunk_footer *)(header.next - sizeof(struct chunk_footer));

  ASSERT_OR_RETURN(check_signature(chunk_end), NULL)

}

bool check_signature(struct chunk_footer *end)
{
  return !!(chunk_end.signature & CHUNK_FOOTER_SIGNATURE);
}
