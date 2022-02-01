#include <stdio.h>
#define MAX_PROCESSES 10
struct processInfo
{

    int at,bt,pri,pid;
};
int main()
{

    struct processInfo process[MAX_PROCESSES], temp;
    int i, j, id, n, ttt = 0, twt = 0, ct;

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES)
    {

        printf("Number of processes should be between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }
    for(i=0;i<n;i++){
        printf("\nProcess id:%d\n",i+1);
        process[i].pid=i+1;
        printf("Arrival time:");
        scanf("%d",&process[i].at);
        printf("Burst time:");
        scanf("%d",&process[i].bt);
        printf("Priority:");
        scanf("%d",&process[i].pri);
    }
    printf("\n%-15s%-15s%-15s%-15s%-17s%-15s\n", "ProcessID", "ArrivalTime", "BurstTime", "Priority", "TurnAroundTime", "WaitingTime");
    for (i = 0, ct = process[0].at; i < n; i++)
    {
        id = -1;
        for (j = i; j < n; j++)
        {
            if (process[j].at <= ct)
            {
                if (i == 0)
                {
                    if (id == -1 || (process[j].at == process[id].at && process[j].pri < process[id].pri))
                    {

                        id = j;
                        ct = process[j].at;
                    }
                }
                else if (id == -1 || process[j].pri < process[id].pri)
                    id = j;
            }
        }
        ct += process[id].bt;
        printf("   P%-15d%-15d%-15d%-15d%-17d%-15d\n",
               process[id].pid,
               process[id].at,
               process[id].bt,
               process[id].pri,
               ct - process[id].at,
               ct - process[id].at - process[id].bt);
        ttt += (ct - process[id].at);
        twt += (ct - process[id].at - process[id].bt);
        if (id != i)
        {

            temp = process[id];
            process[id] = process[i];
            process[i] = temp;
        }
    }
    printf("\nAverage Waiting time = %0.2f \n\nAverage Turnaround Time = %0.2f\n\n", (float)((float)twt / (float)n), (float)((float)ttt / (float)n));

    return 0;
}
