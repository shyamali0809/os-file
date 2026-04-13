#include <stdio.h>
int main()
{
    int n = 5;
    int pid[] = {0, 1, 2, 3, 4};
    int arrival[] = {0, 1, 2, 3, 4};
    int burst[] = {5, 7, 6, 2, 4};

    int i;
    int time = 0;
    int sum_wait = 0, sum_tat = 0;
    int complication[5], start[5], wating[5], turnaround[5];
    for (i = 0; i < n; i++)
    {
        if (time < arrival[i])
        {
            time = arrival[i];
        }
        start[i] = time;
        complication[i] = start[i] + burst[i];
        wating[i] = start[i] - arrival[i];
        turnaround[i] = complication[i] - arrival[i];

        time = complication[i];
        sum_wait += wating[i];
        sum_tat += turnaround[i];
    }
    printf("PID\tArrival-T\tBurstT\tST\tCT\tWT\tTAT\n");
    for (i = 0; i < n; ++i)
    {

        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], arrival[i], burst[i], start[i], complication[i], wating[i], turnaround[i]);
    }
    return 0;
}