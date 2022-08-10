#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to find the waiting time for all processes
int waitingtime(char proc[], int n,
                int burst_time[], int wait_time[])
{
   // waiting time for first process is 0
   wait_time[0] = 0;
   // calculating waiting time
   for (int i = 1; i < n; i++)
      wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
   return 0;
}
// Function to calculate turn around time
int turnaroundtime(char proc[], int n,
                   int burst_time[], int wait_time[], int tat[])
{
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for (i = 0; i < n; i++)
      tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
// Function to calculate average time
int avgtime(char proc[], int n, int burst_time[])
{
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i;
   // Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, wait_time);
   // Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   // Display processes along with all details
   printf("\n*****FCFS Scheduling Algorithm*****\n\n");
   printf("Processes  Burst   Waiting Turn around \n");
   // Calculate total waiting time and total turn
   // around time
   for (i = 0; i < n; i++)
   {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf(" %c\t  %d\t\t %d \t%d\n", proc[i], burst_time[i], wait_time[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}
// main function
int main()
{
   int pid, pid1, pid2, pid3;
   int flag = 0;
   pid = fork();

   // If fork() returns zero then it
   // means it is child process.
   if (pid == 0)
   {

      // First child needs to be printed
      // later hence this process is made
      // to sleep for 3 seconds.
      sleep(4);

      // This is first child process
      // getpid() gives the process
      // id and getppid() gives the
      // parent id of that process.
      printf("Process D --> pid = %d and ppid = %d\n",
             getpid(), getppid());
   }

   else
   {
      pid1 = fork();
      if (pid1 == 0)
      {
         sleep(3);
         printf("Process C --> pid = %d and ppid = %d\n",
                getpid(), getppid());
      }
      else
      {
         pid2 = fork();
         if (pid2 == 0)
         {
            sleep(2);
            // This is third child which is
            // needed to be printed first.
            printf("Process B --> pid = %d and ppid = %d\n",
                   getpid(), getppid());
         }

         // If value returned from fork()
         // in not zero and >0 that means
         // this is parent process.
         else
         {
            pid3 = fork();
            if (pid3 == 0)
            {
               printf("Process A --> pid = %d and ppid = %d\n",
                      getpid(), getppid());
            }
            else
            {

               // This is asked to be printed at last
               // hence made to sleep for 3 seconds.
               sleep(4);
               flag = 1;
               printf("Process E --> pid = %d\n", getpid());
            }
         }
      }
   }

   if (flag == 1)
   {
      // process id's
      char proc[] = {'A', 'B', 'C', 'D', 'E'};
      int n = sizeof proc / sizeof proc[0];
      // Burst time of all processes
      int burst_time[] = {5, 8, 12, 14, 19};
      avgtime(proc, n, burst_time);
   }
   return 0;
}
