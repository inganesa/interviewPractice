#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*Preorder Traversal Algorithm approach*/

/*Given a Binary Tree, write an iterative function to print Preorder traversal of the given binary tree.

Refer this for recursive preorder traversal of Binary Tree. To convert an inherently recursive procedures to iterative, we need an explicit stack. Following is a simple stack based iterative process to print Preorder traversal.
1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack

Right child is pushed before left child to make sure that left subtree is processed first.*/


/* data structure for a node*/
template <class T>
struct node{
	T data;
	node* left;
	node* right;
};


/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
template<class T>
struct node<T>* newNode(T data)
{
    struct node<T>* node = new struct node<T>;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}
/*iterative Preorder traversal algorithm*/
template<class T>
void iterativePreorder(node<T> *root, vector<T> &data)
{
	/*base case*/
	if(root == nullptr)
	{
		cout << "null root" <<endl;
		return;
	}
	/* Pop all items one by one. Do following for every popped item
       a) add to the vector
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
	stack<node<T>*> S;
	S.push(root);
	while(S.empty() == false)
	{
		//struct node<T>* nodeStack = S.top();
		root = S.top();
		data.push_back(root ->data);
		//cout << data.back() << endl;
		S.pop();
		
		if(root->right != nullptr)
			S.push(root->right);
		if(root->left != nullptr)
			S.push(root->left);
	}
}

/* Driver program for traversal algorithms*/
int main() {
	/* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node<int> *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  vector<int> data;
  iterativePreorder(root, data);
  size_t i;
  cout << " Iterative pre order list" << endl;
  for( int i = 0; i < data.size(); i++)
  {
  	cout << data[i] << "\t";
  }
	return 0;
}
