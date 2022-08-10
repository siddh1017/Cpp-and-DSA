#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using namespace std;

int count = 0;
int turn;  // to decide whose turn it is 
bool flag[2];  // to indicate whether the particular process os ready or not to enter in cs

void *increment(void *vargp)
{
    int *myid = (int *)vargp;
    flag[0] = true;  // process ready to enter in c.s.
    turn = 1;        // assinging the turn to other process 
    while (flag[1] == true == 1 && turn == 1);  // if the other process is also ready to enter 
    {
        // critical section
        for (int i = 0; i < 5; i++)
        {
            count += 5;
            cout << "value increased : " << count << endl;
            // exit code
            flag[0] = false;
        }
    }
}
void *decrement(void *vargp)
{
    int *myid = (int *)vargp;
    flag[1] = true;  // process ready to enter in c.s.
    turn  = 0;       // assinging the turn to other process 
    while (flag[0] == 1 && turn == 0);  // if the other process is also ready to enter 
    {
        // critical section
        for (int i = 0; i < 5; i++)
        {
            count =- 5;
            cout << "value decremented : " << count << endl;
            // exit code
            flag[1] = true;
        }
    }
}
int main()
{
    int i;
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, increment, (void *)(&tid1));
    pthread_create(&tid2, NULL, decrement, (void *)(&tid2));
    pthread_exit(NULL);
    return 0;
}
