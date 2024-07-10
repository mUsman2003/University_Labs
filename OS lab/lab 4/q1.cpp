#include <iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;
int main()
{
    int x,y,z;
    int a,b,c,d,e,f;
    int result;

    cout<<"Enter val of a : ";
    cin>>a;
    cout<<"Enter val of b : ";
    cin>>b;
    cout<<"Enter val of c : ";
    cin>>c;
    cout<<"Enter val of d : ";
    cin>>d;
    cout<<"Enter val of e : ";
    cin>>e;
    cout<<"Enter val of f : ";
    cin>>f;


    pid_t pid1=fork();
    if(pid1==0)
    {
        z=a*b;
        exit(z);
    }
    else if(pid1>0)
    {
        wait(&z);
        int ans1=WEXITSTATUS(z);
        pid_t pid2=fork();
        if(pid2==0)
        {
            y=c/b;
            exit(y);
        }
        else if(pid2>0)
        {
            wait(&y);
            int ans2=WEXITSTATUS(y);
            pid_t pid3=fork();
            if(pid3==0)
            {
                x=e-f;
                exit(x);
            }
            else if(pid3>0)
            {
                wait(&x);
                int ans3=WEXITSTATUS(x);
                result=ans1+ans2+ans3;
                cout<<"Result : "<<result<<endl;
            }
        }
    }
    
/*
    pid_t id1=fork();

    if(id1==0)
    {
        pid_t id2=fork();
        if(id2==0)
        {
            cout<<"Process ID : "<<id2<<endl;
            x=a*b;
            exit(x);
        }
        else if(id2>0)
        {
            cout<<"Process ID : "<<id2<<endl;
            wait(&x);
            int ans=WEXITSTATUS(x);
            
            y=(c/d)+ans;
            exit(y);
        }
        else
            cout<<"Error :(";
    }
    else if(id1>0)
    {
        cout<<"Process ID : "<<id1<<endl;
        wait(&y);
        int ans=WEXITSTATUS(y);
            
        z=(e-f)+ans;
        cout<<"Result : "<<z<<endl;
        
    }
    else
        cout<<"Error :(";
    exit(0);
*/

}