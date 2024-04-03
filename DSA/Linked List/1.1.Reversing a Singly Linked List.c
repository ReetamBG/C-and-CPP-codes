#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = 0, *temp;

void insertAtEnd(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(head == 0){
        head = newnode;
    }
    else{
        temp = head;
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void reverseList(){
    if(head == 0){
        printf("List is empty\n");
    }
    else{
        struct node *prevNode = 0, *currentNode, *nextNode;
        currentNode = head;
        while(nextNode != 0){
            nextNode = currentNode -> next;
            currentNode -> next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        head = prevNode;
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