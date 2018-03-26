//Clone LL with new node inserted inbetween

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next,*arbit;
	node(int x)
	{
		data = x;
		next = arbit = NULL;
	}
};

void print(node *head)
{
	node *ptr = head;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", arbit = " << ptr->arbit->data << endl;
		ptr = ptr->next;
	}
}

// This function clones a given linked list in O(1) space
node* makeclone(node *head)
{
	node* curr = head, *tmp;

	while (curr)
	{
		tmp = curr->next;
		curr->next = new node(curr->data);
		curr->next->next = tmp;
		curr = tmp;
	}

	curr = head;

	while (curr)
	{
		curr->next->arbit = curr->arbit->next;

		curr = curr->next?curr->next->next:NULL;
	}

	node* orig = head, *copy = head->next;

	tmp= copy;

	while (orig && copy)
	{
		orig->next = orig->next? orig->next->next : NULL;
		copy->next = copy->next?copy->next->next:NULL;

		orig = orig->next;
		copy = copy->next;
	}

	return tmp;
}

// Driver code
int main()
{
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);

	head->arbit = head->next->next;

	head->next->arbit = head;

	head->next->next->arbit =head->next->next->next->next;
	head->next->next->next->arbit = head->next->next->next->next;

	head->next->next->next->next->arbit = head->next;

	cout << "Original list : \n";
	print(head);

	cout << "\nCloned list : \n";
	node *cloned = makeclone(head);
	print(cloned);

	return 0;
}
