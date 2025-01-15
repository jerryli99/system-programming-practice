//starvation
//occurs when a thread is perpetually denied resources or CPU time due to other
//threads with higher priority or resoruces always being available.


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// int counter = 0;

// void *high_priority_thread(void *arg)
// {
//     for (int index = 0; index < 10; index++)
//     {
//         pthread_mutex_lock(&mutex);
//         counter++;
//         printf("High priority thread: %d\n", counter);
//         pthread_mutex_unlock(&mutex);
//         sleep(1);//simulate work
//     }

//     return NULL;
// }


// void *low_priority_thread(void *arg)
// {
//     for (int index = 0; index < 10; index++)
//     {
//         pthread_mutex_lock(&mutex);
//         counter--;
//         printf("Low priority thread: %d\n", counter);
//         pthread_mutex_unlock(&mutex);
//         sleep(1);//simulate work
//     }
//     return NULL;
// }


// int main()
// {
//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, high_priority_thread, NULL);
//     pthread_create(&thread2, NULL, low_priority_thread, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     return 0;

//     /*
//     The code for thread1 (high priority) might continuously acquire the mutex
//     before thread2 (low priority) gets a chance to execute, effectively starving
//     thread2. This could happen in systems where the scheduler gives more CPU time to
//     thread1 over thread2, leading to starvation of the low-priority thread.
//     High priority thread: 1
//     Low priority thread: 0
//     High priority thread: 1
//     Low priority thread: 0
//     Low priority thread: -1
//     High priority thread: 0
//     Low priority thread: -1
//     High priority thread: 0
//     Low priority thread: -1
//     High priority thread: 0
//     High priority thread: 1
//     Low priority thread: 0
//     High priority thread: 1
//     Low priority thread: 0
//     High priority thread: 1
//     Low priority thread: 0
//     High priority thread: 1
//     Low priority thread: 0
//     Low priority thread: -1
//     High priority thread: 0
//     ??? Uhmmm....
//     we can fix this using a fair scheduling policy, e.g. pthread_cond_t or by reducing
//     priority differences...
//     */
// }

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 0;
int high_priority_turn = 1; // Indicates whether it's high-priority thread's turn to execute

void *high_priority_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        // Wait for the high-priority thread's turn
        while (!high_priority_turn) {
            pthread_cond_wait(&cond, &mutex);
        }

        counter++;
        printf("High priority thread: %d\n", counter);
        high_priority_turn = 0; // Switch turn to low-priority thread
        pthread_cond_signal(&cond); // Signal low-priority thread to run

        pthread_mutex_unlock(&mutex);
        sleep(1);  // Simulate work
    }
    return NULL;
}

void *low_priority_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        // Wait for the low-priority thread's turn
        while (high_priority_turn) {
            pthread_cond_wait(&cond, &mutex);
        }

        counter--;
        printf("Low priority thread: %d\n", counter);
        high_priority_turn = 1; // Switch turn to high-priority thread
        pthread_cond_signal(&cond); // Signal high-priority thread to run

        pthread_mutex_unlock(&mutex);
        sleep(1);  // Simulate work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, high_priority_thread, NULL);
    pthread_create(&thread2, NULL, low_priority_thread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

/*
Output:
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0
High priority thread: 1
Low priority thread: 0

*/