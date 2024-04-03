#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x){   // Insertion from top
    if(top == MAX -1){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){     // Deletion from top as well
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("The popped element is : %d\n", stack[top]);
        top--;
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("The list is : \n");
        for(int i = top; i >= 0; i--){
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("The top element is : %d\n", stack[top]);
    }
}

int main(){
    push(3);
    push(5);
    push(1);
    display();
    pop();
    pop();
    peek();
    display();
    pop();
    pop();
    display();
}
    