//thread creation
#include <stdio.h>
#include <pthread.h>

void *exit_thread(void *arg)
{
    printf("Thread existing\n");
    pthread_exit(NULL); //so we are explicitly exiting the thread
}

int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, exit_thread, NULL);
    pthread_join(thread1, NULL);
    return 0;
}