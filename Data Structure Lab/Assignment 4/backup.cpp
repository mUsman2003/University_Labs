#include<iostream>
using namespace std;

struct Task
{
	Task* parent;
	Task* left;
	Task* right;
	bool color;

	int Priority = -1;
	int TaskID = -1;
	string Description = "";
	string Fname = "";
	string AssigneeID = "";
	bool status = false;
	bool complete = false;

};

struct Node
{
	Node* parent;
	Node* left;
	Node* right;
	bool color;				//	0-Red	1-Black

	int AssignCount = 0;
	int tasksCounter = 0;
	string AssigneeID = "";		//	auto generated & unique
	string Fname = "";
	string Sname = "";
	string Address = "";
	string DOB = "";
	bool status = false;

};

class taskManagementSystem
{
public:
	Node* root;
	Task* task;
	
	int count = 1;
	int taskCounter = 0;

	taskManagementSystem() :root(nullptr),task(nullptr)
	{
	}

	void getTask(Task* temp, int key, int& result)
	{
		if (temp == NULL)
			return;
		getTask(temp->left, key, result);
		if (key == temp->TaskID)
			result = temp->Priority;
		getTask(temp->right, key, result);
	}
	void getFirstName(string& name, Node* node, string& ID)
	{
		if (node == nullptr)
			return;
		getFirstName(name, node->left, ID);
		if (ID == node->AssigneeID)
		{
			name = node->Fname;
			node->status = true;
		}
		getFirstName(name, node->right, ID);

	}

	Task* newTask(int id, string descrip, int priority, string name, string assigneeID)
	{
		Task* temp = new Task;

		temp->parent = NULL;
		temp->left = NULL;
		temp->right = NULL;
		temp->color = 0;

		temp->Description = descrip;
		temp->Priority = priority;
		temp->TaskID = id;
		temp->Fname = name;
		temp->AssigneeID = assigneeID;
		temp->status = true;
		return temp;
	}
	Node* newNode(string ch1, string ch2, string ch3, string ch4, int count)
	{
		Node* temp = new Node;
		//--------------------------
		temp->parent = NULL;
		temp->left = NULL;
		temp->right = NULL;
		temp->color = 0;
		//--------------------------
		temp->Fname = ch1;
		temp->Sname = ch2;
		temp->Address = ch3;
		temp->DOB = ch4;
		//--------------------------
		temp->AssigneeID += "A";
		temp->AssignCount = count;
		return temp;
	}

	Node* minimum(Node* node)
	{
		while (node->left != NULL)
			node = node->left;
		return node;
	}
	Node* maximum(Node* node)
	{
		while (node->right != NULL)
			node = node->right;
		return node;
	}
	Task* minimumTask(Task* Task)
	{
		while (Task->left != NULL)
			Task = Task->left;
		return Task;
	}
	Task* maximumTask(Task* Task)
	{
		while (Task->right != NULL)
			Task = Task->right;
		return Task;
	}

	void leftRotate(Node* x)
	{
		Node* y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			root = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}
	void rightRotate(Node* y)
	{
		Node* x = y->left;
		y->left = x->right;
		if (x->right != nullptr) {
			x->right->parent = y;
		}
		x->parent = y->parent;
		if (y->parent == nullptr) {
			root = x;
		}
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
		x->right = y;
		y->parent = x;
	}
	void leftRotateTask(Task* x)
	{
		Task* y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			task = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}
	void rightRotateTask(Task* y)
	{
		Task* x = y->left;
		y->left = x->right;
		if (x->right != nullptr) {
			x->right->parent = y;
		}
		x->parent = y->parent;
		if (y->parent == nullptr) {
			task = x;
		}
		else if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
		x->right = y;
		y->parent = x;
	}

	void insertFixup(Node* z) 
	{
		while (z->parent != nullptr && z->parent->color == 0) {
			if (z->parent == z->parent->parent->left) {
				Node* y = z->parent->parent->right;
				if (y != nullptr && y->color == 0) {
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->right) {
						z = z->parent;
						leftRotate(z);
					}
					z->parent->color = 1;
					z->parent->parent->color = 0;
					rightRotate(z->parent->parent);
				}
			}
			else {
				Node* y = z->parent->parent->left;
				if (y != nullptr && y->color == 0) {
					z->parent->color = 1;
					y->color = 1;
					z->parent->parent->color = 0;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->left) {
						z = z->parent;
						rightRotate(z);
					}
					z->parent->color = 1;
					z->parent->parent->color = 0;
					leftRotate(z->parent->parent);
				}
			}
		}
		root->color = 1;
	}
	void insertFixupTask(Task* z) {
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
		Node* z = newNode(ch1, ch2, ch3, ch4, count);
		Node* y = NULL;
		Node* x = root;

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
			if (z->AssignCount < x->AssignCount) 
				x = x->left;
			else 
				x = x->right;
		}

		z->parent = y;
		if (y == nullptr) 
			root = z;
		else if (z->AssignCount < y->AssignCount) 
			y->left = z;
		else 
			y->right = z;

		insertFixup(z);
		count++;
	}
	void addTask(int id, string descrip, int priority, string AssigneeID)
	{
		string Name;
		getFirstName(Name, root, AssigneeID);
		Task* z = newTask(id, descrip, priority, Name, AssigneeID);
		Task* y = NULL;
		Task* x = task;

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

		insertFixupTask(z);
		taskCounter++;
	}

	void transplant(Node* u, Node* v) 
	{
		if (u->parent == nullptr) 
			root = v;
		else if (u == u->parent->left) 
			u->parent->left = v;
		else 
			u->parent->right = v;

		if (v != nullptr) 
			v->parent = u->parent;
	}
	void transplantTask(Task* u, Task* v)
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

	void deleteFixup(Node* x)
	{
		while (x != root && (x == nullptr || x->color == 1)) 
		{
			if (x == x->parent->left) 
			{
				Node* w = x->parent->right;
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
					x = root;
				}
			}
			else 
			{
				Node* w = x->parent->left;
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
					x = root;
				}
			}
		}
		if (x != nullptr) 
			x->color = 1;
	}
	void deleteFixupTask(Task* x)
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
					leftRotateTask(x->parent);
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
						rightRotateTask(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 1;
					if (w->right != nullptr)
						w->right->color = 1;
					leftRotateTask(x->parent);
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
					rightRotateTask(x->parent);
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
						leftRotateTask(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 1;
					if (w->left != nullptr)
						w->left->color = 1;
					rightRotateTask(x->parent);
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

		Node* z = root;
		while (z != nullptr) 
		{
			if (key == z->AssignCount)
			{
				if (z->status == true)
					return;
				break;
			}
			else if (key < z->AssignCount) 
				z = z->left;
			else 
				z = z->right;
		}
		if (z == nullptr) 
		{
			cout << "Key not found in the tree." << endl;
			return;
		}
		if (z == root)
		{
			//cout << "Its a root";
			
			Node* x = z->right;
			Node* y = z->left;

			x->parent = NULL;
			y->parent = x;
			x->left->parent = y;
			y->right = x->left;
			x->left = y;

			root= x;

			deleteFixup(root);

			root->color = 1;
			root->left->right->color = 0;
			delete z;
			z = NULL;
			return;

		}

		Node* y = z;
		Node* x;
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
	void deleteTask(int ch)
	{
		int key;
		getTask(task, ch, key);

		Task* z = task;
		while (z != nullptr)
		{
			if (key == z->Priority)
				break;
			else if (key < z->Priority)
				z = z->left;
			else
				z = z->right;
		}

		if (z == nullptr)
		{
			cout << "Key not found in the tree." <<  endl;
			return;
		}
		
		if (z == task)
		{
			//cout << "Its a task";

			Task* x = task->left;
			while (x->right!= NULL)
				x = x->right;
			Task* y = x->parent;
			y->right = NULL;

			x->parent = NULL;
			x->right = task->right;
			x->left = task->left;
			task->left->parent = x;
			task->right->parent = x;
			task = x;
			task->color = 1;
			return;
		}

		Task* y = z;
		Task* x;
		int yOriginalColor = y->color;

		if (z->left == nullptr) {
			x = z->right;
			transplantTask(z, z->right);
		}
		else if (z->right == nullptr) {
			x = z->left;
			transplantTask(z, z->left);
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
				transplantTask(y, y->right);
				y->right = z->right;
				if (y->right != nullptr) {
					y->right->parent = y;
				}
			}

			transplantTask(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}

		if (yOriginalColor == 1)
			deleteFixupTask(x);

		delete z;
		z = NULL;
	}
	
	void displaybyID(stringstream& result, string ch)
	{
		string tempAssigneeId;
		tempAssigneeId += ch[1];
		tempAssigneeId += ch[2];
		tempAssigneeId += ch[3];
		int val = stoi(tempAssigneeId);
		Node* temp = root;
		while (temp)
		{
			if (val == temp->AssignCount)
			{
				result << "Name: " << temp->Fname << " " << temp->Sname << ", Address: " << temp->Address << ", DOB: " << temp->DOB << ", Assignee ID: " << temp->AssigneeID << "\n";
				break;
			}
			else if (val < temp->AssignCount)
				temp = temp->left;
			else if (val > temp->AssignCount)
				temp = temp->right;
			else
				cout << "Not found";
		}
	}

	void displaybyTaskPriority(Task* temp,string indent,bool last)
	{
		if (temp == NULL)
		{
			return;
		}

		cout << indent;
		if (last) 
		{
			if (temp == task)
				cout << "---->";
			else
				cout << "R--->";
			indent += "   ";
		}
		else 
		{
			cout << "L--->";
			indent += "|  ";
		}

		int color = temp->color ? 1 : 0;
		string Color;
		if (color)
			Color = "black";
		else
			Color = "red";

		cout <<temp->Priority << " (" << Color << ")" << endl;
		displaybyTaskPriority(temp->left, indent, false);
		displaybyTaskPriority(temp->right, indent, true);
	}
	void PrintTask()
	{
		Task* temp=task;
		if (temp)
		{
			displaybyTaskPriority(task, "", true);
		}
	}

	void OrderbyName(Node* node, string ch1, string ch2, stringstream& result)
	{
		if (node == nullptr)
			return;
		OrderbyName(node->left, ch1, ch2, result);

		if (ch1 == node->Fname && ch2 == node->Sname)
			result << "Name: " << node->Fname << " " << node->Sname << ", Address: " << node->Address << ", DOB: " << node->DOB << ", Assignee ID: " << node->AssigneeID << "\n";
		OrderbyName(node->right, ch1, ch2, result);
	}
	void displaybyname(stringstream& result, string ch1, string ch2)
	{
		Node* temp = root;
		OrderbyName(temp, ch1, ch2, result);
	}

	void OrderbyNoTask(Node* temp, Task* node, stringstream& result)
	{
		if (temp == nullptr)
			return;


		OrderbyNoTask(temp->left, node, result);
		if (temp->status == false)
		{
			result << "Name: " << temp->Fname << " " << temp->Sname << ", Address: " << temp->Address << ", DOB: " << temp->DOB << ", Assignee ID: " << temp->AssigneeID << "\n";
		}
		OrderbyNoTask(temp->right, node, result);
	}
	void AssigneeWithNoTask(stringstream& result)
	{
		OrderbyNoTask(root, task, result);
	}

	void ShiftTaskbyName(Task* temp, string id, string name,string newID)
	{
		if (temp == NULL)
			return;
		ShiftTaskbyName(temp->left, id, name, newID);
		if (temp->AssigneeID == id)
		{
			temp->Fname = name;
			temp->AssigneeID = newID;
		}
		ShiftTaskbyName(temp->right, id, name, newID);
	}
	void TaskRemover(Node* node, string ID)
	{
		if (node == nullptr)
			return;
		TaskRemover(node->left, ID);
		if (ID == node->AssigneeID)
		{
			node->status = false;
		}
		TaskRemover(node->right, ID);

	}
	void ShiftTask(string ch1, string ch2)
	{
		string Name;
		getFirstName(Name, root, ch2);
		ShiftTaskbyName(task, ch1, Name, ch2);
		TaskRemover(root, ch1);		
	}

	void DisplayTaskbyID(string ID, Task* temp, stringstream &result)
	{
		if (temp == NULL)
			return;
		DisplayTaskbyID(ID, temp->left, result);
		if (temp->AssigneeID == ID && temp->complete==false)
		{
			result << "Task ID: " << temp->TaskID << ", Description: " << temp->Description << ", Priority: " << temp->Priority << ", Assignee: " << temp->Fname << " (" << temp->AssigneeID << ")\n";
		}
		DisplayTaskbyID(ID, temp->right, result);
	}
	void OrderbyTaskQueue(Node* node, stringstream& result)
	{
		if (node == nullptr)
			return;

		OrderbyTaskQueue(node->right, result);
		if (node->status == true)
		{
			DisplayTaskbyID(node->AssigneeID, task, result);
		}
		OrderbyTaskQueue(node->left, result);
	}
	void printTaskQueue(stringstream& result)
	{
		OrderbyTaskQueue(root, result);
	}

	void OrderByAssigneeID(Node* temp,stringstream &result)
	{
		if (temp == nullptr)
			return;
		OrderByAssigneeID(temp->left,result);
		result << "Name: " << temp->Fname << " " << temp->Sname << ", Address: " << temp->Address << ", DOB: " << temp->DOB << ", Assignee ID: " << temp->AssigneeID << "\n";
		OrderByAssigneeID(temp->right,result);
	}
	void DisplayAssignee(stringstream& result)
	{
		OrderByAssigneeID(root, result);
	}

	void InOrderAssigneeDisplay(Node* temp, stringstream& result)
	{
		if (temp == NULL)
			return;

		int color = temp->color ? 1 : 0;
		string Color;
		if (color)
			Color = "black";
		else
			Color = "red";

		InOrderAssigneeDisplay(temp->left, result);
		result << temp->AssigneeID << " (" << Color << ")" << "\n";
		InOrderAssigneeDisplay(temp->right, result);
	}
	void AssigneeInOrder(stringstream& result)
	{
		InOrderAssigneeDisplay(root, result);
	}

	void SearchbyTaskID(Task* temp, int id)
	{
		if (temp == NULL)
			return;
		SearchbyTaskID(temp->left, id);
		if (temp->TaskID == id)
			temp->complete = true;
		SearchbyTaskID(temp->right, id);
	}
	void completeTask(int id)
	{
		SearchbyTaskID(task, id);
	}

	void PriorityUpdator(Task* temp, int id, int p)
	{
		if (temp == NULL)
			return;
		PriorityUpdator(temp->left, id, p);
		if (id == temp->TaskID)
		{
			temp->Priority = p;
		}
		PriorityUpdator(temp->right, id, p);
			
	}
	void updateTaskPriority(int id, int p)
	{
		PriorityUpdator(task, id, p);
	}

	void findHighestPriorityTask(stringstream &result)
	{
		Task* temp = task;
		while (temp->left != NULL)
			temp = temp->left;
		result<<"Highest Priority Task: Task ID: "<<temp->TaskID<<", Description: "<< temp->Description<<", Priority: "<< temp->Priority<<", Assignee: "<<temp->Fname<<" ("<<temp->AssigneeID<<")\n";
	}

	void TaskGiventoSingleAssignee(Task* temp, string id, stringstream& result)
	{
		if (temp == NULL)
			return;
		TaskGiventoSingleAssignee(temp->left, id, result);
		if(temp->AssigneeID==id)
			result << "Task ID: " << temp->TaskID << ", Description: " << temp->Description << ", Priority: " << temp->Priority << ", Assignee: " << temp->Fname << " (" << temp->AssigneeID << ")\n";
		TaskGiventoSingleAssignee(temp->right, id, result);
	}
	void findTasksByAssignee(string id, stringstream& result)
	{
		string name;
		getFirstName(name, root, id);
		cout << name;
		result << "Tasks Assigned to \"" << name << " (" << id << ")\":\n";
		TaskGiventoSingleAssignee(task, id, result);
	}

	void countTotalTasks(stringstream& result)
	{
		result << "Total Tasks in the System: " << taskCounter << "\n";
	}

	void completedTask(Task* temp, stringstream& result)
	{
		if (temp == NULL)
			return;
		completedTask(temp->left, result);
		if(temp->complete==true)
			result << "Task ID: " << temp->TaskID << ", Description: " << temp->Description << ", Priority: " << temp->Priority << ", Assignee: " << temp->Fname << " (" << temp->AssigneeID << ")\n";
		completedTask(temp->right, result);
	}
	void displayCompletedTasks(stringstream& result)
	{
		result << "Completed Tasks:\n";
		completedTask(task, result);
	}

	void taskDisplayInrange(Task* temp,	 int s, int e, stringstream& result)
	{
		if (temp == NULL)
			return;

		taskDisplayInrange(temp->left, s, e, result);
		if (temp->Priority >= s && temp->Priority <= e)
			result << "Task ID: " << temp->TaskID << ", Description: " << temp->Description << ", Priority: " << temp->Priority << ", Assignee: " << temp->Fname << " (" << temp->AssigneeID << ")\n";

		taskDisplayInrange(temp->right, s, e, result);

	}
	void searchTasksByPriorityRange(int start, int end, stringstream& result)
	{
		result << "Tasks within Priority Range (" << start << " to " << end << "):\n";
		taskDisplayInrange(task, start, end, result);
	}

	void DisplayTaskbyOrder(Task* temp, stringstream& result)
	{
		if (temp == NULL)
			return;

		int color = temp->color ? 1 : 0;
		string Color;
		if (color)
			Color = "black";
		else
			Color = "red";

		DisplayTaskbyOrder(temp->left, result);
		result << temp->TaskID << " (" << Color << ")" << "\n";
		DisplayTaskbyOrder(temp->right, result);
	}
	void PrintTreeInorder(stringstream& result)
	{
		DisplayTaskbyOrder(task, result);
	}

};
