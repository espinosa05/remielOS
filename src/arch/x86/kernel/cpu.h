#if !defined(CPU_H)
#define CPU_H

#include <stdint.h>
#include <stdbool.h>
#include "registers.h"

// Vendor strings from CPUs.
#define CPUID_VENDOR_AMD           "AuthenticAMD"
#define CPUID_VENDOR_AMD_OLD       "AMDisbetter!"
#define CPUID_VENDOR_INTEL         "GenuineIntel"
#define CPUID_VENDOR_VIA           "VIA VIA VIA "
#define CPUID_VENDOR_TRANSMETA     "GenuineTMx86"
#define CPUID_VENDOR_TRANSMETA_OLD "TransmetaCPU"
#define CPUID_VENDOR_CYRIX         "CyrixInstead"
#define CPUID_VENDOR_CENTAUR       "CentaurHauls"
#define CPUID_VENDOR_NEXGEN        "NexGenDriven"
#define CPUID_VENDOR_UMC           "UMC UMC UMC "
#define CPUID_VENDOR_SIS           "SiS SiS SiS "
#define CPUID_VENDOR_NSC           "Geode by NSC"
#define CPUID_VENDOR_RISE          "RiseRiseRise"
#define CPUID_VENDOR_VORTEX        "Vortex86 SoC"
#define CPUID_VENDOR_AO486         "MiSTer AO486"
#define CPUID_VENDOR_AO486_OLD     "GenuineAO486"
#define CPUID_VENDOR_ZHAOXIN       "  Shanghai  "
#define CPUID_VENDOR_HYGON         "HygonGenuine"
#define CPUID_VENDOR_ELBRUS        "E2K MACHINE "

// Vendor strings from hypervisors.
#define CPUID_VENDOR_QEMU          "TCGTCGTCGTCG"
#define CPUID_VENDOR_KVM           " KVMKVMKVM  "
#define CPUID_VENDOR_VMWARE        "VMwareVMware"
#define CPUID_VENDOR_VIRTUALBOX    "VBoxVBoxVBox"
#define CPUID_VENDOR_XEN           "XenVMMXenVMM"
#define CPUID_VENDOR_HYPERV        "Microsoft Hv"
#define CPUID_VENDOR_PARALLELS     " prl hyperv "
#define CPUID_VENDOR_PARALLELS_ALT " lrpepyh vr "
#define CPUID_VENDOR_BHYVE         "bhyve bhyve "
#define CPUID_VENDOR_QNX           " QNXQVMBSQG "

/* Eflags bits  */

#define CF_BIT  (1)
#define PF_BIT  (1 << 2)
#define AF_BIT  (1 << 4)
#define ZF_BIT  (1 << 6)
#define SF_BIT  (1 << 7)
#define OF_BIT  (1 << 8)

#define clc()   asm("clc")
#define cld()   asm("cld")
#define cli()   asm("cli")
#define cmc()   asm("cmc")
#define stc()   asm("stc")
#define std()   asm("std")
#define sti()   asm("sti")

#define IS_FLAG_SET(flag) !!(flag & get_flags())

extern u32 get_flags();

extern u32 read_cr4();
extern void write_cr4(u32 cr4);
extern u32 rdmsr(u32 base_address, u32 edx, u32 eax);
extern void wrmsr(u32 base_address, u32 low_value, u32 high_value);

static void cpuid(int function_number, struct gp_registers32 *regs32);
void get_cpu_vendor_string(struct gp_registers32 regs32, char *buffer);


#endif /* CPU_H */
