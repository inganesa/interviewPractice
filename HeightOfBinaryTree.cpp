#include <vector>
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

/* recurive algorithm to find the height of a binary tree*/
template <class T>
int recvHeightofBT(node<T>* root)
{
	if(root == nullptr)
	{
		return 0;
	}
	else
	{
		int leftHeight = recvHeightofBT(root->left);
		int rightHeight= recvHeightofBT(root->right);
        int height = (leftHeight >= rightHeight)? leftHeight : rightHeight;
        height++;
       	return height;
	}

}

/*Driver program to test above functions*/        
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
  
  cout << "The Height of the tree is " << recvHeightofBT(root) <<endl;
	return 0;
}
