#include "node.h"
#include <stdlib.h>

struct node* buildNode(int key, int value, struct node* left, struct node* right)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void freeNode(struct node* node)
{
    free(node);
}