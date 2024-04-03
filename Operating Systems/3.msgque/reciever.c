// msgrcv

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main(){
    struct msgbuf{
        long mtype;
        char mtext[20];
    };
    struct msgbuf msg;                 
    int n = msgget(123456, 0666);
	if(n == -1){
        printf("Error\n");
    }
    else{
        msgrcv(n, &msg, 20, 1, 0);
        printf("Message Recieved : %s", msg.mtext);
    }
    return 0;
}
