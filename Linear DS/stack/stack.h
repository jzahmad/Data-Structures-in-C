#ifndef _stack_h
#define _stack_h

#include <stdbool.h>
#include "lib/linked_list.h"

typedef struct _Stack {
	LinkedList* list;
} Stack;

Stack* stack_initialize(int itemSize, char* type);
bool stack_push(Stack* s, void* elem);
void* stack_pop(Stack* s);
void* stack_peek(Stack* s);
int stack_size(Stack* s);
bool stack_contains(Stack* s, void* elem);
bool stack_destroy(Stack* s);

#endif
