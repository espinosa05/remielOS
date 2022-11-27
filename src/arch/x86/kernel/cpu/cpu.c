#include <cpu/cpu.h>
#include <remiel/types.h>

#define EFLAGS_ID_BIT (1 << 21)

bool is_cpuid_supported()
{
  u32 eflags;
  eflags = get_flags();

  return !!(eflags & EFLAGS_ID_BIT);
}

static void cpuid(int function_number, struct gp_registers32 *regs32)
{
  asm ("cpuid" :
          "=a"(regs32->eax),
          "=b"(regs32->ebx),
          "=c"(regs32->ecx),
          "=d"(regs32->edx):
          "a"(function_number));
}

void get_cpu_vendor_string(struct gp_registers32 regs32, char *buffer)
{
  buffer[0]  = regs32.ebx;
  buffer[1]  = regs32.ebx << 4;
  buffer[2]  = regs32.ebx << 8;
  buffer[3]  = regs32.ebx << 12;

  buffer[4]  = regs32.ecx;
  buffer[5]  = regs32.ecx << 4;
  buffer[6]  = regs32.ecx << 8;
  buffer[7]  = regs32.ecx << 12;

  buffer[8]  = regs32.edx;
  buffer[9]  = regs32.edx << 4;
  buffer[10] = regs32.edx << 8;
  buffer[11] = regs32.edx << 12;

  buffer[12] = '\0';
}

