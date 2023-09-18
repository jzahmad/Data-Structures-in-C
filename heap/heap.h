#ifndef heap_h
#define heap_h

#include <stdbool.h>
#include "lib/array_list.h"

typedef struct Heap {
	ArrayList* a;
	int (*compare)(void*, void*);
	void (*print)(void*);
} Heap;

Heap* heap_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
bool heap_insert(Heap*, void*);
void* heap_remove(Heap*);
void* heap_peek(Heap*);
int heap_size(Heap*);
bool heap_contains(Heap*, void*);
bool _heapify_up(Heap*, int);
bool _heapify(Heap*, int);
void swap(ArrayList*, int, int);

#endif
