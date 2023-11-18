#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
int key;
struct Node *left;
struct Node *right;
int height;
};

int height(struct Node *N)
{
if (N == NULL)
return 0;
return N->height;
}

int max(int a, int b)
{
return (a > b)? a : b;
}

struct Node* newNode(int key)
{
struct Node* node = (struct Node*)
malloc(sizeof(struct Node));
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1;
return(node);
}

struct Node *rightRotate(struct Node *y)
{
struct Node *x = y->left;
struct Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(height(y->left),
height(y->right)) + 1;
x->height = max(height(x->left),
height(x->right)) + 1;
return x;
}

struct Node *leftRotate(struct Node *x)
{
struct Node *y = x->right;
struct Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(height(x->left),
height(x->right)) + 1;
y->height = max(height(y->left),
height(y->right)) + 1;
return y;
}

int getBalance(struct Node *N)
{
if (N == NULL)
return 0;
return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{
if (node == NULL)
return(newNode(key));
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
else 
return node;
node->height = 1 + max(height(node->left),
height(node->right));

return node;
}
struct Node* Rotation(struct Node* root)
// Check balance factor to see if balancing required (bf > 1 or bf < -1).
// If balancing required, perform necessary rotations.
{
	int bf = getBalance(root);
//---Your code goes here
//---<SNIP>---
root->height = height(root);

  int balance = getBalance(root);
  
  //Right
	if (balance > 1 && getBalance(root->left) >= 0){
		return rightRotate(root);
	}
	else if (balance > 1){
		root->left = leftRotate(root->left);
    	return rightRotate(root);
	}
	//Left
	if (balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);
	}
	else if (balance < -1){
		root->right = rightRotate(root->right);
    	return leftRotate(root);
	}
	
//---</SNIP>---
	return root;
}
void preOrder(struct Node *root)
{
if(root != NULL)
{
printf("%d ", root->key);
preOrder(root->left);
preOrder(root->right);
}
}
bool isBalanced(struct Node* root)
{
    int leftHeight;
 

    int rightHeight;
 
 
    if (root == NULL)
        return 1;
 
    
    leftHeight = height(root->left);
    rightHeight = height(root->right);
 
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left)
        && isBalanced(root->right))
        return 1;
 
    return 0;
}

int main()
{
struct Node *root = NULL;
root = insert(root, 12);
root = insert(root, 8);
root = insert(root, 18);
root = insert(root, 5);
root = insert(root, 9);
root = insert(root, 17);
root = insert(root, 4);
root = insert(root, 2);

if(isBalanced(root) == 1){
        printf("Balanced tree\n");
    }
    else{
        printf("Unbalanced tree\n");
    }
printf("Preorder traversal of Balanced tree is \n");

preOrder(root);

return 0;
}