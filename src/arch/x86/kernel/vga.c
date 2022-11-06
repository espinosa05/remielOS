#include "vga.h"

#include <stdint.h>
#include "memory.h"

#define VGA_TEXT_COLUMNS 80
#define VGA_TEXT_ROWS 25
#define VGA_TEXT_COLOR_OFFSET 1
#define UPDATE_VGA_TEXT_COLOR(fg, bg) (bg | (fg << 4))

static struct vga_info      s_vga_info = {0};
static struct vga_font_info s_font_info;
static uint8_t              *s_font;


void vga_set_fg(void *fg)
{
  s_vga_info.fg_color = *((uint8_t*)fg);
}

void vga_set_bg(void *bg)
{
  s_vga_info.bg_color = *((uint8_t*)bg);
}

void vga_text_mode_draw_char(char c, int offset)
{
  uint16_t *vga_char_cell = ((uint16_t *)VGA_TEXT_MEM_BASE);

  vga_char_cell[offset * sizeof(vga_char_cell)] = (c | UPDATE_VGA_TEXT_COLOR(s_vga_info.fg_color, s_vga_info.bg_color) << 8);
}

void vga_set_font(uint8_t *font)
{

}

void vga_graphics_mode_draw_char(char c, int offset)
{

}
