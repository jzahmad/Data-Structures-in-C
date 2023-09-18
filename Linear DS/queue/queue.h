#ifndef _queue_h
#define _queue_h

#include <stdbool.h>
#include "lib/linked_list.h"

typedef struct _Queue { 
	LinkedList* list;
} Queue;

Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue* q);

#endif
