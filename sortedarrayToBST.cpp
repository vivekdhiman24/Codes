#include<stdio.h>
#include<stdlib.h>

/* A Binary Tree node */
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data);

struct Node* sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    struct Node *root = newNode(arr[mid]);

    root->left =  sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node *root = sortedArrayToBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);

    return 0;
}
