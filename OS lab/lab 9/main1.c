#include <stdio.h>
#include <pthread.h>

void* username()
{
    char str[24];
    printf("Enter a name: ");
    scanf("%s",&str);
    void *status =strdup(str);
    pthread_exit((void*)status);
}

void* ascii_convert(void* data)
{

    char *str=(char*)data;
    int len=strlen(str);
    for (int  i = 0; i < len; i++)
    {
        printf("ASCII of %c",str[i]);
        printf(": %d",(int)str[i]);
        printf("\n");
    }
    void *status;
    pthread_exit((void*)status);
}

void *reverse(void* data)
{
    char *str=(char*)data;
    int len=strlen(str);
    printf("Reverse String: ");
    for (int  i = len-1; i >=0 ; i--)
    {
        printf("%c",str[i]);
    }
    void *status;
    pthread_exit((void*)status);
}

void *palindrome(void* data)
{
    char check='0';
    char *str=(char*)data;
    int j=strlen(str)-1;
    int i=0;
    while (i<j)
    {
        if(str[j]!=str[i])
        {
            printf("Not a Palindrome\n");
            check='1';
            break;
        }
        j--;
        i++;
    }
    if(check=='0')
    {
        printf("Is a Palindrome\n");
    }
    
    void *status;
    pthread_exit((void*)status);
}


int main(void)
{
    void *text;
    void *dummydata;

    pthread_t tid[4];
    pthread_create(&tid[0], NULL, username, NULL);
    pthread_join(tid[0], &text);
    printf("\n\n\n");
    printf("Entered Value: %s", (char *)text);
    printf("\n\n\n");

    pthread_create(&tid[1], NULL, ascii_convert, text);
    pthread_join(tid[1], &dummydata);
    printf("\n\n\n");

    pthread_create(&tid[2], NULL, reverse, text);
    pthread_join(tid[2], &dummydata);
    printf("\n\n\n");

    pthread_create(&tid[3], NULL, palindrome, text);
    pthread_join(tid[3], &dummydata);
    printf("\n\n\n");


}
    // pthread_exit(NULL);   for executing all the thread before completing main thread