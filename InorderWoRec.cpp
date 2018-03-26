//code inorder without recursion
#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
node* newnode(int data)
{
    node *root=new node;
    root->data=data;
    root->left=root->right=NULL;
    return root;
}
void non_recur_inorder(node *root)
{
    if(root==NULL)
        return;
    stack<node *> S;
    node *current =root;
    int flag=0;
    while(flag!=1)
    {
        if(current!=NULL)
        {
            S.push(current);
            current=current->left;
        }
        else
        {
            if(!S.empty())
            {
                current=S.top();
                S.pop();
                cout<<current->data<<" ";
                current=current->right;
            }
            else
                flag=1;
        }
    }
}
int main()
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    non_recur_inorder(root);
    return 0;

}
