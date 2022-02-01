#include <stdio.h>
#include <stdlib.h>
struct page_table_entry{
	int page_frame_index;
	int valid;
};
int main(){
	struct page_table_entry *page_table_base[20],*current_page_table_base;
	int number,entry,logical_address,page_table_index,displacement,physical_index,i,j,pid,in;
	printf("Enter the number of programs ");
	scanf("%d",&number);
	for(i=0;i<number;i++){
		page_table_base[i]=(struct page_table_entry*)malloc(16*sizeof(struct page_table_entry));
		printf("Enter number of page table entries of process %d ",i+1);
		scanf("%d",&entry);
		for(j=0;j<16;j++){
			if(j<entry){
				printf("page frame index of %dth page of %d th process ",j,i+1);
				scanf("%d",&page_table_base[i][j].page_frame_index);
				page_table_base[i][j].valid=1;
			}else{
				page_table_base[i][j].valid=0;
			}

		}
	}
	while(1){	
		printf("\n1-Schedule\n2-translate\nelse- exit ");
		scanf("%d",&in);
		if(in==1){
			
			printf("\nEnter the id of process 1- %d ",number);
			scanf("%d",&pid);
			pid--;
			current_page_table_base=page_table_base[pid];
			printf("\nPage table of process %d",pid+1);
			printf("\nPage table index\tPage frame index\tValid");
			for(i=0;i<16;i++){
				printf("\n%d\t\t\t%d\t\t\t%d",i,current_page_table_base[i].page_frame_index,current_page_table_base[i].valid);
			}
		}
		else if(in==2){
			printf("\nEnter the logical address in hexadecimal(16 bit binary) ");
			scanf("%x",&logical_address);
			page_table_index=logical_address/4096;
			displacement=logical_address%4096;
			if(current_page_table_base[page_table_index].valid==1){
				printf("\nphysical address of the given logical address=%x ",(current_page_table_base[page_table_index].page_frame_index)*4096+displacement);
			}
			else{
				printf("\n!!invalid page index!!\n");
			}
		}
		else{
			printf("\n!!Exiting!!\n");
			return 0;
		}
 	}
}
