#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <sys/wait.h>
#include <fstream>

using namespace std;

int main()
{ 
    int x;
    mkfifo("pipe1",0666);

    bool check=true;
    while(check)
    {
        cout<<endl<<"---------------------( Server Mode )---------------------"<<endl;

        string buff;
        cout<<"Write message to clinet: ";
        cin>>buff;
        char* data1=new char[buff.length()-1];
        for(int n=0;n<buff.length();n++)
            data1[n]=buff[n];

        signal(SIGINT,SIG_IGN);
        
        x=open("pipe1",O_WRONLY);
        write(x,data1,strlen(data1));
        close(x);


        char data2[1024];
        cout<<"Reading a message from client: ";
        x=open("pipe1",O_RDONLY);
        read(x,data2,sizeof(data2));
        cout<<data2<<endl;
        close(x);

    }
    unlink("pipe1");

}