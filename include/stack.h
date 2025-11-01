#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include <stdbool.h>

#define T Stack_T
typedef struct T *T;

extern T     Stack_new  (unsigned maxcount);
extern bool  Stack_empty(T stk);
extern void  Stack_push (T stk, void *x);
extern void *Stack_pop  (T stk);
extern void  Stack_free (T *stk);

#undef T
#endif
