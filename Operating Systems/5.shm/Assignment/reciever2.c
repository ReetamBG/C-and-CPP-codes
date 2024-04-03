#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int shmid = shmget(12345, 10, 0666|IPC_CREAT);
    int *shared_memory = shmat(shmid, NULL, 0);
    
    // SORTING
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(shared_memory[j] > shared_memory[j+1]){
                int temp = shared_memory[j];
                shared_memory[j] = shared_memory[j+1];
                shared_memory[j+1] = temp;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        printf("%d \n",*(shared_memory+i));
    }
    
    return 0;
}