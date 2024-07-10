#include<iostream>
using namespace std;

template <typename T>
struct Node
{
    Node<T>* next;
    T data;
};
template<typename T>
class Stack
{
public:
    int count = 0;
    Node<T>* head;
    Stack()
    {
        count = 0;
        head = nullptr;
    }
    bool isEmplty()
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
    char  peek()
    {
        return head->data;
    }
    char pop()
    {
        char ch = head->data;
        head = head->next;
        count--;
        return ch;
    }
    void push(char ch)
    {
        Node<T>* temp = new Node<T>;
        temp->data = ch;
        temp->next = NULL;
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }

        count++;
    }
    void print()
    {
        Node<T>* temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
};

template <typename T>
class Queue
{
public:
    int count = 0;
    Node<T>* front;
    Node<T>* rear;

    Queue()
    {
        front = new Node<T>;
        front->next = NULL;
        front->data = 0;
        rear = new Node<T>;
        rear->next = NULL;
        rear->data = 0;
    }
    void print()
    {
        Node<T>* temp = front;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    void push(int val)
    {
        Node<T>* temp = new Node<T>;
        temp->data = val;
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
    char pop()
    {
        char ch = front->data;
        front = front->next;
        count--;
        return ch;
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
//  Compelixity O(k*n)
string largestString(string ch, int k)
{
    Stack<char>* s = new Stack<char>;
    Queue<char>* q = new Queue<char>;

    int size = 0, size1 = 0;
    int newK = k;
    int i = 0;
    int counter = 0;
    while (ch[i] != '\0')
        i++;
    size = i;
    size1 = i;
    while (i >= 0)
    {
        s->push(ch[i]);
        i--;
    }

    while (newK > 0)
    {
        bool check = false;
        char* c = new char[k];
        for (int n = 0; n < k; n++)
        {
            c[n] = s->pop();
            //cout << c[n] << " ";
        }
        //cout << endl;
        int small = -1;

        if (k == 2)
        {
            check = true;
            if (c[0] > c[1])
                small = 1;
            else if (c[0] < c[1])
                small = 0;
            else
                check = false;
        }

        for (int n = 0; n < k - 1 && k != 2; n++)
            if (c[0] < c[n + 1])
                check = true;

        for (int n = 0; n < k - 1 && newK>0 && check && k != 2; n++)
            if (c[n] < c[n + 1])
            {
                small = n;
                break;
            }

        for (int n = k - 1; n >= 0 && check; n--)
            if (n != small)
                s->push(c[n]);
            else
                newK--;

        if (!check)
        {
            q->push(c[0]);
            counter++;
            for (int n = k - 1; n > 0; n--)
            {
                s->push(c[n]);
            }
        }
        /*  for each cycle
        cout << "Stack : ";
        s->print();
        cout << "Queue : ";
        q->print();
        */
    }

    string temp = "";
    for (int i = 0; i < size1 - k - counter; i++)
        q->push(s->pop());
    for (int i = 0; i < size1 - k; i++)
        temp += q->pop();
    return temp;
}
//  Compelixity O(k)
string solve(string ch, int k)
{
    Stack<char>* s = new Stack<char>;
    Queue<char>* q = new Queue<char>;

    int newK = k;
    int size = 0, size1 = 0;
    int i = 0;
    int counter = 0;

    while (ch[i] != '\0')
        i++;

    size = i;
    size1 = i;

    while (i >= 0)
    {
        s->push(ch[i]);
        i--;
    }

    bool check = true;
    while (newK > 0)
    {

        cout << "Stack Before : ";
        s->print();

        char c1 = s->pop();
        char c2 = s->pop();

        //cout << c1 << "-" << c2 << endl;
        /*
        if (c1 == '1' && c2 != '0')
        {
            q->push(c1);
            s->push(c2);
            newK++;
            counter++;
        }
        if (c1 == '0')
        {
            s->push(c2);
            counter++;
            newK++;
        }
        */
        if (c1 > c2 && c2 != '0')
            s->push(c2);
        else if (c1 < c2 && c2 != '0')
        {
            char temp1 = s->pop();
            if (temp1 < c2)
            {
                s->push(temp1);
            }
            else if (temp1 > c2)
            {
                s->push(c2);
                newK--;

            }
            else if (c2 == temp1)
            {
                char temp2 = s->pop();
                if (temp2 < c2)
                {
                    s->push(temp2);
                }
                else if (temp2 > c2)
                {
                    s->push(c2);
                    s->push(c2);
                    newK--;
                }

            }
            s->push(c1);
        }
        else if (c1 > c2 && c2 == '0')
        {
            char temp1 = s->pop();
            if (temp1 == '0')
            {
                char temp2 = s->pop();
                if (temp2 == '1')
                {
                    char temp3 = s->pop();
                    if (temp3 > c1)
                    {
                        s->push(temp2);
                        s->push(temp1);
                        s->push(c2);
                        s->push(c1);
                    }
                    else if (temp3 == '1')
                    {
                        s->push(temp2);
                        s->push(temp1);
                        s->push(c2);
                        s->push(c1);
                    }
                    else if (temp3 < c1 && temp3 != '0')
                    {
                        newK -= 3;

                    }
                }
                else if (temp2 > c1)
                {
                    s->push(temp1);
                    s->push(c2);
                    s->push(c1);
                }
                else if (temp2 < c1)
                {
                    newK -= 2;
                    s->push(temp2);
                }
            }
            else if (temp1 > c1)
            {
                /*
                char temp2 = s->pop();
                if (temp2 > temp1)
                {
                    s->push(temp1);
                }
                else if (temp2 < temp1)
                {
                    s->push(temp2);
                    newK--;
                }
                */
                s->push(c2);
                s->push(c1);
            }
            else if (temp1 < c1 && newK>2)
            {
                newK--;
                s->push(temp1);
            }
            else if (temp1 < c1)
            {
                char temp2 = s->pop();
                if (temp2 > temp1)
                {
                    s->push(temp1);
                    s->push(c2);
                    s->push(c1);
                }
                else if (temp2 < temp1)
                {
                    s->push(temp2);
                    s->push(c2);
                    s->push(c1);
                    newK--;
                }
            }
        }
        else if (c1 == c2)
        {
            char t1 = s->pop();
            if (t1 > c1)
            {
                s->push(c1);
                s->push(c2);
            }
            else if (t1 < c1)
            {
                s->push(t1);
                s->push(c1);
            }
            else if (t1 = c1)
            {
                char t2 = s->pop();
                if (t2 > c1)
                {
                    s->push(c1);
                    s->push(c2);
                    s->push(c1);
                }
                else if (t2 < c1)
                {
                    s->push(t2);
                    s->push(c1);
                    s->push(c1);
                }
                else if (t2 == c1)
                {
                    char t2 = s->pop();
                    if (t2 > c1)
                    {
                        s->push(c1);
                        s->push(c2);
                        s->push(c1);
                        s->push(c2);
                    }
                    else if (t2 < c1)
                    {
                        s->push(t2);
                        s->push(c1);
                        s->push(c1);
                        s->push(c1);
                    }
                    else if (t2 == c1)
                    {
                        char t3 = s->pop();
                        if (t3 > c1)
                        {
                            s->push(c1);
                            s->push(c2);
                            s->push(c1);
                            s->push(c2);
                            s->push(c1);
                        }
                        else if (t3 < c1)
                        {
                            s->push(t3);
                            s->push(c1);
                            s->push(c1);
                            s->push(c1);
                            s->push(c2);
                        }
                    }
                }
            }
        }
        newK--;

        cout << "Stack After  : ";
        s->print();
        cout << "-----------------------------------------------------------------------------------------\n";


    }
    cout << "Orignal : " << ch << endl;
    string temp = "";
    for (int i = 0; i < size1 - k - counter; i++)
        q->push(s->pop());
    for (int i = 0; i < size1 - k; i++)
        temp += q->pop();
    cout << "Final : " << temp;

    return temp;

}
//  Compelixity O(n)
int* maxSubsequence(int* arr, int size, int k)
{
    Queue<int>* q = new Queue<int>;
    Queue<int>* s = new Queue<int>;
    int sum1 = 0;
    int sum2 = 0;
    int index = 0;

    for (int n = 0; n < k; n++)
    {
        s->push(arr[n]);
        sum1 += arr[n];
    }
    for (int n = 1; n < size; n++)
    {
        while (q->size() != k)
        {
            q->push(arr[n]);
            sum2 += arr[n];
        }
        q->clear();
        if (sum2 > sum1)
        {
            index = n;
            sum1 = sum2;
            sum2 = 0;
        }
        else if (sum2 < sum1)
            sum2 = 0;

    }

    for (int n = 0; n < k; n++)
        arr[n] = arr[n + index];

    return arr;
}
