#include <iostream>
using namespace std;
#define MAX_HEIGHT 1000

struct Node
{
    int key;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void kDistantFromLeafUtil(Node* node, int height[], int pathLen, int k)
{
    if (node==NULL) return;

    height[pathLen] =  node->key;
    pathLen++;

if(node->left == NULL && node->right == NULL){
    cout <<"For Node "<<node->key <<"K distance node is= "<< height[pathLen-k-1] << " "<<endl;
    return;
}
    kDistantFromLeafUtil(node->left, height,  pathLen, k);
    kDistantFromLeafUtil(node->right, height,  pathLen, k);
}

void printKDistantfromLeaf(Node* node, int k)
{
    int height[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    kDistantFromLeafUtil(node, height, 0, k);
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->right = newNode(8);
    cout << "Nodes at distance 2 are: "<<endl;
    printKDistantfromLeaf(root, 2);

    return 0;
}
