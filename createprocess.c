#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int pid,pid1,pid2;
    pid=fork();
    if(pid==-1)
    {
        printf("Error in Process");
        exit(0);
    }
    elseif(pid!=0)
    {
        pid
    }
}