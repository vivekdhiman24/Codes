#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* next;
};
int getCount(struct node* head)
	{
	struct node* current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}



int _getIntesectionNode(int d, struct node* head1, struct node* head2)
{
	while(d--){
		head1=head1->next;
	}
	while(head1 && head2 && head1!=head2){
		head1=head1->next;
		head2=head2->next;
	}
	if(head1){
		return head1->data;
	}
	return -1;
}

int getIntesectionNode(struct node* head1, struct node* head2)
	{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if(c1 > c2)
	{
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else
	{
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}
}


int main()
{
/*
	Create two linked lists

	1st 3->6->9->15->30
	2nd 10->15->30

	15 is the intersection point
*/

struct node* newNode;
struct node* head1 =
			(struct node*) malloc(sizeof(struct node));
head1->data = 10;

struct node* head2 =
			(struct node*) malloc(sizeof(struct node));
head2->data = 3;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 6;
head2->next = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 9;
head2->next->next = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 15;
//head1->next = newNode;
head2->next->next->next = newNode;

newNode = (struct node*) malloc (sizeof(struct node));
newNode->data = 30;
head1->next=newNode;
//head1->next->next= newNode;

//head1->next->next->next = NULL;
head1->next->next=NULL;

printf("\n The node of intersection is %d \n",
		getIntesectionNode(head1, head2));

getchar();
}
