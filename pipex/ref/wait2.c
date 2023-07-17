#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pid;
    int status;

    pid = fork();
    // 자식 프로세스 
    if (pid < 0)
    {
        perror("FORK ERROR :");
        exit(0);
    }    

    if (pid == 0)
    {
        int i;
        for (i = 0; i < 5; i++) 
        {
            printf("Child : %d\n", i);
            sleep(1);
        }
        exit(3);
    }
    else
    {
        // 부모프로세스는 자식프로세스가 
        // 종료할때까지 기다린다. 
        printf("I wait Child(%d)\n", pid);
        wait(&status);
        printf("Child is exit (%d)\n", status >> 8);
    }
}