//thread pool

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//a thread pool allows you to resue threads for multiple tasks, avoiding the
//overhead of repeatedly creating and destroying threads.

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *do_work(void *arg)
{
    //if i don't add mutex lock, the numbers are just messed up :(
    pthread_mutex_lock(&mutex);
    printf("Worker thread is doing work\n");
    printf("Count: %d\n", ++count);
    pthread_mutex_unlock(&mutex);
    return NULL;
}


int main()
{
    pthread_t thread_pool[4];
    for (int index = 0; index < 4; index++)
    {
        pthread_create(&thread_pool[index], NULL, do_work, NULL);
    }

    printf("Main function thread is working\n");
    count += 1;

    for (int index = 0; index < 4; index++)
    {
        pthread_join(thread_pool[index], NULL);
    }
    printf("Count: %d\n", count);

    return 0;
}