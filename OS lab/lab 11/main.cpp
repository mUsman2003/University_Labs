#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t Lock;
int Time_Counter = 0;

void *google(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "google is Running " << endl;
    Time_Counter += 6;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *word(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "word is Running " << endl;
    Time_Counter += 7;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *excel(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "excel is Running " << endl;
    Time_Counter += 5;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *zoom(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "zoom is Running " << endl;
    Time_Counter += 3;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *notepad(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "notepad is Running " << endl;
    Time_Counter += 8;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *vscode(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "vscode is Running " << endl;
    Time_Counter += 3;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *settings(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "settings is Running " << endl;
    Time_Counter += 6;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *oracle(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "oracle is Running " << endl;
    Time_Counter += 4;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}
void *camera(void *p1)
{
    pthread_mutex_lock(&Lock);
    cout << "camera is Open" << endl;
    Time_Counter += 9;
    pthread_mutex_unlock(&Lock);
    pthread_exit(0);
}



int count = 0;
int main()
{
    cout << "---------------Kernel is Starting-------------" << endl;
    cout << "---------Application are going to start-------" << endl;

    pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
    
    pthread_mutex_init(&Lock, NULL);

    pthread_create(&thread1, NULL, &google, NULL);
    pthread_create(&thread2, NULL, &word, NULL);
    pthread_create(&thread3, NULL, &excel, NULL);
    pthread_create(&thread4, NULL, &zoom, NULL);
    pthread_create(&thread5, NULL, &notepad, NULL);
    pthread_create(&thread6, NULL, &vscode, NULL);
    pthread_create(&thread7, NULL, &settings, NULL);
    pthread_create(&thread8, NULL, &oracle, NULL);
    pthread_create(&thread9, NULL, &camera, NULL);

    //  Join is required otherwise the OS can terminate beforer atarting all aplication

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);


    cout << "---------   Kernel is Terminating    ---------" << endl;
    cout << "---------   OS is Shitting down  :(  ---------" << endl;
    cout << "---------   Total Run Time : " << Time_Counter<<"      ---------"<<endl;
    
    pthread_mutex_destroy(&Lock);
    
    pthread_exit(NULL);
    exit(0);
}
