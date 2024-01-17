#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();  // int pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "the process creation failed\n"); 
    }
    else if (pid == 0)
    {
        execlp("sleep", "sleep", "5", NULL);   
    } else {
        while(1)
       {
            //remove zombies
            //int childStatus;
            waitpid(pid, NULL, WNOHANG);
            //check if the process still exist
            //errno = ESRCH No such process, try man kill
            if((kill(pid, 0) == -1) && (errno==ESRCH)){
                printf("Process is dead\n");
                return 0;
            } else {
                printf("Process is running... Do you want to kill it (y/n)? ");
                char input;
                scanf(" %c", &input);//need space to skip '/n'
                if (input=='y' || input == 'Y'){
                    kill(pid, SIGINT);
                    printf("Process is killed\n");
                    return 0;
                }
            }
        }
    }
    return 0;
}
