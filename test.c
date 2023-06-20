#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node.h"

int main(void)
{
/*
        5
       / \
      4   7
     /   / \
    2   6   8
   / \     / \
  1   3   9  99
           \
           10           
           
*/

    struct bst* myBst = buildBst(NULL);
    myBst->root = addNode(myBst->root, 5, 4);
    myBst->root = addNode(myBst->root, 7, 4);
    myBst->root = addNode(myBst->root, 8, 4);
    myBst->root = addNode(myBst->root, 4, 4);
    myBst->root = addNode(myBst->root, 99, 4);
    myBst->root = addNode(myBst->root, 6, 4);
    myBst->root = addNode(myBst->root, 2, 4);
    myBst->root = addNode(myBst->root, 1, 4);
    myBst->root = addNode(myBst->root, 9, 4);
    myBst->root = addNode(myBst->root, 10, 4);
    myBst->root = addNode(myBst->root, 3, 4);
    printBstInOrder(myBst->root);
    if (findNode(myBst->root, 99) != NULL)
        printf("findNode Test... Test passed: Node 99 found in bst\n");
    else 
        printf("findNode Test... Test failed: Node 99 is not in bst\n");
    myBst->root = removeNode(myBst->root, 7);
    if (findNode(myBst->root, 7) == NULL)
        printf("removeNode Test... Test passed: Node 7 was succesfully removed\n");
    else
        printf("removeNode Test... Test failed: Node 7 was still in bst after removeNode called\n");
    if (getHeight(myBst->root) == 5)
    {
        printf("getHeight Test... Test passed: Correctly identifies height of tree is 5\n");
    }
    else
    {
         printf("getHeight Test... Test failed: Incorrectly identifies height of tree is %i\n", getHeight(myBst->root));
    }
    if (addNumNodes(myBst->root) == 11)
    {
        printf("getNumNodes Test... Test passed: Correctly identifies 11 nodes being in tree\n");
    }
    else
    {
        printf("getNumNodes Test... Test failed: Incorrectly identifies %i nodes being in tree\n", getNumNodes(myBst->root));
    }
    freeBst(myBst);

}