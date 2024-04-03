#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(){
    printf("Inside thread\n");
    for(int i=0; i<5; i++){
        sleep(1);
        printf("%d\n", i);
    }
}

int main(){
    pthread_t thread;       // thread variable
    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, NULL);
    printf("Inside main\n");
    for(int i=5; i<10; i++){
        sleep(1);
        printf("%d\n", i);
    }
}

