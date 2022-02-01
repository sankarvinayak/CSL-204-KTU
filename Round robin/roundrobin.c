#include<stdio.h>
#include<string.h>
struct process{
	int at;
	int bt;
	int bt_left;
	int name;
};
int main()
{
	int i,j,k, NOP, sum=0,count=0, y, quant, wt=0, tat=0;
	struct process p[10],temp;
	float avg_wt, avg_tat;
	char gantt[100],str[2];
	printf(" Total number of process in the system: ");
	scanf("%d", &NOP);
	y = NOP; 
    for(i=0; i<NOP; i++)
    {
        printf("\nProcess[%d]\n", i+1);
        printf(" Arrival time :");  
        scanf("%d", &p[i].at);
        printf(" Burst time :"); 
        scanf("%d", &p[i].bt);
		p[i].name=i+1;
        p[i].bt_left = p[i].bt; 
    }
    printf("Time Quantum for the process: \t");
    scanf("%d", &quant);
    for(i=0;i<NOP-1;i++){
        for(j=0;j<NOP-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("\n Process No \t\t Arrival time \t\t Burst Time \t\t TAT \t\t Waiting Time ");
	sum=0;
	i=0;
    while(y!=0)
    {
        if(p[i].bt_left <= quant && p[i].bt_left > 0) 
        {
			strcat(gantt,"[P");
			sprintf(str, "%d",p[i].name );
			strcat(gantt,str);
			for(k=0;k<p[i].bt_left;k++){
				strcat(gantt,"#");
			}
			strcat(gantt,"]");	
        	sum = sum + p[i].bt_left;
        	p[i].bt_left = 0;
        	count=1;
    	}	
        else if(p[i].bt_left > 0)
    	{
			strcat(gantt,"[P");
			sprintf(str, "%d",p[i].name );
			strcat(gantt,str);
			for(k=0;k<quant;k++){
				strcat(gantt,"#");
			}
			strcat(gantt,"]");	
    		p[i].bt_left = p[i].bt_left - quant;
    		sum = sum + quant;	
    	}
    	if(p[i].bt_left==0 && count==1)
    	{
    		y--; 
    		printf("\nProcess No[%d] \t\t %d \t\t\t %d\t\t\t %d\t\t\t %d", p[i].name, p[i].at , p[i].bt, sum-p[i].at, sum-p[i].at-p[i].bt);
    		wt = wt+sum-p[i].at-p[i].bt;
    		tat = tat+sum-p[i].at;
    		count =0;	
    	}
    	if(i==NOP-1)
    	{
    		i=0;
    	}
		else if(p[i+1].at<=sum)
		{
			i++;
		}
		else
		{
			i=0;
		}
    }
    avg_wt = wt*1.0/NOP;
    avg_tat = tat*1.0/NOP;
    printf("\n Average Turn Around Time: \t%.2f",avg_tat );
    printf("\n Average Waiting Time: \t%.2f", avg_wt);
	printf("\n%s\n",gantt);
    return 0;
}
