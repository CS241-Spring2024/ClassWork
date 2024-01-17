#include <stdio.h>
#include <unistd.h> //close, open
#include <fcntl.h> //O_RDONLY
int main()
{
    int fd;
    close(1);
    fd = open("output.txt", O_CREAT | O_RDONLY | O_WRONLY);
    if (fd==-1){
        perror("Opening file output");
    }
    printf("fd = %d\n", fd);
    printf("Hello World!\n");
    return 0;

}
