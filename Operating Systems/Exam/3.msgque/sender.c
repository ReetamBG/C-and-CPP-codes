#include <stdio.h>
#include <sys/msg.h>

struct msgbuf{
    long mtype;
    char mtext[20];
};

int main(){
    struct msgbuf msg;
    msg.mtype = 1;
    fgets(msg.mtext, 20, stdin);
    int n = msgget(123456, 0666|IPC_CREAT);
    if(n == -1){
        printf("Error\n");
    }
    else{
        msgsnd(n, &msg, 20, 0);
    }
}