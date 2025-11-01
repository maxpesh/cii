#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "assert.h"
#include "mem.h"
#include "stack.h"

#define T Stack_T
#define TYPEID 0xCAFEBABE
#define isBadPtr(p) ((p) == NULL || ((uintptr_t)(void *)(p))%8 != 0)

struct T {
	struct elem {
		void *x;
		struct elem *link;
	} *head;
	unsigned count;
	unsigned typeid;
};

T Stack_new(void) {
	T stk;

	NEW(stk);
	stk->count = 0U;
	stk->head = NULL;
	stk->typeid = TYPEID;
	return stk;
}

bool Stack_empty(T stk) {
	assert(!isBadPtr(stk));
	return stk->count == 0U;
}

void Stack_push(T stk, void *x) {
	struct elem *t;

	assert(!isBadPtr(stk));
	NEW(t);
	t->x = x;
	t->link = stk->head;
	stk->head = t;
	stk->count++;
}

void *Stack_pop(T stk) {
	void *x;
	struct elem *t;

	assert(!isBadPtr(stk));
	assert(stk->count > 0U);
	t = stk->head;
	stk->head = t->link;
	stk->count--;
	x = t->x;
	FREE(t);
	return x;
}

void Stack_free(T *stk) {
	struct elem *t, *u;

	assert(stk && *stk);
	for (t = (*stk)->head; t; t = u) {
		u = t->link;
		FREE(t);
	}
	FREE(*stk);
}

#undef TYPEID
