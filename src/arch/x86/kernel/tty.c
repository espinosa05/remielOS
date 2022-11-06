#include "tty.h"
#include "memory.h"
#include "controller.h"

/*
 * Basic console driver that can later be used by virtually any console application
 * */

static struct tty_ctx       s_tty_ctx;

static struct tty_functions text_drivers[NUM_OF_DEFAULT_DRIVERS];

static struct tty_functions *s_tty_functions = NULL; /* will reference the appropiate drivers */

static struct console_info  s_console_info;


static void __setup_tty_functions(struct adapter video_adapter)
{

}

static void setup_initial_tty_driver()
{
}

void tty_set_fg(int color)
{
    *(int*)s_tty_ctx.fg_color = color;
    set_fg_color(s_tty_ctx.fg_color);
}

void tty_set_bg(int color)
{
  *(int*)s_tty_ctx.bg_color = color;
  set_bg_color(s_tty_ctx.bg_color);
}

void rewind_cursor()
{
  s_tty_ctx.cursor_pos = TTY_ORIGIN;
}

void clear_screen()
{
  for(int i = 0; i < s_tty_ctx.max_cursor_pos; i++)
    {
      s_tty_functions->draw_char(i, 0x00);
    }
}

void init_tty(struct adapter adapter_information)
{
  __setup_tty_functions(adapter_information);

  tty_set_fg_color(TTY_WHITE_16);
  tty_set_bg_color(TTY_BLACK_16);

  clear_screen();
  rewind_cursor();
}

void tty_write_string(const char *str)
{
  for(;*str; str++)
    {
      s_tty_functions->draw_char(s_tty_ctx.cursor_pos, *str);
      s_tty_ctx.cursor_pos++;
    }
}

