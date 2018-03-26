//XOR with front and back
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node{
	int data;
	struct node* npr;
};
struct node* XOR(struct node* a,struct node* b){

	return (struct node*) ((unsigned long)(a)^(unsigned long)(b));
}

void insert(node **head, int data){
	//cout << "data is"<<data;
	node *tmp = new node();
	tmp->data=data;
	tmp->npr = *head;

	if(*head == NULL){
		*head=tmp;
		tmp->npr=NULL;
		return;
	}
	(*head)->npr=XOR( tmp, (*head)->npr);
	*head=tmp;
}

void print(node *head){
	node *prev = NULL, *tmp;
	while(head){
		cout << head->data<<"-->";
		tmp = XOR(head->npr,prev);
		prev = head;
		head = tmp;
	}
}

int main() {
	int i=20;

	struct node* head=NULL;
	struct node* frontHead=head;

	insert(&head,10);
	frontHead = head;
	for(;i<50;i+=10){
		insert(&head,i);
	}
	print(frontHead);
	cout <<endl;
	print(head);
	return 0;
}
