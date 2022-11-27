#include "vga.h"

#include <remiel/types.h>
#include "memory.h"

#define VGA_TEXT_COLUMNS 80
#define VGA_TEXT_ROWS 25
#define VGA_TEXT_COLOR_OFFSET 1
#define UPDATE_VGA_TEXT_COLOR(fg, bg) (bg | (fg << 4))

static struct vga_info      s_vga_info = {0};
static struct vga_font_info s_font_info;
static u8                   *s_font;


void vga_set_fg(void *fg)
{
  s_vga_info.fg_color = *((u8*)fg);
}

void vga_set_bg(void *bg)
{
  s_vga_info.bg_color = *((u8*)bg);
}

void vga_text_mode_draw_char(char c, int offset)
{
  u16 *vga_char_cell = ((u16 *)VGA_TEXT_MEM_BASE);
  vga_char_cell[offset * sizeof(vga_char_cell)] = (c | UPDATE_VGA_TEXT_COLOR(s_vga_info.fg_color, s_vga_info.bg_color) << 8);
}

void vga_set_font(u8 *font)
{

}

void vga_graphics_mode_draw_char(char c, int offset)
{

}
