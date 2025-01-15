//thread synchronization (mutexes)

#include <stdio.h>
#include <pthread.h>

//use mutexes to avoid data races when multiple threads access shared resources.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *increment_counter(void *arg)
{
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Counter:%d\n", counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}