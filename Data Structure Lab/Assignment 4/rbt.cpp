#include<iostream>
using namespace std;



class taskManagementSystem
{
public:
	Task* task;
	int count = 1;

	taskManagementSystem() :task(nullptr)
	{
	}

	void newTask(int id, string descrip, int priority, Task* temp)
	{
		temp->Description = descrip;
		temp->Priority = priority;
		temp->TaskID = id;
		temp->status = false;
	}

	void TaskNull(Task* temp)
	{
		temp->Description = "";
		temp->Priority = -1;
		temp->TaskID = -1;
		temp->status = false;
	}



	Task* newNode(string ch1, string ch2, string ch3, string ch4, int count)
	{
		Task* temp = new Task;
		//--------------------------
		temp->parent = NULL;
		temp->left = NULL;
		temp->right = NULL;
		temp->color = 0;
		//--------------------------
		temp->task = new Task;
		newTask(-1, "", -1, temp->task);
		//--------------------------
		temp->Fname = ch1;
		temp->Sname = ch2;
		temp->Address = ch3;
		temp->DOB = ch4;
		//--------------------------
		temp->AssigneeID += "A";
		temp->Priority = count;
		return temp;
	}

	void insertFixup(Task* z) {
		while (z->parent != nullptr && z->parent->color == 0) {
			if (z->parent == z->parent->parent->left) {
				Task* y = z->parent->parent->right;
				if (y != nullptr && y->color == 0) {
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->right) {
						z = z->parent;
						leftRotateTask(z);
					}
					z->parent->color = 1;
					z->parent->parent->color = 0;
					rightRotateTask(z->parent->parent);
				}
			}
			else {
				Task* y = z->parent->parent->left;
				if (y != nullptr && y->color == 0) {
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->left) {
						z = z->parent;
						rightRotateTask(z);
					}
					z->parent->color = 1;
					z->parent->parent->color = 0;
					leftRotateTask(z->parent->parent);
				}
			}
		}
		task->color = 1;
	}

	void addAssignee(string ch1, string ch2, string ch3, string ch4)
	{
		Task* z = newNode(ch1, ch2, ch3, ch4, count);
		Task* y = NULL;
		Task* x = task;

		if (1)
		{
			if (count > 0 && count < 10)
			{
				z->AssigneeID += "00";
				string Atemp = to_string(count);
				z->AssigneeID += Atemp;
			}
			else if (count > 9 && count < 100)
			{
				z->AssigneeID += "0";
				string Atemp = to_string(count);
				z->AssigneeID += Atemp;
			}
			else
			{
				string Atemp = to_string(count);
				z->AssigneeID += Atemp;
			}
		}

		while (x != nullptr)
		{
			y = x;
			if (z->Priority < x->Priority) 
				x = x->left;
			else 
				x = x->right;
		}

		z->parent = y;
		if (y == nullptr) 
			task = z;
		else if (z->Priority < y->Priority) 
			y->left = z;
		else 
			y->right = z;

		insertFixup(z);
		count++;
	}

	void transplant(Task* u, Task* v) 
	{
		if (u->parent == nullptr) 
			task = v;
		else if (u == u->parent->left) 
			u->parent->left = v;
		else 
			u->parent->right = v;

		if (v != nullptr) 
			v->parent = u->parent;
	}

	void deleteFixup(Task* x)
	{
		while (x != task && (x == nullptr || x->color == 1)) 
		{
			if (x == x->parent->left) 
			{
				Task* w = x->parent->right;
				if (w->color == 0) 
				{
					w->color = 1;
					x->parent->color = 0;
					leftRotate(x->parent);
					w = x->parent->right;
				}
				if ((w->left == nullptr || w->left->color == 1) && (w->right == nullptr || w->right->color == 1)) 
				{
					w->color = 0;
					x = x->parent;
				}
				else {
					if (w->right == nullptr || w->right->color == 1) 
					{
						if (w->left != nullptr) 
							w->left->color = 1;
						w->color = 0;
						rightRotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 1;
					if (w->right != nullptr) 
						w->right->color = 1;
					leftRotate(x->parent);
					x = task;
				}
			}
			else 
			{
				Task* w = x->parent->left;
				if (w->color == 0) 
				{
					w->color = 1;
					x->parent->color = 0;
					rightRotate(x->parent);
					w = x->parent->left;
				}
				if ((w->right == nullptr || w->right->color == 1) && (w->left == nullptr || w->left->color == 1)) 
				{
					w->color = 0;
					x = x->parent;
				}
				else 
				{
					if (w->left == nullptr || w->left->color == 1) 
					{
						if (w->right != nullptr) 
							w->right->color = 1;
						w->color = 0;
						leftRotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 1;
					if (w->left != nullptr) 
						w->left->color = 1;
					rightRotate(x->parent);
					x = task;
				}
			}
		}
		if (x != nullptr) 
			x->color = 1;
	}

	void DeleteAssignee(string ch)
	{
		string tempAssigneeId;
		tempAssigneeId += ch[1];
		tempAssigneeId += ch[2];
		tempAssigneeId += ch[3];
		int key = stoi(tempAssigneeId);

		Task* z = task;
		while (z != nullptr) 
		{
			if (key == z->Priority)
			{
				if (z->task->status == true)
					return;
				break;
			}
			else if (key < z->Priority) 
				z = z->left;
			else 
				z = z->right;
		}
		if (z == nullptr) 
		{
			cout << "Key not found in the tree." << std::endl;
			return;
		}
		if (z == task)
		{
			//cout << "Its a task";
			
			Task* x = z->right;
			Task* y = z->left;

			x->parent = NULL;
			y->parent = x;
			x->left->parent = y;
			y->right = x->left;
			x->left = y;

			task= x;

			deleteFixup(task);

			task->color = 1;
			task->left->right->color = 0;
			delete z;
			z = NULL;
			return;

		}

		Task* y = z;
		Task* x;
		int yOriginalColor = y->color;

		if (z->left == nullptr) {
			x = z->right;
			transplant(z, z->right);
		}
		else if (z->right == nullptr) {
			x = z->left;
			transplant(z, z->left);
		}
		else {
			y = z->right;
			while (y->left != nullptr) {
				y = y->left;
			}
			yOriginalColor = y->color;
			x = y->right;

			if (y->parent == z) {
				if (x != nullptr) {
					x->parent = y;
				}
			}
			else {
				transplant(y, y->right);
				y->right = z->right;
				if (y->right != nullptr) {
					y->right->parent = y;
				}
			}

			transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}

		if (yOriginalColor == 1) 
			deleteFixup(x);

		delete z;
		z=NULL;
	}
	

};
