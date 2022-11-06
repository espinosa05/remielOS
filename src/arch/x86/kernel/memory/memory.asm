section .text
global __system_remiel_memset

__system_remiel_memset:
  push    rbp
  mov     ebp, esp
  mov     al,     [rbp - 1]
  mov     ecx,    [rbp - 5]
  mov     edi,    [rbp - 9]

  rep stosb

  pop rbp

  ret
