#include <stdio.h>
#include <stdlib.h>

struct node{
    int data, priority;
    struct node *next;
};

void insertNode(struct node **head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> next = 0;
    printf("Enter the data : " );
    scanf("%d", &newnode -> data);
    printf("Enter the priority : ");
    scanf("%d", &newnode -> priority);
    if(*head == 0){
        *head = newnode;
    }
    else{
        if(newnode -> priority < (*head) -> priority){
            newnode -> next = *head;
            *head = newnode;
        }
        else{
            struct node *temp = *head;
            while(temp -> next != 0 && temp -> priority < (newnode -> priority) - 1){
                temp = temp -> next;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }
}

void deleteNode(struct node **head){
    struct node *temp;
    if(*head == 0){
        printf("Undedrflow\n");
    }
    else{
        struct node *temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
}

void display(struct node *head){
    if(head == 0){
        printf("List is empty\n");
        return;
    }
    printf("The list is : ");
    struct node *temp = head;
    while(temp != 0){
        printf("%d (%d)\t", temp -> data, temp -> priority);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct node *head = 0;
    insertNode(&head);
    insertNode(&head);
    insertNode(&head);
    display(head);
    deleteNode(&head);
    deleteNode(&head);
    display(head);
    insertNode(&head);
    display(head);
    deleteNode(&head);
    deleteNode(&head);
    display(head);
    deleteNode(&head);
}
