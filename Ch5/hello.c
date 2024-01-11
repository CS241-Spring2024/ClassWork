#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Usage error: ./hello n\n");
        exit(1);
    }
    for (int i = 0; i<atoi(argv[1]); i++)
    {
        printf("Hello\n");
        fflush(stdout);
        sleep(1);
    }
    return 0;
}