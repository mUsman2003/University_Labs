#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_data
{
    int m1[100][100];
    int m2[100][100];
    int result[100][100];
}Matrix;

void *Quad1(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;

    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            for (int k = 0; k < 100; ++k)
            {
                data->result[i][j] += data->m1[i][k] * data->m2[k][j];
            }
        }
    }

    void *status;
    pthread_exit((void *)status);
}
void *Quad2(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;

    for (int i = 25; i < 50; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            for (int k = 0; k < 100; ++k)
            {
                data->result[i][j] += data->m1[i][k] * data->m2[k][j];
            }
        }
    }
    void *status;
    pthread_exit((void *)status);
}
void *Quad3(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;

    for (int i = 50; i < 75; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            for (int k = 0; k < 100; ++k)
            {
                data->result[i][j] += data->m1[i][k] * data->m2[k][j];
            }
        }
    }

    void *status;
    pthread_exit((void *)status);
}
void *Quad4(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;

    for (int i = 75; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            for (int k = 0; k < 100; ++k)
            {
                data->result[i][j] += data->m1[i][k] * data->m2[k][j];
            }
        }
    }

    void *status;
    pthread_exit((void *)status);
}

int main()
{
    srand(time(0));
    char text;
    int M1[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            Matrix.m1[i][j] = rand() % 10 + 1;

    int M2[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            Matrix.m2[i][j] = rand() % 10 + 1;

    int result[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            Matrix.result[i][j] = 0;


    pthread_t tid[4];
    pthread_create(&tid[0], NULL, Quad1, (void *)&Matrix);
    pthread_join(tid[0], &text);
    pthread_create(&tid[1], NULL, Quad2, (void *)&Matrix);
    pthread_join(tid[1], &text);
    pthread_create(&tid[2], NULL, Quad3, (void *)&Matrix);
    pthread_join(tid[2], &text);
    pthread_create(&tid[3], NULL, Quad4, (void *)&Matrix);
    pthread_join(tid[3], &text);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            printf(" %d",Matrix.result[i][j]);
        }
        printf("\n");
    }
    
}