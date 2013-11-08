#include <iostream>
using namespace std;

/* data structure for node*/
template <class T>
struct node{
	T data;
	node* next;
};

/* function to create new node*/
template <class T>
node<T>* newNode( T data)
{
	node<T>* node =  new struct node<T>;
	node->data = data;
	node->next = nullptr;
	return node;
}

/* helper function to print to newnode*/
template <class T>
void printList(node<T>* list)
{
	node<T>* itr = list;
	while(itr != nullptr)
	{
		cout << itr->data << "\t";
		itr = itr->next;
	}
	
}

/* funtion that merges two singly linklist that are sorted with '<' criteria*/
template <class T>
node<T>* mergeLists(node<T>* list1, node<T>* list2)
{
	if( list1 == nullptr)
		return list2;

	 if(list2 == nullptr)
		return list1;

	 if(list1->data < list2->data)
	 {
		list1->next = mergeLists(list1->next,list2);
		return list1;
	 }
	 if(list2->data < list1->data)
	 {
		list2->next = mergeLists(list1,list2->next);
	 	return list2;
	 }
}

/* driver function for merge list*/
int main() {
	// call mergeLsit code here
	node<int>* list1 = newNode(7);
    node<int>* list2 = newNode(6);
    list1->next = newNode(9);
    list2->next = newNode(10);
	node<int>* list3 = mergeLists(list1,list2);
	printList(list3);
	return 0;
}
