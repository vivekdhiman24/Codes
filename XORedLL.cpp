/* XORed LL */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* npx; /* XOR of next and previous node */
};

struct node* XOR (struct node *a, struct node *b)
{
	return (struct node*) ((unsigned long) (a) ^ (unsigned long) (b));
}

void insert(node **head,int x)
{
	cout<<"x is"<<x<<endl;
    node *temp=new node();temp->data=x;temp->npx=*head;
    if(*head==NULL)
    {
        temp->npx=NULL;*head=temp;return;
    }

    (*head)->npx =XOR(temp,(*head)->npx);*head=temp;
}

void printList(node *head)
{
    node *prev=NULL,*temp;
    while(head!=NULL)
    {
        cout<<head->data<<"  ";temp=head;
        head=XOR(prev,head->npx);prev=temp;
    }
}

int main ()
{
	/* 	head-->40<-->30<-->20<-->10 */
	struct node *head = NULL;
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);
	printList (head);

	return (0);
}
