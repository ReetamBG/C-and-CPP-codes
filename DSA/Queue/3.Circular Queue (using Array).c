#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if(((rear+1) % MAX) == front){
        printf("Queue is full\n");
    }
    else{
        rear = (rear+1) % MAX;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("The dequeued element is : %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("The dequeued element is : %d\n", queue[front]);
        front = (front+1) % MAX;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        int i = front;
        printf("The queue is :\n");
        // for(int i = front; i != rear+1; i = (i+1) % MAX)   This can also be used
        while(i != rear){
            printf("%d\t", queue[i]);
            i = (i+1) % MAX;
        }
        printf("%d\n", queue[i]);       // To print the last element (or we can use do while loop as well to do this directly)
        // Dont use while(i != rear+1) cuz this will not work if rear is just behind front
        printf("\n");
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("The front element is : %d\n", queue[front]);
    }
}

int main(){
    enqueue(3);
    enqueue(7);
    enqueue(5);
    display();
    peek();
    dequeue();
    dequeue();
    display();
    peek();
    dequeue();
    dequeue();
    display();
    peek();
}