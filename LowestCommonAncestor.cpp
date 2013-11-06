#include <iostream>
#include <stack>
#include <vector>
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
node<T>* recLowestCommonAncestor(node<T> *root, T val1, T val2)
{
	/*base case*/
	if(root == nullptr)
		return nullptr;
	if(root->data == val1 || root->data == val2)
		return root;
	struct node<T>* leftlca = recLowestCommonAncestor(root->left, val1, val2);
	struct node<T>* rightlca = recLowestCommonAncestor(root->right, val1, val2);
	/*each child contains one value, so return root as lowest common ancester*/
	if(leftlca != nullptr && rightlca != nullptr)
		return root;
	if(leftlca == nullptr)
		return rightlca;
	else
		return leftlca;
}

/* Driver program for traversal algorithms*/
int main() {
	/* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  4
  */
  struct node<int> *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(4);
  //vector<int> data;
  int three = 3, five = 5, two = 2, four = 4;
  struct node<int> *lca;
  
  lca = recLowestCommonAncestor(root, three, five);
  if(lca != nullptr)
 	cout << " Lowest Common Ancestor of 3 & 5 is " <<  lca->data << endl;
 	
  lca = recLowestCommonAncestor(root, three, two);
  if( lca != nullptr)
	cout << " Lowest Common Ancestor of 3 & 2 is " <<  lca->data << endl;

  lca = recLowestCommonAncestor(root, four, two);
  if( lca != nullptr)
	cout << " Lowest Common Ancestor of 4 & 2 is " <<  lca->data << endl;
	
	return 0;
}
