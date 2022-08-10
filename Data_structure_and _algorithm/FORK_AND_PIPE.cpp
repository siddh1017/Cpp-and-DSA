#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

void Sort(int n, int *arr)
{
    int is_sort = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        { 
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_sort = 0;
            }
            if (is_sort)
                return;
        }
    }
}

int main()
{
    char process = 'p'; // to keep track which process 
    int c[2];
    pipe(c);

    if (fork() == 0)
    {
        if (fork() == 0)
        {
            if (fork() == 0)
            {
                if (fork() == 0)
                {
                    process = 'E';   // 1st this wiil start, then below in line
                }
                else
                    process = 'D';
            }
            else
                process = 'C';
        }
        else
            process = 'B';
    }
    else
        process = 'A';

    int n = 5;
    int data_A[5], data_B[5], data_C[5];  
    if (process == 'A' ||  process == 'B' || process == 'C'){
        for (int i = 0 ; i < n; i++){
            data_A[i] = rand()%15 + 1;
            Sort(n, data_A);
            data_B[i] = rand()%15 + 1;
            Sort(n , data_B);
            data_C[i] = rand()%15 + 1;
            Sort(n, data_C);
        }
    }

    int data_E[15];  
    if (process == 'C'){
        write (c[1], data_C, 5);
    }

    int data_D[10];
    if (process == 'A' || process == 'B'){
        write(c[1], data_A, 5);
        write(c[1], data_B, 5);
    }

    if (process == 'D'){
        wait();
        read(c[0], data_D, 10);
        // read(c[0], data_B, 5);
        cout << "In process D (A and B are passed to D)" << endl;
        Sort(10, data_D);
        write(c[1], data_D, 10);
    }

    if (process == 'E'){
        read(c[0], data_E,5);
        read(c[0], data_E,10);
        cout << "In process E (C and D are passed to E)" << endl;
        Sort (15, data_E);
        for (int i = 0; i < 15; i++){
            cout << data_E[i] << " ";
        }
    }
    return 0;
}