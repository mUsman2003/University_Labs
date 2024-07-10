#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

using namespace std;

int Current_Direction=-1;
sem_t direction;        //  binary
sem_t Car;              //  4
sem_t Bus;              //  binary


struct Vehicle
{
    int direction;
    int carType;
    Vehicle(int a,int b):direction(a),carType(b){}
};

void Exiting(int carType,int direction)
{
    cout<<"Vehicle";

    if(carType==0)
        cout<<" car ";
    else 
        cout<<" bus ";
    cout<<" has Entered and exited in ";

    if(direction==0)
        cout<<"East Direction"<<endl;
    else 
        cout<<"West Direction"<<endl;
    
}

void* Arrive_at_Bridge_Sem(void* arg)
{
    Vehicle* ch=static_cast<Vehicle*>(arg);
    int value;
    
    if(Current_Direction==-1)
    {
        Current_Direction=ch->direction;
        sem_wait(&direction);
    }

    if(ch->direction!=Current_Direction)
        sem_wait(&direction);

    if(ch->carType==1)      //  for bus
    {
        sem_wait(&Bus);
        sem_wait(&Car);
        sem_wait(&Car);
        Exiting(ch->carType,ch->direction);
        sem_post(&Bus);
        sem_post(&Car);
        sem_post(&Car);
    }
    else if(ch->carType==0) //  for car
    {
        sem_wait(&Car);
        Exiting(ch->carType,ch->direction);
        sem_post(&Car);
    }
  

    sem_getvalue(&Car,&value);
    if(value==4)
    {
        if(Current_Direction==1)
            Current_Direction=0;
        else  
            Current_Direction=1 ; 
        cout<<endl;
        sem_post(&direction);
    }
    
    pthread_exit(0);
}




int main()
{
    srand(time(NULL));
    sem_init(&direction,0,1);
    sem_init(&Bus,0,1);
    sem_init(&Car,0,4);


    for(int n=0;n<10;n++)
    {
        pthread_t thread;
        Vehicle V(rand()%2,rand()%2);
        //cout<<"Car in Main loop:"<<V.carType<<" "<<V.direction<<endl;
        pthread_create(&thread,nullptr,Arrive_at_Bridge_Sem,&V);
    };
    
    //cout<<"Hello";

    pthread_exit(0);

}
