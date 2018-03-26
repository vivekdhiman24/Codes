#include <iostream>
using namespace std;

struct node
{
	int data; //data belong to that node
	node *next; //next pointer
};

void push(node **head, int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

void finalMaxSumList(node *a, node *b)
{
	node *result = NULL;
	node *pre1 = a, *curr1 = a;
	node *pre2 = b, *curr2 = b;

	while (curr1 != NULL || curr2 != NULL)
	{
		int sum1 = 0, sum2 = 0;
		while (curr1!=NULL && curr2!=NULL && curr1->data!=curr2->data)
		{
			if (curr1->data < curr2->data)
			{
				sum1 += curr1->data;
				curr1 = curr1->next;
			}
			else // (curr2->data <= curr1->data)
			{
				sum2 += curr2->data;
				curr2 = curr2->next;
			}
		}

		if (curr1 == NULL)
		{
			while (curr2 != NULL)
			{
				sum2 += curr2->data;
				curr2 = curr2->next;
			}
		}
		if (curr2 == NULL)
		{
			while (curr1 != NULL)
			{
				sum1 += curr1->data;
				curr1 = curr1->next;
			}
		}

		if (pre1 == a && pre2 == b)
			result = (sum1 > sum2)? pre1 : pre2;

		else
		{
			if (sum1 > sum2)
				pre2->next = pre1->next;
			else
				pre1->next = pre2->next;
		}

		pre1 = curr1, pre2 = curr2;
		if (curr1)
			curr1 = curr1->next;
		if (curr2)
			curr2 = curr2->next;
	}

	while (result != NULL)
	{
		cout << result->data << " ";
		result = result->next;
	}
}
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}
int main()
{
	//Linked List 1 : 0->3->10->78->90->180->NULL
	//Linked List 2 : 1->3->8->32->90->95->130->160->NULL
	node *head1 = NULL, *head2 = NULL;
	push(&head1, 180);
	push(&head1, 90);
	push(&head1, 78);
	push(&head1, 10);
	push(&head1, 3);
	push(&head1, 0);
    printList(head1);
	push(&head2, 160);
	push(&head2, 130);
	push(&head2, 95);
	push(&head2, 90);
	push(&head2, 32);
	push(&head2, 8);
	push(&head2, 3);
	push(&head2, 1);
    printList(head2);
	finalMaxSumList(head1, head2);
	return 0;
}
