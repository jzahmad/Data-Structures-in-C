#include "stack.h"
#include "lib/linked_list.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Stack* stack_initialize(int itemSize, char* type) {

	Stack* s = malloc(sizeof(Stack));
	s->list = llist_initialize(itemSize, type);

	return s;
}

bool stack_push(Stack* s, void* elem){
      if(s==NULL){
         return false;
      }
 	return llist_add_last(s->list, elem); 
}

void* stack_pop(Stack* s){
      if(s==NULL){
         return NULL;
      }
  	return llist_remove_last(s->list);
}

void* stack_peek(Stack* s){

 	return llist_get(s->list, s->list->size - 1);
}

int stack_size(Stack* s){

 	return s->list->size;
}

bool stack_contains(Stack* s, void* elem){
	if(s==NULL){
         return false;
      }

	int ans = llist_index_of(s->list, elem);
	if(ans >= 0){
		return true;
  }

  return false;
}

bool stack_destroy(Stack* s){

	return llist_destroy(s->list);
}
