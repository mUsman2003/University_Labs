#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    int x=fork();
    if(x==0)
    {

        char* env[]={"export TERM=t100","path",NULL};
        char* arg[]={"./prac",NULL};

        //char* env[]={"export TERM=t100","path",NULL};
        execve("/home/skn1fer/Desktop/OS lab/lab 5/prac",arg,env);
        //for environmental variables 

        //execlp("/home/skn1fer/Desktop/OS lab/lab 5/prac","./prac",NULL);
        //  for same directory

        //execl("/home/skn1fer/Desktop/OS lab/lab 5/prac","./prac",NULL);
        //  for different directory

        //execv("path",char* arg[]={"./prac",NULL});
        //use to send variables to another fie all together in another directory.

        //execvp("/prac","./prac",NULL);
        //use to send variables to another fie all together in same directory.
        //char* arg[]={"./prac",NULL};
        //execvp("./prac",arg);

        cout<<endl<<"======================="<<endl;
        cout<<"= Welcome to old File ="<<endl;
        cout<<"======================="<<endl;
    }    
    else
    {
        cout<<"------------------------"<<endl;
        cout<<" Calling Parent Process"<<endl;
        cout<<"------------------------"<<endl;
    }
    exit(0);
}
