#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int x = fork();
	if(x == 0){
		printf("CHILD\n");
	}
	else{
        sleep(1);       // The CPU instead of waiting will switch to the child process instead so it will print CHILD first this time
		printf("PARENT\n");
	}
	return 0;
}
  
