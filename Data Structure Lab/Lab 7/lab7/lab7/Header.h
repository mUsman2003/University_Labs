#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;

	int getData()
	{

		return data;
	}
	Node* getNext()
	{
		return next;
	}
};
class CircularLinkedList
{
public:
	int size = 0;
	Node* head;			//moving
	Node* sHead;		//static

	CircularLinkedList()
	{
		head = new Node;
		head = NULL;
	}

	bool search(int val)
	{
		int n = 0;
		Node* q = sHead;
		while (n < size)
		{
			if (q->data == val)
				return true;
			q = q->next;
			n++;
		}
		return false;

	}

	void update(int tar, int val)
	{
		Node* q = sHead;
		for (int n = 0; n < size; n++)
		{
			if (q->data == tar)
			{
				q->data = val;
				break;
			}
			else
				q = q->next;
		}
	}

	void deleteData(int val)
	{
		

		Node* q = sHead;
		if (q->data == val)
		{
			q = q->next;
		}
		else
		{
			while (q->next->data!=val)
			{
				q = q->next;
			}
			q->next = q->next->next;
		}
		size--;
		
	}

	bool insertAtIndex(int val,int index)
	{
		Node* q = new Node;
		q->data = val;

		Node* temp = sHead;
		for (int n = 0; n < index-1; n++)
		{
			temp = temp->next;
		}
		q->next = temp->next;
		temp->next = q;
		
		return false;
	}

	void print()
	{
		Node* t = sHead;
		for (int n = 0; n < size; n++)
		{
			cout << t->data << " ";
			t = t->next;
		}

	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	void insert(int val)
	{
		Node* temp = new Node;
		temp->data = val;
		size++;
		if (head == NULL)
		{
			temp->next = head;
			sHead = temp;
			head = temp;
		}
		else
		{ 
			head->next = temp;
			temp->next = sHead;
			head = temp;
		}
	}

	Node* getHead()
	{
		return sHead;
	}

	int findWinner(int val)
	{
		Node* p = sHead;
		while (size > val-1)
		{
			p = sHead;
			int small = p->data;
			for (int n = 0; n < val; n++)
			{
			cout <<"123";
				if (p->data < small)
					small = p->data;
				cout << "P vale : " << p->data<<endl;
				p = p->next;
			}
			cout << endl;
			deleteData(small);
		}
		if (p->data > p->next->data)
			return p->data;
		return p->next->data;
	}
	
};

struct DoublyNode
{
	int data;
	DoublyNode* next;
	DoublyNode* prev;

	int getData()
	{

		return data;
	}
	DoublyNode* getNext()
	{
		return next;
	}
};

class DoublyLinkedList
{
public:
	int size;
	DoublyNode* head;
	DoublyNode* tail;

	DoublyLinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	bool insertAtIndex(int val, int index)
	{
		DoublyNode* q = new DoublyNode;
		q->data = val;

		DoublyNode* temp = head;
		for (int n = 0; n < index - 1; n++)
		{
			temp = temp->next;
		}
		q->next = temp->next;
		temp->next = q;

		return false;
	}

	void deleteData(int val)
	{

		DoublyNode* q = head;
		while (q->next->data != val)
		{
			q = q->next;
		}

		q->next = q->next->next;
		q = q->next;
		q->prev = q->prev->prev;
		size--;

	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}

	void print()
	{
		DoublyNode* p = head;
		for (int n = 0; n < size; n++)
		{
			cout<<" " << p->data;
			p = p->next;
		}
	}

	DoublyNode* getHead()
	{
		return head;
	}

	bool search(int val)
	{
		DoublyNode* p = head;
		for (int n = 0; n < size; n++)
		{
			if (p->data == val)
				return true;
			p = p->next;
		}
		return false;
	}

	void insert(int val)
	{
		DoublyNode* p = new DoublyNode;
		p->data = val;
		p->next = NULL;
		p->prev = NULL;

		if (head == NULL)
		{
			head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			p->prev = tail;
			tail = p;
		}
		size++;
	}

	void update(int tar, int val)
	{
		DoublyNode* p = head;
		for (int n = 0; n < size; n++)
		{
			if (p->data == tar)
			{
				p->data = val;
				break;
			}
			p = p->next;
		}
	}

	void insertToHead(int val)
	{
		DoublyNode* p = new DoublyNode;
		p->data = val;

		if (head == NULL)
		{
			head = p;
			head->next = NULL;
			head->prev = NULL;
			tail = p;
		}
		else
		{
			p->next = head;
			head->prev = p;
			head = p;
		}
		size++;
	}

};