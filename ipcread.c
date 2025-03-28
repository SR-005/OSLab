#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main()
{
    void*sharedmemory;
    int shmid;

    if(shmid==-1)
    {
        perror("SHM Failed");
        exit(1);
    }
    sharedmemory=shmat(shmid,NULL,0);
    if(shared_memory==(void*)-1)
    {
        perror("SHMAT Failed");
        exit(1);
    }
    printf("Process attached at %p\n",sharedmemory);
    printf("Data Read From Shared Memory: %s\n",(char*)sharedmemory);
}