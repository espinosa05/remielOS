#if !defined(IO_H)
#define IO_H

#include "remiel/types.h"

void outb(u16 port, u8 byte);
u8 inb(u16 port);

void outw(u16 port, u16 word);
u16 inw(u16 port);

void outl(u16 port, u32 dword);
u32 inl(u16 port);

#endif /* IO_H */
