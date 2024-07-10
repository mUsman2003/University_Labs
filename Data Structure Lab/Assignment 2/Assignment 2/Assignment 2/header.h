#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct Node
{
	int station;
	Node* next;
	Node* prev;
	Node* down;
	Node* up;
};

class Transport_Layer_optimization
{
public:
	Node* M_Head;
	Node* B_Head;
	Node* W_Head;
	Node* M_Tail;
	Node* B_Tail;
	Node* W_Tail;

	string GetPath(int start, int stop)
	{
		string ch;
		int layer = 1;
		Node* mtemp = M_Head;

		while (mtemp->station != start)
		{
			mtemp = mtemp->next;
		}
		Node* p = mtemp;
		bool rev = false;

		while(p->station!=stop && p->next!=NULL)
		{
			if (p->next != NULL && p->next->down != NULL)
			{
				ch += to_string(p->station);
				ch += "-";
				ch += to_string(layer);
				if (p->station != stop)
					ch += " -> ";
			}
			if (p->next != NULL && p->next->down == NULL && p->next->station != stop)
			{
				p = p->down;
				ch += to_string(p->station);
				layer++;
				ch += "-";
				ch += to_string(layer);
				if (p->station != stop)
					ch += " -> ";
			}
			p = p->next;
		}
		cout << ch;
		/*
		while (mtemp != NULL)
		{
			bool rev=false;
			if (mtemp->station == start)
			{
				if (mtemp->next == NULL && mtemp->down == NULL)
				{
					rev = false;
				}
				if (rev == false && mtemp->prev->down != NULL)
				{
					mtemp = mtemp->prev->down;
					rev = true;
				}
				if (rev == false && mtemp->prev->down == NULL)
				{
					mtemp = mtemp->prev;
				}
			}
			mtemp = mtemp->next;
		}
		*/

		return ch;
	}

	Transport_Layer_optimization()
	{
		M_Head = NULL;
		B_Head = NULL;
		W_Head = NULL;
		M_Tail = NULL;
		B_Tail = NULL;
		W_Tail = NULL;
	}

	void print()
	{
		cout << "\n------------------------------------------------------------------------------\n\n";
		Node* p = M_Head;
		while (p != NULL)
		{
			cout << "	" << p->station << "->" << "		";
			if (p->prev != NULL)
				cout << "prev : " << p->prev->station << " | ";
			else
				cout << "         | ";
			if (p->down != NULL)
				cout << "down : " << p->down->station << " | ";
			else
				cout << "         | ";
			p = p->next;
			cout << endl;
		}
		cout << "\n------------------------------------------------------------------------------\n\n";

		Node* q = B_Head;
		while (q != NULL)
		{
			cout << "	" << q->station << "->" << "		";
			if (q->prev != NULL)
				cout << "prev : " << q->prev->station << " | ";
			else
				cout << "         | ";
			if (q->up != NULL)
				cout << "up : " << q->up->station << " | ";
			else
				cout << "       | ";
			if (q->down != NULL)
				cout << "down : " << q->down->station<< " | ";
			else
				cout << "         | ";
			q = q->next;
			cout << endl;
		}
		cout << "\n------------------------------------------------------------------------------\n\n";
		Node* r = W_Head;
		while (r != NULL)
		{
			cout << "	" << r->station << "->" << "		";
			if (r->prev != NULL)
				cout << "prev : " << r->prev->station << " | ";
			else
				cout << "         | ";
			if (r->up != NULL)
				cout << "up : " << r->up->station << " | ";
			else
				cout << "       | ";
			r = r->next;
			cout << endl;
		}
		cout << endl;

		/*
		Node* r = W_Head;
		while (r != NULL)
		{
			cout << r->station << "->";
			r = r->next;
		}
		*/
	}

	void addNode(int id, int location)
	{

		if (id == 1)	//metro
		{
			Node* newNode = new Node;
			newNode->station = location;
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->down = NULL;
			newNode->up = NULL;

			if (M_Head == NULL)
			{
				M_Head = newNode;
				M_Tail = newNode;
			}
			else
			{
				newNode->prev = M_Tail;
				M_Tail->next = newNode;
				M_Tail = newNode;
			}
		}
		if (id == 2)	//bus
		{
			Node* newNode = new Node;
			newNode->station = location;
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->down = NULL;
			newNode->up = NULL;

			if (B_Head == NULL)
			{
				B_Head = newNode;
				B_Tail = newNode;
			}
			else
			{
				newNode->prev = B_Tail;
				B_Tail->next = newNode;
				B_Tail = newNode;
			}
		}
		if (id == 3)	//walk
		{
			Node* newNode = new Node;
			newNode->station = location;
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->down = NULL;
			newNode->up = NULL;

			if (W_Head == NULL)
			{
				W_Head = newNode;
				W_Tail = newNode;
			}
			else
			{
				newNode->prev = W_Tail;
				W_Tail->next = newNode;
				W_Tail = newNode;
			}
		}

		Node* mtemp1 = M_Head;
		Node* btemp1 = B_Head;


		while (mtemp1)
		{
			while (btemp1)
			{
				if (mtemp1->station == btemp1->station)
				{
					mtemp1->down = btemp1;
					btemp1->up = mtemp1;
				}
				btemp1 = btemp1->next;
			}
			btemp1 = B_Head;
			mtemp1 = mtemp1->next;
		}
		btemp1 = B_Head;
		Node* wtemp1 = W_Head;
		while (btemp1)
		{
			while (wtemp1)
			{
				if (wtemp1->station == btemp1->station)
				{
					btemp1->down = wtemp1;
					wtemp1->up = btemp1;
				}
				wtemp1 = wtemp1->next;
			}
			wtemp1 = W_Head;
			btemp1 = btemp1->next;
		}
	}

	void DeleteNode(int id, int station)
	{

	}

	void ReadFile(string name)
	{
		ifstream file;
		file.open(name);
		string size1, size2, size3;
		getline(file, size1, ' ');
		getline(file, size2, ' ');
		getline(file, size3);

		int s1 = stoi(size1);
		int s2 = stoi(size2);
		int s3 = stoi(size3);

		for (int n = 1; n <= s1; n++)
		{
			if (n < s1)
			{
				string stemp;
				getline(file, stemp, ' ');
				int temp = stoi(stemp);
				addNode(1, temp);
			}
			else if (n = s1)
			{
				string stemp;
				getline(file, stemp);
				int temp = stoi(stemp);
				addNode(1, temp);
			}
		}
		for (int n = 1; n <= s2; n++)
		{
			if (n < s2)
			{
				string stemp;
				getline(file, stemp, ' ');
				int temp = stoi(stemp);
				addNode(2, temp);
			}
			else if (n = s2)
			{
				string stemp;
				getline(file, stemp);
				int temp = stoi(stemp);
				addNode(2, temp);
			}
		}
		for (int n = 1; n <= s3; n++)
		{
			if (n < s3)
			{
				string stemp;
				getline(file, stemp, ' ');
				int temp = stoi(stemp);
				addNode(3, temp);
			}
			else if (n = s3)
			{
				string stemp;
				getline(file, stemp);
				int temp = stoi(stemp);
				addNode(3, temp);
			}
		}
	}

};


