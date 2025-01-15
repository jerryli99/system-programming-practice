//thread scheduling??? need to come back to this one

//the operating system schedules threads to run based on their priority and 
//available CPU time.


#include <stdio.h>
#include <pthread.h>
#include <sched.h> //??

void *do_work(void *arg)
{
    printf("Thread with adjusted priority is running\n");
    return NULL;
}


int main()
{
    pthread_t thread1;
    struct sched_param param;

    param.sched_priority = 100; //set priority, so high value for high priority
    pthread_create(&thread1, NULL, do_work, NULL);
    pthread_setschedparam(thread1, SCHED_FIFO, &param);//set thread scheduling policy
    printf("Main thread\n");
    pthread_join(thread1, NULL);

    return 0;
}