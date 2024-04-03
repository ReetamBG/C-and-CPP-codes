#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int x = fork();
	if(x == 0){
		printf("CHILD\n");
        printf("Process ID : %d\n", getpid());
        printf("Process ID of the parent : %d\n", getppid());
	}
	else{
        sleep(1);       
		printf("PARENT\n");
        printf("Process ID : %d\n", getpid());
	}
	return 0;
}

// getpid() -> returns process id of the process
// getppid() -> returns process id of the parent process
  
// if the parent gets terminated before the child then the process control of the child is transfered to systemd (process id = 1)
// This is however very rare

// Anytime anything goes wrong the control always goes back to systemd