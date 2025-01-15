//thread detachment

#include <stdio.h>
#include <pthread.h>

void *do_work(void *arg)
{
    printf("Detached thread is doing work\n");
    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, do_work, NULL);
    //a thread is detached, meaning it runs independently and does not need ot be joined.
    pthread_detach(thread1);
    printf("Main thread is not waiting for thread\n");

    return 0;
}

/*
So sometimes I get 
Main thread is not waiting for thread
Detached thread is doing work
Detached thread is doing work

and sometimes I get
Main thread is not waiting for thread


Remember:
Thread join is a thread waits for another thread to finish execution before continuing.


Thread detach is a thread is detached, meaning it runs independently and doesn't need to be joined.

*/