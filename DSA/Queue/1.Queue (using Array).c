#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

  void enqueue(int x){      // Insertion from rear
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if(rear == MAX -1){
        printf("Queue is full\n");
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){     // Deletion from front
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("The dequeued element is : %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("The dequeued element is : %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("The queue is empty\n");
    }
    else{
        printf("The queue is : \n");
        for(int i = front; i <= rear; i++){     // We have to use <= rear or < rear+1
            printf("%d\t", queue[i]);
        }
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
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    peek();
}
    


