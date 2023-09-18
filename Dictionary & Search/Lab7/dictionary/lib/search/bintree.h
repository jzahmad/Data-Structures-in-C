#ifndef _bintree_h
#define _bintree_h

#include <stdbool.h>
#include "lib/Lab6/stack/stack.h"
#include "lib/Lab6/queue/queue.h"

typedef struct _BinaryTreeNode {

    void* data;
    struct _BinaryTreeNode* left;
    struct _BinaryTreeNode* right;

} BinaryTreeNode;

typedef struct _BinaryTree {

    BinaryTreeNode* top;
    int itemSize;
    char* type;
    int (*compare)(void*, void*);
    void (*print)(void*);

} BinaryTree;

BinaryTree* bintree_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
BinaryTreeNode* bintree_create_node(int, void*);
bool _bintree_search_recursive(BinaryTree*, BinaryTreeNode*, void*);
bool bintree_search(BinaryTree*, void*);
bool bintree_insert(BinaryTree*, void*);
bool _bintree_insert_recursive(BinaryTreeNode* a, BinaryTreeNode* newnode, void* elem);
void _bintree_in_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_in_order(BinaryTree* tree);
void _bintree_pre_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_pre_order(BinaryTree*);
void _bintree_post_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_post_order(BinaryTree*);
void _bintree_reverse_order_recursive(BinaryTree*, BinaryTreeNode*);
void bintree_print_reverse_order(BinaryTree*);
void bintree_print_Breadth_first(BinaryTree*);
void bintree_print_depth_first(BinaryTree* a);
bool bintree_insert_replace(BinaryTree* a, void* elem);
bool _bintree_insert_replace_recursive(BinaryTreeNode* a, BinaryTreeNode* newnode, void* elem);
int compare(void *, void *);
void print(void *);

#endif


