#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* next, *random;
};

void populaterandom(Node *head)
{
    static Node *maxNode;

    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        maxNode = head;
        return;
    }
    populaterandom(head->next);

    head->random = maxNode;

    if (head->data > maxNode->data)
        maxNode = head;

   return;
}

void printNextrandomPointers(Node *node)
{
	while (node!=NULL)
	{
		cout << node->data << "\t\t";

		if(node->next)
			cout << node->next->data << "\t\t";
		else cout << "NULL" << "\t\t";

		if(node->random)
			cout << node->random->data;
		else cout << "NULL";

		cout << endl;
		node = node->next;
	}
}
Node *newNode(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
int main()
{
	Node *head = newNode(5);
	head->next = newNode(10);
	head->next->next = newNode(2);
	head->next->next->next = newNode(3);

	populaterandom(head);
	printf("Resultant Linked List is: \n");
	printNextrandomPointers(head);

	return 0;
}
