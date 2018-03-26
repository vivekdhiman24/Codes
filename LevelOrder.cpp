//Level order traversal
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printLevelOrder(node *root)
{
 //if (!root) return NULL;
 queue <node *> q;
 q.push(root);
 while(1){
 	int qSize = q.size();
 	while(!q.empty()){
 		node *tmp = q.front();
 		cout << tmp->data<<"-";
 		q.pop();
 		if(tmp->left){
 			q.push(tmp->left);
 		}
 		if(tmp->right){
 			q.push(tmp->right);
 		}
 	}
 	break;
 }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    printLevelOrder(root);
    return 0;
}
