#ifndef BST_H
#define BST_H

#include "node.h"
struct bst
{
    struct node* root;
};

struct bst* buildBst(); //build new bst

void freeBst(struct bst* bst); //free old bst

void freeNodes(struct node* node); //free all nodes within vst but not bst struct itself

struct node* addNode(struct node* bstRoot, int nodeKey, int nodeVal);

void printBstInOrder(struct node* myBstRoot); //use in order traversal to print each node in bst

struct node* removeNode(struct node* root, int remNodeKey); //remove a node by directly modifiying tree

struct node* findNode(struct node* root, int key); //use binary search to find node we specify the key of and return a pointer to said node if found. will be NULL otherwise

int getHeight(struct node* root); //find heigh of tree starting at root

int getNumNodes(struct node* root);

int addNumNodes(struct node* root); //getNumNodes is wrong by -1, so we need to add 1 to compensate

#endif