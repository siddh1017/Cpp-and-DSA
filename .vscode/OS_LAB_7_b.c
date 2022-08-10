#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

int count = 0;  // shared variable
sem_t mutex;
void *thread1(void *arg)
{
    // entry code
    sem_wait(&mutex);  // similar to down(mutex)
    printf("Entering thread\n");
    // critical section
    for (int i = 0; i < 5; i++)
    {
        count++;
        printf("Count: %d\n", count);
    }
    printf("Exiting thread1\n");
    // exit code
    sem_post(&mutex); // similar to up(mutex)
}
void *thread2(void *arg)
{
    // entry code
    sem_wait(&mutex);  // similar to down(mutex)
    printf("Entering thread2\n");
    // critical section
    for (int i = 0; i < 5; i++)
    {
        count--;
        printf("Count: %d\n", count);
    }
    // exit code
    printf("Exiting thread2");
    sem_post(&mutex);
}
int main()
{
    int i;
    sem_init(&mutex, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_exit(NULL);
    return 0;
}
