#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* next;
};

template<typename T>
class SLinkedList
{
public:
	Node<T>* head;
	T counter;
	SLinkedList()
	{
		head = NULL;
		counter = 0;
	}

	void insert(T val)
	{
		
		if (!head)
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = val;
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = val;
			newNode->next = NULL;

			Node<T>* temp = new Node<T>;
			temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = newNode;
			newNode = NULL;
			delete newNode;
			counter++;
		}
	}

	void insertAtHead(T val)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = val;
		newNode->next = NULL;
		if (!head)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
			counter++;
		}
	}

	void InsertAtIndex(T val, int index)
	{

		if (head==NULL)
		{
			cout << "Head is not craeted";
		}
		else
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = val;
			newNode->next = NULL;

			Node<T>* temp1 = new Node<T>;
			Node<T>* temp2 = new Node<T>;
			temp1 = head;
			temp2 = head->next;
			for (int n = 0; n < index - 1; n++)
			{
				temp1->next = temp2;
				temp2 = temp2->next;
			}
			temp1->next = newNode;
			newNode->next = temp2;
			counter++;
		}
	}

	T search(T val)
	{
		if (head == NULL)
		{
			cout << "No HEAD";
			return -1;
		}
		Node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->data == val)
			{
				return temp->data;

			}
			temp = temp->next;
		}
		return -1;
	}

	void update(int index, T val)
	{
		if (head == NULL)
		{
			cout << "No HEAD";
		}

		Node<T>* temp = new Node<T>;
		temp = head;
		int n = 0;
		while (temp!=NULL && temp->data!=index)
		{
			temp = temp->next;
		}
		temp->data = val;
	}	 

	void remove(int index)
	{
		Node<T>* pre = head;
		Node<T>* curr = head;

		while (curr->data != index && curr->next != NULL)
		{
			pre = curr; 
			curr = curr->next;
		}
		pre->next = curr->next;
		delete curr;
		curr = NULL;
	}

	void print()
	{
		Node<T>* temp = new Node<T>;
		temp = head;
		while (temp!=NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
	}

};

template <typename T>
Node<T>* swapAdjacentNodes(Node<T>* arr)
{
	
	Node<T>* temp1 = arr;
	Node<T>* temp2 = arr->next;
	Node<T>* temp3;
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp3 = temp1->next;
		temp1->next = temp1->next->next;
		temp3->next = temp1;
		temp1 = temp1->next;
		if (temp1 != NULL && temp1->next != NULL)
		{
			temp3->next->next = temp1->next;
		}
	}
	return temp2;
	
}