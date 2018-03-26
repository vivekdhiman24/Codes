#include <stdio.h>
#include <stdlib.h>
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
int isBST(struct node* root)
{
    static struct node *prev = NULL;
    if (root)
    {
        if (!isBST(root->left))
          return 0;
        if (prev != NULL && root->data <= prev->data)
          return 0;
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

int main(void) {
  //BST
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  //Not A BST
  /*struct node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(6);
  root->left->left  = newNode(1);
  root->left->right = newNode(5);
  */
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
  return 0;
}
