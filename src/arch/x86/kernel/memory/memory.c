#include "memory.h"
#include <remiel/types.h>

__unmap_after_init
void __system_remiel_memcpy(void *src, void *dst, int size)
{
  for (int i = 0; i < size; ++i)
    {
      /* void pointers can't be written to */
      *((u8*)dst + i) = *((u8*)src + i);
    }
}
