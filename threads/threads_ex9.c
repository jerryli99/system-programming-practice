//thread attributes (e.g stack size)
//custom attributes like stack size, scheduling policy, etc can be set for threads
#include <stdio.h>
#include <pthread.h>

void *do_work(void *arg)
{
    printf("Thread with custom stack size is running\n");
    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_attr_t attr;
    size_t stack_size = 1024 * 1024; //1 MB
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, stack_size);
    pthread_create(&thread1, &attr, do_work, NULL);
    pthread_join(thread1, NULL);
    pthread_attr_destroy(&attr);
    printf("Main thread\n");
    return 0;
}

