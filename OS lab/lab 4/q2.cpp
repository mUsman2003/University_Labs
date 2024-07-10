#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>

using namespace std;
int main()
{
    cout<<"(P1) : "<<getpid()<<" ==> Parent "<<getppid()<<endl;
    pid_t x=fork();
    if(x==0)
    {
        cout<<"\t(P2) : "<<getpid()<<" ==> Parent "<<getppid()<<endl;
        pid_t y=fork();
        if(y==0)
            cout<<"\t\t(P4) : "<<getpid()<<" ==> Parent "<<getppid()<<endl;
        else if(y>0)
            cout<<"\t\t(P2) : "<<getpid()<<" ==> Parent "<<getppid()<<endl;
        else
            cout<<"Error :(";
    }
    else if(x>0)
        cout<<"\t(P3) : "<<getpid()<<" ==> Parent "<<getppid()<<endl;
    else
        cout<<"Error :(";
    exit(0);
}