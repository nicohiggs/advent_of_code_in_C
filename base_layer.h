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
