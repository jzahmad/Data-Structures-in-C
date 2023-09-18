COMPILER = gcc

CSTD = --std=c18

all: bintree intree pretree posttree revtree bintree.o

bintree : bintree.o bintreeM.o 
	$(COMPILER) $(CSTD) bintree.o bintreeM.o -o bintree

intree : bintree.o intreeM.o
	$(COMPILER) $(CSTD) bintree.o intreeM.o -o intree

pretree : bintree.o pretreeM.o
	$(COMPILER) $(CSTD) bintree.o pretreeM.o -o pretree

posttree : bintree.o posttreeM.o
	$(COMPILER) $(CSTD) bintree.o posttreeM.o -o posttree

bintree.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) -c bintree.c -o bintree.o

revtree : bintree.o revtreeM.o
	$(COMPILER) $(CSTD)  bintree.o revtreeM.o -o revtree

clean :
	rm -f bintree
	rm -f intree
	rm -f pretree
	rm -f posttree
	rm -f bintree.o
	rm -f revtree








