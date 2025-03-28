#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        printf("Exec stats\n");
        execl("/bin/ls","ls","-1",NULL);
        printf("Exec didn't work");
    }
    else
    {
        wait(0);
        printf("Parent=ls is complete in Child")
    }
}