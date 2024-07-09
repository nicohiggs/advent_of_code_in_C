// some context OS and compiler flags here

// helper macros

#define Stmnt(S)                                                               \
  do {                                                                         \
    S                                                                          \
  } while (0)

#if !defined(AssertBreak)
#define AssertBreak() (*(int *)0 = 0) // "crash" eventually add some output
#endif

#if ENABLE_ASSERT
#define Assert(c) Stmnt(if (!(c)) { AssertBreak(); })
#else
#define Assert(c)
#endif

#define Stringify_(S) #S
#define Stringify(S) Stringify_(S)
#define Glue_(A, B) A##B
#define Glue(A, B) Glue_(A, B)

#define ArrayCount(a) (sizeof(a) / sizeof(*(a)))

#define IntFromPtr(p) (unsigned long long)((char *)p - (char *)0)
#define PtrFromInt(n) (void *)((char *)0 + (n))

#define Member(T, m) (((T *)0)->m)
#define OffsetOfMember(T, m) IntFromPtr(&Member(T, m))

#define Min(a, b) (((a) < (b)) ? (a) : (b))
#define Max(a, b) (((a) > (b)) ? (a) : (b))
#define Clamp(a, x, b) (((x) < (a)) ? (a) : ((b) < (x)) ? (b) : (x))
#define ClampTop(a, b) Min(a, b)
#define ClampBot(a, b) Max(a, b)

#define global static
#define local static
#define function static

#define c_linkage_begin extern "C" {
#define c_linkage_end }
#define c_linkage extern "C"

#include <string.h>
#define MemoryZero(p, z) memset((p), 0, (z))
#define MemoryZeroStruct(p) MemoryZero((p), sizeof(*(p)))
#define MemoryZeroArray(p) MemoryZero((p), sizeof(p))
#define MemoryZeroTyped(p, c) MemoryZero((p), sizeof(*(p)) * (c))

#define MemoryMatch(a, b, z) (memcmp((a), (b), (z)) == 0)

#define MemoryCopy(d, s, z) memmove((d), (s), (z))
#define MemoryCopyStruct(d, s)                                                 \
  MemoryCopy((d), (s), Min(sizeof(*(d)), sizeof(*(s))))
#define MemoryCopyArray(d, s) MemoryCopy((d), (s), Min(sizeof(s), sizeof(d)))
#define MemoryCopyTyped(d, s, c)                                               \
  MemoryCopy((d), (s), Min(sizeof(*(d)), sizeof(*(s))) * (c))
