//dead lock

/*

A dead lock occurs when two or more threads are blocked forever, each waiting 
for the other to release a resource. In this case, the threads are stuck in a cycle
of waiting, and no thread can proceed.

*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

// void *thread1_func(void *arg)
// {
//     pthread_mutex_lock(&mutex1);
//     printf("Thread1: Holding mutex 1\n");
//     sleep(1); //simulate work
//     pthread_mutex_lock(&mutex2); //try to lock mutex 2
//     printf("Thread1: holding mutex 2\n");
//     pthread_mutex_unlock(&mutex1);
//     pthread_mutex_unlock(&mutex2);

//     return NULL; 
// }


// void *thread2_func(void *arg)
// {
//     pthread_mutex_lock(&mutex2);
//     printf("Thread2: Holding mutex 2\n");
//     sleep(1); //simulate work
//     pthread_mutex_lock(&mutex1); //try to lock mutex 1
//     printf("Thread2: holding mutex 1\n");
//     pthread_mutex_unlock(&mutex2);
//     pthread_mutex_unlock(&mutex1);

//     return NULL; 
// }

// /*

// So we have the lock and unlock, but right now, the code will not work because
// thread1 holds mutex1 and tries to acquire mutex2, and
// thread2 holds mutex2 and tries to acquire mutex1. Neigher thread can proceed,
// causing a deadlock.

// */
// int main()
// {
//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, thread1_func, NULL);
//     pthread_create(&thread2, NULL, thread2_func, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     return 0;
// }

//so how to fix this?
void *thread1_func(void *arg) {
    pthread_mutex_lock(&mutex1);//lock mutex1 first
    printf("Thread 1: Holding mutex 1\n");
    sleep(1);  //simulate work
    pthread_mutex_lock(&mutex2);  //Lock mutex2 after mutex1
    printf("Thread 1: Holding mutex 2\n");
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void *thread2_func(void *arg) {
    pthread_mutex_lock(&mutex1);  //lock mutex1 first
    printf("Thread 2: Holding mutex 1\n");
    sleep(1);  // Simulate work
    pthread_mutex_lock(&mutex2);  //lock mutex2 after mutex1
    printf("Thread 2: Holding mutex 2\n");
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
/*
Thread 1: Holding mutex 1
Thread 1: Holding mutex 2
Thread 2: Holding mutex 1
Thread 2: Holding mutex 2
*/