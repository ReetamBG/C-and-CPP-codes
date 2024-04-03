#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head = 0, *tail = 0, *temp;

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

void reverseList(){
    struct node *currentNode, *nextNode;
    if(head == 0){
        printf("List is empty\n");
    }
    else{
        currentNode = head;
        while(currentNode != 0){
            nextNode = currentNode -> next;
            currentNode -> next = currentNode -> prev;      
            //  currentNode -> prev already set to zero if it is the head node 
            currentNode -> prev = nextNode;
            currentNode = nextNode;
        }
        currentNode = head;
        head = tail;
        tail = currentNode;
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
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    reverseList();
    display();
}