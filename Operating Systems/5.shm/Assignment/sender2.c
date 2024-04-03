#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
int main()
{
    int shmid = shmget(12345, 10, 0666|IPC_CREAT);
    int *shared_memory = shmat(shmid, NULL, 0);
    shared_memory[0]=4;
    shared_memory[1]=7;
    shared_memory[2]=2;
    shared_memory[3]=9;
    shared_memory[4]=1;
    return 0;
}