#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(int x, struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(head == 0){
        head = newnode;
    }
    else{
        struct node *temp = head;
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void delete(struct node *head){
    struct node *temp;
    temp = head;
    while(temp -> next -> next != 0){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = 0;
}

void display(struct node *head){
    struct node *temp = head;
    
