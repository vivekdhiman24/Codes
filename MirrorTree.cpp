#include<stdio.h>
#include<stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)

{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}



void mirror(struct node* node)
{
  if (node==NULL)
    return;
  else
  {

    struct node* temp;
    mirror(node->left);
    mirror(node->right);

    temp        = node->left;
    node->left  = node->right;
    node->right = temp;

  }
}


void inOrder(struct node* node)
{
  if (node == NULL)
    return;

  printf("%d ", node->data);
  inOrder(node->left);
  inOrder(node->right);
}


/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
  mirror(root);
  printf("\n Inorder traversal of the mirror tree is \n");
  inOrder(root);

  getchar();
  return 0;
}
