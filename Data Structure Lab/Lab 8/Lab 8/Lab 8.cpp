#include <iostream>
#include <cmath>
using namespace std;

//----------------------------------------Q1----------------------------------------//
struct Node
{
    Node* next;
    int data;
};
class Queue
{
public:
    int count = 0;
    Node* front;
    Node* rear;

    Queue()
    {
        front = new Node;
        front->next = NULL;
        front->data = 0;
        rear = new Node;
        rear->next = NULL;
        rear->data = 0;
    }

    void print()
    {
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data ;
            temp = temp->next;
            if (temp != NULL)
                cout << "->";
        }
        cout << endl;
    }

    void enqueue(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->next = NULL;

        if (count==0)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }

    void dequeue()
    {
        front = front->next;
        count--;
    }

    int peek()
    {
        return front->data;
    }

    bool isempty()
    {
        if (count == 0)
            return true;
        return false;
    }

    int size()
    {
        return count;
    }

    void clear()
    {
        while (count != 0)
        {
            front = front->next;
            count--;
        }
    }

};
//----------------------------------------Q2----------------------------------------//
class Process
{
public:
    int ID;
    int priority;
    int BurstTime;
    Process* next;

    Process(Process* p)
    {
        ID =p->ID;
        BurstTime = p->BurstTime;
        priority = p->priority;
        next = p->next;
    }

    Process(int id, int p, int b):ID(id),priority(p),BurstTime(b)
    {
        next = NULL;
    }    
};
class CustomQueue
{
public:
    Process* front;
    Process* rear;

    int count;

    CustomQueue()
    {
        front = NULL;
        rear = NULL;

        count = 0;
    }

    bool isEmpty()
    {
        if (count == 0)
            return true;
        return false;
    }

    void print()
    {
        Process* temp = front;
        while (count != 0)
        {
            cout << temp->ID << " " << temp->BurstTime << " " << temp->priority << endl;
            temp = temp->next;
            count--;
        }
    }

    void enqueue(Process* P)
    {
        Process* temp = new Process(P);
        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }

    void dequeue()
    {
        front = front->next;
        count--;
    }
};
class MultiLevelFeedbackQueueScheduler
{
public:
    CustomQueue arr[3];
    void addProcess(Process* P)
    {
        if (P->priority == 0)
        {
            arr[0].enqueue(P);
        }
        if (P->priority == 1)
        {
            arr[1].enqueue(P);
        }
        if (P->priority == 2)
        {
            arr[2].enqueue(P);
        }
    }
    void executeProcesses()
    {
        int n = 0;
        arr[0].print();
        arr[1].print();
        arr[2].print();
    }
};
//----------------------------------------Q3----------------------------------------//
struct arrNode
{
    arrNode* next;
    int x, y;
    int data;
};
class arrQueue
{
public:
    int count = 0;
    arrNode* front;
    arrNode* rear;

    arrQueue()
    {
        front = new arrNode;
        front->next = NULL;
        front->data = 0;
        rear = new arrNode;
        rear->next = NULL;
        rear->data = 0;
    }

    void print()
    {
        arrNode* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " (" << temp->x << "," << temp->y << ")" << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void enqueue(int val,int x,int y)
    {
        arrNode* temp = new arrNode;
        temp->data = val;
        temp->x = x;
        temp->y = y;
        temp->next = NULL;

        if (count == 0)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }

    void dequeue()
    {
        front = front->next;
        count--;
    }

    int peek()
    {
        return front->data;
    }
    int peekx()
    {
        return front->x;
    }
    int peeky()
    {
        return front->y;
    }

    bool isempty()
    {
        if (count == 0)
            return true;
        return false;
    }

    int size()
    {
        return count;
    }

    void clear()
    {
        while (count != 0)
        {
            front = front->next;
            count--;
        }
    }

};
int NegtoPos(int n)
{
    if (n < 0)
        return n*(-1);
    return n;
}

int main()
{
    //----------------------------------------Q1----------------------------------------//
    
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    cout << "Queue After Enqueue : ";
    Q.print();
    Q.dequeue();
    Q.dequeue();
    cout << "Queue After Dequeue : ";
    Q.print();
    cout << "Front Value : " << Q.peek() << endl;
    cout << "Is Empty? : " << Q.isempty() << endl;
    cout << "Size : " << Q.size() << endl;
    cout << "Queue : ";
    Q.print();
    Q.clear();
    cout << "Queue After Clearing : ";
    Q.print();
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    cout << "Queue After Enqueue : ";
    Q.print();

    //----------------------------------------Q2----------------------------------------//

   

    Process P1(1, 2, 3), P2(3, 1, 1), P3(3, 0, 2);
    MultiLevelFeedbackQueueScheduler MQ;
    MQ.addProcess(&P1);
    MQ.addProcess(&P2);
    MQ.addProcess(&P3);
    MQ.executeProcesses();
    

    //----------------------------------------Q3----------------------------------------//

    int arr[4][5] = { {-1,-9,0,-1,0},{-8,-3,-2,9,-7},{2,0,0,-6,0},{0,-7,-3,5,-4} };
    arrQueue Q1,Q2;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] > 0)
                Q1.enqueue(arr[i][j],i,j);
        }
    }
    Q1.print();
    bool check = true;
    for (int n = 0; n < Q1.size(); n++)
    {
        check = true;
        for (int i = 0; i <= 4 && check; i++)
        {
            for (int j = 0; j <= 3 && check; j++)
            {
                if (Q1.peekx()==i && Q1.peeky()==j)
                {
                    check = false;
                    if (i > 0 && i < 4 && i>0 && j<3)
                    {
                        arr[i + 1][j] = NegtoPos(arr[i + 1][j]);
                        arr[i - 1][j] = NegtoPos(arr[i - 1][j]);
                        NegtoPos(arr[i][j - 1]);
                        NegtoPos(arr[i][j + 1]);
                    }
                    else if (i == 0 && j == 0)
                    {
                        NegtoPos(arr[i + 1][j]);
                        NegtoPos(arr[i][j + 1]);
                    }
                    else if (i == 4 && j == 3)
                    {
                        NegtoPos(arr[i - 1][j]);
                        NegtoPos(arr[i][j - 1]);
                    }
                    else if (i == 0 && j == 3)
                    {
                        NegtoPos(arr[i + 1][j]);
                        NegtoPos(arr[i][j - 1]);
                    }
                    else if (i == 4 && j == 0)
                    {
                        NegtoPos(arr[i - 1][j]);
                        NegtoPos(arr[i][j + 1]);
                    }
                    else if (i > 0 && j < 4 && j == 0)
                    {
                        NegtoPos(arr[i][j + 1]);
                        NegtoPos(arr[i + 1][j]);
                        NegtoPos(arr[i - 1][j]);
                    }
                    else if (i > 0 && i < 4 && j == 3)
                    {
                        NegtoPos(arr[i][j - 1]);
                        NegtoPos(arr[i + 1][j]);
                        NegtoPos(arr[i - 1][j]);
                    }
                    else if (i == 0 && j > 0 && j < 3)
                    {
                        NegtoPos(arr[i + 1][j]);
                        NegtoPos(arr[i][j - 1]);
                        NegtoPos(arr[i][j + 1]);
                    }
                    else if (i == 4 && j > 0 && j< 3)
                    {
                        NegtoPos(arr[i - 1][j]);
                        NegtoPos(arr[i][j + 1]);
                        NegtoPos(arr[i][j - 1]);
                    }

                    Q1.dequeue();
                    cout << Q1.peek()<<endl;
                }
            }
        }
    }

    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] > 0)
                Q2.enqueue(arr[i][j], i, j);
        }
    }
    Q2.print();
   



}
