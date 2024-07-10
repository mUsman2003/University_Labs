#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>

using namespace std;
int main()
{
    cout<<"Process ID : "<<getpid()<<endl;
    if(fork() || fork())
        cout<<"Hello world!\n";
}