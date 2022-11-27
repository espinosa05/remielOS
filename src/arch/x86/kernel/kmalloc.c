#include "kmalloc.h"

#include <memory.h>
#include <remiel/types.h>
#include <remiel/errno.h>
#include <remiel/assertions.h>

u8 kernel_heap[KERNEL_HEAP_MEMORY_SIZE] __set_section(".kernel_heap");
u8 eternal_kernel_heap[ETERNAL_KERNEL_HEAP_MEMORY_SIZE] __set_section(".kernel_heap");

static struct internal_kmalloc_stats s_internal_kmalloc_stats = {0};
static struct internal_erternal_kmalloc_stats s_eternal_heap_kmalloc_stats = {0};

struct kmalloc_stats get_internal_kmalloc_stats()
{
  return s_internal_kmalloc_stats;
}

static struct chunk_header *get_prev_header(struct chunk_header current_header)
{
  return current_header.prev;
}

void *__kmalloc_eternal(size_t nbytes)
{
  struct internal_erternal_kmalloc_stats current_eternal_kmalloc_stats = get_internal_eternal_kmalloc_stats();
  if ((current_eternal_kmalloc_stats.heap_offset_tracer += nbytes) > ETERNAL_KERNEL_HEAP_MEMORY_SIZE)
    {
      __set_remiel_internal_errno(-ENOMEM);
      return NULL;
    }
  return (void*)&eternal_kernel_heap[current_eternal_kmalloc_stats.heap_offset_tracer - nbytes];
}

void *kmalloc(size_t nbytes)
{
  if (get_internal_kmalloc_stats().)
    {
      __set_remiel_internal_errno(-ENOMEM);
      return NULL;
    }

}

void *kfree(void *ptr)
{
  struct chunk_header current_header = *((struct chunk_header*)(ptr - sizeof(struct chunk_header)));
  if (current_header.prev != NULL)
    {
      get_prev_header(header)->next = current_header.next;
    }
  struct chunk_footer *chunk_end = (struct chunk_footer *)(current_header.next - sizeof(struct chunk_footer));

  ASSERT_OR_RETURN_VAL(check_signature(chunk_end),  NULL);

}

u32 __get_chunk_offset(int chunk_selector)
{
    struct chunk_header chunk_tracer = *(struct chunk_header *)get_internal_kmalloc_stats().pool_start;
    ASSERT_OR_RETURN_VAL((chunk_tracer.prev != NULL), -1);
    u32 offset = 0;

    while (chunk_tracer != 0)
      {
        offset += get_ptr_diff(chunk_tracer.prev, chunk_tracer.next);
        chunk_tracer = *chunk_tracer.next;
      }
    return offset;
}

bool is_valid_chunk_selector(int chunk_selector)
{
  return (__get_chunk_offset(chunk_selector) < KERNEL_HEAP_MEMORY_SIZE);
}

bool check_signature(struct chunk_footer *end)
{
  return (chunk_end.signature == CHUNK_FOOTER_SIGNATURE);
}
