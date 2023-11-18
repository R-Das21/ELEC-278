#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *leftChild, *rightChild;
};

void breadthTraverse(struct node* root, int level);
intfindHeight(struct node* node);
struct node* insertNode(int data);
 

void printBreadthTraverse(struct node* root)
{
    int h =findHeight(root);
    int i;
    for (i = 1; i <= h; i++)
        breadthTraverse(root, i);
}
 

void breadthTraverse(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        breadthTraverse(root->leftChild, level - 1);
        breadthTraverse(root->rightChild, level - 1);
    }
}
 
int findHeight(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
      
        int leftChildHeight =findHeight(node->leftChild);
        int rightChildHeight =findHeight(node->rightChild);
 
        if (leftChildHeight > rightChildHeight)
            return (leftChildHeight + 1);
        else
            return (rightChildHeight + 1);
    }
}
 

struct node* insertNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
 
    return (node);
}
 // A utility function to merge two sorted arrays into one
int *merge(int tree1Arr[], int tree2Arr[], int m, int n);
 
// A helper function that stores inorder traversal of a tree in inorder array
void inorderStore(struct node* node, int inorder[], int *indexRef);
 

struct node* sortedArrayToBST(int arr[], int first, int last);
 

 int arrM[4];
 int arrN[5];
 int arrMn[9];
struct node* mergeTrees(struct node *root1, struct node *root2, int m, int n)
{
    // Store inorder traversal of first tree in an array tree1Arr[]
    int *tree1Arr = arrM;
    int i = 0;
    inorderStore(root1, tree1Arr, &i);
 
    // Store inorder traversal of second tree in another array tree2Arr[]
    int *tree2Arr = arrN;
    int j = 0;
    inorderStore(root2, tree2Arr, &j);
 
    // Merge the two sorted array into one
    int *mergedArr = merge(tree1Arr, tree2Arr, m, n);
 
    // Construct a tree from the merged array and return root of the tree
    return sortedArrayToBST (mergedArr, 0, m+n-1);
}
// A utility function to merge two sorted arrays into one
int *merge(int tree1Arr[], int tree2Arr[], int m, int n)
{
    // mergedArr[] is going to contain result
    int *mergedArr = arrMn;
    int i = 0, j = 0, k = 0;
 
    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaller element and put it in mergedArr
        if (tree1Arr[i] < tree2Arr[j])
        {
            mergedArr[k] = tree1Arr[i];
            i++;
        }
        else
        {
            mergedArr[k] = tree2Arr[j];
            j++;
        }
        k++;
    }
 
    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = tree1Arr[i];
        i++; k++;
    }
 
    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = tree2Arr[j];
        j++; k++;
    }
 
    return mergedArr;
}
 
// A helper function that stores inorder traversal of a tree rooted with node
void inorderStore(struct node* node, int inorder[], int *indexRef)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    inorderStore(node->leftChild, inorder, indexRef);
 
    inorder[*indexRef] = node->data;
    (*indexRef)++;  // increase index for next entry
 
    /* now recur on right child */
    inorderStore(node->rightChild, inorder, indexRef);
}
 
struct node* sortedArrayToBST(int arr[], int first, int last)
{
    /* Base Case */
    if (first > last)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (first + last)/2;
    struct node *root = insertNode(arr[mid]);
 
    root->leftChild =  sortedArrayToBST(arr, first, mid-1);

    root->rightChild = sortedArrayToBST(arr, mid+1, last);
 
    return root;
}

int main()
{
    struct node* root1 = insertNode(3);
    root1->leftChild = insertNode(2);
    root1->rightChild = insertNode(5);
    root1->leftChild->leftChild = insertNode(1);
 
    printf("Breadth first traversal of binary tree 1 is \n");
    printBreadthTraverse(root1);


    struct node* root2 = insertNode(4);
    root2->leftChild = insertNode(1);
    root2->rightChild = insertNode(7);
    root2->leftChild->rightChild = insertNode(2);
    root2->rightChild->rightChild = insertNode(9);
    printf("\n");
    printf("Breadth first traversal of binary tree 2 is \n");
    printBreadthTraverse(root2);

    struct node *mergedTree = mergeTrees(root1, root2, 4, 5);
    printf("\n Breadth First traversal of merged binary tree:\n");
    printBreadthTraverse(mergedTree);

    return 0;
}