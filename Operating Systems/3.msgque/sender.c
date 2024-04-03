// msgget

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
    msg.mtype = 1;        // Can be any value (Acts as a key)
    // strcpy(msg.mtext, "Hello");            
    // msgget() to create message queue        
    int n = msgget(123456, 0666 | IPC_CREAT);
	if(n == -1){
        printf("Error\n");
    }
    else{
        fgets(msg.mtext, 20, stdin);  
        msgsnd(n, &msg, 6, 0);
        printf("Message Sent\n");
    }
    return 0;
}


// fgets is used for input (not using scanf cuz scanf breaks off after spaces)