#ifndef NODE_H
#define NODE_H

struct node{
    int key;
    int value;
    struct node* left;
    struct node* right;
};

struct node* buildNode(int key, int value, struct node* left, struct node* right); //build new node

void freeNode(struct node*); //free old node

#endif