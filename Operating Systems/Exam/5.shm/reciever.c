#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
int main(){
    char buf[10];
    int shmid = shmget(123456, 1024, 0666);
    printf("Shared memory created successfully\n");
    void *shared_memory = shmat(shmid, NULL, 0);
    printf("Shared memory attached at %p\n", shared_memory);

    printf("Recieved data : %s", shared_memory);
}