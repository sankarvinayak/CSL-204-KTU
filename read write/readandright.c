#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    int fd;
    char buffer[50];
    char msg[50]="Welcome to shell programming";
    fd=open("read.txt",O_RDWR|O_CREAT);
    printf("fd=%d",fd);
    if(fd!=-1){
        printf("\n read.txt opened with read and write access\n");
        write(fd,msg,sizeof(msg));
        lseek(fd,0,SEEK_SET);
        read(fd,buffer,sizeof(msg));
        printf("\n%s was written to my file\n",buffer);
        close(fd);
    }
    return 0;
}