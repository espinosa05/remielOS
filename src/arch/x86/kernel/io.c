#include "io.h"

void outb(u16 port, u8 byte)
{
  asm ("outb %0, %1" :: "a"(byte), "Nd"(port));
}

u8 inb(u16 port)
{
  u8 byte;
  asm("inb %1, %0" : "=a"(byte): "Nd"(port));
  return byte;
}

void outw(u16 port, u16 word)
{
  asm("outw %0, %1" :: "a"(word), "Nd"(port));
}

u16 inw(u16 port)
{
  u16 word;
  asm("inw %1, %0" : "=a"(word) : "Nd"(port));
  return word;
}

void outl(u16 port, u32 dword)
{
  asm("outl %0, %1" :: "a"(dword) , "Nd"(port));
}

u32 inl(u16 port)
{
  u32 dword;
  asm ("inl %1, %0": "=a"(dword) : "Nd"(port));
  return dword;
}