#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
void sort(int *num, int max)
{
    int a;
    for (int i = max; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (num[j - 1] > num[j])
            {
                a = num[j - 1];
                num[j - 1] = num[j];
                num[j] = a;
            }
        }
    }
}
int main()
{
    int c[2];
    pipe(c);
    printf("\n");
    char g = 'p';
    if (fork() == 0)
    {
        if (fork() == 0)
        {
            if (fork() == 0)
            {
                if (fork() == 0)
                {
                    g = 'E';
                }
                else
                    g = 'D';
            }
            else
                g = 'C';
        }
        else
            g = 'B';
    }
    else
        g = 'A';
    int data[30];
    int ds = sizeof(data);
    int seed = (((getpid() ^ 4) * 3 / 2) % 511) - 256;
    srand(seed);
    if (g == 'A' || g == 'B' || g == 'C')
    {
        for (int n = 0; n < 30; n++)
        {
            data[n] = rand() % 255 + 1;
        }
        sort(data, 30);
        printf("\n");
        printf("%c", g);
        printf("|");
        for (int n = 0; n < 30; n++)
        {
            printf("%d", data[n]);
            printf(" "); 
        }
    }
    if (g == 'A' || g == 'B')
    {
        write(c[1], data, ds);
    }
    if (g == 'C')
    {
        int data2[30];
        int c_dat[90];
        read(c[0], data, ds);
        read(c[0], data2, ds);
        for (int i = 0; i < 60; i++)
        {
            c_dat[i] = i % 2 == 0 ? data[i / 2] : data2[(i - 1) / 2];
        }
        printf("\n");
        printf("Combined:");
        sort(c_dat, 60);
        for (int n = 0; n < 60; n++)
        {
            printf("%d", c_dat[n]);
            printf(" ");
        }
        write(c[1], c_dat, sizeof(ds));
    }
    if (g == 'C')
        write(c[1], data, ds);
    if (g == 'E')
    {
        int data2[30];
        int F_dat[90];
        read(c[0], F_dat, sizeof(F_dat));
        read(c[0], F_dat, sizeof(data2));
        for (int i = 0; i < 30; i++)
        {
            F_dat[60 + i] = data2[i];
        }
        printf("\n");
        printf("\n");
        printf("Combined:");
        sort(F_dat, 90);
        for (int n = 0; n < 90; n++)
        {
            printf("%d", F_dat[n]);
            printf(" ");
        }
    }
    return 0;
}
 
