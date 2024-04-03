#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
int main(){
    char buf[10];
    int shmid = shmget(123456, 1024, 0666|IPC_CREAT);
    printf("Shared memory created successfully\n");
    void *shared_memory = shmat(shmid, NULL, 0);
    printf("Shared memory attached at %p\n", shared_memory);

    printf("Enter the data : ");
    fgets(buf, 10, stdin);

    strcpy(shared_memory, buf);
    printf("Data sent successfully\n");
}
