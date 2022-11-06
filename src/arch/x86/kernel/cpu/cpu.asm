
; 64-bit version meant to be called from C-code

section .text

; @param    = (void)
; @return   = (uint32_t) eflags contents
global get_flags
get_flags:
  push  rbp
  mov   rbp, rsp
  pushfq
  popfq
  pop   rbp
  ret



; @param    = (uint32_t) updated bits
; @return   = (void)
global write_cr4
write_cr4:
  push  rbp
  mov   rbp, rsp
  mov   ebx, DWORD [rbp - 4]
  mov   eax, cr4
  or    eax, ebx
  mov   cr4, eax
  pop   rbp
  ret



; @param    = (void)
; @return   = (uint32_t) contents of control register 4
global read_cr4
read_cr4:
  push  rbp
  mov   rbp, rsp
  mov   eax, cr4
  pop   rbp
  ret



; @param    = (uint32_t) msr_base_addres,
;             (uint32_t) msr_low_value,
;             (uint32_t) msr_high_value
; @return   = (void)
global __wrmsr
__wrmsr:
  push  rbp
  mov   rbp, rsp
  mov   ecx, DWORD [rbp - 4]    ; msr_base_address
  mov   edx, DWORD [rbp - 8]    ; msr_low_value
  mov   eax, DWORD [rbp - 12]   ; msr_high_value
  wrmsr
  pop   rbp
  ret



; @param    = (uint32_t) base address of msr,
;             (uint32_t *) lower msr,
;             (uint32_t *) higher msr
; @return   = (void)
global __rdmsr
__rdmsr:
  push  rbp
  mov   rbp, rsp
  mov   ecx, DWORD [rbp - 4]    ; base_address
  rdmsr
  mov   DWORD [rbp - 8], edx    ; edx
  mov   DWORD [rbp - 12], eax   ; eax
  pop   rbp
  ret
