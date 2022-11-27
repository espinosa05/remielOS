#if !defined(VGA_H)
#define VGA_H

#include <remiel/types.h>

#define VGA_TEXT_MEM_BASE 0xb8000
#define VGA_25_80_TEXT_MAX_OFFSET 2000
#define VGA_TEXT_MAX_CURSOR_OFFSET VGA_25_80_TEXT_MAX_OFFSET
#define VGA_25_80_TEXT_MEM_SIZE (VGA_25_80_TEXT_MAX_OFFSET * 2)

struct vga_info
{
    u8 fg_color;
    u8 bg_color;
};

struct vga_font_info
{
    int n_chars;
};

void vga_text_mode_draw_char(char c, int offset);
void vga_gfx_mode_draw_char(char c, int offset);

void vga_set_font(u8 *font);

void vga_set_bg_color(void *bg);
void vga_set_fg_color(void *fg);



#endif /* VGA_H */
