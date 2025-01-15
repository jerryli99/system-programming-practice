Just some simple thread programs. I will use them to practice some basic Ghidra stuff I guess.

threads vs. processes: (credit https://mohitmishra786.github.io/chessman/2024/09/24/Deep-Threads-Diving-into-the-Core-of-Concurrent-Programming-with-C.html)

1. both threads and processes allow for concurrent execution
2. threads share memory in a process. Processes have isolated memory spaces.
3. inter-thread communication is generally faster and easier than inter-process communication
4. creating a thread is typically faster and less resource intensive than creating a new process.

```
In threads_ex4.c, explored thread synchronization by using mutal exclusion locks (mutex)
to help the counters count right. But there is a cost. While mutex does solve the race
condition problem, performance is going to bite us. Each lock and unlock operation takes time,
and threads may need to wait to acquire the lock. For example:

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *do_work(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

So how to improve?

well, we can do something like this:

void *do_work(void *arg)
{
    int local_count = 0;
    for (int i = 0; i < 1000; i++)
    {
        local_count++;
    }

    pthread_mutex_lock(&mutex);
    counter += local_count;
    pthread_mutex_unlock(&mutex);

    return NULL;
}


So at least we reduced the number of lock/unlock operations
```

List:

