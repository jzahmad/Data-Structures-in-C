#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "lib/array_list.h"
Heap* heap_initialize(int size, char* type, int (*compare)(void*, void*), void (*print)(void*)){

      Heap* h = malloc(sizeof(Heap));
      if(h==NULL){
         return NULL;
        }
      h->a=alist_initialize(sizeof(Heap),size,type);
      h->compare=compare;
      h->print=print;

 return h;
}

bool heap_insert(Heap* h, void* elem){
     
     if(h==NULL || elem==NULL){
        return false;
     }
     bool ans=alist_add(h->a,elem);
     _heapify_up(h,h->a->size-1);
     return true;
}

void* heap_remove(Heap* h){
      if(h==NULL){
	 return NULL;
      }
      swap(h->a,0,h->a->size-1);
      void* elem=alist_remove(h->a,h->a->size-1);
      _heapify(h,0);

 return elem;
}

void* heap_peek(Heap* h){
	if(h==NULL){
	   return NULL;
	}
	return h->a->arr[0];
}

int heap_size(Heap* h){
        if(h==NULL){
		return -1;
	}
	return h->a->size;
}
bool _heapify(Heap* h,int index){
        if(h==NULL){
                return false;
        }
        if(heap_size(h)<=1){
                return true;
        }

        int parent= index;
        void* p_value = alist_get(h->a,parent);

        int left = 2*parent+ 1;
        int right = 2*(parent+1);

        if(alist_get(h->a,left)!=NULL){
		if(h->compare(p_value,alist_get(h->a,left))<0){
			p_value = alist_get(h->a,left);
			parent = left;
		}
        }

        if(alist_get(h->a,right)!=NULL){
		if(h->compare(p_value,alist_get(h->a,right))<0){
                        p_value = alist_get(h->a,right);
                        parent = right;
		}
	}

        if(index==parent){
                return true;
        }
        swap(h->a,index,parent),
        _heapify(h,parent);
        return true;
        }

bool _heapify_up(Heap* h,int index){

        if(h==NULL){
		return false;
        }

        if(heap_size(h)<=1 || index<1){
                return true;
        }
        
        int child = index;
	int parent = (index-1)/2;

        if(h->compare(alist_get(h->a,child),alist_get(h->a,parent))>0){

		swap(h->a,parent,child);
		_heapify_up(h,parent);
        }else{
                return true;
        }
        return true;
}

void swap(ArrayList* a, int i, int j) {

    void* temp = a->arr[i];
    a->arr[i] = a->arr[j];
    a->arr[j] = temp;

}

bool heap_contains(Heap* h,void* elem){
	if(h->a==NULL||elem==NULL){
		return false;
	}
	if(alist_index_of(h->a,elem)!=-1){
		return true;
	}
	return false;

}
