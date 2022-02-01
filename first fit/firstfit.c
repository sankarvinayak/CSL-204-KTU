#include <stdio.h>
int main()
{
    int block[10],pro[10],temp[10],n,i,j;
    printf("Enter the number of blocks/processes ");
    scanf("%d",&n);
    printf("Enter size of each block in order\n");
    for(i=0;i<n;i++){
        printf("Block %d ",i+1);
        scanf("%d",&block[i]);
        temp[i]=0;
    }
    printf("Enter the process memory requirement in order\n");
    for(i=0;i<n;i++){
        printf("Process %d ",i+1);
        scanf("%d",&pro[i]);
    }
    printf("Process number\tProcess size\tblock number\tblock size\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(pro[i]<=block[j]&&temp[j]==0){
                    temp[j]=1;
                    printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,pro[i],j+1,block[j]);
                    break;
            }
            if(j==n-1){
                printf("Unable to find sutable location for process %d of size %d\n",i+1,pro[i]);
            }
        }
    }
    return 0;
}