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



void rightViewUtil(struct node *node, int bredth, int *m_l){
    if (node==NULL) return;

   if (*m_l < bredth){
       printf("%d\t", node->data);
       *m_l = bredth;
    }

   rightViewUtil(node->right, bredth+1, m_l);
   rightViewUtil(node->left, bredth+1, m_l);
}

void rightView(struct node *node){
    int max_level = 0;
    rightViewUtil(node, 1, &max_level);
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
  rightView(root);



  getchar();
  return 0;
}
