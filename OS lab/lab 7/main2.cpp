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
    string result;

    int y=open("pipe1",O_RDONLY);
    read(y,buff,sizeof(buff));

    cout<<"Orignal String: "<<buff<<endl;

    int* arr=new int[strlen(buff)];

    for(int n=0;n<strlen(buff);n++)
    {
        arr[n]=static_cast<int>(buff[n]);
    }

    ofstream file;
    file.open("Processing.txt",std::ios::app);

    for(int n=0;n<strlen(buff);n++)
    {
        file<<arr[n]<<" ";
        string temp=to_string(arr[n]);
        result+=temp;
        result+=" ";
    }
    file.close();

    char* data=new char[result.length()];

    for(int n=0;n<result.length();n++)
    {
        data[n]=result[n];
    }
    cout<<"Processing"<<endl;

    int x=open("pipe2",O_WRONLY);
    write(x,data,strlen(data));

    unlink("pipe1");
    unlink("pipe2");

}