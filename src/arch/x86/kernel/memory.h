#if !defined(MEMORY_H)
#define MEMORY_H

#include <stdbool.h>
#include <remiel/types.h>
/* for __section() */
#include "common_attributes.h"
#include "registers.h"

#define NULL ((void *)0)

/* page privileges */
#define SUPERVISOR_PAGE_PRIV (1 << 2)
#define USER_PAGE_PRIV 0

/* section names */
#define __unmap_after_init __set_section(".unmap_after_init")


extern void __system_remiel_memset(void *dst, int32_t nbytes, char value);
void __system_remiel_memcpy(void *src, void *dst, int num);

u32 get_ptr_diff(void *ptr0, void *ptr1);
bool is_paging_supported();

#endif /* MEMORY_H */
