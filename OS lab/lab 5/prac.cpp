#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main( int argc , char* argv [])
{
    int* arr=new int[argc-1];

    cout<<"In Secound File "<<endl;

    for(int n=0;n<argc-1;n++)
    {
        arr[n]=atoi(argv[n+1]);
        if(arr[n]%2==0)
            cout<<arr[n]<<endl;
    }   
    delete []arr;
    return 0;

}