#include <iostream>
using namespace std;

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

template<class T>
void addGreaterValuesBST(node<T> *root, T *sum)
{
	if(root == nullptr)
		return;
	addGreaterValuesBST(root->right,sum);
	*sum = root->data + *sum;
	root->data = *sum;
	addGreaterValuesBST(root->left,sum);
	
}



// A utility function to do inorder traversal of BST
template<class T>
void inorder(node<T> *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
	// your code goes here
	struct node<int> *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  
  cout << " before list" << endl;
  inorder(root);
  
  int sum = 0;
  addGreaterValuesBST(root, &sum);
 
  cout << "\n after list" << endl;
  inorder(root);
   
  return 0;
}
