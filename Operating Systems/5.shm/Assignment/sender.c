#include <sys/shm.h>
#include <stdio.h>

int main(){
    int shmid = shmget(123456, 5, 0666|IPC_CREAT);
    int *shared_memory_address = shmat(shmid, NULL, 0);
    int buffer[5];

    printf("Enter the data :\n");
    for(int i=0; i<5; i++){
        scanf("%d", shared_memory_address+i);
    }

    for(int i=0; i<5; i++){
        printf("%d", shared_memory_address[i]);
    }
    printf("Data sent\n");
    
}

