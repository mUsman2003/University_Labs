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
    bool check=true;
    while(check)
    {
        char buff[1024];
        cout<<endl<<"---------------------( Client Mode )---------------------"<<endl;

        char data[1024];
        
        x=open("pipe1",O_RDONLY);
        read(x,data,sizeof(data));

        cout<<"Reading a message from Server: ";
        cout<<data<<endl;

        close(x);

        string data2;
        cout<<"Write a message to Server: ";
        cin>>data2;
        
        signal(SIGINT,SIG_IGN);

        char* data3=new char[data2.length()];

        for(int n=0;n<data2.length();n++)
            data3[n]=data2[n];
        x=open("pipe1",O_WRONLY);
        write(x,data3,sizeof(data3));
        close(x);


    }

}
