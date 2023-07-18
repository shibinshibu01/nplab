//Implement full duplex communication using named pipe/fifo

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main() {

    char message[100];

    int fd1=open("npipe1",O_RDONLY);
    read(fd1,message,sizeof(message));   
    puts(message);
    return 0;
}
