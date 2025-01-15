//thread condition variables

#include <stdio.h>
#include <pthread.h>

//threads can synchronize with each other using condition variables

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void *wait_for_ready(void *arg)
{
    pthread_mutex_lock(&mutex);

    while (ready == 0)
    {
        pthread_cond_wait(&cond, &mutex); //wait for condition
    }
    printf("Thread is now ready\n");
    pthread_mutex_unlock(&mutex);

    return NULL;
}


void *signal_ready(void *arg)
{
    pthread_mutex_lock(&mutex);
    ready = 1; //if you change this to 0, program will halt
    pthread_cond_signal(&cond);//signal the condition variable
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, wait_for_ready, NULL);
    pthread_create(&thread2, NULL, signal_ready, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}