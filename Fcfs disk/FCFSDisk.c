#include <stdio.h>
int magdiff(int a,int b){
    if(a>b)
        return a-b;
    else
        return b-a;
}
int main()
{
    int n,i,disk[10],tot=0,curpos,head;
    printf("Enter number of disk operations:");
    scanf("%d",&n);
    printf("\nInitial head position:");
    scanf("%d",&head);
    curpos=head;
    printf("Enter the processes position in arrival order\n");
    for(i=0;i<n;i++){
        scanf("%d",&disk[i]);
        tot+=magdiff(curpos,disk[i]);
        curpos=disk[i];
    }
    printf("\nHead movement\n %d",head);
    for(i=0;i<n;i++)
        printf("-->%d",disk[i]);
    printf("\nTotal seek time:%d",tot);
    printf("\nAverage seek time:%d\n",tot/n);
    return 0;
}
