//Implement a full duplex communication between parent and child process.Parent process writes filename of a file on pipe1.This filename is read by child process.The child process writes the contents of the file to pipe2.The contents are read from pipe2 by the parent process and is displayed on standard output.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
    
    FILE *fptr;
    int fd1[2],fd2[2];
    pid_t pid;
    char str[100],filename[100],filecontent[100];
    int pipe1,pipe2;

    pipe1 = pipe(fd1);
    pipe2 = pipe(fd2);

    if(pipe1 == 0){
        printf("Success pipe1\n");
    }else{
        printf("Error pipe1\n");
    }
    if(pipe2 == 0){
        printf("Success pipe2\n");
    }else{
        printf("Error pipe1\n");
    }

    pid = fork();
    
    if(pid==0){
        //child
        close(fd1[1]);
        read(fd1[0],filename,sizeof(filename));
        fptr=fopen(filename,"r");
        fgets(filecontent,100,fptr);
        close(fd2[0]);
        write(fd2[1],filecontent,sizeof(filecontent));        
    } else if(pid>1){
        //parent
        printf("Enter the file name :");
        scanf("%s",str);
        close(fd1[0]);
        write(fd1[1],str,strlen(str) + 1);
        close(fd2[1]);
        read(fd2[0],filecontent,sizeof(filecontent));    
        puts(filecontent);
    } else{
        printf("\nFork() failed!");
    }
    return 0;
}
