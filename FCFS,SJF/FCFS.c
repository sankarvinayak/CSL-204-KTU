#include <stdio.h>
int main(){
    int n,i,j,bt[20],p[20],at[20],wt[20],tt[20],temp;
    float avwt,avtt;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Process P%d \n",i+1);
        printf("burst time:");
        scanf("%d",&bt[i]);
        printf("Arrival time:");
        scanf("%d",&at[i]);
        p[i]=i+1;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    wt[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        wt[i]=wt[i]-at[i];
    }
 
    printf("\nProcess\t\tArrival time\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    for(i=0;i<n;i++)
    {
        tt[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtt+=tt[i];
        printf("\nP%d\t\t%d\t\t\t%d\t\t%d\t\t%d",p[i],at[i],bt[i],wt[i],tt[i]);
    }
 
    avwt/=i;
    avtt/=i;
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround time:%f\n",avtt);
    printf("Gantt chart : ");
    for(i=0;i<n;i++){
        printf("[");
        printf("P%d",p[i]);
        for(j=0;j<bt[i];j++)
        printf("#");
        printf("]");
    }
    printf("\n");
    return 0;
}