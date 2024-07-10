#include<iostream>
using namespace std;

template <typename T>
class List
{
public:
	T* ptr;
	int capacity;
	int index;
	bool isEmpty()
	{
		if (index < capacity)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (capacity == index)
			return true;
		else
			return false;
	}
	void print()
	{
		for (int n = 0; n < index; n++)
			cout << ptr[n];
		cout << endl;
	}
	List(T n)
	{
		index = 0;
		capacity = n;
		ptr = new T[capacity];
		for (int n = 0; n < capacity; n++)
			ptr[n] = 0;
	}
	bool insert(T item)
	{
		if (index<capacity)
		{
			ptr[index] = item;
			index++;
			return true;
		}
		return false;
	}
	bool insertAt(T val, int p)
	{
		if (index < capacity)
		{
			for (int n = capacity - 1; n > p; n--)
				ptr[n] = ptr[n - 1];
			ptr[p] = val;
			index++;
			return true;
		}
		else
			return false;
	}
	void insertAfter(T val, T tar)
	{
		if (index < capacity)
		{
			int start = 0;
			for (int n = 0; n < index; n++)
			{
				if (tar == ptr[n])
				{
					start = n;
				}
			}
			for (int n = capacity - 1; n > start + 1; n--)
				ptr[n] = ptr[n - 1];
			ptr[start + 1] = val;
			index++;
		}
	}
	void insertBefore(T val, T tar)
	{
		if (index < capacity)
		{
			int start = 0;
			for (int n = 0; n < index; n++)
			{
				if (tar == ptr[n])
				{
					start = n;
				}
			}
			for (int n = capacity - 1; n > start ; n--)
				ptr[n] = ptr[n - 1];
			ptr[start] = val;
			index++;
		}
	}
	void remove(int p)
	{
		int start = 0;
		for (int n = 0; n < index; n++)
			if (ptr[n] == p)
				start = n;
		for (int n = start; n < index - 1; n++)
			ptr[n] = ptr[n + 1];
		index--;
		T* temp = new T[index];
		for (int n = 0; n < index; n++)
			temp[n] = ptr[n];
		delete ptr;
		ptr = NULL;
		ptr = new T[index];
		for (int n = 0; n < index; n++)
			ptr[n] = temp[n];
		delete temp;
		temp = NULL;
	}
	void removeAfter(T tar)
	{
		int start = 0;
		for (int n = 0; n < index; n++)
			if (ptr[n] == tar)
				start = n+1;
		for (int n = start; n < index - 1; n++)
			ptr[n] = ptr[n + 1];
		index--;
		T* temp = new T[index];
		for (int n = 0; n < index; n++)
			temp[n] = ptr[n];
		delete ptr;
		ptr = NULL;
		ptr = new T[index];
		for (int n = 0; n < index; n++)
			ptr[n] = temp[n];
		delete temp;
		temp = NULL;
	}
	void removeBefore(T tar)
	{
		int start = 0;
		for (int n = 0; n < index; n++)
			if (ptr[n] == tar)
				start = n;
		for (int n = start-1;n<index-1;n++)
			ptr[n] = ptr[n + 1];
		index--;
		T* temp = new T[index];
		for (int n = 0; n < index; n++)
			temp[n] = ptr[n];
		delete ptr;
		ptr = NULL;
		ptr = new T[index];
		for (int n = 0; n < index; n++)
			ptr[n] = temp[n];
		delete temp;
		temp = NULL;
	}
	bool operator ==(List L)
	{
		if (this->index = L.index)
		{
			bool check = true;
			for (int n = 0; n < index; n++)
				if (ptr[n] != L.ptr[n])
					return false;
			return true;
		}
		else
			return false;
	}
	void reverse()
	{
		T* temp = new T[index];
		for (int n = 0; n < index; n++)
			temp[n] = ptr[n];
		for (int n = 0; n < index; n++)
			ptr[index - n - 1] = temp[n];
		delete temp;
		temp = NULL;
	}
};

class safeArray
{
public:
	int* ptr;
	int upperbound;
	int lowerbound;
	safeArray(int lower,int upper)
	{
		upperbound = upper;
		lowerbound = lower;
		int size = upperbound-lowerbound;
		ptr = new int[size];
	}
	int& operator[](int index)
	{
		if (index < lowerbound || index > upperbound)
		{
			throw out_of_range("error");
		}
		else
			return ptr[index];
	}
};