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

    mkfifo("pipe1",0666);
    mkfifo("pipe2",0666);

    string buff;
    string temp;

    ifstream file;
    file.open("Input.txt");
    while(!file.eof())
    {
        file>>temp;
        temp+=" ";
        buff.append(temp);
    }file.close();

    char* data=new char[buff.length()-1];

    for(int n=0;n<buff.length()-1;n++)
    {
        data[n]=buff[n];
    }

    int x=open("pipe1",O_WRONLY);
    write(x,data,strlen(data));
    unlink("pipe1");

}