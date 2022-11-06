; externally linked symbols for the header

; load_addr field
extern _text_start

; load_end_addr field
extern _data_end

; bss_end_addr field
extern _bss_end

; entry_addr field
global  _start

section .multiboot

header_start:

  dd    0xE85250D6
  dd    0
  dd    (header_end - header_start)
  dd    0x100000000 - (0xE85250D6 + 0 + (header_end - header_start))

  dw    0
  dw    0
  dd    8
header_end:

extern _stack_top

section .boot
bits 32
_start:

  mov   byte[0xb8000], 'O'
  mov   byte[0xb8001], 0x1e
  mov   byte[0xb8002], 'K'
  mov   byte[0xb8003], 0x1e

  mov   esp, _stack_top

  mov   eax, 0xaa55aa55
  push  eax
  hlt
