// fork

#include <stdio.h>
#include <unistd.h>

int main(){
	int x = fork();
	if(x == 0){
		printf("CHILD\n");
	}
	else{
		printf("PARENT\n");
	}
	return 0;
}
  
