#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node *next;
};

template <class T>
node<T>* newNode(T data)
{
	node<T> *tmp;
	tmp = new node<T>;
	tmp->data = data;
	tmp->next = nullptr;
	return tmp;
}
template <class T>
void printList(node<T> *head)
{
	node<T> *tmp = head;
	while(tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	
}
template<class T> 
node<T> *reverseList(node<T> *ptr)
{
	node<T> *tmp = ptr;
	node<T> *prev = nullptr;
	while(ptr != nullptr)
	{
		tmp = ptr ->next;
		ptr->next = prev;
		prev = ptr;
		ptr = tmp;
	}
	return prev;
}	                                                                                                                                                     

template<class T>
node<T> *recReverseList(node<T> *ptr, node<T> *prev)
{
	node<T> *tmp;
	if(ptr->next == nullptr)
	{
		ptr->next = prev;
		return ptr;
	}
	else
	{
		tmp = recReverseList(ptr->next, ptr);
		ptr->next = prev;
		return tmp;
	}
}
int main() {
	/* testing reversing a list*/
	int data = 5;
	node<int> *head = newNode(data);
	data = 6;
	node<int> *prev = nullptr;
	cout << "before reversal: \n";
	head->next = newNode(data);
	printList(head);

	cout << "\nafter reversal: \n";
	head = reverseList(head);
	printList(head);

	cout<<"\nafter reversal through recursive routine: \n";
	head = recReverseList(head, prev);
	printList(head);
	return 0;
}

