#include <iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;
int main()
{
    int x;
    int a,b,c;
    pid_t pid=fork();
    if(pid==0)
    {
        cout<<"Process ID : "<<pid<<endl;
        cout<<"Enter val of a : ";
        cin>>a;
        cout<<"Enter val of b : ";
        cin>>b;
        x=a+b;
        exit(x);
    }
    else if(pid>0)
    {
        cout<<"Process ID : "<<pid<<endl;
        wait(&x);
        int ans=WEXITSTATUS(x);
        cout<<"Enter val of c : ";
        cin>>c;
        cout<<"Total Sum : "<<ans+c<<endl;
    }
    else
        cout<<"Error :(";
}