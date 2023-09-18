COMPILER = gcc

CSTD = --std=c18

stack : stack.o stackM.o linked_list.o
	$(COMPILER) $(CSTD) stack.o stackM.o linked_list.o -o stack

stack.o : stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c -o stack.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -c lib/linked_list.c -o linked_list.o

clean :
	rm -f stack
	rm -f stack.o

