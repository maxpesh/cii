#ifndef ATOM_INCLUDED
#define ATOM_INCLUDED

#include <stddef.h>

extern size_t Atom_length(const char *str);
extern const char *Atom_new(const char *str, size_t len);
extern const char *Atom_string(const char *str);
extern const char *Atom_int(long n);
extern void Atom_init(size_t len);
extern void Atom_free(const char *str);
extern void Atom_reset(void);

#endif
