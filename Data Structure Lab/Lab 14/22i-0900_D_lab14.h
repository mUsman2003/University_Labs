#include<iostream>
using namespace std;

class Node
{
public:

	int key;
	int value;
	Node* next;

	Node()
	{
		key = 0;
		value = 0;
		next = NULL;
	}

	Node(int k, int v)
	{
		key = k;
		value = v;
		next = NULL;
	}

};



class HashMap
{
public:
	int num;
	int cap;
	Node* arr[10];

	HashMap()
	{
		num = 0;
		cap = 10;
		for (int n = 0; n < cap; n++)
			arr[n] = NULL;
	}
	int HashFunction(int k)
	{
		return k % 10;
	}
	bool insert2(int k, int val)
	{
		int hash = HashFunction(k);
		if (arr[hash] == NULL)
		{
			arr[hash] = new Node;
			arr[hash]->key = k;
			arr[hash]->value = val;
			arr[hash]->next = NULL;
			return true;
		}
		else
			return false;
	}
	void insert(int k, int val)
	{
		int hash = HashFunction(k);
		if (arr[hash] == NULL)
		{
			arr[hash] = new Node;
			arr[hash]->key = k;
			arr[hash]->value = val;
			arr[hash]->next = NULL;
		}
		else
		{
			Node* temp = new Node;
			temp->key = k;
			temp->value = val;
			temp->next = NULL;
			while (arr[hash]->next != NULL)
				arr[hash] = arr[hash]->next;
			arr[hash]->next = temp;
		}
	}

	int search(int key)
	{
		int hash = HashFunction(key);
		if (arr[hash] == NULL)
			return -1;

		if (key == arr[hash]->key)
			return arr[hash]->value;
		else
		{
			while (arr[hash]!=NULL)
			{
				if (key == arr[hash]->key)
					return arr[hash]->value;
				arr[hash] = arr[hash]->next;
			}
		}
		return -1;
	}
	void remove(int key)
	{
		int hash = HashFunction(key);
		if (key == arr[hash]->key)
		{
			delete arr[hash];
			arr[hash] = NULL;
		}
		else
		{
			while (key != arr[hash]->key)
				arr[hash] = arr[hash]->next;

			delete arr[hash];
			arr[hash] = NULL;

		}

	}

};

bool hasLoop(Node* temp)
{
	HashMap mp;
	Node* ptr = temp;
	bool check = true;
	while (ptr->next != NULL && check)
	{
		check = mp.insert2(ptr->key, ptr->value);
		cout << "val : " << ptr->value << "	key:" << ptr->key<<"Check :"<<check  << endl;
		if (!check)
			return true;
		ptr = ptr->next;
	}
	return false;
}