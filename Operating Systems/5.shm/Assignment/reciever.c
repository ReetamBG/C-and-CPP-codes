#include <sys/shm.h>
#include <stdio.h>

int main(){
    int shmid = shmget(123456, 5, 0666);
    int *shared_memory_address = shmat(shmid, NULL, 0);
    // int buffer[5];
    int *buffer_ptr;
    // for(int i=0; i<5; i++){
    //     printf("%d\n", shared_memory_address[i]);
    // }

    buffer_ptr = shared_memory_address;

    for(int i=0; i<5; i++){
        for(int j=i; j<(5-1-i); j++){
            if(*(buffer_ptr+j) > *(buffer_ptr+j+1)){
                int temp = *(buffer_ptr+j);
                *(buffer_ptr+j) = *(buffer_ptr+j+1);
                *(buffer_ptr+j+1) = temp;
            }
        }
    }

    shared_memory_address = buffer_ptr;

    for(int i=0; i<5; i++){
        printf("%d", shared_memory_address+i);
    }
}
        
    