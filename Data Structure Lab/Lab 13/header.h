#include <iostream>
#include <math.h>
using namespace std;



class HashEntry
{
public:
	int key;
	int data;
	HashEntry():key(-1),data(-1){} 

};

class HashMap
{
public:
	int size = 10;
	HashEntry arr[10];

	HashMap()
	{
		for (int n = 0; n < size; n++)
			arr[n].data = -1;
	}
		
	void Insert(int key, int val)
	{
		key = key % size;

		if (arr[key].data == -1)
			arr[key].data = val;
		else
		{
			int n = key + 1;
			while (arr[n].data != -1)
			{
				if (n >= size)
					n = 0;
				if (n == key)
				{
					cout << "Empty space is not found  -_-\n";
					break;
				}
				n++;
			}
			arr[n].data = val;
		}

	}

	int Search(int key)
	{
		return arr[key].data;
	}

	void Remove(int key)
	{
		arr[key].data = -1;
	}

	int HashFunction2(int key)
	{
		int random = 1 + rand() % 10;
		key = (random + key) % size;
		return key;
	}

	int Search2(int key, int val)
	{
		int index = HashFunction2(key);
		if (arr[index].data == val)
		{
			arr[index].key = -1;
			return arr[index].data;
		}
		return -1;
	}

	void Insert2(int key, int val)
	{
		int index = HashFunction2(key);

		if (arr[index].data == -1)
		{
			arr[index].data = val;
			arr[index].key = key;
		}
		else
		{
			int n = index + 1;
			while (arr[n].data != -1)
			{
				if (n >= size)
					n = 0;
				if (n == index)
				{
					cout << "Empty space is not found  -_-\n";
					break;
				}
				n++;
			}
			arr[n].data = val;
		}
	}

	void Insert3(int key, int val)
	{
		int index = key;
		int square=1;
		if (arr[index].data == -1)
		{
			arr[index].data = val;
			arr[index].key = key;
			cout << "Key : " << key << "Value : " << arr[index].data << endl;
		}
		else
		{
			int n = index + 1;
			while (arr[n].data != -1)
			{
				if (n >= size)
					n = 0;
				if (n == index)
				{
					cout << "Empty space is not found  -_-\n";
					break;
				}
				square = square * square;
				n = (n + square) % size;

			}
			arr[n].data = val;
			arr[n].key = n;
			cout << "Key : " << n << "Value : " << arr[n].data << endl;
		}
	}


};