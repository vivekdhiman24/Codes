// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <stack>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void printSpiral(struct node *root)
{
	if (root == NULL) return;

	stack<struct node*> stack1;
	stack<struct node*> stack2;

	stack1.push(root);

	while (!stack1.empty() || !stack2.empty())
	{
		while (!stack1.empty())
		{
			struct node *temp = stack1.top();
			stack1.pop();
			cout << temp->data << " ";
			if (temp->right)
				stack2.push(temp->right);
			if (temp->left)
				stack2.push(temp->left);
		}
		while (!stack2.empty())
		{
			struct node *temp = stack2.top();
			stack2.pop();
			cout << temp->data << " ";
			if (temp->left)
				stack1.push(temp->left);
			if (temp->right)
				stack1.push(temp->right);
		}
	}
}

int main()
{
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	cout << "Spiral Order traversal of binary tree is \n";
	printSpiral(root);

	return 0;
}
