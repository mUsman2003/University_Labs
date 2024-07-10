#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

void* fun()
{
    printf("Fun");
    void *status;
    pthread_exit((void*)status);
}

int main(void)
{
    pthread_t tid;
/*
    void *text;
    pthread_create(&tid, NULL, fun, NULL);
    pthread_detach(&tid);
    pthread_join(tid, &text);
*/

    pthread_attr_t tid1;
    pthread_attr_init(&tid1);
    pthread_attr_setdetachstate(&tid1,PTHREAD_CREATE_DETACHED);
    pthread_create(&tid,&tid1,fun,NULL);        

    // thread is only called on create funtion
    // this is its calling function

    pthread_exit(NULL);
/*
    int* oldstate;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,&oldstate);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,&oldstate);
*/
}

/*

    - by default asynchronus

                    int* oldstate;
                    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,oldstate);
                    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,&oldstate);
                    enable------------------------->asynchronus -------> terminate
         req    |         |------------------------>deffered ----------> join
                |                                           |----------> conditional wait
                |                                           |----------> signal
                |
Main() ---------> 
                |
                    disable ----> pending queue



*/
