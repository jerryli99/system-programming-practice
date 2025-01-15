//race conditionss
//extention from threads_ex4.c.....


#include <stdio.h>
#include <pthread.h>

int counter = 0;

//now add mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *arg)
{
    for (int index = 0; index < 10000; index++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);//good
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Counter value: %d\n", counter);

    return 0;
}