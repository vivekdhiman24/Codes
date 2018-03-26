#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

int maxDepth(struct node* node)
{
if (node==NULL)
	return 0;
else
{
	int lH = maxDepth(node->left);
	int rH = maxDepth(node->right);

	int height = max(lH,rH)+1;
	return height;
}
}


struct node* newNode(int data)
{
	struct node* node = (struct node*)
								malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int main()
{
	struct node *root = newNode(4);

	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);

	root->right->right = newNode(6);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(8);


	printf("Hight of tree is %d", maxDepth(root));

	getchar();
	return 0;
}
