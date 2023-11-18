//Assignment 2 Q1 Rishit_Das
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
};

//return a new node with the given value
struct Node *getNode(int val)
{
    struct Node *node;

    node = malloc(sizeof(struct Node));

    node->key   = val;
    node->leftChild  = NULL;
    node->rightChild = NULL;

    return node;
}

struct Node *insertNode(struct Node *root, int val)
{
     if(root == NULL)
         return getNode(val);

     if(root->key < val)
         root->rightChild = insertNode(root->rightChild,val);

     if(root->key > val)
         root->leftChild = insertNode(root->leftChild,val);

     return root;
}

void postOrder(struct Node *root)
{
    if(root == NULL)
        return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    printf("%d ",root->key);
}

int main()
{
   struct Node *root = NULL;

   root = insertNode(root,10);
   root = insertNode(root, 5);
   root = insertNode(root, 20);
   root = insertNode(root, 1);
   root = insertNode(root, 6);
   root = insertNode(root, 15);
   root = insertNode(root, 30);

   postOrder(root);

   return 0;
}
