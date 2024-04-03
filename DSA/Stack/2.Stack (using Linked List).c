#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = 0, *temp;

void push(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = 0;
    if(top == 0){
        top = newnode;
    }
    else{
        newnode -> next = top;
        // Note that top stores the address of the node and not top -> next
        // top -> next stores the address of the next node of the first node (as head points to the first node so top -> next will mean firstNode -> next)
        top = newnode;
    }
    // Basically insert at beginning (top)
    // To keep time complexity at O(1) {mandatory for stack and queue}
}

void pop(){
    if(top == 0){
        printf("Stack is empty\n");
    }
    else{
        printf("The popped element is : %d\n", top -> data);
        temp = top;
        top = top -> next;
        free(temp);
    }
    // Basically delete at beginning (top)
}

void display(){
    if(top == 0){
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        printf("The stack is :\n");
        while(temp != 0){
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void peek(){
    if(top == 0){
        printf("Stack is empty\n");
    }
    else{
        printf("The top element is : %d\n", top -> data);
    }
}

int main(){
    push(5);
    push(2);
    push(7);
    display();
    pop();
    pop();
    display();
    peek();
    pop();
    display();
    pop();
    peek();
}

