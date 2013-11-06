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

/* preorder traversal of a BT using recursion*/
template<class T>
void recPreorder(node<T>* root, vector<T> &dataList)
{
	if(root == nullptr)
		return;
	else 
	{
		dataList.push_back(root->data);
		recPreorder(root->left,dataList);
		recPreorder(root->right,dataList);
	}
}

/* postorder traversal of a BT using recursion*/
template <class T>
void recPostorder(node<T>* root, vector<int> &dataList)
{
	if(root == nullptr)
		return;
	else 
	{
		recPostorder(root->left,dataList);
		recPostorder(root->right,dataList);
		dataList.push_back(root->data);
	}
}
/*inoder traversal of a BT using recursion*/
template <class T>
void recInorder(node<T>* root, vector<int> &dataList)
{
	if(root == nullptr)
		return;
	else
	{
		recInorder(root->left,dataList);
		dataList.push_back(root->data);
		recInorder(root->right,dataList);
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
  vector<int> dataList;
  
  cout << "Recursive Preorder Traversal" << endl;
  recPreorder(root,dataList);
  vector<int>::iterator it;
  for(it = dataList.begin(); it != dataList.end(); it++)
  {
  	cout<<*it<<"\t";
  }
  cout  << endl;
  dataList.erase(dataList.begin(),dataList.end());
  
  cout << "Recursive Postorder Traversal" << endl;
  recPostorder(root,dataList);
  for(it = dataList.begin(); it != dataList.end(); it++)
  {
  	cout<<*it<<"\t";
  }
  cout  << endl;
  dataList.erase(dataList.begin(),dataList.end());
  
  cout << "Recursive Inorder Traversal" << endl;
  recInorder(root,dataList);
  for(it = dataList.begin(); it != dataList.end(); it++)
  {
  	cout<<*it<<"\t";
  }
  cout  << endl;
  return 0;
}
