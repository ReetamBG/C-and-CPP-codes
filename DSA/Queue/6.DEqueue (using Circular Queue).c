#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueueFront(int x){
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[front] = x;
    }
    else if(front == 0){
        front = MAX - 1;
        queue[front] = x;
    }
    else{
        front--;
        queue[front] = x;
    }
}

void enqueueRear(int x){
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if(rear == MAX-1){
        rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeueFront(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("The dequeued element is : %d\n", queue[front]);
        front = rear = -1;
    }
    else if(front == MAX-1){
        printf("The dequeued element is : %d\n", queue[front]);
        front = 0;
    }
    else{
        printf("The dequeued element is : %d\n", queue[front]);
        front++;
    }
}

void dequeueRear(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("The dequeued element is : %d\n", queue[front]);
        front = rear = -1;
    }
    else if(rear == 0){
        printf("The dequeued element is : %d\n", queue[front]);
        rear = MAX-1;
    }
    else{
        printf("The dequeued element is : %d\n", queue[front]);
        rear--;
    }
}

void getFront(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("The front value is : %d\n", queue[front]);
    }
}

void getRear(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("The rear value is : %d\n", queue[front]);
    }
}

void display(){
    int temp = front;
    printf("The queue is :\n");
    while(temp != rear){
        printf("%d\t", queue[temp]);
        temp = (temp+1) % MAX;
    }
    printf("%d", queue[rear]);
    printf("\n");
}

int main(){
    enqueueFront(4);
    enqueueRear(3);
    enqueueFront(5);
    display();
    getFront();
    getRear();
    dequeueFront();
    dequeueRear();
    display();
    getFront();
    getRear();
    dequeueRear();
    dequeueFront();
    dequeueRear();
    display();
    getFront();
    getRear();
}