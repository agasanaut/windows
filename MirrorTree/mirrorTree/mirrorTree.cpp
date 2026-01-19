// C++ program to convert a binary tree 
// to its mirror 
#include<iostream> 

using namespace std;

/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
		malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}


/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.

So the tree...
	4
	/ \
	2 5
	/ \
1 3

is changed to...
	4
	/ \
	5 2
		/ \
	3 1
*/
void mirror(struct Node* node)
{
	if (nullptr == node) { return; }

	swap(node->left, node->right);
	mirror(node->left);
	mirror(node->right);
}


void inOrder(struct Node* node)
{
	if (node == NULL)
		return;

	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}


// Driver Code 
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	/* Print inorder traversal of the input tree */
	cout << "Inorder traversal of the constructed"
		<< " tree is" << endl;
	inOrder(root);

	/* Convert tree to its mirror */
	mirror(root);

	/* Print inorder traversal of the mirror tree */
	cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	inOrder(root);

	return 0;
}

// This code is contributed by Akanksha Rai 
