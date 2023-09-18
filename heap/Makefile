COMPILER = gcc

CSTD = --std=c18

all : heap rheap 

heap : lib/array_list.o heapM.o heap.o
	$(COMPILER) $(CSTD) lib/array_list.o heapM.o  heap.o -o heap

rheap : lib/array_list.o rheapM.o heap.o
	$(COMPILER) $(CSTD) lib/array_list.o rheapM.o heap.o -o rheap

heap.o : heap.c heap.h
	$(COMPILER) $(CSTD) -c heap.c -o heap.o

clean :
	rm -f heap.o
	rm -f heap
	rm -f rheap



