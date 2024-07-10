#include<iostream>
using namespace std;

#define N 4
#define M 5

template<typename T>
struct Node
{
	Node<T>* next;
	T data;
};
struct cell
{
	cell* next;
	int dir;
	int x;
	int y;
};

template<typename T>
class Stack
{
public:
	int count = 0;
	Node<T>* head;
	cell* cellHead;

	Stack()
	{
		head = nullptr;
		cellHead = nullptr;
	}

	int popx()
	{
		return cellHead->x;
	}
	int popy()
	{
		return cellHead->y;
	}

	void pushxy(int x, int y)
	{
		cell* temp = new cell;
		temp->x = x;
		temp->y = y;
		if (cellHead == nullptr)
		{
			cellHead = temp;
			cellHead->next = NULL;
		}
		else
		{
			temp->next = cellHead;
			cellHead = temp;
		}
		count++;
	}

	void push(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = NULL;
		if (head==nullptr)
		{
			head = temp;
			head->next = NULL;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		count++;
	}

	T peek()
	{
		return head->data;
	}

	void pop()
	{
		head = head->next;
		count--;
	}

	bool isEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}

	void clear()
	{
		delete head;
		head = nullptr;
		count = 0;
	}

};

bool isValid(string  ch)
{
	Stack<char> arr;
	int i = 0;
	while (ch[i] != '\0')
	{

		if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[')
		{
			arr.push(ch[i]);
		}
		else if (ch[0] == ')' || ch[0] == '}' || ch[0] == ']' && i==0)
		{
			return false;
		}
		else if(ch[i] == ')' || ch[i] == '}' || ch[i] == ']')
		{
			if (ch[i] == ')' && arr.peek() == '(')
			{
				arr.pop();
			}
			else if (ch[i] == '}' && arr.peek() == '{')
			{
				arr.pop();
			}
			else if (ch[i] == ']' && arr.peek() == '[')
			{
				arr.pop();
			}
			else
				return false;

		}

		i++;
	}
	if (arr.isEmpty())
		return true;
	return false;
}

bool isReachable(int arr[N][M],int tarx,int tary)
{
	bool visited[N][M];
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			visited[n][m] = arr[n][m];
	Stack<int> start;
	start.pushxy(0, 0);
	int x = 0, y = 0;
	visited[x][y] = false;
	while (start.popx() != tarx && start.popy() != tary && start.popx() <= tarx && start.popy() <= tary)
	{
		if (visited[x + 1][y] == true || visited[x - 1][y] == true || visited[x][y + 1] == true || visited[x][y - 1] == true)
		{
			if (visited[x + 1][y] == true)
			{
				start.pushxy(x + 1, y);
				visited[x + 1][y] = false;
			}
			else if(visited[x - 1][y] == true)
			{
				start.pushxy(x - 1, y);
				visited[x - 1][y] = false;
			}
			else if (visited[x][y + 1] == true)
			{
				start.pushxy(x, y + 1);
				visited[x][y+1] = false;
			}
			else if (visited[x][y-1] == true)
			{
				start.pushxy(x, y-1);
				visited[x][y-1] = false;
			}
		}
		
		x = start.popx();
		y = start.popy();
		tarx--;
		tary--;
	}

	
	


	return true;
}


