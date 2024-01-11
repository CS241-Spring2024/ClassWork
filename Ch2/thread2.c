#include <stdio.h>
#include <pthread.h>
void printMessage(char * m);
int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)printMessage, (void *)"A");
    pthread_create(&t2, NULL, (void *)printMessage, (void *)"B");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void printMessage(char * m)
{
    for (int i = 0; i< 1000; i++){
        printf("%s\n", m);
        fflush(stdout);
    }
}
