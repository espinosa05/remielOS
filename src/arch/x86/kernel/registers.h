#if !defined(REGISTERS_H)
#define REGISTERS_H

#include <stdint.h>

struct gp_registers32
{
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
};

#endif /* REGISTERS_H */
