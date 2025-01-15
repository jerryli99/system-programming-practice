//thread cancellation

//Uhm, so a thread can be cancelled by another thread

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *do_work(void *arg)
{
    printf("Thread started now\n");
    while(1) 
    {
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, do_work, NULL);
    sleep(2); //let the thread just run for a little while
    pthread_cancel(thread1); //cancel the thread
    pthread_join(thread1, NULL);
    printf("Thread canceled\n");
    //haha, so funny, I don't why, when i see the thread canceled, i find it humorous.
    return 0;
}