#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>

using namespace std;
int main()
{
    pid_t x=fork();
    if(x==0)
    {
        cout<<"(P2) Chiled ID : "<<x<<endl;
        pid_t y=fork();
        if(y==0)
            cout<<"(P3) New Child ID : "<<y<<endl;
        else if(y>0)
            cout<<"(P2) Parent ID of new Child : "<<y<<endl;
        else
            cout<<"Error :(";
    }
    else if(x>0)
        cout<<"(P1) Parent ID : "<<getpid()<<endl;
    else
        cout<<"Error :(";
    exit(0);
}