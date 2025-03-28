#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
    void*sharedmemory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of Shared Memory is: %d\n",shmid);
    sharedmemory=shmat(shmit,NULL,0);
    prinft("Process Attatched at %p\n",sharedmemory);
    printf("Enter Data to Write: ");
    read(0,buff,100);
    strcpy(sharedmemory,buff);
    printf("You Wrote: %s\n", (char*)sharedmemory);

}
