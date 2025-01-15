/**
 * @brief Situation #1: create a thread that is actively running
 * 
 */

#include <stdio.h>
#include <pthread.h>

void *print_msg(void *arg)
{
    pthread_t tid = pthread_self(); //get ID of curr thread
    printf("Hello, thread %lu is running now...\n", tid);
    return NULL;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, print_msg, NULL);
    pthread_create(&thread2, NULL, print_msg, NULL);
    
    printf("The Main function thread id is: %lu\n", pthread_self());
    /*
    So pthread_join means wait for a thread to terminate, 
    then choose to clean up resources used by the thread.

    After a successful call to pthread_join(), the caller is guaranteed that the
    target thread has terminated.

    Joining with a thread that has previously been joined results in undefined 
    behavior.

    Failure to join with a thread that is joinable (i.e., one that is not detached), 
    produces a "zombie thread".  Avoid doing this, since each zombie thread 
    consumes some system resources, and when enough zombie threads have 
    accumulated, it will no longer be possible to create new threads (or processes).
    */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}