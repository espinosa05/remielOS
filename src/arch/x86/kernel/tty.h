#if !defined(TTY_H)
#define TTY_H

#define TTY_ORIGIN 0

enum tty_colors_16
{
    TTY_BLACK_16 = 0,
    TTY_BLUE_16,
    TTY_GREEN_16,
    TTY_CYAN_16,
    TTY_RED_16,
    TTY_MAGENTA_16,
    TTY_LIGHT_GREY_16,
    TTY_GREY_16,
    TTY_LIGHT_BLUE_16,
    TTY_LIGHT_GREEN_16,
    TTY_LIGHT_CYAN_16,
    TTY_LIGHT_RED_16,
    TTY_LIGHT_MAGENTA_16,
    TTY_YELLOW_16,
    TTY_WHITE_16
};

extern void (*_set_fg_color)(void *);
extern void (*_set_bg_color)(void *);

struct console_info
{
    int n_char_cells;
    int color_depth;
};

struct tty_ctx
{
    int cursor_pos;
    int max_cursor_pos;
    void *fg_color;
    void *bg_color;
};
enum text_driver_indeces
{
    VGA_DEFAULT_DRIVER,
    EGA_DEFAULT_DRIVER,
    NUM_OF_DEFAULT_DRIVERS
};

/*
 * every graphics driver needs to
 * at least implement these functions
 * to operate in a text mode
 * */
struct tty_functions
{
    void (*draw_char) (char, int);
    void (*set_fg_color)(void *);
    void (*set_bg_color)(void *);
};

void tty_write_char(char c);
void clear_screen();
void tty_write_string(const char *str);
void tty_set_fg_color(int color);
void tty_set_bg_color(int color);

static void __setup_tty_functions();
static void __setup_tty_info(struct tty_info *global_tty_info);

#endif /* TTY_H */
