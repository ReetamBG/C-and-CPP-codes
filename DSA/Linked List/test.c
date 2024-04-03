#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertNode(int x, struct node **head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(*head == 0){
        *head = newnode;
    }
    else{
        struct node *temp = *head;
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void display(struct node **head){
    if(*head == 0){
        printf("List is empty\n");
        return;
    }
    printf("The list is : ");
    struct node *temp = *head;
    while(temp != 0){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct node *head = 0;
    insertNode(2, &head);
    insertNode(3, &head);
    display(&head);
}
 
