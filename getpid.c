#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t childpid;
    childpid=fork();
    if(childpid==0)
    {  
        print("Child Process Successfully Created\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(),getpid());
    }
    elseif(childpid<0)
    {
        printf("Fork Failed!");
        return 1;
    }
    else
    {
        wait(NULL);
        printf("Parent Process Successfully Created\n");
        printf("Child PID: %d, Parent PID: %d", getpid(), getpid());
    }
}