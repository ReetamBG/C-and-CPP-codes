#include <stdio.h>
#include <string.h>
#define MAX 10

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

void pop(){  
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
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

void palindromeChecker(char *str){
    int length = strlen(str);
    int i = 0;
    while(i < length / 2){
        push(*(str + i));
        i++;
    }
    if(length % 2 != 0){
        i++;
    }
    while(top >= 0){
        if(*(str + i) != stack[top]){                // Compare mid -> last element (using i++) with mid -> first element (using pop)
            printf("Not Palnidrome\n");              // Refer to https://www.youtube.com/watch?v=uDfqjMIXB8s
            return;
        }
        i++;
        pop();
    }
    if(top == -1){
        printf("String is a palindrome\n");
    }
}

int main(){
    char string[] = "mom";
    palindromeChecker(string);
}
    