
#ifndef _OSA_DEBUG_H_
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define _OSA_DEBUG_H_

#include <stdio.h>
#include <osa.h>

// printf wrapper that can be turned on and off by defining/undefining
#ifdef OSA_DEBUG_MODE

  #define OSA_printf(...)  do { printf(" [host   ] " __VA_ARGS__); fflush(stdout); } while(0)
  //# for debug - phoong
  #define xprn(x, ...)  printf(" [host   ] \033[42m %s(%d):\033[0m " x "\n" , __func__, __LINE__, ##__VA_ARGS__);

  #define OSA_assert(x)  \
  { \
    if( (x) == 0) { \
      fprintf(stderr, " ASSERT (%s|%s|%d)\r\n", __FILE__, __func__, __LINE__); \
      while (getchar()!='q')  \
        ; \
    } \
  }

    #define UTILS_assert(x)   OSA_assert(x)

#define OSA_DEBUG \
  fprintf(stderr, " %s:%s:%d Press Any key to continue !!!", __FILE__, __func__, __LINE__);


#define OSA_DEBUG_WAIT \
  OSA_DEBUG \
  getchar();

#define OSA_COMPILETIME_ASSERT(condition)                                       \
                   do {                                                         \
                       typedef char ErrorCheck[((condition) == TRUE) ? 1 : -1]; \
                   } while(0)

#else

  #define OSA_printf(...)
  #define OSA_assert(x)
  #define UTILS_assert(x)
  #define OSA_DEBUG
  #define OSA_DEBUG_WAIT
#endif

// printf wrapper that can be used to display errors. Prefixes all text with
// "ERROR" and inserts the file and line number of where in the code it was
// called
#define OSA_ERROR(...) \
  do \
  { \
  fprintf(stderr, " ERROR  (%s|%s|%d): ", __FILE__, __func__, __LINE__); \
  fprintf(stderr, __VA_ARGS__); \
  } \
  while(0);

#define OSA_assertSuccess(ret)  OSA_assert(ret==OSA_SOK)


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif  //_OSA_DEBUG_H_



