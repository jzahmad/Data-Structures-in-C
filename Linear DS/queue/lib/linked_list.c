#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

LinkedList* llist_initialize(int itemSize, char* type) {

    LinkedList* a = malloc(sizeof(LinkedList));
    a->first = NULL;
    a->last = NULL;
    a->size = 0;
    a->itemSize = itemSize;
    a->type = malloc(strlen(type)+1);
    strcpy(a->type, type);
    
return a;
}

bool llist_add_at(LinkedList* a, int index, void* elem) {
    if(a==NULL){
       return false;
    }
    // for invalid index
    if (index < 0 || index > a->size) {

     return false;
    }
    // by default nodes
    Node* newNode = malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = NULL;
    // adding a first node
    if (index == 0) {
         // if there is no node before and you're adding at first
        if (a->size == 0) {

            a->first = newNode;
            a->last = newNode;
        } else {
        // if there is a node before and you're adding at first

            newNode->next = a->first;
            a->first->prev = newNode;
            a->first = newNode;
        }
    // adding at last node
    } else if (index == a->size) {

        newNode->prev = a->last;
        a->last->next = newNode;
        a->last = newNode;
    } else {
    // adding in the middle of the node
        Node* current = a->first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    // after adding increase the size
    a->size++;

 return true;
}

bool llist_add_first(LinkedList* a, void* elem){
    if(a==NULL){
       return false;
    }
    bool res=false;
    res=llist_add_at(a, 0, elem);

 return res;
}

bool llist_add_last(LinkedList* a, void* elem){
    if(a==NULL){
    }
    bool res=false;
    res=llist_add_at(a, a->size,elem);

 return res;
}

void* llist_get(LinkedList* a, int index){

     if (a==NULL || index < 0 || index >= a->size) {
         return NULL;
     }
     Node* current = a->first;
     for (int i = 0; i < index; i++) {
            current = current->next;
     }
 return current->data;
}

int llist_index_of(LinkedList* a, void* elem) {
    if(a==NULL){
       return -1;
    }
    int index = 0;
    Node* current = a->first;

    while (current != NULL) {
        if (memcmp(current->data, elem, a->itemSize) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

void* llist_remove(LinkedList* a, int index){

    if (a==NULL || index < 0 || index >= a->size) {
        return NULL;
    }
    Node* current = a->first;

    if (a->size == 1) {
        a->first = NULL;
        a->last = NULL;
    } else if (index == 0) {
        a->first = current->next;
        a->first->prev = NULL;
    } else if (index == a->size - 1) {
        current = a->last;
        a->last = current->prev;
        a->last->next = NULL;
    } else {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    void* removed = current->data;
    free(current);
    a->size--;

return removed;
}

void* llist_remove_first(LinkedList* a){
   if (a==NULL || a->size == 0) {
        return NULL;
   }
   void* elem=NULL;
   elem=llist_remove(a,0);

 return elem;    
}

void* llist_remove_last(LinkedList* a){
    if (a==NULL || a->size == 0) {
        return NULL;
    }
    void* elem=NULL;
    elem=llist_remove(a,(a->size)-1);

 return elem;    
}

bool llist_destroy(LinkedList* a){
    if (a == NULL) {
        return false;
    }
    Node* current = a->first;
    while(current != NULL){
	  Node* nex=current->next;
	  free(current);
          current=nex;
    }

    free(a->type);
    free(a);

    return true;
}

