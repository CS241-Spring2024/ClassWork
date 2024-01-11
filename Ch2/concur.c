#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void * count(int * num);
const int LOOP=100000;//change
int main()
{
    int counter = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)count, (void *)&counter);
    pthread_create(&t2, NULL, (void *)count, (void *)&counter);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final value: %d\n", counter);
    return 0;
}

void * count(int * num)
{
   for (int i = 0; i< LOOP; i++)
   {
        (*num)++;
   } 
   return NULL;
}
