// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;

//utility function to print contents of
//a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
	for (int j=i; j<v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// binary tree node
struct Node
{
	int data;
	Node *left,*right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void printKPathUtil(Node *root, vector<int>& path, int k)
{
	if (!root) return;
	cout << "Accessing node " << root->data <<endl;
	path.push_back(root->data);
	printKPathUtil(root->left, path, k);
	printKPathUtil(root->right, path, k);
    /*cout << "Printing Vector"<<endl;
    for (int j=0; j<path.size(); j++)
            cout << path[j] << " ";
    cout << endl;
    cout << "Vector priting complete";
    */
	int f = 0;
	for (int j=path.size()-1; j>=0; j--)
	{
		f += path[j];
		// If path sum is k, print the path
		if (f == k)
			printVector(path, j);
	}
	// Remove the current element from the path
	path.pop_back();
}

// A wrapper over printKPathUtil()
void printKPath(Node *root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}

// Driver code
int main()
{
	Node *root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	printKPath(root, k);

	return 0;
}
