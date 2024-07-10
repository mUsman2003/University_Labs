#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

struct IntArray {
    int values[10];
}arr;

void* input(void* arg)
{
    struct IntArray *data = (struct IntArray *)arg;
    printf("Enter 10 integer values for the array:-\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter value for index %d: ", i);
        scanf("%d", &(data->values[i])); 
    }
    
    void *status;
    pthread_exit((void*)status);
}

void* Max(void* arg)
{
    struct IntArray *data = (struct IntArray *)arg;
    int max=0;
    for (int i = 0; i < 10; i++) {
        
        if(max<data->values[i])
            max=data->values[i];
    }
    printf("\nMax integer in the string: %d",max);
    
    pthread_exit(NULL);
}

void* TwoMul(void* arg)
{
    struct IntArray *data = (struct IntArray *)arg;
    int count=0;
    printf("\nMultiple of 2: ");
    for (int i = 0; i < 10; i++) {
        
        if(data->values[i]%2==0)
        {
            printf("  %d",data->values[i]);
            count=count+1;
        }
    }
    printf("\nTotal multiples of 2: %d",count);
    
    pthread_exit(NULL);
}

void* EvenOdd(void* arg)
{
    struct IntArray *data = (struct IntArray *)arg;
    int OddCount=0;
    int EvenCount=0;
    for (int i = 0; i < 10; i++) {
        
        if(data->values[i]%2==0)
        {            
            EvenCount=EvenCount+1;
        }
        else
        {
            OddCount=OddCount+1;
        }
    }
    printf("\nTotal Odd: %d",OddCount);
    printf("\nTotal Even: %d",EvenCount);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid[4];
    void *text;
    pthread_attr_t tid1;

    pthread_attr_init(&tid1);
    pthread_attr_setdetachstate(&tid1,PTHREAD_CREATE_DETACHED);

    pthread_create(&tid[0],NULL,input,(void*)&arr);    
    pthread_join(tid[0],&text);    

    pthread_create(&tid[1],&tid1,Max,(void*)&arr);    

    pthread_create(&tid[2],&tid1,TwoMul,(void*)&arr);  

    pthread_create(&tid[3],&tid1,EvenOdd,(void*)&arr); 

    pthread_attr_destroy(&tid1);
    pthread_exit(NULL);
}
