#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;

// Creation (simple implementation / adding nodes)
void create_node(int x){
    struct node *newnode;
    head = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    if(head == 0){
        head = tail = newnode;
        head -> next = head;
        head -> prev = head;
    }
    else{
        tail -> next = newnode;
        newnode  -> prev = tail;
        newnode -> next = head;
        head -> prev = newnode;
        tail = newnode;
    }
}

// Display
void display(){
    struct node *temp = head;
    if(head == 0){
        printf("The List is Empty");
    }
    else{
        printf("The list is : ");
        do{
            printf("%d", temp -> data);
            temp = temp -> next;
            if(temp != tail){
                printf(" -> ");
            }
        }
        while(temp != tail);    //using while loop wont print the last element
        printf("\n");
    }   
}

// Function to get number of nodes (length of the list)
int get_length(){
    int count = 1;
    struct node *temp;
    temp = head;
    do{
        temp = temp -> next;
        count ++;
    }
    while(temp -> next != tail);
    return count;
}

// Function to insert node at beginning
void insert_at_beginning(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    if(head == 0){
        head = tail = newnode;
        head -> prev = tail;
        head -> next = head;
    }
    else{
        newnode -> next = head;
        head -> prev = newnode;
        newnode -> prev = tail;
        tail -> next = newnode;
        head = newnode;
    }
}

// Function to insert node at end
void insert_at_end(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    if(head == 0){
        head = tail = newnode;
        head -> prev = tail;
        head -> next = head;
    }    
    else{
        newnode -> prev = tail;
        tail -> next = newnode;
        newnode -> next = head;
        head -> prev = newnode;
        tail = newnode;
    }
}

// Function to insert node at position
void insert_at_position(int x, int pos){
    struct node *newnode, *temp = head;
    int i = 1, length = get_length();
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    if(pos < 1 || pos > length){
        printf("Invalid Position");
    }
    else if(pos == 1){
        insert_at_beginning(x);
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = x;
        while(i < pos -1){
            temp = temp -> next;
            i++;
        }
        newnode -> prev = temp;
        newnode -> next = temp -> next;
        temp -> next -> prev = newnode;
        temp -> next = newnode;
    }
}

// Function to delete node at beginning
void delete_at_beginning(){
    struct node *temp;
    temp = head;
    if(head == 0){
        printf("List is Empty\n");
    }
    else if(head-> next == head){    // i.ew only one node as head -> next = head ... we can also use tail -> next = tail
        head = tail = 0;
        printf("The Deleted Element is : %d\n", temp -> data);
        free(temp);
    }
    else{
        head = head -> next;
        head -> prev = tail;
        tail -> next = head;
        printf("The Deleted Element is : %d\n", temp -> data);
        free(temp);
    }
}

// Function to delete node at end
void delete_at_end(){
    struct node *temp;
    temp = tail;
    if(head == 0){
        printf("List is Empty\n");
    }
    else if(head-> next == head){  
        head = tail = 0;
        printf("The Deleted Element is : %d\n", temp -> data);
        free(temp);
    }
    else{
        tail = tail -> prev;
        tail -> next = head;
        head -> prev = tail;
        printf("The Deleted Element is : %d\n", temp -> data);
        free(temp);
    }
}

// Function to delete node at position
void delete_at_pos(int pos){
    struct node *temp;
    int length = get_length(), i = 1;
    temp = head;
    if(pos < 1 || pos > length){
        printf("Invalid Position\n");
    }
    else{
        while(i < pos){
            temp = temp -> next;
            i ++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        printf("The Deleted Element is : %d\n", temp -> data);
        free(temp);
    }
}

int main(){
    create_node(1);    
    insert_at_beginning(2);
    insert_at_beginning(4);
    display();
    insert_at_end(5);
    insert_at_position(9, 2);
    display();
    delete_at_beginning();
    display();
    delete_at_end();
    display();
    delete_at_pos(2);
    display();
}