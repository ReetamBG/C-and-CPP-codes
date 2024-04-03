#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = 0, *rear = 0, *temp;

void enqueue(int x){        // Insert from rear
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(front == 0 && rear == 0){
        front = rear = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
    }
}

void dequeue(){     // Delete from front
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        printf("The dequeued element is : %d\n", front -> data);
        temp = front;
        front = front -> next;
        free(temp);
        if(front == 0){
            rear = 0 ;
        }
    }
}

void display(){
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        temp = front;
        printf("The queue is :\n");
        while(temp != 0){
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void peek(){
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        printf("The front element is : %d\n", front -> data);
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
    display();
    dequeue();
    peek();
}