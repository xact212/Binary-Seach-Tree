#include "node.h"
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct bst* buildBst()
{
    struct bst* newBst = malloc(sizeof(struct bst));
    newBst->root = NULL;
    return newBst;

}

struct node* addNode(struct node* bstRoot, int newNodeKey, int newNodeValue)
{
    if (bstRoot == NULL) //if no other nodes in tree, just make the node the root
    {
        bstRoot = buildNode(newNodeKey, newNodeValue, NULL, NULL);
    }
    
    if (newNodeKey < bstRoot->key) //if less than current node, make root of left subtree
    {
        bstRoot->left = addNode(bstRoot->left, newNodeKey, newNodeValue);
    }
    else if (newNodeKey > bstRoot->key) //if greater than current node, make root of right subtree
    {
        bstRoot->right = addNode(bstRoot->right, newNodeKey, newNodeValue);
    }

    return bstRoot;
}

struct node* findNode(struct node* root, int key)
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            return root;
        }
        else
        {
            findNode(root->left, key);
            findNode(root->right, key);
        }
    }
}

struct node* removeNode(struct node* root, int remNodeKey)
{
    if (root == NULL)
    {
        return root;
    }
    //find ndoe recursively 
    if(root->key > remNodeKey)
    {
        root->left = removeNode(root->left, remNodeKey);
        return root;
    }
    if (root->key < remNodeKey)
    {
        root->right = removeNode(root->right, remNodeKey);
        return root;
    }

    if (root->left == NULL) //if one of children is empty
    {
        struct node* temp = root->right; //make right root
        freeNode(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node* temp = root->left;
        freeNode(root);
        return temp;
    }

    //if both children exist
    else
    {
        struct node* succParent = root;

        struct node* succ = root->right;
        //find in order succesor
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        //if no succesor, succ->right == succParent->right
        if (succParent != root)
        {
            succParent->left = succ->right;
        }
        else 
        {
            succParent->right = succ->right;
        }

        root->key = succ->key;

        freeNode(succ);
        return root;
    }
}

void printBstInOrder(struct node* myBstRoot)
{
    if (myBstRoot != NULL)
    {
        printBstInOrder(myBstRoot->left);
        printf("%i\n", myBstRoot->key);
        printBstInOrder(myBstRoot->right);
    }
}

void freeNodes(struct node* node)
{
    if (node != NULL)
    {
        //printf("node: %i \n", node->key); //postorder traversal lets us access all subtrees then delete all of them
        freeNodes(node->left);
        freeNodes(node->right);
        //printf("%i node freed! \n", node->key);
        freeNode(node); //delete nodes from bottom up
        node = NULL;
    }

}

void freeBst(struct bst* bst)
{
    freeNodes(bst->root); //free all nodes in bst
    free(bst); //free bst struct
    bst = NULL;
}

int getHeight(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }   
    else
    {
        int rdepth = getHeight(root->right);
        int ldepth = getHeight(root->left);

        if (ldepth > rdepth)
        {
            return ldepth + 1;
        }
        else
        {
            return rdepth + 1;
        }
    }
}

int getNumNodes(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int numNodes = 1 + getNumNodes(root->right) + getNumNodes(root->left);
        return numNodes;
    }
}

int addNumNodes(struct node* root)
{
    return getNumNodes(root) + 1;
}