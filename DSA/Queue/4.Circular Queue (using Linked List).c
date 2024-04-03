#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = 0, *rear = 0, *temp;

void enqueue(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(rear == 0){
        if(rear == 0){
            front = rear = newnode;
            rear -> next;
        }
    }
    else{
        rear -> next = newnode;
        rear = newnode;
        rear -> next = front;
    }
}

void dequeue(){
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else if(front == rear){     // Meaning only one element present
        printf("The dequeued element is : %d\n", front -> data);
        temp = front;
        front = rear = 0;
        free(temp);
    }
    else{
        printf("The dequeued element is : %d\n", front -> data);
        temp = front;
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void display(){
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        temp = front;
        printf("The queue is :\n");
        while(temp -> next != front){       // temp -> next == front when temp == rear
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
        printf("%d", temp -> data);     // To print the last element 
        // Or we can use do while loop as well to directly do this
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