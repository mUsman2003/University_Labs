#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <sys/wait.h>

using namespace std;

int main()
{
    char buff[10];
    char user_input[10];
    char resultant[10];


    cout<<"Enter a string: ";
    cin>>user_input;
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);


    pid_t pid=fork();

    if(pid==0)
    {
        close(fd1[1]);
        close(fd2[0]);
        
        read(fd1[0],buff,sizeof(buff));
        cout<<"Child process reciveing string: "<<buff<<endl;
        int n=0;
        int m=strlen(buff)-1;

        while(n<m)
        {
            char temp=buff[n];
            buff[n]=buff[m];
            buff[m]=temp;
            n++;
            m--;
        }

        cout<<"Child process reversing string....."<<endl;

        write(fd2[1],buff,sizeof(buff));
        cout<<"Child process sending reverse string back to the parent: "<<buff<<endl;
        exit(0);
    }
    else if(pid>0)
    {
        close(fd1[0]);
        close(fd2[1]);
        cout<<"Parent process sending string to child process: "<<user_input;
        write(fd1[1],user_input,sizeof(user_input));

        wait(NULL);

        read(fd2[0],resultant,sizeof(resultant));

        cout<<"Parent process reciveing the string: "<<resultant<<endl;
        cout<<"Reverse String: "<<resultant<<endl;


    }
    else
    {
        cout<<"Process not created"<<endl;
    }


}
