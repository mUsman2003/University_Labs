#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <sys/wait.h>
#include <fstream>

using namespace std;

int main()
{

    char buff[1024];
    int y=open("pipe2",O_RDONLY);
    read(y,buff,sizeof(buff));


    ofstream file;

    int* arr=new int[strlen(buff)];

    for(int n=0;n<strlen(buff);n++)
    {
        arr[n]=static_cast<int>(buff[n]);
    }
    int a=open("Result.txt",std::ios::app);
    
    //read(a,buff,sizeof(buff));
    write(a,buff,strlen(buff));

    close(a);

    cout<<"Result: "<<buff<<endl;
    
}