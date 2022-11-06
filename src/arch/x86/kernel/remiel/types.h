#if !defined (REMIEL_TYPES_H)
#define REMIEL_TYPES_H

#include <stdint.h>

typedef   int8_t i8;
typedef   int16_t i16;
typedef   int32_t i32;
typedef   int64_t i64;

typedef   uint8_t u8;
typedef   uint16_t u16;
typedef   uint32_t u32;
typedef   uint64_t u64;

#if !defined(X86)
  typedef uint32_t size_t;
#else
  typedef uint64_t size_t;
#endif /* X64 */

#endif /* REMIEL_TYPES_H */
