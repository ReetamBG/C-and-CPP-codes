#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *adj, *next;
};

int main(){
    struct node *A =(struct node *)malloc(sizeof(struct node));
    struct node *B =(struct node *)malloc(sizeof(struct node));
    struct node *C =(struct node *)malloc(sizeof(struct node));
    struct node *D =(struct node *)malloc(sizeof(struct node));

    // For A
    A -> data = 'A';
    A -> next = (struct node *)malloc(sizeof(struct node));
    A -> next -> data = 'B';
    A -> next -> next = (struct node *)malloc(sizeof(struct node));
    A -> next -> next -> data ='C';
    A -> next -> next -> next = 0;

    // For B
    B -> data = 'B';
    B -> next = (struct node *)malloc(sizeof(struct node));
    B -> next -> data = 'D';
    B -> next -> next = (struct node *)malloc(sizeof(struct node));
    B -> next -> next -> data ='A';
    B -> next -> next -> next = 0;

    // For C
    C -> data = 'C';
    C -> next = (struct node *)malloc(sizeof(struct node));
    C -> next -> data = 'A';
    C -> next -> next = 0;

    // For D
    D -> data = 'D';
    D -> next = (struct node *)malloc(sizeof(struct node));
    D -> next -> data = 'B';
    D -> next -> next = 0;

    // Adjacency List
    A -> adj = B;
    B -> adj = C;
    C -> adj = D;
    D -> adj = 0;

    // Print Graph

    struct node *temp1 = A, *temp2;
    while(temp1 != 0){
        temp2 = temp1 -> next;
        while(temp2 != 0){
            printf("%c is connected to %c\n", (temp1 -> data), (temp2 -> data));
            temp2 = temp2 -> next;
        }
        temp1 = temp1 -> adj;
    }

    return 0;
}



    
    
