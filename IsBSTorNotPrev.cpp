#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int isBST(struct node* root,int prev)
{

  if (!root) return 1;

  if (isBST(root->left, prev)) {
    //printf("%d - %d \n",root->data, prev);
    if (root->data > prev) {
      prev = root->data;
      return isBST(root->right, prev);
    }
    else return 0;
  }
  else return 0;
}

int main(void) {
  //BST
  /*struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  */
  //Not A BST
  struct node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(6);
  root->left->left  = newNode(1);
  root->left->right = newNode(5);

  if(isBST(root,0))
    printf("Is BST");
  else
    printf("Not a BST");
  return 0;
}
