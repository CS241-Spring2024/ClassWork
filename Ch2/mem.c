#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "usage: mem <value>\n"); 
        exit(1); 
    } 
    int x =5;
    printf("Address of x is %p\n", &x);
    int *p; 
    p = malloc(sizeof(int));
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);
    *p = atoi(argv[1]); // assign value to addr stored in p
    for (int i = 0; i<20; i++) {
        sleep(1);
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}
