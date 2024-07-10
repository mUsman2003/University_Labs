#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>

using namespace std;

int main(int argc, char* argv[])
{

    cout<<"In First File";  

    char** arg=new char*[argc-1];

    for(int n=0;n<argc-2;n++)
    {
        arg[n]=argv[n+2];
    }

    execv(argv[1],arg);
    
    exit(0);
}
