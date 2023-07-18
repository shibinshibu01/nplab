//Implement full duplex communication using named pipe/fifo

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int pipe1, pipe2;
    char str[1000];

    pipe1 = mkfifo("npipe1", 0777);
    // pipe2 = mkfifo("npipe2", 0777);

    if (pipe1 == 0 || pipe2 == 0) {  
        printf("Pipes created!\n");
    } else {
        printf("Error\n");
    }

    printf("Enter the Sentence: ");
    fgets(str,1000,stdin);
    puts(str);
    int fd=open("npipe1",O_WRONLY);
    write(fd,str,sizeof(str));    
    return 0;
}
