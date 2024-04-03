#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = 0, *temp;

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
    if(head == 0){
        head = newnode;
    }
    else{
        newnode -> next = head;
        head = newnode;
    }
}

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

void insertAfterPosition(int x, int pos){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(pos > getLength()){          // Starting from 1
        printf("Out of Bounds\n");
    }
    else if(pos == 0){
        insertAtBeginning(x);
    }
    else{
        temp = head;
        int i = 1;
        while(i < pos){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void deleteAtBeginning(){
    if(head == 0){
        printf("Underflow\n");
    }
    else{
        printf("The deleted element is : %d\n", head -> data); 
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
        struct node *prev;
        temp = prev = head;
        while(temp -> next != 0){
            prev = temp;
            temp = temp -> next;
        }
        printf("The deleted element is : %d\n", temp -> data); 
        if(temp == head){           // To check if only one element
            head = 0;               // But shouldnt this be automatically checked in the while loop cuz if there is only one element the while loop wont run and temp is still head so it can directly free head and prev also = head so prev -> = 0 will set head -> next = 0???
            // No cuz we are setting head = 0 and not head -> next = 0 ... we can also do the same if we write temp = 0 but doing this or that same thing
        }
        else{
            prev -> next = 0;
        }
            free(temp);
    }
}

void deleteAfterPosition(int pos){
    if(pos > getLength() - 1){
        printf("Out of Bounds\n");
    }
    else if(pos == 0){
        deleteAtBeginning();
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
        printf("The deleted element is : %d\n", ptr -> data); 
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
    printf("HH");
    deleteAtEnd();
    printf("HH");
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