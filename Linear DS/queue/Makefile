COMPILER = gcc

CSTD = --std=c18

queue : queue.o queueM.o linked_list.o
	$(COMPILER) $(CSTD) queue.o queueM.o linked_list.o -o queue

queue.o : queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c -o queue.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -c lib/linked_list.c -o linked_list.o

clean :
	rm -f queue
	rm -f queue.o

