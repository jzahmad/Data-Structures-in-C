#include "queue.h"
#include "lib/linked_list.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Queue* queue_initialize(int itemSize, char* type) {
  
    Queue* q = malloc(sizeof(Queue));
    q->list = llist_initialize(itemSize, type);

    return q;
}

bool queue_enqueue(Queue* q, void* elem){   
     if(q!=NULL){
     return llist_add_last(q->list, elem); 
     }
     return false;
}

void* queue_dequeue(Queue* q){
      if(q!=NULL){
      return llist_remove_first(q->list);
      }
      return NULL;
}

void* queue_peek(Queue* q){

     return llist_get(q->list,0);

}

int queue_size(Queue* q){
 
     return q->list->size;

}

bool queue_contains(Queue* q, void* elem){
      if(q!=NULL){
      	int ans=llist_index_of(q->list, elem);
        if(ans>=0){
           return true;
          }
      }
      return false;
}

bool queue_destroy(Queue* q){
      
      return llist_destroy(q->list);

}
