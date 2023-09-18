#include "array_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

ArrayList* alist_initialize(int maxSize, int itemSize, char* type){
         
      ArrayList* a= malloc( (sizeof(ArrayList)) );
      if(a==NULL){
         return NULL;
      }

	   a->arr= malloc(maxSize * (sizeof(void*)));
      if(a->arr == NULL){
         free(a);
         return NULL;
      }

      a->size=0;
	   a->maxSize=maxSize;
	   a->itemSize=itemSize;
	   a->type = malloc(strlen(type)+1);
      strcpy(a->type, type);
      if (a->type == NULL) {
         free(a->arr);
         free(a);
         return NULL;
    }

   return a;           
}

bool alist_add(ArrayList* a, void* elem){
         if(a==NULL){
            return false;
         }else if(a->size == a->maxSize){
              bool resize=alist_resize(a);
         }
         a->arr[a->size]=elem;
         a->size+=1;
         return true;
}

bool alist_add_at(ArrayList* a, int index, void* elem){
         if(a==NULL){
            return false;
         }else if(index<0 || index>=a->size){
            return false;
         }else if(a->size == a->maxSize){
	          bool resize=alist_resize(a);
	      }
         for(int i=a->size-1; i>=index; i--){
	       a->arr[i+1]=a->arr[i];
         }
         a->arr[index]=elem;
         a->size+=1;
         return true;
}

void alist_clear(ArrayList* a){
         
         for(int i=0; i< a->size; i++){
	       free(a->arr[i]); 
         }
         a->size=0;   
}

void* alist_get(ArrayList* a, int index){
         void *elem;
	      if(a==NULL){
            return NULL;
         }else if(index<0 || index>a->size){
            return NULL;
         }
         
 return a->arr[index];
}

int alist_index_of(ArrayList* a, void* elem){\
         if(a==NULL){
            return -1;
         }
	      for(int i=0; i< a->size; i++){
	         if(a->arr[i]==elem){
               return i;
		      }
         }
 return -1;
}

void* alist_remove(ArrayList* a, int index){
         
         if(a==NULL){
            return NULL;
         }else if(index<0 || index>a->size){
            return NULL;
         }
         void* rm_elem=a->arr[index];
         for(int i=index; i<a->size-1; i++){
	       a->arr[i]=a->arr[i+1];
         }
         a->size-=1;
         return rm_elem;
}

bool alist_destroy(ArrayList* a){
    	   if (a == NULL) {
            return false;
    	   }
	      free(a->arr);
    	   free(a->type);
    	   free(a);

 return true;
}

bool alist_resize(ArrayList* a) {
      if (a == NULL) {
         return false;
      }
      int newMaxSize = a->maxSize * 2;
      void** newArr = realloc(a->arr, newMaxSize * sizeof(void*));
      if (newArr == NULL) {
         return false;
      }
      a->arr = newArr;
      a->maxSize = newMaxSize;

    return true;
}


