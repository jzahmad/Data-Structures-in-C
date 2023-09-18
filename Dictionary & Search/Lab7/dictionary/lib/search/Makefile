COMPILER = gcc

CSTD = --std=c18

all : bfs dfs search search.o

bfs : search.o bfsM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o
	$(COMPILER) $(CSTD) search.o bfsM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o lib/Lab6/queue/linked_list.o -o bfs

dfs : search.o dfsM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o lib/Lab6/queue/linked_list.o
	$(COMPILER) $(CSTD) search.o dfsM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o lib/Lab6/queue/linked_list.o -o dfs

search : search.o searchM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o
	$(COMPILER) $(CSTD) search.o searchM.o lib/Lab6/queue/queue.o lib/Lab6/stack/stack.o lib/Lab6/queue/linked_list.o -o search

search.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) -c bintree.c -o search.o

clean :
	rm -f bfs
	rm -f dfs
	rm -f search
	rm -f search.o

