#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pos[20],n,head,i,j,temp,tst=0,max;
    printf("\nEnter number of disk seeks:");
    scanf("%d",&n);
    printf("Enter disk seeks position:\n");
    for(i=0;i<n;i++){
        scanf("%d",&pos[i]);
    }
    printf("Enter initial head position:");
    scanf("%d",&head);
    printf("Enter max value of seek for the disk:");
    scanf("%d",&max);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(pos[i]>pos[j]){
                temp=pos[j];
                pos[j]=pos[i];
                pos[i]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(head<=pos[i])
        break;
    }
    j=n;
    while (j>0)
    {
        if(i<n){
            printf("\nDisk moved from %d to %d with seek time %d",head,pos[i],abs(head-pos[i]));
            tst+=abs(head-pos[i]);
            head=pos[i];
            i++;
            j--;
        }if(i==n){
            printf("\nDisk moved from %d to %d with seek time %d",head,max,max-head);
            tst+=max-head;
            printf("\nDisk moved from %d to %d with seek time %d",max,0,max);
            tst+=max;
            i=0;
            head=0;
        }
    }
    printf("\nTotal seek time=%d",tst);
    printf("\nAverage seek time=%d\n",tst/n);
    return 0;
}
