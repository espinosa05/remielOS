#if !defined(COMMON_ATTRIBUTES_H)
#define COMMON_ATTRIBUTES_H

#define __always_inline     __attribute__((always_inline))
#define __set_section(symbol) __attribute__((section(symbol)))
#define __noreturn          __attribute__((noreturn))
#define __packed            __attribute__((packed))

#endif /* COMMON_ATTRIBUTES_H */
