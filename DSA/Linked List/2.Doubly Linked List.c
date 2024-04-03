#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head = 0, *tail = 0, *temp;

int getLength(){
    int count = 0; 
    temp = head;
    while(temp != 0){
        temp = temp -> next;
        count++;
    }
    return count;
}

void insertAtBeginning(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    newnode -> prev = 0;
    if(head == 0){
        head = tail = newnode;
    }
    else{
        newnode -> next = head;
        head -> prev = newnode;
        head = newnode;
    }
}

void insertAtEnd(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    newnode -> prev = 0;
    if(head == 0){
        head = newnode;
    }
    else{
        temp = head;
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        tail = newnode;
    }
}

void insertAfterPosition(int x, int pos){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(pos > getLength()){          // Starting from 1
        printf("Out of Bounds\n");
    }
    else if(pos == 1){
        insertAtBeginning(x);
    }
    else if(pos == getLength()){
        insertAtEnd(x);
    }
    else{
        int i = 1;
        temp = head;
        while(i < pos){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        newnode -> prev = temp;
        temp -> next = newnode;
        temp -> next -> prev = newnode;
    }
}

void deleteAtBeginning(){
    if(head == 0){
        printf("Underflow\n");
    }
    else{
        printf("The deleted element is: %d\n", head -> data);
        temp = head;
        head = head -> next;
        free(temp);
    }
}

void deleteAtEnd(){
    if(head == 0){
        printf("Underflow\n");
    }
    else{
        temp = head;
        while(temp -> next -> next != 0){
            temp = temp -> next;
        }
        printf("The deleted element is: %d\n", temp -> next -> data);
        free(temp -> next);
        temp -> next = 0;
    }
}

void deleteAfterPosition(int pos){
    if(pos > getLength() - 1){
        printf("Out of Bounds\n");
    }
    else if(pos == 0){
        deleteAtBeginning();
    }
    else if(pos == getLength()-1){
        deleteAtEnd();
    }
    else{
        int i = 1;
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        temp = head;
        while(i < pos){
            temp = temp -> next;
            i++;
        }
        ptr = temp -> next;
        temp -> next -> next -> prev = temp;
        temp -> next = temp -> next -> next;
        free(ptr);
    }
}

void display(){
    temp = head;
    printf("The list is : ");
    while(temp != 0){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


int main(){
    insertAtBeginning(3);
    deleteAfterPosition(0);
    deleteAtBeginning();
    insertAtBeginning(2);
    insertAtEnd(5);
    insertAtBeginning(-3);
    display();
    insertAfterPosition(2, 5);
    display();
    insertAfterPosition(7, 2);
    display();
    deleteAfterPosition(3);
    display();
    deleteAfterPosition(1);
}

